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
add('A','8 5\n-0.01 0\n+0 0\n3 4\n-3.01 4\n5.0 0\n0 -5.00\n4 3.01\n-5 -5\n',2.5,tol=1e-7)
add('A','1000 1000\n'+'1000.00 0\n'*1000,4,tol=1e-7)
for n in [1,4,5,8,9,200]:
    add('B',f'{n} 65536\n'+('0 '*n+'\n')*n,'')
add('C','1 1\nH HH\n01a1b\n7\n1 1\n2 0 H8007 H0007\n1 2\n2 2 HHabc\n1 2\n3 0 a b\n1 1\n','H: HH\nb: a\nb: a\nb: Habc\nb: Habc\na: b\nH: HH')
# Every recursive-parent labelled tree through four vertices, all permutations,
# all ordered path endpoint pairs: independently search each actual path.
for n in range(1,5):
    for par in itertools.product(*[range(i) for i in range(1,n)]):
        edges=[(i+1,p) for i,p in enumerate(par)];g=[[] for _ in range(n)]
        for u,v in edges:g[u].append(v);g[v].append(u)
        for a in itertools.permutations(range(n)):
            out=[];qs=[]
            for u in range(n):
                for v in range(n):
                    prev={u:-1};q=[u]
                    for x in q:
                        for y in g[x]:
                            if y not in prev:prev[y]=x;q.append(y)
                    vals=set();x=v
                    while x!=-1:vals.add(a[x]);x=prev[x]
                    ans=0
                    while ans in vals:ans+=1
                    qs.append((u,v));out.append(ans)
            inp=f'{n} {len(qs)}\n'+' '.join(map(str,a))+'\n'+''.join(f'{u+1} {v+1}\n' for u,v in edges+qs)
            add('D',inp,'\n'.join(map(str,out)))
n=200000
add('D',f'{n} 4\n'+' '.join(map(str,range(n)))+'\n'+''.join(f'{i} {i+1}\n' for i in range(1,n))+f'1 {n}\n2 {n}\n1 1\n{n} {n}\n',f'{n}\n0\n1\n0','constructive_stress')
# Direct DP enumerates every morning/afternoon make/finish choice, not slopes.
for a in itertools.product([1,2],repeat=3):
    for b in itertools.product([1,2],repeat=3):
        dp={(0,0):0}
        for x,y in zip(a,b):
            nd={}
            for (stock,cnt),cost in dp.items():
                for make,done in itertools.product([0,1],repeat=2):
                    if stock+make<done:continue
                    key=(stock+make-done,cnt+done)
                    nd[key]=min(nd.get(key,10**9),cost+x*make+y*done)
            dp=nd
        for m in range(1,13):
            ans=max(cnt for (stock,cnt),cost in dp.items() if not stock and cost<=m)
            add('E',f'3 {m}\n'+ ' '.join(map(str,a))+'\n'+' '.join(map(str,b))+'\n',ans)
for m in [1,1999999999,2000000000,10**18]:
    add('E',f'1 {m}\n1000000000\n1000000000\n',int(m>=2000000000))
n=500000
add('E',f'{n} 500000000\n'+'1000 '*n+'\n'+'1000 '*n+'\n',250000,'constructive_stress')
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
    independent_oracles='Repository independent generators, geometric integer count, direct pattern matching, Huffman literal simulation, explicit tree paths, make/finish choice DP.',
    note='Historical accepted records belong to the original version; no online submission was made for this refactor.')
(P/'reports/report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False,indent=2))
