"""Independent BPE/rectangle oracles and analytical maximum cases."""
import collections
import importlib.util
import random
from pathlib import Path


def bpe(words, freq, target):
    vocab = sorted(set(''.join(words)))
    seqs = [list(s) for s in words]
    while len(vocab) < target:
        cnt = collections.Counter()
        for seq, f in zip(seqs, freq):
            for pair in zip(seq, seq[1:]):
                cnt[pair] += f
        if not cnt:
            break
        pair = min(cnt, key=lambda p: (-cnt[p], len(p[0]) + len(p[1]), len(p[0]), ''.join(p)))
        vocab.append(''.join(pair))
        for i, seq in enumerate(seqs):
            out = []
            j = 0
            while j < len(seq):
                if tuple(seq[j:j + 2]) == pair:
                    out.append(vocab[-1])
                    j += 2
                else:
                    out.append(seq[j])
                    j += 1
            seqs[i] = out
    return '\n'.join(vocab)


def cases():
    spec = importlib.util.spec_from_file_location('optimized', '/tmp/csp-style-publish/tests/optimized_regressions.py')
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    rng = random.Random(20240620261124)
    for n, rectangles, queries in module.rectangle_cases(rng):
        yield dict(problem='E', kind='retained_independent',
                   input=module.rectangle_input(n, rectangles, queries),
                   output='\n'.join(str(module.rectangle_answer(rectangles, q)) for q in queries))
    values = [i % 2001 - 1000 for i in range(10000)]
    yield dict(problem='A', kind='stress', label='10000 elements row-major',
               input='100 100 1 10000\n' + ' '.join(map(str, values)) + '\n',
               output=' '.join(map(str, values)))
    rows = [values[i:i + 100] for i in range(0, 10000, 100)]
    ops = []
    ans = []
    for i in range(100):
        ops.append('2 0 0')
        rows = [list(x) for x in zip(*rows)]
        for j in range(999):
            x, y = (j * 17 + i) % 100, (j * 23 + i) % 100
            ops.append(f'3 {x} {y}')
            ans.append(str(rows[x][y]))
    yield dict(problem='B', kind='stress', label='100000 operations and 100 transposes',
               input='100 100 100000\n' + ' '.join(map(str, values)) + '\n' + '\n'.join(ops) + '\n',
               output='\n'.join(ans))
    for word in ['a' * 250000, 'abacaba' * 35714]:
        yield dict(problem='C', kind='stress', label='near 250000 characters overlap',
                   input=f'1 5000\n{word} 1000000\n', output=bpe([word], [1000000], 5000))
    yield dict(problem='D', kind='stress', label='maximum total cost 40000',
               input='1000 1000 960000\n' + '20 20\n' * 1000 + ''.join(f'1000 {i}\n' for i in range(1000)),
               output='40000')
    n = 500000
    data = [f'{n} {n}']
    data.extend(f'1 {n} {i} {i} {i}' for i in range(1, n + 1))
    ans = []
    for i in range(1, n + 1):
        y = i * 12345 % n + 1
        data.append(f'{i} {i} {y} {y}')
        ans.append(str(y))
    yield dict(problem='E', kind='stress', label='500000 horizontal strips; axis swap',
               input='\n'.join(data) + '\n', output='\n'.join(ans), timeout=120)
    data = [f'{n} {n}']
    data.extend(f'{i} {i} {i} {i} {i}' for i in range(1, n + 1))
    ans = []
    for i in range(1, n + 1):
        x, y = sorted((i, i * 12345 % n + 1))
        a, b = sorted((i * 941 % n + 1, i * 7547 % n + 1))
        data.append(f'{x} {y} {a} {b}')
        ans.append(str(min(y, b) if max(x, a) <= min(y, b) else 0))
    yield dict(problem='E', kind='stress', label='500000 diagonal points and intersection queries',
               input='\n'.join(data) + '\n', output='\n'.join(ans), timeout=120)
    data = [f'{n} {n}']
    data.extend(f'1 {n} {i} {n} {i}' for i in range(1, n + 1))
    ans = []
    for i in range(1, n + 1):
        y = i * 12345 % n + 1
        data.append(f'{i} {i} 1 {y}')
        ans.append(str(y))
    yield dict(problem='E', kind='stress', label='500000 full-width nested strips; maximum envelope workspace',
               input='\n'.join(data) + '\n', output='\n'.join(ans), timeout=120)
