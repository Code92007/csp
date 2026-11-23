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
# Repeated boundary blocking, streaming arbitrarily long command token.
add('A','1 1\n1 1 '+ 'fblr'*250000+'\n','1 1','constructive_stress')
for n in range(1,4):
    for x,y in itertools.product(range(1,n+1),repeat=2):
        ops=[''.join(s) for s in itertools.product('fblr',repeat=4)]
        out=[]
        for s in ops:
            u,v=x,y
            for c in s:
                if c=='f':v=min(n,v+1)
                elif c=='b':v=max(1,v-1)
                elif c=='l':u=max(1,u-1)
                else:u=min(n,u+1)
            out.append(f'{u} {v}')
        add('A',f'{n} {len(ops)}\n'+''.join(f'{x} {y} {s}\n' for s in ops),'\n'.join(out))
rng=random.Random(20241224)
for z in range(150):
    n=rng.randrange(1,12);a=[rng.randrange(1,30) for _ in range(n+1)];b=[rng.randrange(1,30) for _ in range(n)]
    out=[]
    for removed in range(n):
        for energy in range(sum(a)+1):
            cur=energy-a[0]
            if cur<0:continue
            for i in range(n):
                if i!=removed:cur+=b[i]
                cur-=a[i+1]
                if cur<0:break
            else:out.append(energy);break
    add('B',f'{n}\n'+' '.join(map(str,a))+'\n'+' '.join(map(str,b))+'\n',' '.join(map(str,out)))
for z in range(150):
    ways=rng.randrange(1,6);groups=rng.randrange(1,6);cache=[[] for _ in range(groups)];ops=[];out=[]
    for j in range(120):
        op=rng.randrange(2);x=rng.randrange(50);ops.append((op,x));cur=cache[x//ways%groups]
        hit=next((i for i,v in enumerate(cur) if v[0]==x),None)
        if hit is not None:
            item=cur.pop(hit);item[1]|=op==1;cur.insert(0,item);continue
        if len(cur)==ways:
            addr,dirty=cur.pop()
            if dirty:out.append(f'1 {addr}')
        out.append(f'0 {x}');cur.insert(0,[x,op==1])
    add('C',f'{ways} {groups} {len(ops)}\n'+''.join(f'{op} {x}\n' for op,x in ops),'\n'.join(out))
for z in range(300):
    n=rng.randrange(1,16);a=[rng.randrange(i+1) for i in range(n)];a[-1]=0;k=[rng.choice([1,n,10**9,rng.randrange(1,n+1)]) for _ in range(n)]
    dis=[-1]*n;dis[0]=0;q=[0]
    for u in q:
        for j in range(u+1,min(n,u+k[u]+1)):
            v=j-a[j]
            if dis[v]<0:dis[v]=dis[u]+1;q.append(v)
    add('D',f'{n}\n'+' '.join(map(str,a))+'\n'+' '.join(map(str,k))+'\n',dis[-1])
n=100000
add('D',f'{n}\n'+'0 '*n+'\n'+'1000000000 '*n+'\n',1,'constructive_stress')
# Optimal interval expansion: directly try either next target recursively.
def brute(a,b):
    n=len(a);ans=0
    for p in range(1,n):
        @functools.lru_cache(None)
        def go(l,r):
            if l<0 and r==n:return 0
            v=[]
            if l>=0:v.append(max(a[l],go(l-1,r)-b[l]))
            if r<n:v.append(max(a[r],go(l,r+1)-b[r]))
            return min(v)
        ans^=go(p-1,p)
    return ans
for a in itertools.product([1,2],repeat=3):
    for b in itertools.product([1,2],repeat=3):
        aa=list(a);bb=list(b);aa[0]=10;bb[0]=1
        aa2=list(a);bb2=list(b);aa2[-1]=8;bb2[-1]=2
        out=[brute(a,b),brute(aa,bb),brute(aa2,bb2),brute(a,b)]
        add('E','3\n'+' '.join(map(str,a))+'\n'+' '.join(map(str,b))+'\n4\n0\n1\n1 10 1\n1\n3 8 2\n0\n','\n'.join(map(str,out)))
n=2000000
add('E',f'{n}\n'+'1000000000 '*n+'\n'+'1000000000 '*n+'\n2\n0\n0\n','1000000000\n1000000000','constructive_stress')
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
    independent_oracles='Independent step simulation, initial-energy feasibility, list-based cache simulation, explicit graph BFS, interval make/kill DP.',
    note='Historical accepted records belong to the original version; no online submission was made for this refactor.')
(P/'reports/report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False,indent=2))
