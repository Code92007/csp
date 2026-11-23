"""Independent verification for the refactored CSP 202512 A/B.

Usage: python3 202512/reports/verify-ab.py --repo /path/to/website/repository
Compile A/B to .build/202512-prep/refactored; add corresponding -ubsan builds.
The --repo supplies retained independent oracles and saved samples only.
"""
from pathlib import Path
from collections import Counter
import argparse
import ast
import functools
import hashlib
import itertools
import json
import random
import subprocess
import time

ROOT=Path(__file__).resolve().parents[2]
OUT=Path(__file__).resolve().parent
BIN=ROOT/'.build/202512-prep/refactored'
SEED=92007202512
rng=random.Random(SEED)
parser=argparse.ArgumentParser()
parser.add_argument('--repo',type=Path,required=True)
args=parser.parse_args()
cases=[]
source_hash={c+'.cpp':hashlib.sha256((ROOT/'202512'/(c+'.cpp')).read_bytes()).hexdigest() for c in 'AB'}


def add(problem,kind,name,data,answer,sanitize=False):
    cases.append(dict(problem=problem,kind=kind,name=name,input=data,
                      output=str(answer),sanitize=sanitize))


# Reuse exactly the retained independent oracle loops, with explicit seeds.
for filename,problem,seed in [('first_all.py','A',9200701),('second_first.py','B',9200702)]:
    key='202512'+problem
    tree=ast.parse((args.repo/'tests'/filename).read_text())
    loops=[node for node in tree.body if isinstance(node,ast.For) and any(
        isinstance(x,ast.Constant) and x.value==key for x in ast.walk(node))]
    assert len(loops)==1
    count=[0]
    def case(k,data,out,tol=None):
        assert k==key and tol is None
        add(problem,'retained_independent',f'retained-{count[0]:03d}',data,out,True)
        count[0]+=1
    scope=dict(rng=random.Random(seed),case=case,functools=functools)
    exec(compile(ast.fix_missing_locations(ast.Module(body=loops,type_ignores=[])),
                 filename,'exec'),scope)
    for index,sample in enumerate(json.loads((args.repo/'tests'/('202512'+problem+'.json')).read_text())):
        add(problem,'saved_sample',f'sample-{index}',sample['input'],sample['output'],True)


def a_case(kind,name,values,left,right,sanitize=False):
    n,m=len(values),len(left)
    assert len(right)==m and 1<=n<=10000 and 1<=m<=100
    assert all(0<=x<2**31 for x in values)
    outputs=[]
    for s,t in zip(left,right):
        assert 1<=len(s)<=1000 and 1<=len(t)<=1000
        assert s==sorted(set(s)) and t==sorted(set(t))
        assert all(1<=x<=n for x in s+t)
        sx=functools.reduce(int.__xor__,(values[x-1] for x in s),0)
        tx=functools.reduce(int.__xor__,(values[x-1] for x in t),0)
        outputs.append('correct' if (set(s)==set(t))==(sx==tx) else 'wrong')
    lines=[f'{n} {m}',' '.join(map(str,values))]
    lines.extend(str(len(s))+' '+' '.join(map(str,s)) for s in left+right)
    add('A',kind,name,'\n'.join(lines)+'\n','\n'.join(outputs),sanitize)


# Every nonempty pair of subsets and every assignment in a tiny value domain.
for n in range(1,5):
    subsets=[[i+1 for i in range(n) if mask>>i&1] for mask in range(1,1<<n)]
    pairs=list(itertools.product(subsets,repeat=2))
    for index,values in enumerate(itertools.product(range(4),repeat=n)):
        for start in range(0,len(pairs),100):
            chunk=pairs[start:start+100]
            a_case('exhaustive_small',f'n{n}-a{index}-{start}',list(values),
                   [s for s,t in chunk],[t for s,t in chunk],index%23==0)

for index,values in enumerate([[0,0,0,0],[2**31-1]*4,
    [2**31-1,2**31-2,1,0],[1<<30,(1<<30)-1,2**31-1,0],
    [0,1,2,3],[1,2,4,7]]):
    subsets=[[i+1 for i in range(4) if mask>>i&1] for mask in range(1,16)]
    pairs=list(itertools.product(subsets,repeat=2))
    for start in range(0,len(pairs),100):
        chunk=pairs[start:start+100]
        a_case('value31_boundary',f'highbit-{index}-{start}',values,
               [s for s,t in chunk],[t for s,t in chunk],True)

for which in range(2):
    n,m=10000,100
    values=[0]*n if not which else [rng.randrange(2**31) for _ in range(n)]
    left=[sorted(rng.sample(range(1,n+1),1000)) for _ in range(m)]
    right=[]
    for i,s in enumerate(left):
        if i%4==0:t=s[:]
        elif i%4==1:t=s[:-1]
        elif i%4==2:
            t=sorted(s[:-1]+[next(x for x in range(n,0,-1) if x not in s)])
        else:t=sorted(rng.sample(range(1,n+1),1000))
        right.append(t)
    a_case('max_size',f'n10000-m100-size1000-{which}',values,left,right,True)


