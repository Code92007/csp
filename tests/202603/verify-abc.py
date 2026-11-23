"""Additional independent boundaries for 202603 A/B/C (Python 3, no packages).

Compile each solution to .build/202603-prep/refactored/{A,B,C}, and compile
{A,B,C}-ubsan with -fsanitize=undefined -fno-sanitize-recover=all.
Run this file from any directory. It never runs the retained baseline cases.
"""
from pathlib import Path
from fractions import Fraction
from collections import Counter
import hashlib
import itertools
import json
import random
import subprocess
import time

ROOT=Path(__file__).resolve().parents[2]
OUT=Path(__file__).resolve().parent
BIN=ROOT/'.build/202603-prep/refactored'
SEED=92007202603
rng=random.Random(SEED)
cases=[]


def add(problem,kind,name,data,answer,ubsan=False):
    cases.append(dict(problem=problem,kind=kind,name=name,input=data,
                      answer=answer,ubsan=ubsan))


def a_case(kind,name,values,ubsan=False):
    # Literal effective binary strings, independent of shifting/popcount code.
    expected=sum(bin(x)[2:].count('0')==bin(x)[2:].count('1') for x in values)
    add('A',kind,name,f'{len(values)}\n'+' '.join(map(str,values))+'\n',
        str(expected),ubsan)


# Exhaust every positive value with at most 16 effective bits, in small inputs.
for start in range(1,1<<16,100):
    a_case('exhaustive_16bit',f'block-{start:05d}',
           list(range(start,min(start+100,1<<16))),start%1300==1)

edges={1,10**9}
for bits in range(1,30):
    edges.update(x for x in [(1<<bits)-1,1<<bits,(1<<bits)+1]
                 if 1<=x<=10**9)
