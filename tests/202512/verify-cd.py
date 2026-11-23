"""Independent forward-image and literal-tuple checks for CSP 202512 C/D."""
from pathlib import Path
from collections import Counter
import argparse
import ast
import hashlib
import json
import random
import string
import subprocess
import sys
import time

ROOT=Path(__file__).resolve().parents[2]
OUT=Path(__file__).resolve().parent
BIN=ROOT/'.build/202512-prep/refactored'
SEED=9200720251203
rng=random.Random(SEED)
parser=argparse.ArgumentParser()
parser.add_argument('--repo',type=Path,required=True)
args=parser.parse_args()
cases=[]
source_hash={p:hashlib.sha256((ROOT/'202512'/f'{p}.cpp').read_bytes()).hexdigest() for p in 'CD'}


def add(problem,kind,name,data,answer,sanitize=True):
    cases.append(dict(problem=problem,kind=kind,name=name,input=data,
                      output=str(answer),sanitize=sanitize))


# Saved cases precede retained random loops so their identities survive deduplication.
for problem in 'CD':
    for index,case in enumerate(json.loads((args.repo/'tests'/f'202512{problem}.json').read_text())):
        add(problem,'saved_sample',f'saved-{index}',case['input'],case['output'])


def cw(a):
    return [list(row) for row in zip(*a[::-1])]


for filename,problem,seed in [('third_first.py','C',9200703),('fourth_first.py','D',9200704)]:
    tree=ast.parse((args.repo/'tests'/filename).read_text())
    loops=[node for node in ast.walk(tree) if isinstance(node,ast.For) and any(
        isinstance(x,ast.Constant) and x.value=='202512'+problem for x in ast.walk(node))]
    # Select the innermost loop enclosing the case call; D's nested op loop must
    # retain its enclosing b enumeration and cumulative totals.
    if problem=='D':
        loops=[node for node in loops if isinstance(node.target,ast.Name) and node.target.id=='b']
    assert len(loops)==1,(filename,len(loops))
    number=[0]
    def case(key,data,answer,tol=None):
        assert key=='202512'+problem and tol is None
        add(problem,'retained_independent',f'retained-{number[0]:03d}',data,answer)
        number[0]+=1
    scope=dict(rng=random.Random(seed),case=case,cw=cw,total=[0,0])
    exec(compile(ast.fix_missing_locations(ast.Module(body=loops,type_ignores=[])),
                 filename,'exec'),scope)


def original_image(n,m):
    chars=string.ascii_letters+string.digits+'_'
    return [''.join(chars[(i*37+j*11+i*j)%len(chars)] for j in range(m)) for i in range(n)]


def image_input(z,image,operations):
    assert 1<=z<=400 and 1<=len(operations)<=50000
    return str(z)+'\n'+'\n'.join(''.join(row) for row in image)+'\n'+str(6*len(operations)+1)+'\n'+str(len(operations))+' '+' '.join(str(x) for op in operations for x in op)+'\n'


