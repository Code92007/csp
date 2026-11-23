from pathlib import Path
import argparse,collections,hashlib,itertools,json,random,resource,subprocess,time,sys
from fractions import Fraction
P=Path(__file__).resolve().parents[1]
W=P.parent
ap=argparse.ArgumentParser();ap.add_argument('--repo',default='/tmp/csp-style-publish');args=ap.parse_args()
repo=Path(args.repo);d=P.name
from retained_oracles import collect
cases=collect(repo,d)
for c in 'ABCDE':
    for x in json.loads((repo/'tests'/f'{d}{c}.json').read_text()):
        cases.append(dict(problem=c,kind='saved_sample',**x))
def add(c,inp,out,kind='additional_independent',tol=None):
    cases.append(dict(problem=c,input=inp,output=str(out),kind=kind,abs_tol=tol))
rng=random.Random(20240324)
add('A','2 3\n4 1 1 1 1\n3 1 2 2\n','2 5\n1 2\n0 0')
add('B','5 5\nA a Ab AB z\naB Z zz ZZ a\n','3\n4')
n=500000
add('B',f'{n} {n}\n'+'Aa '*n+'\n'+'aA '*n+'\n','1\n1','constructive_stress')
def exactrank(a):
    a=[[Fraction(x) for x in row] for row in a];n=len(a);m=len(a[0]);r=0
    for c in range(m):
        p=next((i for i in range(r,n) if a[i][c]),None)
        if p is None:continue
        a[r],a[p]=a[p],a[r];v=a[r][c];a[r]=[x/v for x in a[r]]
        for i in range(r+1,n):
            v=a[i][c];a[i]=[x-v*y for x,y in zip(a[i],a[r])]
        r+=1
        if r==n:break
    return r
names=[chr(97+i) if i<26 else 'a'+chr(97+i-26) for i in range(40)]
def chem(a):
    return str(len(a[0]))+'\n'+'\n'.join(''.join(f'{names[i]}{a[i][j]}' for i in range(len(a)) if a[i][j]) for j in range(len(a[0])))
for z in range(160):
    n=rng.randrange(1,9);m=rng.randrange(1,9);a=[[rng.randrange(1,51) for _ in range(m)] for _ in range(n)]
    if z%3==0 and m>1:
        for row in a:row[-1]=row[0]
    add('C','1\n'+chem(a)+'\n','Y' if exactrank(a)<m else 'N')
a=[[int(i==j)*50 for j in range(40)] for i in range(40)]
b=[row[:] for row in a]
for row in b:row[-1]=row[0]
add('C','2\n'+chem(a)+'\n'+chem(b)+'\n','N\nY')
for z in range(200):
    m=rng.randrange(1,30);coords=sorted(rng.sample(range(1,200),m));water={x:rng.randrange(1,5) for x in coords};initial=water.copy();ops=[];out=[]
    for j in range(4*m):
        if not water:break
        x=rng.choice(list(water));ops.append(x);water[x]+=1
        while any(v>=5 for v in water.values()):
            x=min(x for x,v in water.items() if v>=5);xs=sorted(water);i=xs.index(x)
            del water[x]
            if i:water[xs[i-1]]+=1
            if i+1<len(xs):water[xs[i+1]]+=1
        out.append(len(water))
    data=f'200 {m} {len(ops)}\n'+''.join(f'{x} {v}\n' for x,v in initial.items())+'\n'.join(map(str,ops))+'\n'
    add('D',data,'\n'.join(map(str,out)))
