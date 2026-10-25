#!/usr/bin/env python3
"""Portable regressions for the current CSP202112E implementation.

Place this file in the project's tests directory and run from any directory:
    python3 tests/extreme_path_v2_regressions.py
    python3 tests/extreme_path_v2_regressions.py --stress
Optional: --baseline /path/to/older/E.cpp performs an additional live comparison.
Python 3.9+ standard library; CXX chooses a C++17 compiler. Compiles 202112/E.cpp
into .build/extreme-path-v2-regressions and writes latest-report.json there.
Default: 1 sample, 650 independent path-enumeration cases, 3 analytic n=5000 cases.
--stress: 13 n=500000 cases; 8 independent checks and 5 explicitly marked frozen
historical differential references with input hashes. No old source/executable is
required. Saved historical reports are never overwritten; no network/submissions.
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
SOURCE = ROOT / '202112' / 'E.cpp'
BUILD = ROOT / '.build' / 'extreme-path-v2-regressions'
REPORT = BUILD / 'latest-report.json'
# Frozen full-output comparisons against the preserved 84-point v1 source
# SHA-256 31830c5aa36db5caefb2833b37132f359579f29e82279170f47761c99115cba7.
# These are historical differential references, NOT independent oracles.
# Hash checking rejects any changed generator before an answer is reused.
HISTORICAL_REFERENCES = {
    'chain_shuffled': ('052178c1b4a5a94d8ff6428720bfa5c112789f5d4436d1f4de5e21d1c25d171c', '20841252006'),
    'random_shuffled': ('b7510b3bcdf9a98ad41440aa8d88e684b747121e29d8805dc22bc54dd383491a', '70582995369'),
    'balanced_shuffled': ('40cec063c6df7d0f1a7c61cfd369aa6b1e609351b8e30801e735ca50dd71d17a', '69750296633'),
    'zigzag_chain': ('3c609df89c4ae745b5ce4e4dec74626e735d15407a15480bcc22e1657c2bb348', '62066631944'),
    'broom_shuffled': ('9f31f3cb8c46d21abd43b518ce635f6d1d2d7d180702d5fd07b5f4425fdebb15', '50262631647'),
}


def encode(n, k1, k2, edges):
    return f'{n} {k1} {k2}\n' + ''.join(f'{u} {v}\n' for u, v in edges)


def brute(n, k1, k2, edges):
    adjacency = [[] for _ in range(n+1)]
    for u, v in edges:
        adjacency[u].append(v)
        adjacency[v].append(u)
    answer = 0
    for start in range(1, n+1):
        stack = [(start, 0, start, start)]
        while stack:
            u, parent, low, high = stack.pop()
            if u >= start and low >= start-k1 and high <= u+k2:
                answer += 1
            for v in adjacency[u]:
                if v != parent:
                    stack.append((v, u, min(low, v), max(high, v)))
    return str(answer)


def tree(rng, n, mode):
    if mode == 'chain':
        edges = [(i-1, i) for i in range(2, n+1)]
    elif mode == 'star':
        root = rng.randint(1, n)
        edges = [(root, i) for i in range(1, n+1) if i != root]
    elif mode == 'balanced':
        edges = [(i//2, i) for i in range(2, n+1)]
    else:
        edges = [(rng.randrange(1, i), i) for i in range(2, n+1)]
    return edges


def permute(rng, n, edges):
    labels = list(range(1, n+1))
    rng.shuffle(labels)
    return [(labels[u-1], labels[v-1]) for u, v in edges]


def maximum_case(name):
    rng = random.Random(20211205 + ['chain_order', 'chain_shuffled', 'star', 'heap_balanced',
                                  'heap_random', 'random_shuffled', 'all_paths'].index(name))
    n = 500000
    expected = None
    if name == 'chain_order':
        edges = tree(rng, n, 'chain')
        k1 = k2 = 0
        expected = n*(n+1)//2
    elif name == 'chain_shuffled':
        edges = permute(rng, n, tree(rng, n, 'chain'))
        k1, k2 = n//3, n//4
    elif name == 'star':
        centre = n//2
        edges = [(centre, i) for i in range(1, n+1) if i != centre]
        k1, k2 = n//5, n//7
        upper, lower = max(0, n-centre-k1), max(0, centre-k2-1)
        expected = n*(n+1)//2-upper*(upper-1)//2-lower*(lower-1)//2
    elif name in ('heap_balanced', 'heap_random'):
        edges = tree(rng, n, 'balanced' if name == 'heap_balanced' else 'random')
        k1 = k2 = 0
        depth = [0]*(n+1)
        for u, v in edges:
            depth[v] = depth[u]+1
        expected = n+sum(depth)
    else:
        edges = permute(rng, n, tree(rng, n, 'random'))
        k1 = k2 = n//2 if name == 'random_shuffled' else n-2
        if name == 'all_paths':
            # For x<y, x<=n-1 and y>=2. Thus k1=k2=n-2 already admits
            # every non-singleton path; this still exercises the full solver.
            expected = n*(n+1)//2
    return encode(n, k1, k2, edges), None if expected is None else str(expected)



def extended_case(name):
    seed = 2021120510 + ['balanced_shuffled', 'zigzag_chain', 'broom_shuffled',
                       'nearfull_random', 'min_endpoint_random', 'max_endpoint_random'].index(name)
    rng = random.Random(seed)
    n = 500000
    expected = None
    if name == 'balanced_shuffled':
        edges = permute(rng, n, tree(rng, n, 'balanced'))
        k1 = k2 = n//2
    elif name == 'zigzag_chain':
        labels = [value for i in range(1, n//2+1) for value in (i, n+1-i)]
        edges = [(labels[i-1], labels[i]) for i in range(1, n)]
        k1, k2 = n//3, n//4
    elif name == 'broom_shuffled':
        edges = [(i-1, i) for i in range(2, n//2+1)]
        edges += [(n//2, i) for i in range(n//2+1, n+1)]
        edges = permute(rng, n, edges)
        k1 = k2 = n//3
    else:
        edges = permute(rng, n, tree(rng, n, 'random'))
        adjacency = [[] for _ in range(n+1)]
        for u, v in edges:
            adjacency[u].append(v)
            adjacency[v].append(u)
        if name == 'nearfull_random':
            k1 = k2 = n-3
            expected = n*(n+1)//2
            # Only (n-1,n) can violate the lower limit and only (1,2)
            # can violate the upper limit. Independently walk both paths.
            for start, target in [(n-1, n), (1, 2)]:
                stack = [(start, 0, start, start)]
                while stack:
                    u, parent, low, high = stack.pop()
                    if u == target:
                        expected -= low < start-k1 or high > target+k2
                        break
                    for v in adjacency[u]:
                        if v != parent:
                            stack.append((v, u, min(low, v), max(high, v)))
        else:
            # Independent DSU oracle. At activation of endpoint x, its
            # component is precisely the vertices reachable without crossing
            # a label smaller (or larger) than x.
            descending = name == 'min_endpoint_random'
            k1, k2 = (0, n) if descending else (n, 0)
            parent = list(range(n+1))
            size = [1]*(n+1)
            active = bytearray(n+1)
            def find(u):
                while parent[u] != u:
                    parent[u] = parent[parent[u]]
                    u = parent[u]
                return u
            expected = 0
            for u in (range(n, 0, -1) if descending else range(1, n+1)):
                active[u] = 1
                for v in adjacency[u]:
                    if active[v]:
                        a, b = find(u), find(v)
                        if size[a] < size[b]:
                            a, b = b, a
                        parent[b] = a
                        size[a] += size[b]
                expected += size[find(u)]
    return encode(n, k1, k2, edges), None if expected is None else str(expected)


def compile_source(source, name, compiler):
    executable = BUILD/name
    subprocess.run(compiler+['-std=c++17', '-O2', '-Wall', '-Wextra', '-Wpedantic',
                             str(source), '-o', str(executable)], check=True)
    return executable


def run_small(executable, data):
    return subprocess.run([str(executable)], input=data, text=True, capture_output=True,
                          check=True, timeout=15).stdout.strip()


def timed_run(executable, path):
    with path.open('rb') as incoming:
        start = time.perf_counter()
        result = subprocess.run([str(executable)], stdin=incoming, stdout=subprocess.PIPE,
                                timeout=180, check=True)
        elapsed = time.perf_counter()-start
    return elapsed, result.stdout.decode().strip()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--baseline', type=Path)
    parser.add_argument('--stress', action='store_true')
    args = parser.parse_args()
    BUILD.mkdir(parents=True, exist_ok=True)
    compiler = shlex.split(os.environ.get('CXX', 'c++'))
    new = compile_source(SOURCE, 'candidate-v2', compiler)
    old = compile_source(args.baseline, 'baseline-v1', compiler) if args.baseline else None
    report = {'problem': 'CSP202112E', 'date': date.today().isoformat(), 'platform': platform.platform(),
              'machine': platform.machine(),
              'compiler': subprocess.run(compiler+['--version'], text=True, capture_output=True,
                                         check=True).stdout.splitlines()[0],
              'flags': '-std=c++17 -O2 -Wall -Wextra -Wpedantic',
              'source_sha256': hashlib.sha256((SOURCE).read_bytes()).hexdigest(),
              'baseline_sha256': hashlib.sha256(args.baseline.read_bytes()).hexdigest() if old else None,
              'samples': 0, 'independent_random_cases': 0, 'medium_analytic_cases': 0,
              'stress': [], 'online_status': 'not_submitted_by_validator',
              'historical_reference_baseline': {'source_sha256': '31830c5aa36db5caefb2833b37132f359579f29e82279170f47761c99115cba7',
                                         'score': 84, 'status': 'Time Exceeded',
                                         'url': 'https://oj.shumeng.tech/record/6addfee374ace1cba9a233c6'}}
    assert run_small(new, '5 0 1\n5 4\n4 2\n4 1\n2 3\n') == '12'
    report['samples'] = 1
    rng = random.Random(20211205)
    for i in range(650):
        n = rng.randint(1, 120) if i < 600 else rng.randint(300, 600)
        edges = tree(rng, n, rng.choice(['chain', 'star', 'balanced', 'random']))
        if i % 3:
            edges = permute(rng, n, edges)
        k1, k2 = rng.randint(0, n), rng.randint(0, n)
        if i % 7 == 0:
            k1 = k2 = 0
        data, expected = encode(n, k1, k2, edges), brute(n, k1, k2, edges)
        if run_small(new, data) != expected:
            (BUILD/'counterexample.in').write_text(data)
            raise AssertionError((i, expected))
        if old:
            assert run_small(old, data) == expected
        report['independent_random_cases'] += 1
    for mode in ['chain', 'balanced', 'random']:
        n = 5000
        data = encode(n, n-2, n-2, permute(rng, n, tree(rng, n, mode)))
        expected = str(n*(n+1)//2)
        assert run_small(new, data) == expected
        if old:
            assert run_small(old, data) == expected
        report['medium_analytic_cases'] += 1
    print('1 sample, 650 independent path-enumeration cases, and 3 analytic n=5000 cases passed', flush=True)
    if args.stress:
        original_names = ['chain_order', 'chain_shuffled', 'star', 'heap_balanced',
                          'heap_random', 'random_shuffled', 'all_paths']
        extra_names = ['balanced_shuffled', 'zigzag_chain', 'broom_shuffled',
                       'nearfull_random', 'min_endpoint_random', 'max_endpoint_random']
        for name in original_names + extra_names:
            data, expected = maximum_case(name) if name in original_names else extended_case(name)
            path = BUILD/(name+'.in')
            path.write_text(data)
            elapsed, answer = timed_run(new, path)
            input_hash = hashlib.sha256(data.encode()).hexdigest()
            if expected is not None:
                assert answer == expected, (name, answer, expected)
            else:
                reference_hash, reference_answer = HISTORICAL_REFERENCES[name]
                assert input_hash == reference_hash, (name, 'generator changed', input_hash)
                assert answer == reference_answer, (name, answer, reference_answer)
            result = {'case': name, 'n': 500000, 'candidate_seconds': elapsed,
                      'input_sha256': input_hash,
                      'answer': answer, 'independent_oracle': expected is not None,
                      'historical_baseline_reference': expected is None,
                      'oracle': ('DSU activation' if 'endpoint_random' in name else
                                 'two necessary bad paths' if name == 'nearfull_random' else
                                 'analytic formula' if expected is not None else 'historical v1 full-output differential (not an independent oracle)')}
            if old:
                old_time, old_answer = timed_run(old, path)
                assert answer == old_answer, (name, answer, old_answer)
                result.update(baseline_seconds=old_time, speedup=old_time/elapsed)
            report['stress'].append(result)
            print(json.dumps(result), flush=True)
    report['status'] = 'passed'
    REPORT.write_text(json.dumps(report, indent=2)+'\n')
    print(f'Saved {REPORT}', flush=True)


if __name__ == '__main__':
    main()
