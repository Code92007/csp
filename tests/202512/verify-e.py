"""202512E: subset-partition oracle, retained cases, thresholds and exact stresses."""
from pathlib import Path
from collections import Counter
from functools import lru_cache
import argparse
import hashlib
import itertools
import json
import random
import re
import subprocess
import sys
import time

ROOT = Path(__file__).resolve().parents[1]
SEED = 92007202512


@lru_cache(maxsize=100000)
def cost(values, w):
    # Adapted from tests/fifth_support.py: enumerate stable subsets, then partition.
    # Instances remain distinct even when their weights coincide.
    n = len(values)
    dp = [n + 1] * (1 << n)
    dp[0] = 0
    stable = []
    for mask in range(1, 1 << n):
        indices = [i for i in range(n) if mask >> i & 1]
        if all((values[i] ^ values[j]) >= w
               for i, j in itertools.combinations(indices, 2)):
            stable.append(mask)
    for mask in range(1, 1 << n):
        for sub in stable:
            if sub & mask == sub:
                dp[mask] = min(dp[mask], 1 + dp[mask ^ sub])
    return dp[-1]


def pack(packets, w, operations, kind):
    packets = [list(p) for p in packets]
    lines = [f'{len(packets)} {w}']
    lines.extend(str(len(p)) + (' ' + ' '.join(map(str, p)) if p else '')
                 for p in packets)
    active = set(range(len(packets)))
    answers = []
    ops = []
    for op in operations:
        ops.append(' '.join(map(str, op)))
        if op[0] == 1:
            u, x = op[1] - 1, op[2]
            assert u in active and 0 <= x <= 10 ** 9
            packets[u].append(x)
        elif op[0] == 2:
            u, v = op[1] - 1, op[2] - 1
            assert u in active and v in active and u != v
            packets[u].extend(packets[v])
            packets[v].clear()
            active.remove(v)
        else:
            answers.append(sum(cost(tuple(sorted(packets[u])), w) for u in active))
    return dict(input='\n'.join(lines + [str(len(ops))] + ops) + '\n',
                output=answers, kind=kind, sanitize=True)


def retained_cases():
    # Preserve the original generator's RNG state before its 100 202512E cases.
    rng = random.Random(920072026)
    for _ in range(120):
        n = rng.randint(1, 8)
        for _ in range(2 * n):
            rng.randint(1, 30)
        rng.randint(1, 300)
    for _ in range(100):
        w = rng.choice([1, 2, 3, 4, 5, 7, 8, 9, 15, 16, 100, 2 ** 30])
        packets = [[rng.randrange(32) for _ in range(rng.randrange(3))]
                   for _ in range(3)]
        current = [p[:] for p in packets]
        active = list(range(3))
        ops = []
        for _ in range(9):
            if sum(map(len, current)) < 8 and rng.randrange(3):
                u = rng.choice(active)
                x = rng.randrange(32)
                current[u].append(x)
                ops.append((1, u + 1, x))
            elif len(active) > 1:
                u, v = rng.sample(active, 2)
                current[u].extend(current[v])
                current[v] = []
                active.remove(v)
                ops.append((2, u + 1, v + 1))
            ops.append((3,))
        yield pack(packets, w, ops, 'retained_random')


