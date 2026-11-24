"""Recheck D branches and E static arrays without replacing historical evidence."""
from pathlib import Path
import argparse
import collections
import hashlib
import json
import random
import subprocess
import sys
import time

P = Path(__file__).resolve().parents[1]
W = P.parent
ap = argparse.ArgumentParser()
ap.add_argument('--repo', default='/tmp/csp-style-publish')
args = ap.parse_args()
sys.path.insert(0, str(P / 'reports'))
original = P / 'reports/verify.py'
source = original.read_text().split("build=W/'.build'/f'{d}-prep';compilelog={};results=[]", 1)
assert len(source) == 2
scope = {'__file__': str(original), '__name__': 'retained_followup_input_generation'}
argv = sys.argv
try:
    sys.argv = [str(original), '--repo', args.repo]
    exec(compile(source[0], str(original), 'exec'), scope)
finally:
    sys.argv = argv
cases = [c for c in scope['cases'] if c['problem'] in 'DE']
original_counts = dict(collections.Counter(c['problem'] for c in cases))
rng = random.Random(2017122411)
MOD = 10**18


def text(rows):
    return str(len(rows)) + '\n' + ''.join('%d %d %d %d\n' % r for r in rows)


def brute(rows):
    n = len(rows)
    par = [0] + [r[0] for r in rows]
    dep = [0] * (n + 1)
    dp = [0] * (n + 1)
    for u, (_, length, value, ideal) in enumerate(rows, 1):
        dep[u] = dep[par[u]] + length
    for u in range(n, 0, -1):
        p = par[u]
        while p:
            value, ideal = rows[p - 1][2:]
            dp[p] = max(dp[p], dp[u] + value - (ideal - dep[u] + dep[p])**2)
            p = par[p]
    return sum(dp) % MOD


def add(blocks, answers=None, kind='array_reset_independent'):
    answers = [brute(rows) for rows in blocks] if answers is None else answers
    cases.append({'problem': 'E', 'kind': kind,
                  'input': str(len(blocks)) + '\n' + ''.join(map(text, blocks)),
                  'output': '\n'.join(map(str, answers))})


for _ in range(120):
    blocks = []
    for group in range(10):
        n = rng.randrange(1, 66)
        rows = []
        for u in range(1, n + 1):
            p = 0 if u == 1 else (u - 1 if group % 3 == 0 else rng.randrange(1, u))
            length = 0 if u == 1 else rng.choice([1, 10000, rng.randrange(1, 10001)])
            value = rng.choice([0, 1, 10**13, rng.randrange(10**13 + 1)])
            ideal = rng.choice([0, 1, 10000, 10**9, rng.randrange(10**9 + 1)])
            rows.append((p, length, value, ideal))
        blocks.append(rows)
    add(blocks)


def chain(n, value=10**13, length=10000, ideal=10000):
    return [(0, 0, value, ideal)] + [(u - 1, length, value, ideal) for u in range(2, n + 1)]


