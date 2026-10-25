#!/usr/bin/env python3
"""Local CSP201412C audit; Python 3.9+ standard library, no network actions.

Default: compile the current project source and check 9 fixed + 200 random
cases. --stress checks 2000 random cases and 5 maximum 5000-line cases.
The actual 90 WA remains unresolved: local passes do not establish OJ AC.
Zero-volume cases test a stated convention, not an unambiguous specification.
"""
from __future__ import annotations

import argparse
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import platform
import random
import shlex
import subprocess
import time

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "201412" / "C.cpp"
BUILD = ROOT / ".build" / "auction-regressions"
REPORT = ROOT / "tests" / "auction-report.json"
SEED = 20141203


def encode(rows):
    return "\n".join(
        "cancel %d" % row[1] if row[0] == "cancel" else
        "%s %d.%02d %d" % (row[0], row[1] // 100, row[1] % 100, row[2])
        for row in rows) + "\n"


def brute(rows, all_cents=False):
    # Rebuild orders using cancelled row numbers, independently of the C++
    # program's in-place flags and cumulative volume sweep.
    cancelled = {r[1] for r in rows if r[0] == "cancel"}
    orders = [r for i, r in enumerate(rows, 1)
              if i not in cancelled and r[0] != "cancel"]
    if not orders:
        return "0.00 0", 0
    prices = sorted({r[1] for r in orders})
    candidates = range(prices[0], prices[-1] + 1) if all_cents else prices
    best = (-1, -1)
    for p in candidates:
        buy = sum(q for t, price, q in orders if t == "buy" and price >= p)
        sell = sum(q for t, price, q in orders if t == "sell" and price <= p)
        best = max(best, (min(buy, sell), p))
    volume, price = best
    return "%d.%02d %d" % (price // 100, price % 100, volume), volume


def fixed_cases():
    # Ties, cancelled row numbering, exact cents, largest quantities/prices.
    return [
        [("buy", 100, 10), ("sell", 1, 10)],
        [("buy", 1000000, 100000000), ("sell", 1, 100000000)],
        [("buy", 101, 2), ("sell", 100, 1), ("buy", 99, 10)],
        [("buy", 101, 10), ("cancel", 1), ("buy", 102, 10),
         ("sell", 1, 10), ("cancel", 3), ("buy", 103, 10)],
        [("buy", 100, 10), ("sell", 100, 10), ("cancel", 1)],
        [("buy", 100, 10), ("cancel", 1)],
        [("buy", 100, 10), ("sell", 101, 10)],
        [("sell", 100, 10)],
        [("buy", 100, 10)],
    ]


def random_cases(rng, count):
    for _ in range(count):
        rows, active = [], []
        for _ in range(rng.randint(2, 80)):
            if active and rng.random() < .3:
                idx = rng.choice(active)
                active.remove(idx)
                rows.append(("cancel", idx))
            else:
                rows.append((rng.choice(("buy", "sell")), rng.randint(1, 40),
                             rng.choice((1, 2, 3, 99999999, 100000000))))
                active.append(len(rows))
        yield rows


def maximum_cases(rng):
    # When --stress follows 2000 random cases, this reproduces the historical
    # full audit's random stream exactly. Inputs are generated in memory.
    for kind in range(5):
        rows, active = [], []
        for _ in range(5000):
            if kind == 1 and active and rng.random() < .5:
                idx = rng.choice(active)
                active.remove(idx)
                rows.append(("cancel", idx))
            else:
                price = rng.randint(1, 1000000) if kind < 3 else 1000000
                quantity = rng.randint(1, 100000000) if kind < 4 else 100000000
                rows.append((rng.choice(("buy", "sell")), price, quantity))
                active.append(len(rows))
        yield rows


class Runner:
    def __init__(self):
        BUILD.mkdir(parents=True, exist_ok=True)
        self.executable = BUILD / "201412C"
        compiler = shlex.split(os.environ.get("CXX", "c++"))
        subprocess.run(compiler + ["-std=c++17", "-O2", str(SOURCE),
                                  "-o", str(self.executable)], check=True)
        self.result = {
            "recorded_at_utc": datetime.now(timezone.utc).isoformat(),
            "platform": platform.platform(),
            "machine": platform.machine(),
            "compiler": subprocess.run(compiler + ["--version"], text=True,
                                       capture_output=True, check=True).stdout.splitlines()[0],
            "source_sha256": hashlib.sha256(SOURCE.read_bytes()).hexdigest(),
            "seed": SEED, "fixed_cases": 0, "random_cases": 0,
            "maximum_5000_line_cases": 0,
            "positive_volume_cases": 0, "zero_volume_convention_cases": 0,
            "maximum_solver_process_seconds": 0.0,
        }

    def check(self, label, rows, all_cents=False):
        assert 1 <= len(rows) <= 5000
        cancelled = set()
        for line, row in enumerate(rows, 1):
            if row[0] == "cancel":
                assert 1 <= row[1] < line
                assert rows[row[1] - 1][0] in ("buy", "sell")
                assert row[1] not in cancelled
                cancelled.add(row[1])
            else:
                assert row[0] in ("buy", "sell")
                assert 1 <= row[1] <= 1000000 and 1 <= row[2] <= 100000000
        expected, volume = brute(rows, all_cents)
        text = encode(rows)
        started = time.perf_counter()
        try:
            process = subprocess.run([str(self.executable)], input=text, text=True,
                                     capture_output=True, timeout=5)
            actual = process.stdout.strip()
            failure = process.returncode != 0 or actual != expected
            detail = {"actual": actual, "stderr": process.stderr[:1000],
                      "returncode": process.returncode}
        except subprocess.TimeoutExpired:
            failure, detail = True, {"timeout_seconds": 5}
        self.result["maximum_solver_process_seconds"] = max(
            self.result["maximum_solver_process_seconds"], time.perf_counter() - started)
        if failure:
            path = BUILD / (label + "-failure.in")
            path.write_text(text)
            self.result["failure"] = {"case": label, "expected": expected,
                                      "input": path.relative_to(ROOT).as_posix(), **detail}
            raise AssertionError(json.dumps(self.result["failure"]))
        key = "positive_volume_cases" if volume else "zero_volume_convention_cases"
        self.result[key] += 1


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--stress", action="store_true",
                        help="run 2000 random cases and 5 maximum cases")
    args = parser.parse_args()
    runner = Runner()
    report = json.loads(REPORT.read_text())
    runner.result["stress_requested"] = args.stress
    try:
        for i, rows in enumerate(fixed_cases()):
            runner.check("fixed_%d" % i, rows)
            runner.result["fixed_cases"] += 1
        rng = random.Random(SEED)
        for i, rows in enumerate(random_cases(rng, 2000 if args.stress else 200)):
            runner.check("random_%d" % i, rows, all_cents=True)
            runner.result["random_cases"] += 1
        if args.stress:
            for i, rows in enumerate(maximum_cases(rng)):
                runner.check("maximum_%d" % i, rows)
                runner.result["maximum_5000_line_cases"] += 1
        runner.result["status"] = "passed_local_audit_but_online_WA_unresolved"
    except Exception:
        runner.result["status"] = "failed_local_audit"
        raise
    finally:
        # Keep the real original execution history; a new run cannot replace
        # or promote the external judge verdict.
        report["latest_run"] = runner.result
        REPORT.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n")
    print(json.dumps(runner.result, ensure_ascii=False, indent=2))
    print("Local checks passed. The recorded Shumeng 90 WA is still unresolved.")


if __name__ == "__main__":
    main()
