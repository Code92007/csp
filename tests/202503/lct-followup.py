"""Recheck the LinkCutTree template against connected-subset enumeration."""
from pathlib import Path
import collections,hashlib,json,random,re,subprocess,time
root=Path(__file__).resolve().parents[1]
cases=[c for c in json.loads((root/'reports/cases.json').read_text()) if c['problem']=='E']
rng=random.Random(2025032026112401)
for trial in range(200):
    n=rng.randint(1,9);w=[rng.randint(-12,12) for _ in range(n)];initial=w[:]
    edges=[(i,rng.randrange(i)) for i in range(1,n)];old=edges[:];rt=0;ops=[]
    def best(u,required):
        g=[[] for _ in range(n)]
        for x,y in edges:g[x].append(y);g[y].append(x)
        pa={rt:-1};order=[rt]
        for x in order:
            for y in g[x]:
                if y!=pa[x]:pa[y]=x;order.append(y)
        nodes=[];stack=[u]
        while stack:
            x=stack.pop();nodes.append(x);stack.extend(y for y in g[x] if pa.get(y)==x)
        ans=-10**30
        for mask in range(1,1<<len(nodes)):
            chosen={nodes[i] for i in range(len(nodes)) if mask>>i&1}
            if required and u not in chosen:continue
            seen={next(iter(chosen))};todo=list(seen)
            for x in todo:
                for y in g[x]:
                    if y in chosen and y not in seen:seen.add(y);todo.append(y)
            if seen==chosen:ans=max(ans,sum(w[x] for x in chosen))
        return ans
    ans=[best(rt,True)]
    for turn in range(40):
        op=rng.choice([1,2,3]+([4] if n>1 else []));u=rng.randrange(n)
        if op==1:ops.append(f'1 {u+1}');ans.append(best(u,False));continue
        if op==2:
            x=rng.randint(-12,12);w[u]=x;ops.append(f'2 {u+1} {x}')
        elif op==3:rt=u;ops.append(f'3 {u+1}')
        else:
            x,y=edges.pop(rng.randrange(len(edges)));seen={x};todo=[x]
            for v in todo:
                for a,b in edges:
                    z=b if a==v else a if b==v else -1
                    if z>=0 and z not in seen:seen.add(z);todo.append(z)
            a=rng.choice(list(seen));b=rng.choice(list(set(range(n))-seen));edges.append((a,b))
            ops.append(f'4 {x+1} {y+1} {a+1} {b+1}')
        ans.append(best(rt,True))
    data=f'{n} {len(ops)}\n'+' '.join(map(str,initial))+'\n'+''.join(f'{x+1} {y+1}\n' for x,y in old)+'\n'.join(ops)+'\n'
    cases.append(dict(problem='E',kind='connected_subset_independent',input=data,output='\n'.join(map(str,ans))))
n=100000;ops=[]
for i in range(25000):
    ops.extend([f'3 {i% n+1}',f'1 {(i*37)%n+1}','4 1 2 2 3','4 2 3 1 2'])
data=f'{n} {len(ops)}\n'+'-1 '*n+'\n'+''.join(f'1 {i}\n' for i in range(2,n+1))+'\n'.join(ops)+'\n'
cases.append(dict(problem='E',kind='negative_star_stress',input=data,output='-1\n'*(len(ops)+1)))
(root/'reports/lct-cases.json').write_text(json.dumps(cases)+'\n')
report=dict(prior_report='summary.json',source_sha256=hashlib.sha256((root/'E.cpp').read_bytes()).hexdigest(),cases_sha256=hashlib.sha256((root/'reports/lct-cases.json').read_bytes()).hexdigest(),results={})
for name,flags in [('opt',['-O2']),('ubsan',['-O1','-fsanitize=undefined','-fno-sanitize-recover=all'])]:
    exe=Path('/tmp')/('csp-202503-E-'+name+'-lct')
    built=subprocess.run(['clang++','-std=c++17','-Wall','-Wextra','-I/tmp/csp-personal-compat',*flags,str(root/'E.cpp'),'-o',str(exe)],capture_output=True,text=True);assert built.returncode==0,built.stderr
    counts=collections.Counter();start=time.monotonic()
    for c in cases:
        result=subprocess.run([str(exe)],input=c['input'],text=True,capture_output=True,timeout=120)
        if result.returncode or result.stdout.split()!=str(c['output']).split():
            (root/'reports/lct-failure.json').write_text(json.dumps(dict(case=c,stdout=result.stdout,stderr=result.stderr)))
            raise AssertionError((name,c['kind'],result.stderr,result.stdout[:100],str(c['output'])[:100]))
        counts[c['kind']]+=1
    report['results'][name]=dict(total=sum(counts.values()),counts=dict(counts),seconds=time.monotonic()-start,compile_stderr=built.stderr)
    print(name,report['results'][name],flush=True)
(root/'reports/lct-followup.json').write_text(json.dumps(report,indent=2)+'\n')
for p in [root/'README.md',root.parent/'202503题解.md']:
    s=p.read_text();i=[0]
    def change(m):
        c='ABCDE'[i[0]];i[0]+=1
        return '```cpp\n'+(root/(c+'.cpp')).read_text()+'```'
    s=re.sub(r'```cpp\n.*?```',change,s,flags=re.S);assert i[0]==5;p.write_text(s)
print(report['source_sha256'])
