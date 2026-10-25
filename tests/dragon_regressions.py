#!/usr/bin/env python3
"""Portable independent regressions for CSP202309D.

Run from any directory after placing this file in the project's tests directory:
    python3 tests/dragon_regressions.py
    python3 tests/dragon_regressions.py --stress
Optional: --baseline /path/to/old/D.cpp compares a supplied old source.
Python 3.9+ standard library; CXX selects the C++17 compiler.
Current project source is compiled into .build/dragon-regressions.
Generated inputs, executables, and latest-report.json stay there; saved historical
benchmark reports are never overwritten. No network or OJ submission.
"""
import argparse
from datetime import date
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
SOURCE = ROOT / "202309" / "D.cpp"
BUILD = ROOT / ".build" / "dragon-regressions"
REPORT = BUILD / "latest-report.json"
DIRECTIONS = [(1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1)]


def checksum(points):
    answer = 0
    for i, (x, y) in enumerate(points, 1):
        answer ^= i*x + y
    return str(answer)


def encode(n, m, initial, events):
    return (f"{n} {m} {len(initial)} {len(events)}\n"
            + "".join(f"{x} {y}\n" for x, y in initial)
            + "".join(f"{u} {v} {t}\n" for u, v, t in events))


def brute(n, m, initial, events):
    # Scan every employee to determine the radius: no ordered-set indices.
    points = initial[:]
    for u, v, t in events:
        distance = min(u-1, n-u, v-1, m-v) + 1
        boundary = distance - 1
        for x, y in points:
            dx, dy = x-u, y-v
            if (dx or dy) and (not dx or not dy or abs(dx) == abs(dy)):
                distance = min(distance, max(abs(dx), abs(dy)))
        if distance > boundary:
            continue
        changed = dict(zip([(u+distance*dx, v+distance*dy) for dx, dy in DIRECTIONS],
                           [(u+distance*DIRECTIONS[(d+t) % 8][0],
                             v+distance*DIRECTIONS[(d+t) % 8][1]) for d in range(8)]))
        points = [changed.get(point, point) for point in points]
        assert len(set(points)) == len(points)
    return checksum(points)


def grid_oracle(n, m, initial, events, known_radius=None):
    # Independent grid/ray simulation: test cells at distance 1,2,... .
    # For isolated rings known_radius is justified by far-away filler points.
    occupied = {point: i for i, point in enumerate(initial, 1)}
    for u, v, t in events:
        boundary = min(u-1, n-u, v-1, m-v)
        candidates = [known_radius] if known_radius is not None else range(1, boundary+1)
        for distance in candidates:
            source = [(u+distance*dx, v+distance*dy) for dx, dy in DIRECTIONS]
            live = [(d, occupied[point]) for d, point in enumerate(source) if point in occupied]
            if live:
                for d, _ in live:
                    del occupied[source[d]]
                for d, employee in live:
                    occupied[source[(d+t) % 8]] = employee
                break
    answer = 0
    for (x, y), employee in occupied.items():
        answer ^= employee*x + y
    assert len(occupied) == len(initial)
    return str(answer)


def compile_source(source, name, compiler):
    executable = BUILD / name
    subprocess.run(compiler + ["-std=c++17", "-O2", "-Wall", "-Wextra", "-Wpedantic",
                               str(source), "-o", str(executable)], check=True)
    return executable


def run_small(executable, data):
    return subprocess.run([str(executable)], input=data, text=True, capture_output=True,
                          timeout=10, check=True).stdout.strip()


def random_case(rng, number):
    n, m = rng.randint(1, 18), rng.randint(1, 18)
    cells = [(x, y) for x in range(1, n+1) for y in range(1, m+1)]
    initial = rng.sample(cells, rng.randint(1, min(len(cells), 80)))
    events = [(rng.randint(1, n), rng.randint(1, m), rng.randint(1, 7)) for _ in range(80)]
    if number % 4 == 0:
        # Exercise large encoded line keys, negative diagonals, and 64-bit XOR.
        ox = 1000000000-n if number % 8 == 0 else 123456789
        oy = 1000000000-m if number % 12 == 0 else 876543210
        initial = [(x+ox, y+oy) for x, y in initial]
        events = [(u+ox, v+oy, t) for u, v, t in events]
        n, m = n+ox, m+oy
    return encode(n, m, initial, events), brute(n, m, initial, events)


