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
    ok = process.stdout.rstrip('\n') == str(expected).rstrip('\n') if key in {'202512C', '202509C', '201703C', '201509C', '202409C', '202303C', '202305C', '201409C', '202506C', '201604C', '201512C'} else got == want
    if tolerance is not None:
        ok = len(got) == len(want) and all(abs(float(a)-float(b)) <= tolerance for a,b in zip(got,want))
    if process.returncode or not ok:
        (ROOT/'first-failure.json').write_text(json.dumps(dict(problem=key,input=data,expected=str(expected),got=process.stdout,stderr=process.stderr),ensure_ascii=False,indent=2))
        raise AssertionError(key + ': differential check failed; see tests/first-failure.json')
def case(key, data, expected):
    check(key,data,expected)
    report[key]=report.get(key,0)+1

def binary(key): return PROJECT / ".build" / key[:6] / key[-1]