def balanced(n, value=10**13):
    return [(0, 0, value, 1)] + [(u // 2, 1, value, 1) for u in range(2, n + 1)]


def balanced_answer(n):
    h = [0] * (n + 1)
    for u in range(n, 1, -1):
        h[u // 2] = max(h[u // 2], h[u] + 1)
    return sum(h) * 10**13 % MOD


n = 100000
long = chain(n)
chain_answer = n * (n - 1) // 2 * 10**13 % MOD
add([long], [chain_answer], 'array_capacity_stress')
add([balanced(n)], [balanced_answer(n)], 'array_capacity_stress')
zero = [(0, 0, 0, 0)] + [(u // 2, rng.randrange(1, 10001), 0,
                                  rng.choice([0, rng.randrange(10**9 + 1)]))
                                 for u in range(2, n + 1)]
add([zero], [0], 'array_capacity_stress')
star = [(0, 0, 10**13, 10000)] + [(1, 10000, 10**13, 0)] * 98764
add([long, [(0, 0, 10**13, 10**9)], star, balanced(257),
     [(0, 0, 0, 0)], chain(65537, value=0)],
    [chain_answer, 0, 10**13, balanced_answer(257), 0, 0], 'array_capacity_reset_stress')
unique = {}
for c in cases:
    key = (c['problem'], c['input'])
    if key in unique:
        assert unique[key]['output'].split() == c['output'].split()
    unique[key] = c
cases = list(unique.values())
build = W / '.build/201712-prep'
compilation = {}
for mode, compiler, flags in [
        ('O2', '/opt/homebrew/bin/g++-16', ['-O2']),
        ('UBSan', 'clang++', ['-O1', '-g', '-fsanitize=undefined',
                              '-fno-sanitize-recover=all', '-I/tmp/csp202609-check/include'])]:
    folder = build / ('refactored' if mode == 'O2' else 'ubsan')
    for c in 'DE':
        cmd = [compiler, '-std=c++17', '-Wall', '-Wextra', '-Wshadow', *flags,
               str(P / f'{c}.cpp'), '-o', str(folder / f'{c}-review')]
        p = subprocess.run(cmd, text=True, capture_output=True)
        assert p.returncode == 0 and not p.stderr, (cmd, p.stderr)
        compilation[f'{mode}/{c}'] = 'passed without diagnostics'
runs = []
for mode, folder in [('O2', 'refactored'), ('UBSan', 'ubsan')]:
    counts = collections.Counter()
    stresses = []
    start = time.monotonic()
    for i, c in enumerate(cases):
        t = time.monotonic()
        p = subprocess.run([str(build / folder / (c['problem'] + '-review'))],
                           input=c['input'], text=True, capture_output=True, timeout=90)
        assert p.returncode == 0 and not p.stderr, (mode, i, c['kind'], p.stderr)
        assert p.stdout.split() == c['output'].split(), (mode, i, c['kind'], p.stdout, c['output'])
        counts[c['problem']] += 1
        if 'stress' in c['kind']:
            stresses.append({'problem': c['problem'], 'kind': c['kind'],
                             'input_sha256': hashlib.sha256(c['input'].encode()).hexdigest(),
                             'seconds': round(time.monotonic() - t, 4)})
    runs.append({'mode': mode, 'passed': dict(counts), 'total': sum(counts.values()),
                 'seconds': round(time.monotonic() - start, 3), 'stress': stresses})
report = {
    'contest': '201712',
    'previous_sha256': {'D': '8e72a9eff1ee30609be8961b85325834bf88a123f67562c260ad2fc62486f2f7',
                       'E': '6c7b2c04e8a6bc12a5b80fd955a15b5ace8b6f5adf2379971789221a7e0ae3db'},
    'current_source_sha256': {c: hashlib.sha256((P / f'{c}.cpp').read_bytes()).hexdigest() for c in 'DE'},
    'changes': {'D': 'Expanded both long shortest-path relaxation if bodies with braces.',
                'E': 'Global ordinary arrays for vertex data, query coordinates, linked small-to-large line lists, and the Li Chao node pool; all required per-test resets retained.'},
    'source_limits': {'n_max': 100000, 'value_max': 10**13, 'ideal_max': 10**9, 'edge_max': 10000,
                      'verified_against': 'https://oj.shumeng.tech/p/CSP201712E'},
    'capacity_proof': 'Each insertion allocates at most one Li Chao node. A line moves only from the smaller set into a set at least twice as large, at most floor(log2 n) times. Initial insertions plus moves are at most 17*n for n<=100000. M=18*N, N=100010, includes the unused zero node. Linked lists store every line exactly once in the current partition; appending only changes the old tail next pointer after traversal.',
    'reset_proof': 'rt/head/tail/nxt/sz/dp are memset before each group; fa/dep/val/f/xs active entries are overwritten in parent-before-child order, dep[0] stays zero; tot resets to zero and every allocated pool node overwrites both children.',
    'original_input_counts': original_counts,
    'distinct_inputs': dict(collections.Counter(c['problem'] for c in cases)),
    'categories': dict(collections.Counter(c['kind'] for c in cases)),
    'independent_oracles': 'Original direct road-state Dijkstra (D); exact Python ancestor/descendant DP (E), extended to 120 ten-group inputs with range extremes. Max chain/balanced/stars have independent closed-form or zero-reward answers.',
    'input_set_sha256': hashlib.sha256(json.dumps(cases, sort_keys=True, separators=(',', ':')).encode()).hexdigest(),
    'compilation': compilation,
    'runs': runs,
    'historical_reports': ['report.json', 'nightly-review-followup.json'],
    'no_online_submission': True,
}
(P / 'reports/de-array-followup-report.json').write_text(json.dumps(report, ensure_ascii=False, indent=2) + '\n')
print(json.dumps(report, ensure_ascii=False, indent=2))