def maximum_case(name):
    rng = random.Random(20230904 + ["dense_full", "checkerboard", "four_ring", "one_ring",
                                  "sparse_static", "boundary"].index(name))
    n = m = 1000000000
    if name == "dense_full":
        n = m = 1000
        initial = [(x, y) for x in range(101, 501) for y in range(101, 351)]
        events = [(rng.randint(102, 499), rng.randint(102, 349), rng.randint(1, 7))
                  for _ in range(100000)]
        expected = grid_oracle(n, m, initial, events)
    elif name == "checkerboard":
        n = m = 1000
        initial = [(x, y) for x in range(101, 601) for y in range(101, 501) if (x+y) % 2 == 0]
        events = [(rng.randint(110, 590), rng.randint(110, 490), rng.randint(1, 7))
                  for _ in range(100000)]
        expected = grid_oracle(n, m, initial, events)
    elif name in ("four_ring", "one_ring"):
        u = v = 500000000
        directions = [0, 2, 4, 6] if name == "four_ring" else [0]
        initial = [(u+100*DIRECTIONS[d][0], v+100*DIRECTIONS[d][1]) for d in directions]
        initial += [(i, i) for i in range(1, 100001-len(initial))]
        events = [(u, v, 1) for _ in range(100000)]
        expected = grid_oracle(n, m, initial, events, known_radius=100)
    else:
        pairs = set()
        while len(pairs) < 100000:
            pairs.add((4*rng.randint(1, 249999999), 4*rng.randint(1, 249999999)))
        initial = sorted(pairs)
        if name == "sparse_static":
            # No employee shares x, y, x-y, or x+y modulo four with a centre.
            events = [(4*rng.randint(1, 249999998)+1, 4*rng.randint(1, 249999998)+2,
                       rng.randint(1, 7)) for _ in range(100000)]
        else:
            events = [(1, rng.randint(1, m), rng.randint(1, 7)) for _ in range(100000)]
        expected = checksum(initial)
    assert len(initial) == len(set(initial)) == 100000 and len(events) == 100000
    return encode(n, m, initial, events), expected


def timed_run(executable, input_path):
    with input_path.open("rb") as incoming:
        start = time.perf_counter()
        process = subprocess.run([str(executable)], stdin=incoming, stdout=subprocess.PIPE,
                                 check=True, timeout=180)
        elapsed = time.perf_counter() - start
    return elapsed, process.stdout.decode().strip()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--baseline", type=Path)
    parser.add_argument("--stress", action="store_true")
    args = parser.parse_args()
    BUILD.mkdir(parents=True, exist_ok=True)
    compiler = shlex.split(os.environ.get("CXX", "c++"))
    new = compile_source(SOURCE, "candidate", compiler)
    old = compile_source(args.baseline, "baseline", compiler) if args.baseline else None
    report = {"problem": "CSP202309D", "date": date.today().isoformat(), "machine": platform.machine(),
              "platform": platform.platform(),
              "compiler": subprocess.run(compiler + ["--version"], text=True, capture_output=True,
                                         check=True).stdout.splitlines()[0],
              "flags": "-std=c++17 -O2 -Wall -Wextra -Wpedantic",
              "source_sha256": hashlib.sha256((SOURCE).read_bytes()).hexdigest(),
              "baseline_sha256": hashlib.sha256(args.baseline.read_bytes()).hexdigest() if old else None,
              "sample_cases": 0, "independent_random_cases": 0, "occupancy_masks": 0, "stress": [],
              "online_status": "not_submitted_by_validator"}

    def check(data, expected, label):
        actual = run_small(new, data)
        if actual != expected:
            (BUILD / "counterexample.in").write_text(data)
            raise AssertionError((label, actual, expected))
        if old:
            assert run_small(old, data) == expected, label

    sample = "3 3 9 1\n1 1\n1 2\n1 3\n2 1\n2 2\n2 3\n3 1\n3 2\n3 3\n2 2 1\n"
    check(sample, "20", "sample")
    report["sample_cases"] = 1
    rng = random.Random(20230904)
    for i in range(700):
        data, expected = random_case(rng, i)
        check(data, expected, "random_%d" % i)
        report["independent_random_cases"] += 1
    for mask in range(1, 256):
        initial = [(5, 5)] + [(5+2*dx, 5+2*dy) for d, (dx, dy) in enumerate(DIRECTIONS) if mask >> d & 1]
        events = [(5, 5, t) for t in [1, 2, 3, 4, 5, 6, 7] * 3]
        check(encode(9, 9, initial, events), brute(9, 9, initial, events), "mask_%d" % mask)
        report["occupancy_masks"] += 1
    print("1 sample, 700 independent random cases, and 255 occupancy masks passed", flush=True)
    if args.stress:
        for name in ["dense_full", "checkerboard", "four_ring", "one_ring", "sparse_static", "boundary"]:
            data, expected = maximum_case(name)
            path = BUILD / (name + ".in")
            path.write_text(data)
            new_time, answer = timed_run(new, path)
            assert answer == expected, (name, answer, expected)
            result = {"case": name, "p": 100000, "q": 100000, "candidate_seconds": new_time,
                      "input_sha256": hashlib.sha256(data.encode()).hexdigest(),
                      "expected_checksum": expected, "independent_oracle": True}
            if old:
                old_time, old_answer = timed_run(old, path)
                assert old_answer == expected, name
                result.update(baseline_seconds=old_time, speedup=old_time/new_time)
            report["stress"].append(result)
            print(json.dumps(result), flush=True)
    report["status"] = "passed"
    REPORT.write_text(json.dumps(report, indent=2) + "\n")
    print(f"Saved {REPORT}", flush=True)


if __name__ == "__main__":
    main()
