#!/usr/bin/env python3
"""Portable numerical regressions for CSP 202309B (Python 3.9+, standard library).

Default: compile the project's current C++17 source, run two saved examples,
500 independently simulated cases, and the deterministic 70-digit regression.
--stress adds long random/repeated-angle cases and 100000 queries. Binaries and
failure inputs go to .build/precision-regressions; no prior executable is needed.
"""
from __future__ import annotations

import argparse
from datetime import datetime, timezone
from decimal import Decimal as D, localcontext
import hashlib
import json
import math
import os
from pathlib import Path
import platform
import random
import shlex
import subprocess
import time

ROOT = Path(__file__).resolve().parents[1]
TESTS = ROOT / "tests"
BUILD = ROOT / ".build" / "precision-regressions"
REPORT = TESTS / "precision-report.json"
PI = D("3.141592653589793238462643383279502884197169399375105820974944592307816406286")
REQUIRED_ERROR = D("0.1")


def decimal_trig(angle):
    """Taylor sine/cosine after 70-digit reduction, independent of C++ libm."""
    angle %= 2 * PI
    if angle > PI:
        angle -= 2 * PI
    sine, cosine = angle, D(1)
    st, ct = angle, D(1)
    for i in range(1, 100):
        st *= -angle * angle / D(2 * i * (2 * i + 1))
        ct *= -angle * angle / D((2 * i - 1) * 2 * i)
        sine += st
        cosine += ct
        if abs(st) + abs(ct) < D("1e-65"):
            break
    return cosine, sine


def rotated(angle, scale, x, y):
    cosine, sine = decimal_trig(angle)
    return [scale * (x * cosine - y * sine), scale * (x * sine + y * cosine)]


def make_input(operations, queries):
    return (f"{len(operations)} {len(queries)}\n"
            + "".join(f"{kind} {value}\n" for kind, value in operations)
            + "".join(" ".join(map(str, query)) + "\n" for query in queries))


def random_cases():
    rng = random.Random(20230925002)
    for _ in range(500):
        n = rng.randint(1, 100)
        operations, exponent = [], 0
        for _ in range(n):
            if rng.randrange(2):
                step = rng.choice([x for x in (-1, 0, 1) if -4 <= exponent + x <= 4])
                exponent += step
                operations.append((1, str(2.0**step)))
            else:
                operations.append((2, str(D(rng.randrange(6283185307179586477)) / 10**18)))
        queries, expected = [], []
        for _ in range(20):
            left = rng.randint(1, n)
            right = rng.randint(left, n)
            x, y = rng.randint(-1000000, 1000000), rng.randint(-1000000, 1000000)
            queries.append((left, right, x, y))
            # Independent oracle: apply each operation in its original order.
            for kind, word in operations[left - 1:right]:
                value = float(word)
                if kind == 1:
                    x *= value
                    y *= value
                else:
                    x, y = x * math.cos(value) - y * math.sin(value), x * math.sin(value) + y * math.cos(value)
            expected.extend([D.from_float(x), D.from_float(y)])
        yield make_input(operations, queries), expected


def long_operations(angles):
    # All scale factors and their total product 1000 are exact binary values.
    return [(2, str(angle)) for angle in angles] + [(1, "2")] * 9 + [(1, "1.953125")]


def deterministic_case():
    query = (2640, 100000, 1000000, -1000000)
    operations = long_operations(["6.283"] * 99990)
    expected = rotated(D("6.283") * (99990 - query[0] + 1), 1000, query[2], query[3])
    return make_input(operations, [query]), expected


class Runner:
    def __init__(self, compiler):
        self.executable = BUILD / "202309B"
        self.source = ROOT / "202309" / "B.cpp"
        subprocess.run(compiler + ["-std=c++17", "-O2", "-Wall", "-Wextra", "-Wpedantic",
                                   str(self.source), "-o", str(self.executable)], check=True)

    def run(self, label, data, expected=None, tolerance=REQUIRED_ERROR):
        started = time.perf_counter()
        process = subprocess.run([str(self.executable)], input=data, text=True,
                                 capture_output=True, timeout=30)
        elapsed = time.perf_counter() - started
        try:
            actual = [D(word) for word in process.stdout.split()]
        except Exception as error:
            raise AssertionError(f"{label}: invalid numeric output") from error
        invalid = process.returncode or any(not value.is_finite() for value in actual)
        difference = None
        if expected is not None:
            invalid = invalid or len(actual) != len(expected)
            if len(actual) == len(expected) and not invalid:
                difference = max((abs(a - b) for a, b in zip(actual, expected)), default=D(0))
                invalid = difference > tolerance
        result = {"case": label, "seconds": round(elapsed, 3)}
        if difference is not None:
            result["maximum_absolute_error"] = str(difference)
            result["allowed_absolute_error"] = str(tolerance)
        if invalid:
            filename = "".join(c if c.isalnum() or c in "-_" else "_" for c in label)
            failure = BUILD / (filename + "-failure.in")
            failure.write_text(data)
            result["failure_input"] = failure.relative_to(ROOT).as_posix()
            result["stderr"] = process.stderr[:1000]
            raise RegressionFailure(result)
        return actual, result


