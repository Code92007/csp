#!/usr/bin/env python3
"""Compile and independently validate the project 202312/D.cpp, optionally benchmark.

python3 tests/treasure_regressions.py --baseline /path/to/202312/D.cpp --stress
The baseline is optional; all small cases use a direct independent simulator.
Maximum inputs are regenerated deterministically under .build, not committed.
"""
import argparse
from collections import deque
import hashlib
import json
import os
from pathlib import Path
import platform
import random
import shlex
import subprocess
import time

MOD = 998244353
BASE = Path(__file__).resolve().parents[1]
SOURCE = BASE / "202312/D.cpp"
BUILD = BASE / ".build/treasure"
IDENTITY = (1, 0, 0, 1)


def mul(a, b):
    return ((a[0]*b[0]+a[1]*b[2]) % MOD, (a[0]*b[1]+a[1]*b[3]) % MOD,
            (a[2]*b[0]+a[3]*b[2]) % MOD, (a[2]*b[1]+a[3]*b[3]) % MOD)


def command(rng, mode="mixed"):
    kind = rng.randint(1, 2) if mode == "push" else rng.randint(1, 3)
    if kind == 3:
        return (3, IDENTITY)
    matrix = tuple(rng.randrange(MOD) for _ in range(4))
    return (kind, matrix)


def row(cmd):
    return str(cmd[0]) + (" " + " ".join(map(str, cmd[1])) if cmd[0] != 3 else "")


def simulate(commands, left, right):
    live = []
    for kind, matrix in commands[left:right+1]:
        if kind == 3:
            if live:
                live.pop()
        else:
            live.append((kind, matrix))
    matrices = deque()
    for kind, matrix in live:
        if kind == 1:
            matrices.appendleft(matrix)
        else:
            matrices.append(matrix)
    answer = IDENTITY
    for matrix in matrices:
        answer = mul(answer, matrix)
    return " ".join(map(str, answer))


def compile_source(source, name, compiler):
    target = BUILD / name
    subprocess.run(compiler + ["-std=c++17", "-O2", "-Wall", "-Wextra", "-Wpedantic",
                               str(source), "-o", str(target)], check=True)
    return target


def run_small(executable, data):
    result = subprocess.run([str(executable)], input=data, text=True,
                            capture_output=True, check=True, timeout=10)
    return result.stdout.strip()


def input_text(initial, events):
    return (f"{len(initial)} {len(events)}\n" + "\n".join(map(row, initial))
            + "\n" + "\n".join(events) + "\n")


