from pathlib import Path
import argparse,collections,hashlib,itertools,json,random,resource,subprocess,time,sys,functools,math
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
rng=random.Random(20131224)
for z in range(40):
    a0=[rng.randrange(1,10001) for i in range(rng.randrange(1,1001))];c0=collections.Counter(a0);best=max(c0.values())
    add('A',str(len(a0))+'\n'+' '.join(map(str,a0))+'\n',min(x for x,c in c0.items() if c==best))
for z in range(100):
    digits=[rng.randrange(10) for i in range(9)];r0=sum((i+1)*x for i,x in enumerate(digits))%11;c0='X' if r0==10 else str(r0)
    d0=''.join(map(str,digits));base=d0[:1]+'-'+d0[1:4]+'-'+d0[4:9]+'-'
    add('B',base+c0+'\n','Right')
    wrong=rng.choice([c for c in '0123456789X' if c!=c0]);add('B',base+wrong+'\n',base+c0)
for n0 in range(1,7):
    for h0 in itertools.product([1,2,3],repeat=n0):
        best=max(min(h0[l:r])*(r-l) for l in range(n0) for r in range(l+1,n0+1))
        add('C',str(n0)+'\n'+' '.join(map(str,h0))+'\n',best)
add('C','100000\n'+'1000000000 '*100000+'\n',10**14,'constructive_stress')
def formula(n0):
    # Choose positive counts inside 0^a1^b and 2^c3^d. First digit is 2;
    # interleave all k zero/one digits in n-1 remaining slots.
    return sum((k-1)*(n0-k-1)*math.comb(n0-1,k) for k in range(2,n0-1))%1000000007
for n0 in range(1,101):add('D',str(n0)+'\n',formula(n0))
add('D','1000\n'+'\n'.join(map(str,range(1,1001)))+'\n','\n'.join(str(formula(n0)) for n0 in range(1,1001)))
# Each test cell is independently explored forward all the way to T. This
# intentionally does not use a reverse graph or a reverse traversal.
dirs={'+':[(-1,0),(1,0),(0,-1),(0,1)],'S':[(-1,0),(1,0),(0,-1),(0,1)],'T':[(-1,0),(1,0),(0,-1),(0,1)],'-':[(0,-1),(0,1)],'|':[(-1,0),(1,0)],'.':[(1,0)],'#':[]}
def stuck(a0):
    n0=len(a0);m0=len(a0[0]);s0=next((i,j) for i in range(n0) for j in range(m0) if a0[i][j]=='S');t0=next((i,j) for i in range(n0) for j in range(m0) if a0[i][j]=='T')
    def reach(start):
        seen={start};todo=[start]
        while todo:
            i,j=todo.pop()
            for di,dj in dirs[a0[i][j]]:
                x,y=i+di,j+dj
                if 0<=x<n0 and 0<=y<m0 and a0[x][y]!='#' and (x,y) not in seen:seen.add((x,y));todo.append((x,y))
        return seen
    seen=reach(s0)
    if t0 not in seen:return "I'm stuck!"
    return sum(t0 not in reach(u) for u in seen)
def gridcase(a0):add('E',f'{len(a0)} {len(a0[0])}\n'+'\n'.join(a0)+'\n',stuck(a0))
for s0,t0 in itertools.permutations(range(4),2):
    rest=[u for u in range(4) if u not in [s0,t0]]
    for chars in itertools.product('#+-|.',repeat=2):
        a0=['']*4;a0[s0]='S';a0[t0]='T'
        for u,c0 in zip(rest,chars):a0[u]=c0
        gridcase([''.join(a0[:2]),''.join(a0[2:])])
for chars in itertools.product('#+-|.',repeat=4):gridcase(['S'+chars[0]+'T',''.join(chars[1:])])
for z in range(220):
    n0=rng.randrange(1,7);m0=rng.randrange(1,7)
    if n0*m0<2:continue
    a0=[rng.choice('#+-|.') for i in range(n0*m0)];s0,t0=rng.sample(range(n0*m0),2);a0[s0]='S';a0[t0]='T'
    gridcase([''.join(a0[i*m0:(i+1)*m0]) for i in range(n0)])
a0=['+'*50 for i in range(50)];a0[0]='S'+'+'*49;a0[-1]='+'*49+'T'
add('E','50 50\n'+'\n'.join(a0)+'\n',0,'constructive_stress')
a0[25]='#'*50
add('E','50 50\n'+'\n'.join(a0)+'\n',"I'm stuck!",'constructive_stress')
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
    independent_oracles='Frequency counter/minimum tie, independent ISBN weighted checksum, exhaustive subinterval histogram minima, combinatorial digit-count/interleaving formula independent of bitmask DP, literal forward reachability from every reachable cell independent of reverse BFS.',
    note='Historical accepted records belong to the original version; no online submission was made for this refactor.')
(P/'reports/report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False,indent=2))
