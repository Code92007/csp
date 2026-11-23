from pathlib import Path
import argparse,collections,hashlib,itertools,json,random,resource,subprocess,time,sys,heapq
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
rng=random.Random(20230524)
board=['********']*8
add('A','3\n'+('\n'.join(board)+'\n')*3,'1\n2\n3')
n=10000;k=20
add('B',f'{n} {k}\n'+('1000 '*k+'\n')*(n*3)+'1000 '*n+'\n',('\n'.join([' '.join([str(n*k*1000**4)]*k)]*n)),'constructive_stress')
def varint(v):
    a=[]
    while v>=128:a.append((v&127)|128);v>>=7
    return a+[v]
def literal(data):
    z=len(data)-1
    if z<60:return [z<<2]+data
    cnt=(z.bit_length()+7)//8
    return [(59+cnt)<<2]+list(z.to_bytes(cnt,'little'))+data
def packed(raw,payload):
    a=varint(len(raw))+payload
    return str(len(a))+'\n'+''.join(f'{v:02x}' for v in a)+'\n'
def hexout(raw):return '\n'.join(bytes(raw[i:i+8]).hex() for i in range(0,len(raw),8))
for length in [1,2,8,59,60,61,255,256,257,65535,65536,65537]:
    raw=[i%256 for i in range(length)]
    add('C',packed(raw,literal(raw)),hexout(raw))
for off in [1,2,3,7,255,256,2047,2048,65535]:
    raw=[rng.randrange(256) for _ in range(off)];payload=literal(raw)
    for length in [4,11,64]:
        if off<2048 and length<=11:tag=[1|((length-4)<<2)|((off>>8)<<5),off&255]
        else:tag=[2|((length-1)<<2),off&255,off>>8]
        payload+=tag
        for _ in range(length):raw.append(raw[-off])
    add('C',packed(raw,payload),hexout(raw))
# Max output construction is a single legal literal, with a 3-byte length.
raw=[123]*(2*1024*1024-16)
add('C',packed(raw,literal(raw)),hexout(raw),'constructive_stress')
def network(n,k,edges):
    cost=[[rng.randrange(12) for _ in range(k)] for _ in range(n)];g=[]
    for u,v in edges:g.append((u,v,[[rng.randrange(12) for _ in range(k)] for _ in range(k)]))
    ans=min(sum(cost[i][s[i]] for i in range(n))+sum(a[s[u]][s[v]] for u,v,a in g) for s in itertools.product(range(k),repeat=n))
    inp=f'{n} {len(g)} {k}\n'+''.join(' '.join(map(str,row))+'\n' for row in cost)
    for u,v,a in g:inp+=f'{u} {v}\n'+''.join(' '.join(map(str,row))+'\n' for row in a)
    add('D',inp,ans)
for z in range(100):
    n=rng.randrange(1,8);k=rng.randrange(1,4);edges={(v,rng.randrange(v)) for v in range(1,n)}
    for u in range(n):
        for v in range(u):
            if rng.randrange(3)==0:edges.add((u,v))
    network(n,k,sorted(edges))
for z in range(30):
    edges=list(itertools.combinations(range(4),2));n=4
    for _ in range(z%4):
        u,v=edges.pop(rng.randrange(len(edges)));edges.extend([(u,n),(n,v)]);n+=1
    network(n,3,edges)
for z in range(160):
    n=rng.randrange(1,15);target=''.join(rng.sample('abcd',rng.randrange(1,5)));routes=[''.join(rng.choices('abcdx',k=rng.randrange(1,8))) for _ in range(n)]
    ids={c:i for i,c in enumerate(target)};full=(1<<len(target))-1;g=collections.defaultdict(list);out=[]
    for s in routes:
        mask=sum(1<<ids[c] for c in set(s) if c in ids);g[s[0]].append((s[-1],mask,len(s)-1))
    for s in routes:
        mask=sum(1<<ids[c] for c in set(s) if c in ids);state=(s[-1],mask);dist={state:0};q=[(0,*state)];ans=-1
        while q:
            val,u,mask=heapq.heappop(q)
            if dist[u,mask]!=val:continue
            if u==s[0] and mask==full:ans=val+len(s)-1;break
            for v,b,w in g[u]:
                key=(v,mask|b);nd=val+w
                if nd<dist.get(key,10**9):dist[key]=nd;heapq.heappush(q,(nd,*key))
        out.append(ans)
    add('E',f'{n} {target}\n'+'\n'.join(routes)+'\n','\n'.join(map(str,out)))
add('E','10 abcdefghij\n'+'\n'.join('abcdefghij'[i]+'abcdefghij'[(i+1)%10] for i in range(10))+'\n','\n'.join(['10']*10),'constructive_stress')
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
    independent_oracles='Complete board comparison; direct Q*K-transpose then V multiplication; independently encoded Snappy streams; exhaustive label assignment; raw-route state Dijkstra without edge dominance or SOS preprocessing.',
    note='Historical accepted records belong to the original version; no online submission was made for this refactor.')
(P/'reports/report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False,indent=2))
