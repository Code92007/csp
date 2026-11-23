"""Independent numerical, ray-rotation and dynamic-diameter checks."""
from decimal import localcontext
import importlib.util
import random


def load(name):
    spec = importlib.util.spec_from_file_location(name, '/tmp/csp-style-publish/tests/' + name + '.py')
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def cases():
    precision = load('precision_regressions')
    with localcontext() as ctx:
        ctx.prec = 70
        for data, expected in precision.random_cases():
            yield dict(problem='B', kind='retained_independent', input=data,
                       output=' '.join(map(str, expected)), abs_tol=0.1)
        data, expected = precision.deterministic_case()
        yield dict(problem='B', kind='boundary', input=data,
                   output=' '.join(map(str, expected)), abs_tol=0.1)
        captured = []
        class End(Exception):
            pass
        class Capture:
            def run(self, label, data, expected=None):
                if expected is None:
                    raise End()
                captured.append(dict(problem='B', kind='boundary', label=label,
                                     input=data, output=' '.join(map(str, expected)), abs_tol=0.1))
                return None, {}
        try:
            precision.run_stress(Capture())
        except End:
            pass
        yield from captured
    n = 100000
    yield dict(problem='B', kind='stress', label='100000 operations and queries',
               input=f'{n} {n}\n' + '2 0\n' * n + f'1 {n} 1000000 -1000000\n' * n,
               output='1000000 -1000000\n' * n, abs_tol=0.1)
    dragon = load('dragon_regressions')
    rng = random.Random(20230920261124)
    for i in range(700):
        data, expected = dragon.random_case(rng, i)
        yield dict(problem='D', kind='retained_independent', input=data, output=expected)
    for mask in range(1, 256):
        points = [(10 + 3 * dx, 10 + 3 * dy) for d, (dx, dy) in enumerate(dragon.DIRECTIONS) if mask >> d & 1]
        points.append((10, 10))
        events = [(10, 10, mask % 7 + 1)]
        yield dict(problem='D', kind='boundary', input=dragon.encode(20, 20, points, events),
                   output=dragon.grid_oracle(20, 20, points, events))
    for name in ['dense_full', 'checkerboard', 'four_ring', 'one_ring', 'sparse_static', 'boundary']:
        data, expected = dragon.maximum_case(name)
        yield dict(problem='D', kind='stress', label='100000 points/events ' + name,
                   input=data, output=expected, timeout=180)
    n = 100000
    data = [f'{n} {n}']
    data.extend(f'{i} {i + 1} 0 1000000000' for i in range(1, n))
    data.extend('1 0' for _ in range(n))
    yield dict(problem='E', kind='stress', label='100000-city positive chain',
               input='\n'.join(data) + '\n', output=(str((n - 1) * 1000000000) + '\n') * (n + 1))
    data = [f'{n} {n}']
    data.extend(f'1 {i} 1000000000 0' for i in range(2, n + 1))
    data.extend('1 0' for _ in range(n))
    yield dict(problem='E', kind='stress', label='100000-city nonpositive star',
               input='\n'.join(data) + '\n', output='0\n' * (n + 1))