for bits in range(2,31,2):
    # Three distinct balanced layouts at every permitted even effective length.
    for text in ['10'*(bits//2),'1'*(bits//2)+'0'*(bits//2),
                 '1'+'0'*(bits//2)+'1'*(bits//2-1)]:
        value=int(text,2)
        if value<=10**9:
            edges.update(x for x in [value-1,value,value+1] if 1<=x<=10**9)
for i,x in enumerate(sorted(edges)):
    a_case('binary_boundary',f'value-{x}',[x],i%7==0)
a_case('upper_bound_repeated','one-billion',[10**9]*100,True)


def b_oracle(tasks,m):
    """Enumerate vertices of each fractional box after fixing a 0/1 subset.

    All integral items are 0/full. At a fractional-knapsack polytope vertex,
    all but at most one flexible item are 0/full. Enumerate those choices,
    without sorting by efficiency, unit expansion, or a knapsack recurrence.
    """
    n=len(tasks)
    best=Fraction(0)
    for mask in range(1<<n):
        cost=sum(tasks[i][2] for i in range(n) if mask>>i&1)
        if cost>m:
            continue
        gain=Fraction(sum(tasks[i][3] for i in range(n) if mask>>i&1))
        best=max(best,gain)
        for i,(op,t,x,y) in enumerate(tasks):
            if not op and not (mask>>i&1):
                best=max(best,gain+Fraction(min(m-cost,x)*y,x))
    return Fraction(sum(x[1] for x in tasks))-best


def b_case(kind,name,tasks,m,ubsan=False,answer=None):
    assert 1<=len(tasks)<=200 and 1<=m<=1000
    assert all(op in (0,1) and 1<=x<=100 and 0<y<t<=10000 for op,t,x,y in tasks)
    expected=b_oracle(tasks,m) if answer is None else Fraction(answer)
    data=f'{len(tasks)} {m}\n'+''.join(' '.join(map(str,x))+'\n' for x in tasks)
    add('B',kind,name,data,expected,ubsan)


# One indivisible item must not be reused; exact, just-too-small, surplus budget.
for cost in [1,2,3,7,31,97,100]:
    for m in sorted({1,max(1,cost-1),cost,min(1000,cost+1)}):
        b_case('indivisible_threshold',f'one-{cost}-{m}',[(1,50,cost,31)],m,True)

for m in [1,2,3,4,5,6,7,8,9,10,11,12,15,20,30,1000]:
    b_case('mixed_boundary',f'competing-{m}',
           [(1,40,3,11),(1,40,4,15),(0,40,7,23),(0,40,5,17)],m,m%3==0)
    b_case('equal_ratio',f'equal-{m}',
           [(0,40,3,6),(0,40,6,12),(0,40,7,14),(1,40,4,9)],m,m%3==1)
    b_case('all_flexible',f'fraction-{m}',
           [(0,40,7,13),(0,40,11,19),(0,40,13,23)],m,m%3==2)

for i in range(240):
    n=rng.randint(1,9)
    m=rng.randint(1,35)
    tasks=[]
    for j in range(n):
        op=rng.randrange(2)
        x=rng.choice([1,2,3,7,11,13,31,rng.randint(1,40)])
        y=rng.randint(1,80)
        tasks.append((op,y+rng.randint(1,80),x,y))
    b_case('fraction_vertex_random',f'random-{i:03d}',tasks,m,i%11==0)

# Max n,m with a simple exact envelope; many equal densities and unused budget.
for op in [0,1]:
    tasks=[(op,1000,7,14)]*200
    b_case('max_n_budget',f'max-{op}',tasks,1000,True,
           answer=200000-(2000 if op==0 else (1000//7)*14))
# A coprime denominator near the item-cost limit, with cancellation against total.
b_case('coprime_fraction','denominator-97',[(0,1000,97,91)],49,True)


# Item/time limits and ratios that differ by very small rational amounts.
for op in [0,1]:
    for m in [999,1000]:
        benefit=Fraction(m*9999,100) if not op else (m//100)*9999
        b_case('max_item_time',f'limit-{op}-{m}',[(op,10000,100,9999)]*200,
               m,True,answer=2000000-benefit)
for i in range(50):
    tasks=[(rng.randrange(2),10000,rng.choice([96,97,99,100]),
            rng.choice([9991,9997,9999])) for _ in range(rng.randint(2,9))]
    b_case('close_ratio_fraction',f'close-{i:02d}',tasks,rng.randint(1,1000),i%9==0)


class MemoryOracle:
    """Reconstruct free segments from occupied queues on every allocation.

    There is no free-list index, explicit tail, merge, or best-fit set.
    Optional byte simulation cross-checks this oracle for small sequences.
    """
    def __init__(self,n,bitmap=False):
        self.queues=[[] for _ in range(n)]
        self.ops=[]
        self.out=[]
        self.bitmap=[] if bitmap else None
        self.allocations=[]
        self.send_max=0

    def new(self,p,length):
        occupied=sorted((l,l+size) for queues in self.queues for l,size,count in queues)
        free=[]
        last=0
        for left,right in occupied:
            assert left>=last
            if left>last:
                free.append((left-last,last))
            last=right
        suitable=[(size,left) for size,left in free if size>=length]
        start=min(suitable)[1] if suitable else last
        if self.bitmap is not None:
            holes=[]
            j=0
            while j<len(self.bitmap):
                if self.bitmap[j]:
                    j+=1
                    continue
                left=j
                while j<len(self.bitmap) and not self.bitmap[j]:
                    j+=1
                if j<len(self.bitmap) and j-left>=length:
                    holes.append((j-left,left))
            end=len(self.bitmap)
            while end and not self.bitmap[end-1]:
                end-=1
            expected=min(holes)[1] if holes else end
            assert start==expected,(start,expected,self.ops)
            if start+length>len(self.bitmap):
                self.bitmap.extend([False]*(start+length-len(self.bitmap)))
            assert not any(self.bitmap[start:start+length])
            self.bitmap[start:start+length]=[True]*length
        self.queues[p-1].append([start,length,0])
        self.ops.append(f'new {p} {length}')
        self.out.append(start)
        self.allocations.append(start)
        return start

    def send(self,p):
        value=0
        for queue in self.queues[p-1]:
            left,length,count=queue
            value+=left+count%length
            queue[2]+=1
        self.ops.append(f'send {p}')
        self.out.append(value)
        self.send_max=max(self.send_max,value)
        return value

    def delete(self,p,index):
        left,length,count=self.queues[p-1].pop(index-1)
        if self.bitmap is not None:
            assert all(self.bitmap[left:left+length])
            self.bitmap[left:left+length]=[False]*length
        self.ops.append(f'delete {p} {index}')

    def emit(self,kind,name,ubsan=False):
        assert 1<=len(self.ops)<=8000
        data=f'{len(self.queues)} {len(self.ops)}\n'+'\n'.join(self.ops)+'\n'
        add('C',kind,name,data,'\n'.join(map(str,self.out)),ubsan)


mem=MemoryOracle(8,True)
for p,length in [(1,9),(2,2),(3,9),(4,2),(5,5)]:mem.new(p,length)
mem.delete(1,1)
mem.delete(3,1)
assert mem.new(6,5)==0  # equal-size holes choose the leftmost
assert mem.new(6,4)==5  # exact smallest-fit remainder
mem.delete(6,1)
mem.delete(6,1)
assert mem.new(7,8)==0
for p in range(1,9):mem.send(p)
mem.emit('directed_best_fit','tie-and-split',True)

mem=MemoryOracle(8,True)
for p,length in enumerate([3,4,5,6,1],1):mem.new(p,length)
mem.delete(2,1)
mem.delete(4,1)
mem.delete(3,1)
assert mem.new(6,14)==3  # merge both neighbours into a 15-byte segment
assert mem.new(7,1)==17
mem.delete(1,1)
assert mem.new(8,3)==0
mem.delete(7,1)
mem.delete(5,1)
assert mem.new(1,2)==17  # right tail absorbs the preceding finite hole
mem.emit('directed_merge','both-neighbours-and-tail',True)

mem=MemoryOracle(4,True)
mem.new(1,5)
mem.new(1,4)
mem.new(2,3)
mem.delete(1,2)
mem.delete(2,1)
assert mem.new(3,7)==5
mem.delete(3,1)
mem.delete(1,1)
assert mem.new(4,2)==0
mem.emit('directed_tail','repeated-tail-shrink',True)

mem=MemoryOracle(2,True)
assert mem.send(1)==0
mem.new(1,2)
mem.new(1,3)
for _ in range(17):mem.send(1)
mem.delete(1,1)
for _ in range(11):mem.send(1)
mem.new(1,1)
for _ in range(13):mem.send(1)
mem.delete(1,1)
mem.delete(1,1)
assert mem.send(1)==0
mem.emit('directed_send','wrap-renumber-empty',True)

for i in range(220):
    n=rng.randint(1,12)
    mem=MemoryOracle(n,True)
    for j in range(rng.randint(80,400)):
        p=rng.randint(1,n)
        action=rng.randrange(10)
        if action<4 or not any(mem.queues):
            mem.new(p,rng.choice([1,1,2,3,4,7,8,13,17,31]))
        elif action<7:
            mem.send(p)
        else:
            active=[p for p in range(1,n+1) if mem.queues[p-1]]
            p=rng.choice(active)
            mem.delete(p,rng.randint(1,len(mem.queues[p-1])))
    mem.emit('bitmap_random',f'random-{i:03d}',i%13==0)

# Full q, legal L: addresses above signed int and send sums far above 32 bits.
mem=MemoryOracle(100)
for i in range(7900):mem.new(i%100+1,500000)
for p in range(1,101):mem.send(p)
assert max(mem.allocations)>2**31 and mem.send_max>2**31
mem.emit('max_q_address64','8000-operations-3950000000-tail',True)

mem=MemoryOracle(5)
for _ in range(4400):mem.new(1,500000)
for _ in range(800):mem.delete(1,2)
for _ in range(600):mem.new(2,499999)
for _ in range(50):mem.send(1)
for _ in range(600):mem.delete(2,1)
for _ in range(1000):mem.new(3,500000)
for p in range(1,6):mem.send(p)
assert len(mem.ops)==7455 and mem.send_max>2**31
mem.emit('fragmented_address64','large-hole-reuse-and-merge',True)

# Additional inputs only: de-duplicate and exclude the parent's existing set.
old=set()
retained=ROOT/'.build/202603-prep/cases.json'
if retained.exists():
    old={x['input'] for x in json.loads(retained.read_text())}
seen=set()
unique=[]
for case in cases:
    if case['input'] in seen or case['input'] in old:continue
    seen.add(case['input'])
    unique.append(case)
cases=unique

def run(binary,selected):
    start=time.monotonic()
    counts=Counter()
    max_error=Fraction(0)
    for index,case in enumerate(selected):
        exe=BIN/(case['problem']+binary)
        result=subprocess.run([str(exe)],input=case['input'],text=True,
                              capture_output=True,timeout=40)
        expected=case['answer']
        if case['problem']=='B':
            try:
                error=abs(Fraction(result.stdout.strip())-expected)
            except (ValueError,ZeroDivisionError):
                error=Fraction(10**100)
            max_error=max(max_error,error)
            ok=error<=Fraction(1,10**6)
        else:
            ok=result.stdout.split()==expected.split()
        if result.returncode or result.stderr or not ok:
            failure=dict(case,index=index,binary=exe.name,answer=str(expected),
                         stdout=result.stdout,stderr=result.stderr,
                         returncode=result.returncode)
            (OUT/'abc-failure.json').write_text(json.dumps(failure,ensure_ascii=False,indent=2)+'\n')
            raise AssertionError((exe.name,index,case['name'],'see abc-failure.json'))
        counts[case['problem']+'/'+case['kind']]+=1
    return dict(binary_suffix=binary or '(optimized)',distinct_inputs=len(selected),
                cases=dict(sorted(counts.items())),max_B_absolute_error=str(max_error),
                seconds=round(time.monotonic()-start,3))

results=[run('',cases),run('-ubsan',[c for c in cases if c['ubsan']])]
digest=hashlib.sha256()
for case in cases:
    digest.update(case['input'].encode())
    digest.update(b'\0')
    digest.update(str(case['answer']).encode())
    digest.update(b'\0')
report=dict(problems='202603ABC',seed=SEED,distinct_additional_inputs=len(cases),
            source_sha256={c+'.cpp':hashlib.sha256((ROOT/'202603'/(c+'.cpp')).read_bytes()).hexdigest() for c in 'ABC'},
            oracle_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
            case_sha256=digest.hexdigest(),results=results,
            scope=dict(A='Every positive value below 2^16, powers of two and balanced layouts through 10^9.',
                       B='Exact Fraction enumeration of 0/1 choices and fractional polytope vertices; integer budgets, ties, prime denominators, close efficiencies, n=200,m=1000,a<=100,b<t<=10000.',
                       C='Rebuild holes from occupied intervals, cross-checked by a byte bitmap on small cases; best-fit ties, merge, tail shrink, renumbering, send wrap; q=8000,L=500000, addresses/sums beyond signed 32-bit.'),
            note='These inputs are additional to the retained 420 independent cases and 10 saved samples. UBSan repeats a subset and is not counted as new inputs. Local validation only; no new online-judge submission.')
(OUT/'abc-boundary-report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False,indent=2))
