#!/usr/bin/env python3
"""Portable independent regressions for CSP202303C.

Run from any directory after placing this file in the project's tests directory:
    python3 tests/ldap_regressions.py
    python3 tests/ldap_regressions.py --stress
Optional: --baseline /path/to/old/C.cpp compares a supplied old source.
Python 3.9+ standard library; CXX selects the C++17 compiler.
Current project source is compiled into .build/ldap-regressions.
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
SOURCE = ROOT / "202303" / "C.cpp"
BUILD = ROOT / ".build" / "ldap-regressions"
REPORT = BUILD / "latest-report.json"


def format_result(matches, dns):
    return " ".join(map(str, sorted(dns[i] for i in matches)))


def atom(key, value, op):
    return (op, key, value)


def stringify(tree):
    op, a, b = tree
    if op in ":~":
        return f"{a}{op}{b}"
    return f"{op}({stringify(a)})({stringify(b)})"


def direct(tree, user):
    op, a, b = tree
    if op == ':':
        return a in user and user[a] == b
    if op == '~':
        return a in user and user[a] != b
    if op == '&':
        return direct(a, user) and direct(b, user)
    return direct(a, user) or direct(b, user)


def small_case(rng):
    n = rng.randint(1, 70)
    dns = rng.sample(range(1, 1000000001), n)
    keys = rng.sample(range(1, 1000000001), 25)
    values = rng.sample(range(1, 1000000001), 12)
    users = [{k: rng.choice(values) for k in rng.sample(keys[:20], rng.randint(0, 20))}
             for _ in range(n)]
    def tree(depth):
        if not depth or rng.random() < .35:
            return atom(rng.choice(keys), rng.choice(values), rng.choice(":~"))
        return (rng.choice("&|"), tree(depth-1), tree(depth-1))
    trees = [tree(rng.randint(0, 5)) for _ in range(15)]
    expressions = [stringify(t) for t in trees]
    # The generated grammar must remain within the original 2000-char limit.
    for i, text in enumerate(expressions):
        if len(text) > 2000:
            trees[i] = atom(keys[0], values[0], ':')
            expressions[i] = stringify(trees[i])
    lines = [str(n)]
    for dn, user in zip(dns, users):
        lines.append(f"{dn} {len(user)}" + ''.join(f" {a} {b}" for a, b in sorted(user.items())))
    lines += [str(len(expressions))] + expressions
    expected = '\n'.join(format_result({i for i, user in enumerate(users) if direct(t, user)}, dns)
                         for t in trees) + '\n'
    return '\n'.join(lines) + '\n', expected


def combine(leaves, op):
    # Build a valid balanced tree, evaluating independently with Python sets.
    layer = leaves
    while len(layer) > 1:
        next_layer = []
        for i in range(0, len(layer)-1, 2):
            a, b = layer[i], layer[i+1]
            next_layer.append((f"{op}({a[0]})({b[0]})",
                               a[1] & b[1] if op == '&' else a[1] | b[1]))
        if len(layer) & 1:
            next_layer.append(layer[-1])
        layer = next_layer
    return layer[0]


def maximum_case(name):
    rng = random.Random(20230303 + ["dense_repeated", "many_values", "unique_attributes",
                                  "many_missing", "deep_expression", "wide_attribute_ids"].index(name))
    n, k, m = 2500, 500, 500
    dns = [1000000000-i*123457 for i in range(n)]
    rows = [str(n)]
    unique = name in ("unique_attributes", "many_missing")
    wide = name == "wide_attribute_ids"
    for user in range(n):
        fields = []
        for j in range(k):
            if unique:
                index = user*k+j+1
                attribute, value = index*701, index*100003 % 999999999+1
            else:
                attribute = (j+1)*1000003 if wide else j+1
                value = user+1 if name in ("many_values", "wide_attribute_ids") else user % 3+1
            fields.append(f"{attribute} {value}")
        rows.append(f"{dns[user]} {k} " + ' '.join(fields))
    expressions, answers = [], []
    universe = set(range(n))
    for query in range(m):
        if unique:
            leaves = []
            for j in range(60):
                index = rng.randint(1, n*k)
                attribute = index*701 if name != "many_missing" else 999999999-index
                value = index*100003 % 999999999+1
                leaves.append((f"{attribute}:{value}", {(index-1)//k} if name != "many_missing" else set()))
            text, result = combine(leaves, '|')
        else:
            attribute = (query % 9+1)*1000003 if wide else query % 9+1
            value = query % n+1 if name in ("many_values", "wide_attribute_ids") else query % 3+1
            equal = {value-1} if name in ("many_values", "wide_attribute_ids") else set(range(value-1, n, 3))
            result = universe - equal
            leaf = f"{attribute}~{value}"
            count = min(249, (2000+5)//(len(leaf)+5))
            if name == "deep_expression":
                text = leaf
                for _ in range(count-1):
                    text = f"&({text})({leaf})"
            else:
                text, result = combine([(leaf, result)]*count, '&')
        assert 1 <= len(text) <= 2000
        expressions.append(text)
        answers.append(format_result(result, dns))
    rows += [str(m)] + expressions
    return '\n'.join(rows)+'\n', '\n'.join(answers)+'\n'


def compile_source(source, name, compiler):
    target = BUILD / name
    subprocess.run(compiler + ["-std=c++17", "-O2", "-Wall", "-Wextra", "-Wpedantic",
                               str(source), "-o", str(target)], check=True)
    return target


def run_small(executable, data):
    return subprocess.run([str(executable)], input=data, text=True, capture_output=True,
                          check=True, timeout=10).stdout


def timed_run(executable, incoming_path, outgoing_path):
    with incoming_path.open('rb') as incoming, outgoing_path.open('wb') as outgoing:
        start = time.perf_counter()
        subprocess.run([str(executable)], stdin=incoming, stdout=outgoing, check=True, timeout=180)
        elapsed = time.perf_counter()-start
    return elapsed, outgoing_path.read_text()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--baseline', type=Path)
    parser.add_argument('--stress', action='store_true')
    args = parser.parse_args()
    BUILD.mkdir(parents=True, exist_ok=True)
    compiler = shlex.split(os.environ.get('CXX', 'c++'))
    new = compile_source(SOURCE, 'candidate', compiler)
    old = compile_source(args.baseline, 'baseline', compiler) if args.baseline else None
    report = {"problem": "CSP202303C", "date": date.today().isoformat(), "platform": platform.platform(),
              "machine": platform.machine(),
              "compiler": subprocess.run(compiler+['--version'], capture_output=True, text=True,
                                         check=True).stdout.splitlines()[0],
              "flags": "-std=c++17 -O2 -Wall -Wextra -Wpedantic",
              "source_sha256": hashlib.sha256((SOURCE).read_bytes()).hexdigest(),
              "baseline_sha256": hashlib.sha256(args.baseline.read_bytes()).hexdigest() if old else None,
              "samples": 0, "independent_random_cases": 0, "stress": [],
              "online_status": "not_submitted_by_validator"}
    sample = '2\n1 2 1 2 2 3\n2 2 2 3 3 1\n4\n1:2\n3~1\n&(1:2)(2:3)\n|(1:2)(3:1)\n'
    assert run_small(new, sample) == '1\n\n1\n1 2\n'
    report['samples'] = 1
    rng = random.Random(20230303)
    for i in range(600):
        data, expected = small_case(rng)
        if run_small(new, data) != expected:
            (BUILD/'counterexample.in').write_text(data)
            (BUILD/'counterexample.expected').write_text(expected)
            raise AssertionError(i)
        if old:
            assert run_small(old, data) == expected
        report['independent_random_cases'] += 1
    print('1 sample and 600 independent per-user AST cases passed', flush=True)
    if args.stress:
        for name in ['dense_repeated', 'many_values', 'unique_attributes', 'many_missing',
                     'deep_expression', 'wide_attribute_ids']:
            data, expected = maximum_case(name)
            path = BUILD/(name+'.in')
            path.write_text(data)
            elapsed, actual = timed_run(new, path, BUILD/(name+'.new.out'))
            assert actual == expected, name
            result = {'case': name, 'n': 2500, 'attributes_per_user': 500, 'm': 500,
                      'candidate_seconds': elapsed, 'independent_set_oracle': True,
                      'input_sha256': hashlib.sha256(data.encode()).hexdigest(),
                      'output_sha256': hashlib.sha256(expected.encode()).hexdigest()}
            if old:
                old_time, actual = timed_run(old, path, BUILD/(name+'.old.out'))
                assert actual == expected, name
                result.update(baseline_seconds=old_time, speedup=old_time/elapsed)
            report['stress'].append(result)
            print(json.dumps(result), flush=True)
    report['status'] = 'passed'
    REPORT.write_text(json.dumps(report, indent=2)+'\n')
    print(f'Saved {REPORT}', flush=True)


if __name__ == '__main__':
    main()
