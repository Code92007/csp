from pathlib import Path
import argparse,collections,hashlib,itertools,json,random,resource,subprocess,time,sys,bisect,builtins
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
rng=random.Random(20211224)
for nmax in range(2,25):
    for n in range(1,min(nmax,6)):
        a=sorted(rng.sample(range(1,nmax),n));inp=f'{n} {nmax}\n'+' '.join(map(str,a))+'\n';rate=nmax//(n+1)
        add('A',inp,sum(bisect.bisect_right(a,x) for x in range(nmax)))
        add('B',inp,sum(abs(bisect.bisect_right(a,x)-x//rate) for x in range(nmax)))
for z in range(200):
    disk=rng.randrange(1,35);owner=[0]*disk;data=[0]*disk;ops=[];out=[]
    for _ in range(90):
        op=rng.randrange(4);idx=rng.randrange(1,5);l=rng.randrange(disk);rr=rng.randrange(l,disk)
        if op==3:ops.append(f'3 {l+1}');out.append(f'{owner[l]} {data[l]}' if owner[l]>0 else '0 0')
        elif op==0:
            val=rng.randrange(101);ops.append(f'0 {idx} {l+1} {rr+1} {val}');end=l-1
            for x in range(l,rr+1):
                if owner[x]>0 and owner[x]!=idx:break
                owner[x]=idx;data[x]=val;end=x
            out.append(str(end+1) if end>=l else '-1')
        else:
            ops.append(f'{op} {idx} {l+1} {rr+1}');need=idx if op==1 else -idx;ok=all(x==need for x in owner[l:rr+1]);out.append('OK' if ok else 'FAIL')
            if ok:owner[l:rr+1]=[-need]*(rr-l+1)
    add('D',f'4 {disk} {len(ops)}\n'+'\n'.join(ops)+'\n','\n'.join(out))
add('D','2 1000000000 8\n0 1 1 1000000000 999\n1 1 1 1000000000\n3 999999999\n2 1 1 1000000000\n3 999999999\n0 2 1000000000 1000000000 2\n1 1 1 999999999\n3 1000000000\n','1000000000\nOK\n0 0\nOK\n1 999\n-1\nOK\n1 999')
for z in range(600):
    n=rng.randrange(1,71);perm=list(range(n));rng.shuffle(perm);edges=[(perm[i],perm[rng.randrange(i)]) for i in range(1,n)];g=[[] for _ in range(n)]
    for u,vv in edges:g[u].append(vv);g[vv].append(u)
    k1=rng.choice([0,1,n,rng.randrange(n+1)]);k2=rng.choice([0,1,n,rng.randrange(n+1)]);ans=0
    for u in range(n):
        par={u:-1};ord=[u];mn={u:u};mx={u:u}
        for x in ord:
            for y in g[x]:
                if y not in par:par[y]=x;ord.append(y);mn[y]=min(mn[x],y);mx[y]=max(mx[x],y)
        ans+=sum(mn[y]>=u-k1 and mx[y]<=y+k2 for y in range(u,n))
    add('E',f'{n} {k1} {k2}\n'+''.join(f'{u+1} {vv+1}\n' for u,vv in edges),ans)
n=500000
for kind,k1,k2,ans in [('chain',0,0,n*(n+1)//2),('star',0,0,2*n-1),('star',n,0,n*(n+1)//2)]:
    edges=''.join(f'{i} {i+1}\n' if kind=='chain' else f'1 {i+1}\n' for i in range(1,n))
    add('E',f'{n} {k1} {k2}\n'+edges,ans,'constructive_stress')
# A compatibility/performance supplement is kept separate from independent tests.
exe=W/'.build/202112-prep/original-E';exe.parent.mkdir(parents=True,exist_ok=True)
r0=subprocess.run(['clang++','-std=c++17','-O2',str(repo/'202112/E.cpp'),'-o',str(exe)],capture_output=True,text=True);assert r0.returncode==0,r0.stderr
for z in range(2):
    perm=list(range(1,n+1));rng.shuffle(perm)
    edges=''.join(f'{perm[i]} {perm[(i-1)//2] if z==0 else perm[rng.randrange(i)]}\n' for i in range(1,n));inp=f'{n} 400 2000\n'+edges
    r0=subprocess.run([str(exe)],input=inp,text=True,capture_output=True,timeout=90);assert r0.returncode==0,r0.stderr
    add('E',inp,r0.stdout,'compatibility_stress')
# The retained barcode generator performs checks via subprocess itself, so
# add a standalone property oracle instead of counting it as captured cases.
trans={(0,1):[27],(0,2):[28],(1,0):[28,28],(1,2):[28],(2,0):[28],(2,1):[27]}
for z in range(140):
    width=rng.randrange(1,31);grade=rng.choice(list(range(-1,9)));text=''.join(rng.choices('AZaz09',k=rng.randrange(1,70)));chars=[];state=0
    for char in text:
        target=0 if char.isupper() else 1 if char.islower() else 2
        if state!=target:chars+=trans[state,target]
        chars.append(builtins.ord(char)-builtins.ord('A' if target==0 else 'a' if target==1 else '0'));state=target
    if len(chars)%2:chars.append(29)
    prefix=[0]+[chars[i]*30+chars[i+1] for i in range(0,len(chars),2)]
    count=0 if grade==-1 else 2**(grade+1)
    prefix += [900]*(-(len(prefix)+count)%width);prefix[0]=len(prefix)
    cases.append(dict(problem='C',input=f'{width} {grade}\n{text}\n',output='',kind='additional_independent_checker',checker='barcode',prefix=prefix,roots=count))
cases=[c for c in cases if c['problem'] in 'DE']
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
    for p in 'DE':
        cmd=['clang++','-std=c++17','-Wall','-Wextra','-I/tmp/csp202609-check/include',*flags,str(P/f'{p}.cpp'),'-o',str(build/mode/p)]
        r=subprocess.run(cmd,text=True,capture_output=True);assert r.returncode==0,r.stderr
        assert not r.stderr,r.stderr
        compilelog[f'{mode}/{p}']='passed without diagnostics'
    counts=collections.Counter();start=time.monotonic()
    for c in cases:
        # UBSan covers all small cases, including full exhaustive families.
        if mode=='ubsan' and c['kind'] in ['constructive_stress','compatibility_stress']:continue
        p=c['problem'];begin=time.monotonic()
        r=subprocess.run([str(build/mode/p)],input=c['input'],text=True,capture_output=True,timeout=90)
        got=r.stdout.split();want=c['output'].split();tol=c.get('abs_tol')
        if c.get('checker')=='barcode':
            nums=list(map(int,got));prefix=c['prefix'];roots=c['roots']
            ok=nums[:len(prefix)]==prefix and len(nums)==len(prefix)+roots
            ok=ok and all(0<=x<929 for x in nums)
            for j in range(1,roots+1):
                x=pow(3,j,929);value=0
                for v0 in nums:value=(value*x+v0)%929
                ok=ok and value==0
        else:
            ok=len(got)==len(want) and (all(abs(float(x)-float(y))<=tol for x,y in zip(got,want)) if tol else got==want)
        if r.returncode or r.stderr or not ok:
            (P/'reports/failure.json').write_text(json.dumps(dict(case=c,mode=mode,stdout=r.stdout,stderr=r.stderr),ensure_ascii=False,indent=2))
            raise AssertionError((p,c['kind'],r.returncode,r.stdout[:200],r.stderr))
        counts[p]+=1
        if c['kind']=='constructive_stress':results.append(dict(problem=p,kind=c['kind'],seconds=time.monotonic()-begin))
    results.append(dict(mode=mode,cases=dict(counts),total=sum(counts.values()),seconds=time.monotonic()-start))
report=dict(contest=d,source_sha256={p:hashlib.sha256((P/f'{p}.cpp').read_bytes()).hexdigest() for p in 'DE'},
    different_inputs=len(cases),categories=dict(collections.Counter(c['kind'] for c in cases)),compilation=compilelog,runs=results,
    independent_oracles='Direct point-by-point sequence queries; independently constructed barcode polynomial checks; cell-by-cell disk owner/value/history; exhaustive actual tree paths. Maximum random trees additionally compare the historical accepted source, classified separately.',
    note='Historical accepted records belong to the original version; no online submission was made for this refactor.')
(P/'reports/name-followup-report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False,indent=2))