class RegressionFailure(Exception):
    def __init__(self, result):
        self.result = result
        super().__init__(json.dumps(result, ensure_ascii=False))


def run_stress(runner):
    results = []
    rng = random.Random(20230920261025)
    angles = [D(rng.randint(6200000000000000000, 6283000000000000000)) / 10**18
              for _ in range(99990)]
    prefix = [D(0)]
    for angle in angles:
        prefix.append(prefix[-1] + angle)
    queries = [(1, 100000, 1000000, 1000000), (50000, 100000, -1000000, 1000000),
               (99990, 100000, 1000000, -1000000)]
    queries.extend((rng.randint(1, 99990), 100000,
                    rng.choice([-1000000, 1000000]), rng.choice([-1000000, 1000000]))
                   for _ in range(5000))
    expected = []
    for left, _, x, y in queries:
        expected.extend(rotated(prefix[-1] - prefix[left - 1], 1000, x, y))
    _, result = runner.run("large_random_prefixes", make_input(long_operations(angles), queries), expected)
    results.append(result)
    print("5003 long-prefix queries passed the 70-digit oracle", flush=True)
    for word in ["0", "0.0000001", "3.141592653589793238462643", "6.283",
                 "6.283185307179585", "6.247183912837454857"]:
        queries = [(1, 100000, 1000000, 1000000), (50000, 100000, -1000000, 1000000),
                   (99990, 100000, 1000000, -1000000), (50000, 75000, 1000000, 1000000)]
        expected = []
        for left, right, x, y in queries:
            expected.extend(rotated(D(word) * (min(right, 99990) - left + 1),
                                    1000 if right == 100000 else 1, x, y))
        _, result = runner.run("repeated_angle_" + word,
                                make_input(long_operations([word] * 99990), queries), expected)
        results.append(result)
    word = "6.247183912837454857"
    queries = [(rng.randint(1, 99990), 100000,
                rng.choice([-1000000, 1000000]), rng.choice([-1000000, 1000000]))
               for _ in range(100000)]
    actual, result = runner.run("maximum_queries", make_input(long_operations([word] * 99990), queries))
    if len(actual) != 200000:
        raise AssertionError("maximum_queries: wrong number of output values")
    largest = D(0)
    for i in range(0, 100000, 1000):
        left, _, x, y = queries[i]
        expected = rotated(D(word) * (99990 - left + 1), 1000, x, y)
        largest = max(largest, max(abs(a - b) for a, b in zip(actual[2*i:2*i+2], expected)))
    if largest > REQUIRED_ERROR:
        raise AssertionError(f"maximum_queries: independent oracle error {largest}")
    result.update(independent_queries=100, maximum_sampled_absolute_error=str(largest))
    results.append(result)
    return results


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--stress", action="store_true", help="also check long random/repeated angles and 100000 queries")
    args = parser.parse_args()
    BUILD.mkdir(parents=True, exist_ok=True)
    compiler = shlex.split(os.environ.get("CXX", "c++"))
    runner = Runner(compiler)
    report = json.loads(REPORT.read_text())
    current = {
        "recorded_at_utc": datetime.now(timezone.utc).isoformat(),
        "platform": platform.platform(),
        "machine": platform.machine(),
        "compiler": subprocess.run(compiler + ["--version"], text=True, capture_output=True, check=True).stdout.splitlines()[0],
        "flags": "-std=c++17 -O2 -Wall -Wextra -Wpedantic",
        "source_sha256": hashlib.sha256(runner.source.read_bytes()).hexdigest(),
        "stress_requested": args.stress,
        "samples": 0,
        "independent_sequential_random": 0,
    }
    try:
        with localcontext() as context:
            context.prec = 70
            for i, case in enumerate(json.loads((TESTS / "202309B.json").read_text())):
                runner.run("saved_example_" + str(i + 1), case["input"],
                           [D(word) for word in case["output"].split()], D(str(case.get("abs_tol", 0.1))))
                current["samples"] += 1
            largest = D(0)
            for data, expected in random_cases():
                _, result = runner.run("sequential_random", data, expected, D("0.0001"))
                largest = max(largest, D(result["maximum_absolute_error"]))
                current["independent_sequential_random"] += 1
            current["random_maximum_absolute_difference"] = str(largest)
            print("2 saved examples and 500 independent sequential-operation cases passed", flush=True)
            data, expected = deterministic_case()
            _, current["deterministic_high_precision"] = runner.run("deterministic_high_precision", data, expected)
            print("Deterministic 70-digit precision regression passed", flush=True)
            if args.stress:
                current["stress"] = run_stress(runner)
            current["status"] = "passed"
    except RegressionFailure as error:
        current["status"] = "failed"
        current["failure"] = error.result
        report["latest_run"] = current
        REPORT.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n")
        raise SystemExit(str(error))
    report["latest_run"] = current
    REPORT.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n")
    print(f"Report written to {REPORT.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