def random_case(rng, case_id):
    n = rng.randint(1, 90) if case_id < 500 else rng.randint(100, 550)
    mode = "push" if case_id % 7 == 0 else "mixed"
    initial = [command(rng, mode) for _ in range(n)]
    if case_id % 9 == 0:
        initial = [(3, IDENTITY)] * n
    if case_id % 11 == 0:
        initial = [(1, (0, 0, 0, 0)), (2, (1, 2, 2, 4))] * (n // 2) + initial[:n % 2]
    current = initial[:]
    events, answers = [], []
    for i in range(100):
        if rng.random() < .45:
            index = rng.randrange(n)
            value = command(rng, mode)
            current[index] = value
            events.append(f"1 {index+1} {row(value)}")
        else:
            left = rng.randrange(n)
            right = rng.randrange(left, n)
            if i % 10 == 0:
                left, right = 0, n-1
            events.append(f"2 {left+1} {right+1}")
            answers.append(simulate(current, left, right))
    return input_text(initial, events), "\n".join(answers)


def maximum_case(name):
    rng = random.Random(202312000 + ["push_queries", "push_updates", "mixed",
                                    "balanced", "deletion_heavy", "updates"].index(name))
    n = m = 100000
    if name.startswith("push"):
        initial = [command(rng, "push") for _ in range(n)]
    elif name == "balanced":
        initial = [command(rng, "push") if rng.randrange(2) else (3, IDENTITY) for _ in range(n)]
    elif name == "deletion_heavy":
        initial = [command(rng, "push") if i % 3 == 0 else (3, IDENTITY) for i in range(n)]
    else:
        initial = [command(rng) for _ in range(n)]
    current = initial[:]
    events, oracle = [], {}
    query_count = 0
    for i in range(m):
        update = name != "push_queries" and i != m-1 and (name == "updates" or i % 2 == 0)
        if update:
            index = rng.randrange(n)
            if name.startswith("push"):
                value = command(rng, "push")
            elif name == "balanced":
                value = command(rng, "push") if rng.randrange(2) else (3, IDENTITY)
            else:
                value = command(rng)
            current[index] = value
            events.append(f"1 {index+1} {row(value)}")
        else:
            left = rng.randrange(n // 4)
            right = rng.randrange(3*n // 4, n)
            if i == m-1 or i % 8 == 1:
                left, right = 0, n-1
            events.append(f"2 {left+1} {right+1}")
            if query_count < 2 or i == m-1 or i == 50001:
                oracle[query_count] = simulate(current, left, right)
            query_count += 1
    return input_text(initial, events), oracle


def timed_run(executable, input_path, output_path):
    with input_path.open("rb") as incoming, output_path.open("wb") as outgoing:
        start = time.perf_counter()
        subprocess.run([str(executable)], stdin=incoming, stdout=outgoing, check=True, timeout=180)
        elapsed = time.perf_counter() - start
    output = output_path.read_bytes()
    return elapsed, output


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--baseline", type=Path)
    parser.add_argument("--stress", action="store_true")
    args = parser.parse_args()
    BUILD.mkdir(parents=True, exist_ok=True)
    compiler = shlex.split(os.environ.get("CXX", "c++"))
    new = compile_source(SOURCE, "candidate", compiler)
    old = compile_source(args.baseline, "baseline", compiler) if args.baseline else None
    report = {
        "problem": "CSP202312D", "date": "2026-10-25", "machine": platform.machine(),
        "platform": platform.platform(),
        "compiler": subprocess.run(compiler + ["--version"], text=True, capture_output=True,
                                   check=True).stdout.splitlines()[0],
        "flags": "-std=c++17 -O2 -Wall -Wextra -Wpedantic",
        "source_sha256": hashlib.sha256((SOURCE).read_bytes()).hexdigest(),
        "baseline_sha256": hashlib.sha256(args.baseline.read_bytes()).hexdigest() if old else None,
        "sample_cases": 0, "independent_random_cases": 0, "stress": [],
        "online_status": "not_submitted_by_validator"
    }
    sample = "3 4\n1 2 3 9 3\n2 6 9 4 2\n2 2 8 2 1\n2 2 3\n1 2 1 3 1 0 1\n1 3 3\n2 1 3\n"
    assert run_small(new, sample) == "30 57 12 34\n2 3 9 3"
    report["sample_cases"] = 1
    rng = random.Random(20231204)
    for i in range(700):
        data, expected = random_case(rng, i)
        actual = run_small(new, data)
        if actual != expected:
            (BUILD / "counterexample.in").write_text(data)
            (BUILD / "counterexample.expected").write_text(expected)
            raise AssertionError(f"independent case {i} differs")
        if old:
            assert run_small(old, data) == expected
        report["independent_random_cases"] += 1
    print("1 sample and 700 independent simulator cases passed", flush=True)
    if args.stress:
        for name in ["push_queries", "push_updates", "mixed", "balanced", "deletion_heavy", "updates"]:
            data, oracle = maximum_case(name)
            input_path = BUILD / (name + ".in")
            input_path.write_text(data)
            new_time, new_output = timed_run(new, input_path, BUILD / (name + ".new.out"))
            result = {"case": name, "n": 100000, "m": 100000,
                      "candidate_seconds": new_time,
                      "input_sha256": hashlib.sha256(data.encode()).hexdigest(),
                      "output_sha256": hashlib.sha256(new_output).hexdigest(),
                      "independent_queries": len(oracle)}
            lines = new_output.decode().splitlines()
            for index, expected in oracle.items():
                assert lines[index] == expected, (name, index)
            if old:
                old_time, old_output = timed_run(old, input_path, BUILD / (name + ".old.out"))
                assert new_output == old_output, name
                result.update(baseline_seconds=old_time, speedup=old_time/new_time)
            report["stress"].append(result)
            print(json.dumps(result), flush=True)
    report["status"] = "passed"
    (BUILD / "report.json").write_text(json.dumps(report, indent=2) + "\n")
    print("Saved .build/treasure/report.json", flush=True)


if __name__ == "__main__":
    main()
