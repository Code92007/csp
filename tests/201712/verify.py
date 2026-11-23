from pathlib import Path
import argparse,collections,hashlib,itertools,json,random,resource,subprocess,time,sys,datetime,heapq
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
rng=random.Random(20171224)
add('A','1000\n'+'1 '*1000+'\n',0)
for n0 in range(1,31):
    for k0 in range(1,10):
        a=list(range(1,n0+1));i=0;v=1
        while len(a)>1:
            if v%k0==0 or v%10==k0:a.pop(i);i%=len(a)
            else:i=(i+1)%len(a)
            v+=1
        add('B',f'{n0} {k0}\n',a[0])
for z in range(80):
    start=datetime.datetime(rng.choice([1970,1999,2000,2004,2099]),rng.choice([1,2,3,12]),rng.randrange(1,26),rng.randrange(24),rng.randrange(60));end=start+datetime.timedelta(minutes=rng.randrange(1,1600));fields=[];commands=[]
    for i in range(4):
        minute=sorted(rng.sample(range(60),4));hour=sorted(rng.sample(range(24),3));dow=sorted(rng.sample(range(7),4));fields.append((minute,hour,dow));commands.append(f'cmd{i}')
    out=[];cur=start
    while cur<end:
        for i,(minute,hour,dow) in enumerate(fields):
            if cur.minute in minute and cur.hour in hour and (cur.weekday()+1)%7 in dow:out.append(cur.strftime('%Y%m%d%H%M')+' '+commands[i])
        cur+=datetime.timedelta(minutes=1)
    inp=f'4 {start:%Y%m%d%H%M} {end:%Y%m%d%H%M}\n'
    for i,(minute,hour,dow) in enumerate(fields):inp+=','.join(map(str,minute))+' '+','.join(map(str,hour))+' * * '+','.join(map(str,dow))+' '+commands[i]+'\n'
    add('C',inp,'\n'.join(out))
add('C','3 200002282359 200003010001\n0 0 29 fEb tUE leap\n0,0 0 29 FEB 2 dup\n0 0 1 mAr wED end\n','200002290000 leap\n200002290000 dup\n200003010000 end')
for z in range(140):
    n0=rng.randrange(2,9);edges=[];g=[[] for _ in range(n0)]
    pairs={(i,rng.randrange(i)) for i in range(1,n0)}
    for i in range(n0):
        for j in range(i):
            if rng.randrange(5)==0:pairs.add((i,j))
    for u,vv in pairs:
        op=rng.randrange(2);w=rng.randrange(1,6);edges.append((op,u,vv,w));g[u].append((vv,op,w));g[vv].append((u,op,w))
    bound=(n0-1)*5;dist={(0,0):0};q=[(0,0,0)]
    while q:
        cost,u,run=heapq.heappop(q)
        if dist[u,run]!=cost:continue
        for vv,op,w in g[u]:
            nr=run+w if op else 0
            if nr>bound:continue
            nd=cost+(nr*nr-run*run if op else w);key=(vv,nr)
            if nd<dist.get(key,10**30):dist[key]=nd;heapq.heappush(q,(nd,*key))
    expected=min(vv for (u,run),vv in dist.items() if u==n0-1)
    add('D',f'{n0} {len(edges)}\n'+''.join(f'{op} {u+1} {vv+1} {w}\n' for op,u,vv,w in edges),expected)
for alt in [False,True]:
    n0=500;edges=''.join(f'{i%2 if alt else 1} {i} {i+1} 1\n' for i in range(1,n0))
    add('D',f'{n0} {n0-1}\n'+edges,n0-1 if alt else (n0-1)**2,'constructive_stress')
for z in range(150):
    blocks=[];out=[]
    for _ in range(3):
        n0=rng.randrange(1,51);par=[0]+[rng.randrange(i) for i in range(1,n0)];length=[0]+[rng.randrange(1,1001) for _ in range(n0-1)];depth=[0]*n0;value=[rng.randrange(1000001) for _ in range(n0)];ideal=[rng.randrange(1001) for _ in range(n0)];dp=[0]*n0
        for u in range(1,n0):depth[u]=depth[par[u]]+length[u]
        for u in range(n0-1,-1,-1):
            p=par[u] if u else -1
            while p>=0:dp[p]=max(dp[p],dp[u]+value[p]-(ideal[p]-(depth[u]-depth[p]))**2);p=par[p] if p else -1
        blocks.append(str(n0)+'\n'+''.join(f'{par[u]+1 if u else 0} {length[u]} {value[u]} {ideal[u]}\n' for u in range(n0)));out.append(sum(dp)%10**18)
    add('E','3\n'+''.join(blocks),'\n'.join(map(str,out)))
n0=100000
add('E','1\n'+str(n0)+'\n'+'0 0 0 0\n'+''.join(f'{i} 1 0 0\n' for i in range(1,n0)),0,'constructive_stress')
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
    independent_oracles='All-pair differences, live-circle deletion, Python datetime minute enumeration, direct road-state Dijkstra with current consecutive-small-road length, ancestor/descendant DP with exact Python integers.',
    note='Historical accepted records belong to the original version; no online submission was made for this refactor.')
(P/'reports/report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False,indent=2))