parents={}
for z in range(160):
    n=rng.randrange(1,20);par=[-1]+[rng.randrange(i) for i in range(1,n)];val=[rng.randrange(1,1000000001) for _ in range(n)];init=val[:];parents[z]=par[:];live=set(range(n));ops=[];out=[]
    for j in range(60):
        u=rng.choice(sorted(live))
        if rng.randrange(2):
            ops.append((2,u));depth=0;x=u
            while x>=0:depth+=1;x=par[x]
            out.append(str(depth))
        else:
            ops.append((1,u));children=[v for v in live if par[v]==u]
            for v in children:
                val[u]+=val[v];live.remove(v)
                for w in live:
                    if par[w]==v:par[w]=u
            out.append(f'{sum(par[v]==u for v in live)} {val[u]}')
    # Recover original parent list with the deterministic construction RNG snapshot
    # by storing it before mutations below (assigned immediately in generation).
    original=parents[z]
    data=f'{n} {len(ops)}\n'+' '.join(str(x+1) for x in original[1:])+'\n'+' '.join(map(str,init))+'\n'+''.join(f'{op} {u+1}\n' for op,u in ops)
    add('E',data,'\n'.join(out))
n=500000
add('E',f'{n} 4\n'+'1 '*(n-1)+'\n'+'1000000000 '*n+'\n1 1\n2 1\n1 1\n2 1\n',f'0 {n*10**9}\n1\n0 {n*10**9}\n1','constructive_stress')
# An exact duplicate does not count twice, regardless of its source category.
uniq={}
for c in cases:
    k=(c['problem'],c['input']);old=uniq.get(k)
    if old and old['output'].split()!=c['output'].split():
        # Printed float precision in saved fixtures may differ.
        assert c.get('abs_tol') or old.get('abs_tol'),k
    uniq[k]=c
cases=list(uniq.values())
build=W/'.build'/f'{d}-prep';compilelog={};results=[]
for mode,flags in [('refactored',['-O2']),('ubsan',['-O1','-g','-fsanitize=undefined','-fno-sanitize-recover=all'])]:
    (build/mode).mkdir(parents=True,exist_ok=True)
    for p in 'ABCDE':
        cmd=['clang++','-std=c++17','-Wall','-Wextra','-I/tmp/csp202609-check/include',*flags,str(P/f'{p}.cpp'),'-o',str(build/mode/p)]
        r=subprocess.run(cmd,text=True,capture_output=True);assert r.returncode==0,r.stderr
        assert not r.stderr,r.stderr
        compilelog[f'{mode}/{p}']='passed without diagnostics'
    counts=collections.Counter();start=time.monotonic()
    for c in cases:
        # UBSan covers all small cases, including full exhaustive families.
        if mode=='ubsan' and c['kind']=='constructive_stress':continue
        p=c['problem'];begin=time.monotonic()
        r=subprocess.run([str(build/mode/p)],input=c['input'],text=True,capture_output=True,timeout=90)
        got=r.stdout.split();want=c['output'].split();tol=c.get('abs_tol')
        ok=len(got)==len(want) and (all(abs(float(x)-float(y))<=tol for x,y in zip(got,want)) if tol else got==want)
        if r.returncode or r.stderr or not ok:
            (P/'reports/failure.json').write_text(json.dumps(dict(case=c,mode=mode,stdout=r.stdout,stderr=r.stderr),ensure_ascii=False,indent=2))
            raise AssertionError((p,c['kind'],r.returncode,r.stdout[:200],r.stderr))
        counts[p]+=1
        if c['kind']=='constructive_stress':results.append(dict(problem=p,kind=c['kind'],seconds=time.monotonic()-begin))
    results.append(dict(mode=mode,cases=dict(counts),total=sum(counts.values()),seconds=time.monotonic()-start))
report=dict(contest=d,source_sha256={p:hashlib.sha256((P/f'{p}.cpp').read_bytes()).hexdigest() for p in 'ABCDE'},
    different_inputs=len(cases),categories=dict(collections.Counter(c['kind'] for c in cases)),compilation=compilelog,runs=results,
    independent_oracles='Per-article sets, normalized string sets, exact rational matrix rank, literal water dictionary/minimum explosion simulation, explicit live-parent folder merging.',
    note='Historical accepted records belong to the original version; no online submission was made for this refactor.')
(P/'reports/report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False,indent=2))