def reverse_value(value,keys):
    # Work backwards through the supplied keys; unlike the solution, never
    # enumerate a forward image and store an inverse table.
    for key in reversed(keys):
        high,middle,low=value//64,value//8%8,value%8
        b=high
        c=middle^(((b*b+key*key)%8)^key)
        a=low^(((c*c+key*key)%8)^key)
        value=64*a+8*b+c
    return value


def b_case(kind,name,keys,values,sanitize=False):
    assert 1<=len(keys)<=1000 and 1<=len(values)<=500000
    assert all(0<=x<8 for x in keys) and all(0<=x<512 for x in values)
    # This is just memoization of an independent backward oracle.
    table={x:reverse_value(x,keys) for x in set(values)}
    if len(table)==512:assert len(set(table.values()))==512
    answer=' '.join(str(table[x]) for x in values)
    data=f'{len(values)} {len(keys)}\n'+' '.join(map(str,keys))+'\n'+' '.join(map(str,values))+'\n'
    add('B',kind,name,data,answer,sanitize)


for length in [1,2,3]:
    for index,keys in enumerate(itertools.product(range(8),repeat=length)):
        b_case('exhaustive_short_keys',f'keys-{length}-{index}',list(keys),
               list(range(512)),index%19==0)

for key in range(8):
    b_case('thousand_repeated_keys',f'key{key}-m1000',[key]*1000,
           list(range(512)),True)
for length in [999,1000]:
    b_case('long_alternating_keys',f'alternating-{length}',
           [i%8 for i in range(length)],list(range(511,-1,-1)),True)
    b_case('long_random_keys',f'random-{length}',
           [rng.randrange(8) for _ in range(length)],list(range(512)),True)
keys=[(i*5+i//7)%8 for i in range(1000)]
values=[(i*137+i//512)%512 for i in range(500000)]
b_case('max_size','n500000-m1000',keys,values,True)

seen=set()
unique=[]
for case in cases:
    marker=(case['problem'],case['input'])
    if marker not in seen:
        seen.add(marker)
        unique.append(case)
cases=unique


def run(suffix,selected):
    start=time.monotonic()
    counts=Counter()
    for index,case in enumerate(selected):
        binary=BIN/(case['problem']+suffix)
        result=subprocess.run([str(binary)],input=case['input'],text=True,
                              capture_output=True,timeout=30)
        if result.returncode or result.stderr or result.stdout.split()!=case['output'].split():
            failure=dict(case,binary=binary.name,stdout=result.stdout,
                         stderr=result.stderr,returncode=result.returncode)
            (OUT/'ab-failure.json').write_text(json.dumps(failure,ensure_ascii=False,indent=2)+'\n')
            raise AssertionError((binary.name,index,case['name'],'see ab-failure.json'))
        counts[case['problem']+'/'+case['kind']]+=1
    return dict(binary_suffix=suffix or '(optimized)',inputs=len(selected),
                cases=dict(sorted(counts.items())),seconds=round(time.monotonic()-start,3))


results=[run('',cases),run('-ubsan',[c for c in cases if c['sanitize']])]
assert source_hash=={c+'.cpp':hashlib.sha256((ROOT/'202512'/(c+'.cpp')).read_bytes()).hexdigest() for c in 'AB'}
digest=hashlib.sha256()
for case in cases:
    digest.update(case['input'].encode())
    digest.update(b'\0')
    digest.update(case['output'].encode())
    digest.update(b'\0')
report=dict(problems='202512AB',seed=SEED,source_sha256=source_hash,
            oracle_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
            case_sha256=digest.hexdigest(),distinct_inputs=len(cases),results=results,
            source_ranges=dict(A='1<=n<=10000,1<=m<=100,0<=a_i<2^31,1<=set_size<=1000; nonempty strictly increasing sets.',
                               B='1<=n<=500000,1<=m<=1000,0<=key<8,0<=value<512.'),
            sources=['https://pcs2.roj.ac.cn/problems/shumeng/CSP202512A/',
                     'https://pcs2.roj.ac.cn/problems/shumeng/CSP202512B/'],
            oracle='Retained 60 A/30 B independent oracle loops and four saved samples. A compares actual Python sets and exact XOR; exhaustive tiny assignments/subset pairs and full-size inputs. B applies algebraic inverse rounds backwards for all 512 states; exhausts key sequences of lengths 1..3, long keys and maximum input.',
            compilation='Apple Clang C++17, -O2 -Wall -Wextra; additional -O1 -g -fsanitize=undefined -fno-sanitize-recover=all builds. No compiler warnings or sanitizer diagnostics.',
            note='Local validation only; no new online submission. Repeated sanitizer executions do not add distinct inputs.')
(OUT/'ab-report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False,indent=2))
