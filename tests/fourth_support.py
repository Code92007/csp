from pathlib import Path
import random, subprocess, json, re, functools, itertools, collections, sys, math, heapq
ROOT = Path(__file__).resolve().parent
PROJECT = ROOT.parent
rng = random.Random(9200704)
report = {}
def check(key, data, expected, tolerance=None):
    binary = PROJECT / '.build' / key[:6] / key[-1]
    process = subprocess.run([str(binary)], input=data, text=True, capture_output=True, timeout=30)
    got, want = process.stdout.split(), str(expected).split()
    ok = got == want
    if tolerance is not None:
        ok = len(got) == len(want) and all(abs(float(a)-float(b)) <= tolerance for a,b in zip(got,want))
    if process.returncode or not ok:
        (ROOT/'fourth-failure.json').write_text(json.dumps(dict(problem=key,input=data,expected=str(expected),got=process.stdout,stderr=process.stderr),ensure_ascii=False,indent=2))
        raise AssertionError(key + ': differential check failed; see tests/fourth-failure.json')
def case(key, data, expected):
    check(key,data,expected)
    report[key]=report.get(key,0)+1