def threshold_cases():
    thresholds = {1, 2 ** 30, 2 ** 31, 10 ** 12, 10 ** 18, 2 ** 63 - 1}
    for bit in range(31):
        for delta in (-1, 0, 1):
            if (1 << bit) + delta > 0:
                thresholds.add((1 << bit) + delta)
    for w in sorted(thresholds):
        pool = sorted({0, 1, 10 ** 9 - 1, 10 ** 9} |
                      {x for x in (w - 1, w, w + 1) if 0 <= x <= 10 ** 9})
        packets = [[0, pool[-1]], [pool[len(pool) // 2]] * 2, [], [10 ** 9], []]
        ops = [(3,), (2, 3, 1), (3,), (1, 3, 0), (3,),
               (2, 2, 3), (3,), (2, 4, 2), (3,),
               (1, 4, pool[1]), (3,), (2, 5, 4), (3,)]
        yield pack(packets, w, ops, 'threshold_boundary')


def random_cases():
    rng = random.Random(SEED)
    for index in range(300):
        n = rng.randint(1, 6)
        bit = index % 30
        w = rng.choice([1, (1 << bit), max(1, (1 << bit) - 1),
                        (1 << bit) + 1, rng.randint(1, 10 ** 9)])
        def value():
            if index % 3 == 0:
                return rng.randrange(32)
            return rng.choice([0, 10 ** 9, rng.randrange(10 ** 9 + 1),
                               min(10 ** 9, 1 << bit)])
        packets = [[] for _ in range(n)]
        initial = rng.randint(1, 5)
        for _ in range(initial):
            packets[rng.randrange(n)].append(value())
        active = list(range(n))
        total = initial
        ops = [(3,)]
        for _ in range(20):
            if total < 10 and (len(active) == 1 or rng.randrange(3)):
                u = rng.choice(active)
                ops.append((1, u + 1, value()))
                total += 1
            elif len(active) > 1:
                u, v = rng.sample(active, 2)
                ops.append((2, u + 1, v + 1))
                active.remove(v)
            ops.append((3,))
        yield pack(packets, w, ops, 'subset_partition_random')


def official_cases():
    yield dict(input='2 3\n2 0 3\n0\n5\n3\n1 2 0\n3\n2 1 2\n3\n',
               output=[1, 2, 2], kind='retained_saved', sanitize=True)
    yield dict(input='3 16\n1 21\n1 16\n1 29\n5\n3\n2 2 1\n3\n2 3 2\n3\n',
               output=[3, 3, 3], kind='oj_sample', sanitize=True)
    yield dict(input='5 15\n7 4 7 8 13 13 0 11\n1 11\n9 9 4 19 0 11 9 5 9 8\n2 9 16\n4 10 17 12 1\n9\n1 3 10\n1 5 19\n2 1 4\n1 2 16\n3\n1 2 18\n1 5 11\n3\n2 5 2\n',
               output=[17, 19], kind='oj_sample', sanitize=True)
    yield dict(input='3 2\n0\n0\n2 7 5\n2\n2 2 1\n3\n',
               output=[1], kind='oj_sample', sanitize=True)


def pressure_cases():
    n = 500000
    lines = [f'{n} 1'] + ['1 0'] * n
    ops = [f'2 1 {v}' for v in range(2, n + 1)] + ['3']
    yield dict(input='\n'.join(lines + [str(len(ops))] + ops) + '\n',
               output=[n], kind='max_singletons_merge', sanitize=False)
    lines = [f'{n} 1'] + ['1 0'] * n
    ops = [f'1 {u} {1 << 29}' for u in range(1, n)] + ['3']
    yield dict(input='\n'.join(lines + [str(len(ops))] + ops) + '\n',
               output=[n], kind='max_distinct_path_growth', sanitize=False)
    n, period = 250000, 1024
    lines = [f'{n} 1'] + [f'1 {i % period}' for i in range(n)]
    groups = [(i + 1, 1) for i in range(n)]
    ans = n
    ops, out = ['3'], [ans]
    def repair_cost(length):
        return (length + period - 1) // period
    while len(groups) > 1:
        next_groups = []
        for i in range(0, len(groups) - 1, 2):
            u, a = groups[i]
            v, b = groups[i + 1]
            ans += repair_cost(a + b) - repair_cost(a) - repair_cost(b)
            ops.extend([f'2 {u} {v}', '3'])
            out.append(ans)
            next_groups.append((u, a + b))
        if len(groups) & 1:
            next_groups.append(groups[-1])
        groups = next_groups
    assert ans == repair_cost(n) and len(ops) == 499999
    yield dict(input='\n'.join(lines + [str(len(ops))] + ops) + '\n',
               output=out, kind='balanced_duplicate_merges', sanitize=False)
    n = 500000
    lines = [f'1 {10 ** 18}', str(n) + ' ' + ' '.join(['0'] * n)]
    ops = [f'1 1 {i % (10 ** 9 + 1)}' for i in range(n - 1)] + ['3']
    yield dict(input='\n'.join(lines + [str(len(ops))] + ops) + '\n',
               output=[2 * n - 1], kind='max_all_conflict', sanitize=True)


def execute(binary, case):
    cmd = [str(binary)]
    if not case['sanitize']:
        runner = ('import resource,subprocess,sys; '
                  'p=subprocess.run(sys.argv[1:]); '
                  'r=resource.getrusage(resource.RUSAGE_CHILDREN).ru_maxrss; '
                  'print("LOCAL_PEAK_RSS_BYTES",r if sys.platform=="darwin" else r*1024,file=sys.stderr); '
                  'sys.exit(p.returncode)')
        cmd = [sys.executable, '-c', runner] + cmd
    start = time.monotonic()
    result = subprocess.run(cmd, input=case['input'], text=True,
                            capture_output=True, timeout=90)
    elapsed = time.monotonic() - start
    want = list(map(str, case['output']))
    if result.returncode or result.stdout.split() != want:
        (ROOT / 'reports/e-failure.in').write_text(case['input'])
        (ROOT / 'reports/e-failure.json').write_text(json.dumps(dict(
            kind=case['kind'], returncode=result.returncode,
            expected=want, stdout=result.stdout, stderr=result.stderr), indent=2))
        raise AssertionError((case['kind'], result.returncode, result.stderr[:1000],
                              result.stdout.split()[:15], want[:15]))
    rss = re.search(r'LOCAL_PEAK_RSS_BYTES (\d+)', result.stderr)
    return dict(seconds=round(elapsed, 4),
                peak_rss_bytes=int(rss[1]) if rss else None)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--bin', type=Path, required=True)
    parser.add_argument('--ubsan', type=Path)
    parser.add_argument('--large', action='store_true')
    parser.add_argument('--report', type=Path, default=ROOT / 'reports/e-report.json')
    args = parser.parse_args()
    cases = itertools.chain(official_cases(), retained_cases(), threshold_cases(), random_cases(),
                            pressure_cases() if args.large else [])
    digest, counts = hashlib.sha256(), Counter()
    results = {str(args.bin): dict(cases=Counter(), seconds=0, stresses=[])}
    if args.ubsan:
        results[str(args.ubsan)] = dict(cases=Counter(), seconds=0, stresses=[])
    for case in cases:
        counts[case['kind']] += 1
        digest.update(case['input'].encode())
        digest.update(json.dumps(case['output']).encode())
        for binary in (args.bin, args.ubsan):
            if binary is None or (binary == args.ubsan and not case['sanitize']):
                continue
            result = execute(binary, case)
            entry = results[str(binary)]
            entry['cases'][case['kind']] += 1
            entry['seconds'] += result['seconds']
            if case['kind'].startswith('max_') or case['kind'] == 'balanced_duplicate_merges':
                entry['stresses'].append(dict(kind=case['kind'], **result))
                print(binary.name, case['kind'], result, flush=True)
    for entry in results.values():
        entry['seconds'] = round(entry['seconds'], 3)
    report = dict(problem='202512E', seed=SEED,
        source_sha256=hashlib.sha256((ROOT / 'E.cpp').read_bytes()).hexdigest(),
        distinct_inputs=sum(counts.values()), cases=dict(counts),
        case_sha256=digest.hexdigest(), results=results,
        oracle='Retained and new small cases use independent stable-subset partition DP, adapted from tests/fifth_support.py. No Trie states or clique recurrence are used. Large W=1 stresses use duplicate multiplicities; balanced merges preserve contiguous ranges of periodic values so each cost is ceil(length/1024). W>=2^30 makes every pair conflict and the cost equals element count.',
        allocation=dict(kind='Global static node pool', capacity_nodes=30000600, node_bytes=20, capacity_bytes=600012000, rationale='At most 500000 initial elements plus 500000 inserted elements; each insertion creates at most 30 nodes. Avoids vector reallocation peak.', prior_vector_sha256='a5da5e6cb2bdceda402cbe6b7d31040f6425920edf63b5f7f22cd76b3dbb4939', prior_vector_peak_rss_bytes=1266745344),
        compiler='Apple Clang C++17 with -I/tmp/csp202609-check/include for bits/stdc++.h; optimized -O2 -Wall -Wextra; UBSan -O1 -g -fsanitize=undefined -fno-sanitize-recover=all.',
        sources=['https://oj.shumeng.tech/p/CSP202512E', 'https://pcs2.roj.ac.cn/problems/shumeng/CSP202512E/'],
        original_oj=dict(status='accepted', score=100,
            record='https://oj.shumeng.tech/record/6adce734a67df0b81749b63c',
            belongs_to='Original source only; replica evaluation.'),
        refactored_online_submission=False,
        note='Local validation only. Retained historical generator cases may include an all-empty initial state, beyond the official positive initial-total lower bound; new random/boundary/pressure cases respect it. Stress timings and RSS from Python resource.getrusage are machine-specific, not official judge measurements.')
    args.report.write_text(json.dumps(report, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps(report, ensure_ascii=False), flush=True)


if __name__ == '__main__':
    main()
