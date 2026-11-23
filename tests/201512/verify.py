from pathlib import Path
import argparse,collections,hashlib,itertools,json,random,resource,subprocess,time,sys,functools
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
rng=random.Random(20151224)
for num in [0,1,9,10,99,1000000000]:add('A',str(num)+'\n',sum(map(int,str(num))))
for flat in itertools.product([1,2],repeat=9):
    a=[list(flat[i:i+3]) for i in range(0,9,3)];erase=set()
    for i in range(3):
        if len(set(a[i]))==1:erase.update((i,j) for j in range(3))
    for j in range(3):
        if len({a[i][j] for i in range(3)})==1:erase.update((i,j) for i in range(3))
    out='\n'.join(' '.join(str(0 if (i,j) in erase else a[i][j]) for j in range(3)) for i in range(3))
    add('B','3 3\n'+'\n'.join(' '.join(map(str,row)) for row in a)+'\n',out)
add('C','5 5 6\n0 2 0 2 4\n1 0 0 A\n1 0 4 A\n1 4 0 B\n1 4 4 B\n0 0 2 4 2\n','AA|BB\nAA|BB\n--+--\nAA|BB\nAA|BB')
for n0 in range(2,6):
    possible=list(itertools.combinations(range(n0),2))
    masks=list(range(1,1<<len(possible))) if n0<5 else rng.sample(range(1,1<<len(possible)),100)
    for mask0 in masks:
        edges=[e for i,e in enumerate(possible) if mask0>>i&1]
        @functools.lru_cache(None)
        def go(u,mask):
            if mask==(1<<len(edges))-1:return (u,)
            paths=[]
            for i,(v,w) in enumerate(edges):
                if mask>>i&1 or u not in (v,w):continue
                nxt=w if u==v else v;rest=go(nxt,mask|1<<i)
                if rest:paths.append((u,)+rest)
            return min(paths) if paths else None
        ans=go(0,0);out='-1' if ans is None else ' '.join(str(x+1) for x in ans)
        add('D',f'{n0} {len(edges)}\n'+''.join(f'{u+1} {v+1}\n' for u,v in edges),out)
def mul(a,b):
    out=[]
    for row in a:
        z=0
        for j in range(len(a)):
            if row>>j&1:z^=b[j]
        out.append(z)
    return out
for z in range(150):
    n0=rng.randrange(1,14);a=[rng.randrange(1<<n0) for _ in range(n0)];vec=rng.randrange(1<<n0);queries=[0,1,2,10**9]+[rng.randrange(10000) for _ in range(6)];out=[]
    for k0 in queries:
        cur=vec;mat=a[:];exp=k0
        while exp:
            if exp&1:cur=sum((bin(row&cur).count("1")%2)<<i for i,row in enumerate(mat))
            mat=mul(mat,mat);exp>>=1
        out.append(''.join(str(cur>>i&1) for i in range(n0)))
    fmt=lambda x:''.join(str(x>>i&1) for i in range(n0))
    inp=str(n0)+'\n'+'\n'.join(map(fmt,a))+'\n'+fmt(vec)+'\n'+str(len(queries))+'\n'+'\n'.join(map(str,queries))+'\n'
    add('E',inp,'\n'.join(out))
n0=1000;queries=[0,1,999,1000,10**9]
a=[''.join('1' if j==(i-1)%n0 else '0' for j in range(n0)) for i in range(n0)]
vec='1'+'0'*(n0-1)
out=[''.join('1' if i==k0%n0 else '0' for i in range(n0)) for k0 in queries]
add('E',str(n0)+'\n'+'\n'.join(a)+'\n'+vec+'\n'+str(len(queries))+'\n'+'\n'.join(map(str,queries))+'\n','\n'.join(out),'constructive_stress')
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
    independent_oracles='Digit strings, maximal equal-color runs before simultaneous elimination, literal canvas simulation, exhaustive edge-mask Euler trail search, direct GF(2) matrix exponentiation independent of Krylov polynomials.',
    note='Historical accepted records belong to the original version; no online submission was made for this refactor.')
(P/'reports/report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False,indent=2))
