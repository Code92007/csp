"""Capture the repository's independent oracles without changing that checkout.

collect(repo, date) returns replayable cases. AST pruning omits loops that
explicitly target other contests; all helper definitions remain available.
"""
import ast
import importlib
import random
import re
import sys
from pathlib import Path


def collect(repo, date):
    tests = Path(repo) / 'tests'
    sys.path.insert(0, str(tests))
    cases = []

    def capture(key, data, expected, tolerance=None):
        if key[:6] != date:
            return
        problem = key[-1] if len(key) == 7 else 'E'
        cases.append(dict(problem=problem, kind='retained_independent',
                          input=data, output=str(expected), abs_tol=tolerance))

    class Prune(ast.NodeTransformer):
        def visit_For(self, node):
            keys = {x.value[:6] for x in ast.walk(node)
                    if isinstance(x, ast.Constant) and isinstance(x.value, str)
                    and re.fullmatch(r'\d{6}[A-E]?', x.value)}
            if keys and date not in keys:
                return None
            return self.generic_visit(node)

    groups = {
        'A': ('first_support', ['first_all.py']),
        'B': ('second_support', ['second_first.py', 'second_last.py']),
        'C': ('third_support', ['third_first.py', 'third_second.py',
                                'third_third.py', 'third_last.py']),
        'D': ('fourth_support', ['fourth_first.py', 'fourth_second.py',
                                 'fourth_third.py', 'fourth_fourth.py',
                                 'fourth_last.py']),
    }
    for letter, (support_name, filenames) in groups.items():
        support = importlib.import_module(support_name)
        support.check = capture
        support.case = capture
        support.report = {}
        support.rng = random.Random(9200700 + ord(letter))
        for filename in filenames:
            path = tests / filename
            source = path.read_text()
            if date + letter not in source:
                continue
            tree = Prune().visit(ast.parse(source))
            ast.fix_missing_locations(tree)
            scope = dict(__name__='captured_oracle', __file__=str(path))
            exec(compile(tree, str(path), 'exec'), scope)
            # Most C/D generators wrap their loops, while A/B run at top level.
            for name in ('first', 'run'):
                if name in scope and callable(scope[name]):
                    scope[name]()

    support = importlib.import_module('fifth_support')
    support.check = capture
    support.report = {}
    support.rng = random.Random(920072026)
    if date in {'202509', '202512', '202412', '202506', '202503'}:
        path = tests / 'fifth_support.py'
        tree = Prune().visit(ast.parse(path.read_text()))
        ast.fix_missing_locations(tree)
        scope = dict(__name__='captured_fifth', __file__=str(path))
        exec(compile(tree, str(path), 'exec'), scope)
        scope['check'] = capture
        scope['random_first']()
    else:
        groups = {
            'fifth_extended': {'202303', '202112', '202309', '201503',
                               '201712', '201809', '201512', '201604',
                               '201403', '201703', '202109'},
            'fifth_extra': {'201912', '202006', '202409', '202403',
                            '202603', '202312', '202305', '201509', '201409'},
            'fifth_geometry': {'202406', '202104', '202206'},
        }
        for name, dates in groups.items():
            if date in dates:
                module = importlib.import_module(name)
                module.check = capture
                module.run(date)
    # Preserve different expected values for identical input: a disagreement
    # between retained generators should be investigated, never overwritten.
    unique = {}
    for case in cases:
        marker = (case['problem'], case['input'])
        if marker in unique:
            assert unique[marker]['output'].split() == case['output'].split()
        unique[marker] = case
    return list(unique.values())
