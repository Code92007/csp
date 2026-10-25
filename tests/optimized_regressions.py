#!/usr/bin/env python3
"""Independent regressions for the optimized 201809E and 202406E solutions.

Run from any directory:
    python3 tests/optimized_regressions.py
    python3 tests/optimized_regressions.py --stress

The default runs saved examples and 500/600 independent small cases. --stress
additionally reproduces the historical maximum cases and checks full-output
SHA256 fingerprints. It needs no baseline executable and keeps no large inputs
unless a failure must be reproduced; failure inputs and binaries go to .build/.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
from pathlib import Path
import platform
import random
import shlex
import subprocess
import time
from datetime import datetime, timezone

ROOT = Path(__file__).resolve().parents[1]
TESTS = ROOT / "tests"
BUILD = ROOT / ".build" / "optimized-regressions"
REPORT = TESTS / "optimization-report.json"
MOD = 998244353


def recurrence_input(m, left, right, coefficients):
    return f"{m} {left} {right}\n" + " ".join(map(str, coefficients)) + "\n"


def recurrence_cases(rng):
    boundaries = [1, 2, 3, 31, 32, 33, 63, 64, 65, 127, 128, 129, 255, 256, 257]
    for case in range(500):
        m = rng.choice(boundaries) if case < 90 else rng.randint(1, 180)
        left = rng.randint(0, 500)
        right = left + rng.randint(0, 180)
        mode = case % 8
        if mode == 0:
            coefficients = [0] * m
        elif mode == 1:
            coefficients = [1] * m
        elif mode == 2:
            coefficients = [MOD - 1] * m
        elif mode == 3:
            coefficients = [0] * m
            coefficients[rng.randrange(m)] = rng.randrange(MOD)
        else:
            coefficients = [rng.randrange(MOD) for _ in range(m)]
        yield m, left, right, coefficients


def direct_recurrence(m, left, right, coefficients):
    values = [1]
    for i in range(1, right + 1):
        values.append(sum(coefficients[j - 1] * values[i - j]
                          for j in range(1, min(i, m) + 1)) % MOD)
    return list(map(str, values[left:right + 1]))


def interval(rng, n):
    return sorted((rng.randint(1, n), rng.randint(1, n)))


def rectangle_input(n, rectangles, queries):
    lines = [f"{n} {len(queries)}"]
    lines.extend(" ".join(map(str, row)) for row in rectangles)
    lines.extend(" ".join(map(str, row)) for row in queries)
    return "\n".join(lines) + "\n"


def rectangle_cases(rng):
    boundaries = [1, 2, 3, 7, 8, 9, 15, 16, 17, 31, 32, 33, 63, 64, 65, 127, 128, 129]
    for case in range(600):
        n = rng.choice(boundaries) if case < 120 else rng.randint(1, 180)
        rectangles = []
        mode = case % 8
        for _ in range(n):
            a, b = interval(rng, n)
            c, d = interval(rng, n)
            if mode == 0:
                a = b = rng.randint(1, n)
                c = d = rng.randint(1, n)
            elif mode == 1:
                a, b = 1, n
            elif mode == 2:
                c, d = 1, n
            elif mode == 3:
                c = d = rng.randint(1, n)
            elif mode == 4:
                a = b = rng.randint(1, n)
            rectangles.append((a, b, c, d, rng.randint(1, n)))
        queries = [(*interval(rng, n), *interval(rng, n)) for _ in range(100)]
        queries.extend((i, i, j, j) for i, j in [(1, 1), (1, n), (n, 1), (n, n)])
        yield n, rectangles, queries


def rectangle_answer(rectangles, query):
    a, b, c, d = query
    return max((value for x, y, z, w, value in rectangles
                if x <= b and y >= a and z <= d and w >= c), default=0)


def recurrence_stress(rng):
    # Preserve the historical RNG schedule: 100 large-index differential cases
    # were generated between the small cases and maximum benchmarks. No old
    # executable is needed here; these draws only reproduce the saved fixtures.
    for _ in range(100):
        m = rng.randint(1, 500)
        left = rng.choice([10**12, (1 << 39) - 1, 1 << 39, rng.randrange(10**12)])
        right = left + rng.randint(0, 300)
        coefficients = [rng.randrange(MOD) for _ in range(m)]
    specs = [
        ("maximum_random", 100000, 10**12, 300001, "random"),
        ("maximum_many_set_bits", 100000, (1 << 39) - 1, 300001, "random"),
        ("maximum_zero_coefficients", 100000, 10**12, 300001, "zero"),
        ("maximum_l_zero", 100000, 0, 300001, "random"),
        ("power_two_boundary", 65537, (1 << 39) - 1, 300001, "random"),
    ]
    for label, m, left, count, mode in specs:
        coefficients = [rng.randrange(MOD) for _ in range(m)] if mode == "random" else [0] * m
        yield label, recurrence_input(m, left, left + count - 1, coefficients), mode


def rectangle_stress(rng):
    for label in ["random", "points", "horizontal", "vertical", "short_intervals", "nested"]:
        n = 500000
        rectangles, queries = [], []
        ys = list(range(1, n + 1))
        rng.shuffle(ys)
        for i in range(n):
            if label == "random":
                a, b = interval(rng, n)
                c, d = interval(rng, n)
            elif label == "points":
                a = b = i + 1
                c = d = ys[i]
            elif label == "horizontal":
                a, b = interval(rng, n)
                c = d = ys[i]
            elif label == "vertical":
                a = b = i + 1
                c, d = interval(rng, n)
            elif label == "short_intervals":
                a = rng.randint(1, n)
                b = min(n, a + rng.randint(0, 100))
                c = rng.randint(1, n)
                d = min(n, c + rng.randint(0, 100))
            else:
                a = c = i // 2 + 1
                b = d = n - i // 2
            rectangles.append((a, b, c, d, rng.randint(1, n)))
        for _ in range(n):
            if label in ["random", "nested", "points"]:
                a, b = interval(rng, n)
                c, d = interval(rng, n)
            else:
                a = b = rng.randint(1, n)
                c = d = rng.randint(1, n)
            queries.append((a, b, c, d))
        yield label, n, rectangles, queries


class Runner:
    def __init__(self, compiler):
        self.compiler = compiler
        self.executables = {}

    def compile(self, problem):
        source = ROOT / problem[:6] / (problem[6] + ".cpp")
        executable = BUILD / problem
        subprocess.run(self.compiler + ["-std=c++17", "-O2", "-Wall", "-Wextra", "-Wpedantic",
                                      str(source), "-o", str(executable)], check=True)
        self.executables[problem] = executable
        return hashlib.sha256(source.read_bytes()).hexdigest()

    def run(self, problem, data, expected=None, expected_hash=None):
        started = time.perf_counter()
        result = subprocess.run([str(self.executables[problem])], input=data, text=True,
                                capture_output=True, timeout=120)
        elapsed = time.perf_counter() - started
        actual = result.stdout.split()
        digest = hashlib.sha256(("\n".join(actual) + "\n").encode()).hexdigest()
        if result.returncode or (expected is not None and actual != expected) or (
                expected_hash is not None and digest != expected_hash):
            failure = BUILD / (problem + "-failure.in")
            failure.write_text(data)
            raise AssertionError(f"{problem} failed; input saved to {failure}; stderr={result.stderr[:1000]!r}")
        return actual, {"seconds": round(elapsed, 3), "output_sha256": digest}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--stress", action="store_true", help="also run eleven maximum-size historical fixtures")
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
        "stress_requested": args.stress,
        "problems": {},
    }
    for problem in ["201809E", "202406E"]:
        current["problems"][problem] = {"source_sha256": runner.compile(problem), "samples": 0, "independent_random": 0}
        for case in json.loads((TESTS / (problem + ".json")).read_text()):
            runner.run(problem, case["input"], expected=case["output"].split())
            current["problems"][problem]["samples"] += 1
    recurrence_rng = random.Random(20180920261025)
    for m, left, right, coefficients in recurrence_cases(recurrence_rng):
        runner.run("201809E", recurrence_input(m, left, right, coefficients),
                   expected=direct_recurrence(m, left, right, coefficients))
        current["problems"]["201809E"]["independent_random"] += 1
    print("201809E: 3 saved examples and 500 independent recurrence cases passed", flush=True)
    rectangle_rng = random.Random(20240620261025)
    for n, rectangles, queries in rectangle_cases(rectangle_rng):
        expected = [str(rectangle_answer(rectangles, query)) for query in queries]
        runner.run("202406E", rectangle_input(n, rectangles, queries), expected=expected)
        current["problems"]["202406E"]["independent_random"] += 1
    print("202406E: 2 saved examples and 600 independent intersection cases passed", flush=True)
    if args.stress:
        for problem in current["problems"]:
            current["problems"][problem]["stress"] = []
        fingerprints = {problem: {case["case"]: case["output_sha256"]
                                  for case in data["benchmarks"]}
                        for problem, data in report["historical"]["problems"].items()}
        for label, data, mode in recurrence_stress(recurrence_rng):
            actual, result = runner.run("201809E", data, expected_hash=fingerprints["201809E"][label])
            if mode == "zero":
                assert set(actual) == {"0"}
            current["problems"]["201809E"]["stress"].append(dict(case=label, **result))
            print(f"201809E {label}: {result['seconds']:.3f}s, full-output hash matched", flush=True)
        for label, n, rectangles, queries in rectangle_stress(rectangle_rng):
            actual, result = runner.run("202406E", rectangle_input(n, rectangles, queries),
                                        expected_hash=fingerprints["202406E"][label])
            for i in range(0, n, 100000):
                assert int(actual[i]) == rectangle_answer(rectangles, queries[i])
            current["problems"]["202406E"]["stress"].append(dict(case=label, **result))
            print(f"202406E {label}: {result['seconds']:.3f}s, full-output hash and 5 independent scans matched", flush=True)
    current["status"] = "passed"
    report["latest_run"] = current
    REPORT.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n")
    print(f"Report written to {REPORT.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