def c_case(z,n,m,operations,kind,name):
    original=original_image(n,m)
    image=[list(row+'?'*(z-m)) for row in original]+[list('?'*z) for _ in range(z-n)]
    for op in operations:
        if op[0]==1:
            _,u,v,size,angle,whole=op
            assert 1<=size<=min(z,10) and angle in [90,180,270] and 0<=whole<=3
            u-=1
            v-=1
            assert 0<=u<=z-size and 0<=v<=z-size
            part=[row[v:v+size] for row in image[u:u+size]]
            for _ in range(angle//90):
                part=cw(part)
            for i,row in enumerate(part):
                image[u+i][v:v+size]=row
            for _ in range(whole):
                # Physical counterclockwise whole-image rotation; no lazy view.
                image=[list(row) for row in zip(*image)][::-1]
        else:
            _,u,d,l,r,flip=op
            assert 1<=u<=d<=z and 1<=l<=r<=z and flip in [-1,1]
            assert d-u+1<=10 and r-l+1<=10
            u-=1
            l-=1
            part=[row[l:r] for row in image[u:d]]
            part=part[::-1] if flip==1 else [row[::-1] for row in part]
            for i,row in enumerate(part):
                image[u+i][l:r]=row
    add('C',kind,name,image_input(z,image,operations),f'{n} {m}\n'+'\n'.join(original))


for z in range(1,6):
    n=max(1,z-1)
    m=z
    for size in range(1,min(z,3)+1):
        for u in range(1,z-size+2):
            for v in range(1,z-size+2):
                for angle in [90,180,270]:
                    for whole in range(4):
                        c_case(z,n,m,[(1,u,v,size,angle,whole)],'all_small_rotations',
                               f'z{z}-u{u}-v{v}-size{size}-angle{angle}-whole{whole}')
    for height in range(1,min(z,3)+1):
        for width in range(1,min(z,3)+1):
            for u in range(1,z-height+2):
                for l in range(1,z-width+2):
                    for flip in [-1,1]:
                        c_case(z,n,m,[(2,u,u+height-1,l,l+width-1,flip)],'all_small_flips',
                               f'z{z}-u{u}-l{l}-h{height}-w{width}-flip{flip}')

for index in range(300):
    z=rng.randrange(1,15)
    n=rng.randrange(1,z+1)
    m=rng.randrange(1,z+1)
    operations=[]
    for j in range(rng.randrange(1,81)):
        if rng.randrange(2):
            size=rng.randrange(1,min(z,10)+1)
            operations.append((1,rng.randrange(1,z-size+2),rng.randrange(1,z-size+2),
                               size,rng.choice([90,180,270]),rng.randrange(4)))
        else:
            h=rng.randrange(1,min(z,10)+1)
            w=rng.randrange(1,min(z,10)+1)
            u=rng.randrange(1,z-h+2)
            l=rng.randrange(1,z-w+2)
            operations.append((2,u,u+h-1,l,l+w-1,rng.choice([-1,1])))
    c_case(z,n,m,operations,'mixed_forward_random',f'random-{index:03d}')


# At maximum size, legal operation blocks provably compose to the identity.
# This gives an independent exact answer without doing O(t*z*z) oracle work.
for n,m in [(400,400),(397,389)]:
    z=400
    operations=[]
    for j in range(15000):
        size=j%10+1
        u=1 if j%2 else z-size+1
        v=1 if j%3 else z-size+1
        angle=90*(j%3+1)
        whole=j%4
        operations.extend([(1,u,v,size,angle,whole),
                           (1,1,1,1,90,(-whole)%4),
                           (1,u,v,size,360-angle,0)])
    for j in range(2500):
        h=j%10+1
        w=j//10%10+1
        u=1 if j%2 else z-h+1
        l=1 if j%3 else z-w+1
        op=(2,u,u+h-1,l,l+w-1,1 if j%2 else -1)
        operations.extend([op,op])
    assert len(operations)==50000
    original=original_image(n,m)
    image=[list(row+'?'*(z-m)) for row in original]+[list('?'*z) for _ in range(z-n)]
    add('C','max_size_identity',f'z400-n{n}-m{m}-t50000',image_input(z,image,operations),
        f'{n} {m}\n'+'\n'.join(original))


def divisors_square(b):
    # Trial divide b, then generate divisors of b*b. No local weighted functions.
    factors=[]
    remaining=b
    p=2
    while p*p<=remaining:
        if remaining%p==0:
            e=0
            while remaining%p==0:
                remaining//=p
                e+=1
            factors.append((p,2*e))
        p+=1
    if remaining>1:factors.append((remaining,2))
    result=[1]
    for p,e in factors:
        previous=result[:]
        power=1
        for _ in range(e):
            power*=p
            result.extend(x*power for x in previous)
    return sorted(result)


limit=5000
prefix=[[0]*(limit+1) for _ in range(2)]
for b in range(1,limit+1):
    values=divisors_square(b)
    b2=b*b
    b3=b2*b
    total=perfect=0
    for c in values:
        for e in values:
            product=c*e
            if product>b3:break
            if b3%product:continue
            a=b2//c
            g=b2//e
            d=b3//product
            assert a*c==b2 and e*g==b2 and a*b*c==c*d*e==e*b*g
            total+=d
            # Literal seven-position set cardinality, independent of inclusion-exclusion.
            if len({a,b,c,d,e,b,g})==6:perfect+=d
    prefix[0][b]=(prefix[0][b-1]+total)%998244353
    prefix[1][b]=(prefix[1][b-1]+perfect)%998244353

numbers=set(range(1,161))
numbers.update([255,256,257,511,512,513,1023,1024,1025,2047,2048,2049,
                3125,4095,4096,4097,4999,5000])
numbers.update(rng.randrange(161,limit+1) for _ in range(150))
for n in sorted(numbers):
    for op in [0,1]:
        add('D','literal_tuple_oracle',f'op{op}-n{n}',f'{op} {n}\n',prefix[op][n])

unique=[]
seen=set()
for case in cases:
    key=(case['problem'],case['input'])
    if key not in seen:
        seen.add(key)
        unique.append(case)
cases=unique
print(f'Generated {len(cases)} distinct independent inputs.',flush=True)


def run(suffix,selected):
    start=time.monotonic()
    counts=Counter()
    for i,case in enumerate(selected):
        binary=BIN/(case['problem']+suffix)
        p=subprocess.run([str(binary)],input=case['input'],text=True,
                         capture_output=True,timeout=30)
        exact=case['problem']=='C'
        passed=(p.stdout.rstrip('\n')==case['output'].rstrip('\n')) if exact else (p.stdout.split()==case['output'].split())
        if p.returncode or p.stderr or not passed:
            failure=dict(case,binary=binary.name,index=i,stdout=p.stdout,stderr=p.stderr,returncode=p.returncode)
            (OUT/'cd-failure.json').write_text(json.dumps(failure,ensure_ascii=False,indent=2)+'\n')
            raise AssertionError((binary.name,i,case['name'],'see cd-failure.json'))
        counts[case['problem']+'/'+case['kind']]+=1
    return dict(binary_suffix=suffix or '(optimized)',inputs=len(selected),
                cases=dict(sorted(counts.items())),seconds=round(time.monotonic()-start,3))


results=[run('',cases)]
print('Optimized independent checks passed.',flush=True)
results.append(run('-ubsan',[c for c in cases if c['sanitize']]))
print('UBSan independent checks passed.',flush=True)
stress=[]
worker='''import json,resource,subprocess,sys
p=subprocess.run([sys.argv[1]],input=sys.stdin.read(),text=True,capture_output=True)
rss=resource.getrusage(resource.RUSAGE_CHILDREN).ru_maxrss
print(json.dumps(dict(returncode=p.returncode,stdout=p.stdout,stderr=p.stderr,
                     peak_rss_bytes=rss if sys.platform=="darwin" else rss*1024)))
'''
for op in [0,1]:
    data=f'{op} 10000000\n'
    original=subprocess.run([str(ROOT/'.build/202512-prep/original/D')],input=data,
                            text=True,capture_output=True,timeout=60)
    assert original.returncode==0 and not original.stderr
    for suffix in ['', '-ubsan']:
        start=time.monotonic()
        # A fresh wrapper has exactly one child, so RUSAGE_CHILDREN gives this
        # binary's actual peak RSS without privileged system-information calls.
        p=subprocess.run([sys.executable,'-c',worker,str(BIN/('D'+suffix))],input=data,
                         text=True,capture_output=True,timeout=60)
        assert p.returncode==0 and not p.stderr,(op,suffix,p.stderr)
        measured=json.loads(p.stdout)
        assert measured['returncode']==0 and not measured['stderr'] and measured['stdout'].split()==original.stdout.split(),(op,suffix,measured)
        stress.append(dict(problem='D',op=op,n=10000000,binary='D'+suffix,
                           seconds=round(time.monotonic()-start,3),peak_rss_bytes=measured['peak_rss_bytes'],
                           output=measured['stdout'].strip(),reference='Original source compatibility check; independent literal oracle covers n<=5000.'))

assert source_hash=={p:hashlib.sha256((ROOT/'202512'/f'{p}.cpp').read_bytes()).hexdigest() for p in 'CD'}
digest=hashlib.sha256()
for case in cases:
    digest.update(case['input'].encode())
    digest.update(b'\0')
    digest.update(case['output'].encode())
    digest.update(b'\0')
report=dict(problems='202512CD',seed=SEED,source_sha256=source_hash,
            script_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
            original_source_sha256={p:hashlib.sha256((args.repo/'202512'/f'{p}.cpp').read_bytes()).hexdigest() for p in 'CD'},
            case_sha256=digest.hexdigest(),distinct_independent_inputs=len(cases),
            results=results,stress=stress,literal_tuple_prefix_limit=limit,
            source_ranges={'C':'1<=z<=400,1<=t<=50000,key_length=6*t+1; local dimensions<=10; rotations90/180/270 and whole turns0..3; flips1/-1.',
                           'D':'op in {0,1},1<=n<=10000000; modulus998244353.'},
            oracles={'C':'Physical forward encryption of copied grids; exhaustive small rotation/flip parameters, mixed operations, and provably identity operation blocks for maximum-size cases.',
                     'D':'Enumerate divisors C,E of b*b, retain literal positive integral seven-tuples satisfying all equations, directly test seven-value set cardinality. No weighted local-function/inclusion-exclusion oracle.'},
            compilation='Apple Clang C++17 -O2 -Wall -Wextra -Wshadow; additional -O1 -g -fsanitize=undefined -fno-sanitize-recover=all builds. No warnings.',
            note='Local checks only; no new online submission. Maximum-n D runs are source-compatibility/performance checks, not independent brute force. Repeated sanitizer runs are not additional distinct inputs.')
(OUT/'cd-report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False,indent=2))
