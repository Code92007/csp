"""Independent path simulation and large tree constructions for 202603E."""
from pathlib import Path
from collections import Counter, deque
import argparse
import hashlib
import json
import random
import subprocess
import time

ROOT = Path(__file__).resolve().parents[1]
SEED = 92007202603
rng = random.Random(SEED)


def pack(n, edges, stations, plans, ops, answers, kind):
    data = [f'{n} {pack.mask}', *(f'{u} {v}' for u, v in edges),
            str(len(stations)), ' '.join(map(str, stations)), str(len(plans)),
            *(f'{u} {v}' for u, v in plans), str(len(ops)), *ops]
    return dict(input='\n'.join(data) + '\n', output=list(answers), kind=kind)


def small_case(index):
    n = 2 + index % 69
    kind = index % 5
    if kind == 0:
        edges = [(u - 1, u) for u in range(2, n + 1)]
    elif kind == 1:
        edges = [(1, u) for u in range(2, n + 1)]
    elif kind == 2:
        edges = [(u // 2, u) for u in range(2, n + 1)]
    else:
        edges = [(rng.randrange(1, u), u) for u in range(2, n + 1)]
    adj = [[] for _ in range(n + 1)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)
    count = (0, min(1, n), min(20, n), rng.randrange(min(20, n) + 1))[index % 4]
    stations = set(rng.sample(range(1, n + 1), count))
    plans = [tuple(rng.sample(range(1, n + 1), 2)) for _ in range(45)]
    plans += [plans[0], plans[0][::-1], (1, n), (n, 1)]
    paths = []
    for s, t in plans:
        par = {s: 0}
        queue = deque([s])
        while t not in par:
            u = queue.popleft()
            for v in adj[u]:
                if v not in par:
                    par[v] = u
                    queue.append(v)
        p = [t]
        while p[-1] != s:
            p.append(par[p[-1]])
        paths.append(p[::-1])
    repaired = set()

    def answer():
        total = 0
        for path in paths:
            left = 0
            for u, v in zip(path, path[1:]):
                left += tuple(sorted((u, v))) not in repaired
                if left > 1:
                    break
                if v in stations:
                    left = 0
            else:
                total += 1
        return total

    pack.mask = index & 1
    last = 0
    ops, answers = [], []

    def query():
        nonlocal last
        last = answer()
        ops.append('2')
        answers.append(last)

    query()
    remaining = edges[:]
    rng.shuffle(remaining)
    for i, (u, v) in enumerate(remaining):
        if i % 2:
            u, v = v, u
        ops.append(f'1 {u ^ (pack.mask * last)} {v ^ (pack.mask * last)}')
        repaired.add(tuple(sorted((u, v))))
        if i % 3 or rng.randrange(2):
            query()
    query()
    assert answers[-1] == len(plans)
    return pack(n, edges, sorted(stations), plans, ops, answers, 'small_bfs')


def chain_case(station_count):
    n = m = 100000
    edges = [(u, u + 1) for u in range(1, n)]
    stations = [n * (i + 1) // (station_count + 1) for i in range(station_count)]
    plans = [tuple(rng.sample(range(1, n + 1), 2)) for _ in range(m)]
    activate = Counter()
    for s, t in plans:
        s, t = sorted((s, t))
        cuts = [s] + [x for x in stations if s < x < t] + [t]
        # After repairing prefix edges 1..p, [a,b] has at most one
        # unrepaired edge iff b-a<=1 or p>=b-2.
        threshold = max([b - 2 for a, b in zip(cuts, cuts[1:]) if b - a > 1] or [0])
        activate[threshold] += 1
    pack.mask = 1
    ans = activate[0]
    ops, answers = ['2'], [ans]
    for u in range(1, n):
        v = u + 1
        ops.append(f'1 {u ^ ans} {v ^ ans}')
        ans += activate[u]
        ops.append('2')
        answers.append(ans)
    assert ans == m and len(ops) == 199999
    return pack(n, edges, stations, plans, ops, answers,
                f'max_chain_{station_count}_stations')


def star_case():
    n = m = 100000
    edges = [(1, u) for u in range(2, n + 1)]
    plans = [tuple(rng.sample(range(1, n + 1), 2)) for _ in range(m)]
    incident = [[] for _ in range(n + 1)]
    valid = [False] * m
    ans = 0
    for i, (u, v) in enumerate(plans):
        if 1 in (u, v):
            valid[i] = True
            ans += 1
        else:
            incident[u].append(i)
            incident[v].append(i)
    pack.mask = 1
    ops, answers = ['2'], [ans]
    for u in range(2, n + 1):
        ops.append(f'1 {1 ^ ans} {u ^ ans}')
        for i in incident[u]:
            if not valid[i]:
                valid[i] = True
                ans += 1
        ops.append('2')
        answers.append(ans)
    assert ans == m
    return pack(n, edges, [], plans, ops, answers, 'max_star')


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--bin', type=Path, required=True)
    parser.add_argument('--ubsan', type=Path)
    parser.add_argument('--report', type=Path, default=ROOT / 'reports/e-report.json')
    args = parser.parse_args()
    cases = [small_case(i) for i in range(300)]
    cases.extend([chain_case(0), chain_case(20), star_case()])
    digest = hashlib.sha256()
    for case in cases:
        digest.update(case['input'].encode())
        digest.update(json.dumps(case['output']).encode())
    results = []
    for binary, selected in [(args.bin, cases), (args.ubsan, cases[:300])]:
        if binary is None:
            continue
        counts = Counter()
        start = time.monotonic()
        for case in selected:
            p = subprocess.run([str(binary)], input=case['input'], text=True,
                               capture_output=True, timeout=45)
            got = p.stdout.split()
            want = list(map(str, case['output']))
            if p.returncode or got != want:
                (ROOT / 'reports/e-failure.in').write_text(case['input'])
                raise AssertionError((case['kind'], p.returncode, p.stderr,
                                      got[:10], want[:10]))
            counts[case['kind']] += 1
        results.append(dict(binary=binary.name, cases=dict(counts),
                            seconds=round(time.monotonic() - start, 3)))
    report = dict(problem='202603E', seed=SEED,
                  source_sha256=hashlib.sha256((ROOT / 'E.cpp').read_bytes()).hexdigest(),
                  case_sha256=digest.hexdigest(), distinct_inputs=len(cases), results=results,
                  oracle='BFS literal paths for small trees; activation thresholds for prefix-repaired chains; incident-plan counting for stars.',
                  note='Local validation; randomized witnesses affect runtime, not answer correctness. No online submission.')
    args.report.write_text(json.dumps(report, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps(report, ensure_ascii=False), flush=True)


if __name__ == '__main__':
    main()
