from pathlib import Path
import argparse,collections,hashlib,itertools,json,random,resource,subprocess,time,sys
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
rng=random.Random(20200624)
add('A','4 3\n-2 -1 A\n-3 2 A\n2 1 B\n3 -2 B\n0 1 0\n4 1 0\n0 0 1\n','Yes\nNo\nNo')
n=500000
add('B',f'1000000000 {n} {n}\n'+''.join(f'{i} 10000\n' for i in range(1,n+1))*2,n*10000**2,'constructive_stress')
rows=250000
add('C','80\n'+('a'*80+'\n')*rows,rows,'constructive_stress')
for z in range(180):
    steps=rng.randrange(21);text='1'
    for _ in range(steps):text=''.join({'1':'2','2':'4','4':'16','6':'64'}[c] for c in text)
    if rng.randrange(2) and text:
        pos=rng.randrange(len(text));pat=text[pos:pos+rng.randrange(1,12)]
    else:pat=''.join(rng.choices('1246',k=rng.randrange(1,12)))
    ans=sum(text.startswith(pat,i) for i in range(len(text)))
    add('D',f'{steps}\n{pat}\n',ans)
add('D','1000000000\n'+'1'*100000+'\n',0,'constructive_stress')
for z in range(200):
    n=rng.randrange(1,6);goods=[]
    for _ in range(n):
        l=rng.randrange(1,4);rr=l+rng.randrange(2,5);goods.append((l,rr,rng.randrange(-3,4),rng.randrange(-5,6),rng.randrange(-10,11)))
    rules=[(rng.randrange(1,3),*rng.sample(range(n),2)) for _ in range(rng.randrange(9))] if n>1 else []
    ans=0
    for xs in itertools.product(*[[None]+list(range(l,rr+1)) for l,rr,*_ in goods]):
        ok=True
        for kind,x,y in rules:
            trigger=xs[y] is not None and (kind==1 or xs[y] in goods[y][:2])
            if trigger and xs[x] is None:ok=False;break
        if not ok:continue
        value=sum(a*x*x+b*x+c for x,(l,rr,a,b,c) in zip(xs,goods) if x is not None)
        ans=max(ans,value)
    inp=f'{n} {len(rules)}\n'+''.join(' '.join(map(str,g))+'\n' for g in goods)+''.join(f'{kind} {x+1} {y+1}\n' for kind,x,y in rules)
    add('E',inp,ans)
n=10000
add('E',f'{n} {n-1}\n'+'1 3 0 0 1000\n'*n+''.join(f'1 {i} {i+1}\n' for i in range(1,n)),n*1000,'constructive_stress')
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
    independent_oracles='Direct signs and sparse dictionaries; explicit line-by-line Markdown rendering; literal simultaneous substitution and substring enumeration; exhaustive product purchase quantities with original dependency rules.',
    note='Historical accepted records belong to the original version; no online submission was made for this refactor.')
(P/'reports/report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False,indent=2))
