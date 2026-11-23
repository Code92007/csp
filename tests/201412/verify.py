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
rng=random.Random(20141224)
add('A','1000\n'+'1000 '*1000+'\n',' '.join(map(str,range(1,1001))),'constructive_stress')
add('B','500\n'+'7 '*250000+'\n','7 '*250000,'constructive_stress')
def auction(lines):
    orders=[]
    for s in lines:
        x=s.split()
        if x[0]=='cancel':orders[int(x[1])-1]=None;orders.append(None)
        else:orders.append((x[0],int(x[1].replace('.','')),int(x[2])))
    orders=[o for o in orders if o];prices={o[1] for o in orders}
    if not prices:return '0.00 0'
    vol,p=max((min(sum(q for typ,z,q in orders if typ=='buy' and z>=p),sum(q for typ,z,q in orders if typ=='sell' and z<=p)),p) for p in prices)
    return f'{p//100}.{p%100:02d} {vol}'
for z in range(220):
    lines=[];active=[]
    for j in range(rng.randrange(1,20)):
        if active and rng.randrange(4)==0:
            i=rng.choice(active);active.remove(i);lines.append(f'cancel {i}')
        else:
            p0=rng.randrange(1,15);typ=rng.choice(['buy','sell']);q0=rng.randrange(1,10)
            lines.append(f'{typ} {p0//100}.{p0%100:02d} {q0}');active.append(j+1)
    add('C','\n'.join(lines)+'\n',auction(lines))
lines=['buy 100.00 100000000']*2500+['sell 99.00 100000000']*2500
add('C','\n'.join(lines)+'\n','100.00 250000000000','constructive_stress')
for z in range(150):
    n0=rng.randrange(2,7);es=[(i,rng.randrange(i),rng.randrange(1,20)) for i in range(1,n0)]
    possible=[(u,v) for u in range(n0) for v in range(u) if not any({u,v}=={x,y} for x,y,c0 in es)];rng.shuffle(possible)
    es += [(u,v,rng.randrange(1,20)) for u,v in possible[:rng.randrange(min(3,len(possible))+1)]]
    best=10**9
    for sub in itertools.combinations(es,n0-1):
        reach={0}
        for j in range(n0):
            for u,v,c0 in sub:
                if u in reach or v in reach:reach.update([u,v])
        if len(reach)==n0:best=min(best,sum(e[2] for e in sub))
    add('D',f'{n0} {len(es)}\n'+''.join(f'{u+1} {v+1} {c0}\n' for u,v,c0 in es),best)
es=list(itertools.combinations(range(1,1001),2));rng.shuffle(es);es=es[:100000]
add('D','1000 100000\n'+''.join(f'{u} {v} 1\n' for u,v in es),999,'constructive_stress')
def cycle(a,b,cap,hold,road):
    # Enumerate all end-of-day inventory states and all production choices.
    # No residual graph, augmenting paths or potentials are used by this oracle.
    states=list(itertools.product(*(range(c+1) for c in cap)));ans=10**9
    for initial in states:
        dp={initial:0}
        for day in range(7):
            nd={}
            for stock,cost in dp.items():
                for end in states:
                    req=[b[i][day]+end[i]-stock[i] for i in range(2)];best=10**9
                    for prod in range(a[0][day]+1):
                        other=sum(req)-prod
                        if 0<=other<=a[1][day]:best=min(best,abs(prod-req[0])*road)
                    if best==10**9:continue
                    val=cost+best+sum(end[i]*hold[i] for i in range(2))
                    nd[end]=min(nd.get(end,10**9),val)
            dp=nd
        ans=min(ans,dp.get(initial,10**9))
    return None if ans==10**9 else ans
def schedule(a,b,cap,hold,road):
    return '2 1\n'+''.join(' '.join(map(str,a[i]+b[i]+[cap[i],hold[i]]))+'\n' for i in range(2))+f'1 2 {road}\n'
# A Sunday production must serve the following Monday, charging exactly one night.
a=[[0]*7 for i in range(2)];b=[[0]*7 for i in range(2)];a[0][6]=1;b[0][0]=1
add('E',schedule(a,b,[1,0],[3,5],10),3)
count=0
while count<220:
    a=[[rng.randrange(3) for day in range(7)] for i in range(2)];b=[[rng.randrange(2) for day in range(7)] for i in range(2)]
    cap=[rng.randrange(3) for i in range(2)];hold=[rng.randrange(1,6) for i in range(2)];road=rng.randrange(1,6)
    ans=cycle(a,b,cap,hold,road)
    if ans is None:continue
    add('E',schedule(a,b,cap,hold,road),ans);count+=1
es=list(itertools.combinations(range(1,101),2));rng.shuffle(es);es=es[:500]
add('E','100 500\n'+('1 '*14+'10 3\n')*100+''.join(f'{u} {v} 2\n' for u,v in es),0,'constructive_stress')
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
    independent_oracles='Visit-prefix counts, literal Z-walk retained oracle, direct candidate-price order summation (current zero-volume convention only), exhaustive spanning-tree subsets, exhaustive cyclic end-of-day inventory DP with literal production choices (independent of min-cost flow).' ,
    note='No online submission was made. Original C remains 90 Wrong Answer, unresolved; local oracle agreement is not a full-score claim. Other original accepted records are historical.')
(P/'reports/report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False,indent=2))
