"""Run retained independent fixtures and saved samples against current sources."""
from pathlib import Path
from collections import Counter
import argparse
import hashlib
import json
import math
import subprocess
import time

ROOT = Path(__file__).resolve().parents[1]
HERE = Path(__file__).resolve().parent
parser = argparse.ArgumentParser()
parser.add_argument('--bin-dir', type=Path, required=True)
args = parser.parse_args()
fixture = HERE / 'retained-cases.json'
cases = json.loads(fixture.read_text())
counts = Counter()
start = time.monotonic()
for index, case in enumerate(cases):
    p = subprocess.run([str(args.bin_dir / case['problem'])], input=case['input'],
                       text=True, capture_output=True, timeout=30)
    got, want = p.stdout.split(), case['output'].split()
    tol = case.get('abs_tol')
    if tol is None:
        ok = got == want
    else:
        ok = len(got) == len(want) and all(
            math.isclose(float(x), float(y), abs_tol=tol,
                         rel_tol=case.get('rel_tol', 0)) for x, y in zip(got, want))
    if p.returncode or p.stderr or not ok:
        failure = dict(case, index=index, stdout=p.stdout, stderr=p.stderr,
                       returncode=p.returncode)
        (HERE / 'retained-failure.json').write_text(
            json.dumps(failure, ensure_ascii=False, indent=2) + '\n')
        raise AssertionError((case['problem'], index, 'see retained-failure.json'))
    counts[case['problem'] + '/' + case['kind']] += 1
report = dict(cases=dict(counts), total=len(cases),
              seconds=round(time.monotonic() - start, 3),
              source_sha256={p: hashlib.sha256((ROOT / (p + '.cpp')).read_bytes()).hexdigest()
                             for p in 'ABCDE'},
              case_sha256=hashlib.sha256(fixture.read_bytes()).hexdigest(),
              oracle_sources={'A': 'tests/first_all.py', 'B': 'tests/second_first.py',
                              'C': 'tests/third_first.py', 'D': 'tests/fourth_first.py',
                              'E': 'tests/fifth_extra.py'},
              repository='https://github.com/Code92007/csp/tree/4097b5ae124c402ce6b5c6f0804c4a6477c9560c',
              note='Current refactored sources; independent expected answers and saved samples. No online submission.')
(HERE / 'retained-report.json').write_text(json.dumps(report, indent=2) + '\n')
print(json.dumps(report), flush=True)
