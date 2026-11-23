"""Independent per-element verification of 202603D, including digit boundaries."""
from pathlib import Path
from collections import Counter
import hashlib
import json
import random
import subprocess
import time

ROOT=Path(__file__).resolve().parents[2]
PREP=ROOT/'.build/202603-prep'
REPORT=Path(__file__).resolve().parent
LIMIT=10**12
SEED=92007202604
BASES=[11,13,15,21,25,27,81,99,999,1001,9999,10001,99999,
       999999,1000001,999999937,999999999]
rng=random.Random(SEED)
cases=[]


def digit_add(x,y,k):
    ans=0
    w=1
    while x or y:
        ans+=((x%k+y%k)%k)*w
        x//=k
        y//=k
        w*=k
    return ans


def prefix(x,k):
    # Count each digit in 0..x by complete blocks and the final incomplete block.
    # This does not use the solution's sums, cross products or update formulas.
    ans=0
    w=1
    while w<=x:
        full,rem=divmod(x+1,w*k)
        q,r=divmod(rem,w)
        total=full*w*k*(k-1)//2+w*q*(q-1)//2+q*r
        ans+=(total%k)*w
        w*=k
    return ans


def bounds(k):
    values={0,1,LIMIT-1,LIMIT}
    w=1
    while w<=LIMIT:
        values.update(v for v in (w-1,w,w+1) if 0<=v<=LIMIT)
        w*=k
    return sorted(values)


def small_case(name,k,a,operations):
    cur=a[:]
    out=[]
    for op in operations:
        if op[0]==1:
            _,l,r,v=op
            for i in range(l-1,r):
                cur[i]=digit_add(cur[i],v,k)
        else:
            _,l,r=op
            ans=0
            for x in cur[l-1:r]:
                ans=digit_add(ans,prefix(x,k),k)
            out.append(ans)
    data=f'{len(a)} {len(operations)} {k}\n'+' '.join(map(str,a))+'\n'
    data+=''.join(' '.join(map(str,op))+'\n' for op in operations)
    return dict(problem='D',kind='digit_boundary' if name.startswith('edge') else 'overlap_random',
                name=name,input=data,output='\n'.join(map(str,out)))


def repeated(x,count,k):
    ans=0
    w=1
    while x:
        ans+=(x%k*count%k)*w
        x//=k
        w*=k
    return ans


def uniform_case(k,q):
    n=500000
    x=LIMIT
    operations=[]
    out=[]
    values=bounds(k)
    for j in range(q):
        if j%2==0:
            v=values[(j//2)%len(values)]
            operations.append(f'1 1 {n} {v}')
            x=digit_add(x,v,k)
        else:
            l=rng.randrange(1,n+1)
            r=rng.randrange(l,n+1)
            if j%11==1:l,r=1,n
            operations.append(f'2 {l} {r}')
            out.append(repeated(prefix(x,k),r-l+1,k))
    data=f'{n} {q} {k}\n'+(str(LIMIT)+' ')*(n-1)+str(LIMIT)+'\n'
    data+='\n'.join(operations)+'\n'
    return dict(problem='D',kind='max_size_uniform',name=f'uniform-k{k}-n{n}-q{q}',
                input=data,output='\n'.join(map(str,out)))


# Check the counting oracle against the literal definition on small values.
literal_checks=0
for k in [11,15,21,99]:
    f=0
    for x in range(1500):
        if x:f=digit_add(f,x,k)
        assert prefix(x,k)==f,(x,k)
        literal_checks+=1

for k in BASES:
    values=bounds(k)
    for n in [1,2,3,7,8,9,31,33]:
        a=[values[i%len(values)] for i in range(n)]
        operations=[(2,1,n)]
        for j,v in enumerate(values):
            if j%4==0:l,r=1,n
            elif j%4==1:l,r=1,(n+1)//2
            elif j%4==2:l,r=(n+1)//2,n
            else:l,r=1+rng.randrange(n),n
            operations.append((1,l,r,v))
            operations.append((2,max(1,l-1),min(n,r+1)))
            operations.append((2,(n+1)//2,(n+1)//2))
        # Several full-cover shifts must combine before a point query pushes them.
        for _ in range(k if k<=99 else 9):
            operations.append((1,1,n,LIMIT))
        operations.extend([(2,1,1),(2,n,n),(2,1,n)])
        cases.append(small_case(f'edge-k{k}-n{n}',k,a,operations))

for index in range(200):
    k=rng.choice(BASES)
    n=rng.randrange(1,66)
    values=bounds(k)
    a=[rng.choice(values) if rng.randrange(2) else rng.randrange(LIMIT+1) for _ in range(n)]
    operations=[]
    for j in range(120):
        l=rng.randrange(1,n+1)
        r=rng.randrange(l,n+1)
        if j%7==0:l,r=1,n
        elif j%7==1:l=1
        elif j%7==2:r=n
        if j%3:
            v=rng.choice(values) if rng.randrange(2) else rng.randrange(LIMIT+1)
            operations.append((1,l,r,v))
        else:operations.append((2,l,r))
    operations.append((2,1,n))
    cases.append(small_case(f'random-{index:03d}',k,a,operations))

existing=[case for case in json.loads((PREP/'cases.json').read_text()) if case['problem']=='D']
for index,case in enumerate(existing):
    case['name']=f'existing-{index:03d}'
cases=existing+cases
cases.extend([uniform_case(11,10000),uniform_case(999999999,2000)])

summaries=[]
for binary in ['D','D-ubsan']:
    start=time.monotonic()
    counts=Counter()
    for index,case in enumerate(cases):
        p=subprocess.run([str(PREP/'refactored'/binary)],input=case['input'],text=True,
                         capture_output=True,timeout=60)
        if p.returncode or p.stderr or p.stdout.split()!=case['output'].split():
            failure=dict(case,index=index,binary=binary,stdout=p.stdout,
                         stderr=p.stderr,returncode=p.returncode)
            (REPORT/'d-failure.json').write_text(json.dumps(failure,ensure_ascii=False,indent=2)+'\n')
            raise AssertionError((binary,index,case['name'],'see d-failure.json'))
        counts[case['kind']]+=1
    summaries.append(dict(binary=binary,cases=dict(counts),total=len(cases),
                          seconds=round(time.monotonic()-start,3)))

digest=hashlib.sha256()
for case in cases:
    digest.update(case['input'].encode())
    digest.update(b'\0')
    digest.update(case['output'].encode())
    digest.update(b'\0')
report=dict(problem='202603D',seed=SEED,source_sha256=hashlib.sha256((ROOT/'202603/D.cpp').read_bytes()).hexdigest(),
            case_sha256=digest.hexdigest(),literal_oracle_checks=literal_checks,bases=BASES,
            results=summaries,
            oracle='Small cases simulate every element and count each f digit over 0..x by digit cycles; large uniform cases independently use repeated digit addition.',
            note='Local validation only. The refactored source has not been submitted to an online judge.')
(REPORT/'d-boundary-report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False,indent=2))
