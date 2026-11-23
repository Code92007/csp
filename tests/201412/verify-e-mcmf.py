"""Verify the array/SPFA refactor with inventory DP and analytic full-size cases."""
from pathlib import Path
import ast, collections, hashlib, itertools, json, random, subprocess, sys, time
P=Path(__file__).resolve().parents[1]
W=P.parent
sys.path.insert(0,str(P/'reports'))
# Retain the prior cases, including the independent cyclic inventory oracle.
old=ast.parse((P/'reports/verify.py').read_text())
body=[]
for node in old.body:
    if isinstance(node,ast.Assign) and any(isinstance(t,ast.Name) and t.id=='build' for t in node.targets):break
    body.append(node)
ns={'__file__':str(P/'reports/verify.py')}
sargv=sys.argv;sys.argv=['verify.py','--repo','/tmp/csp-style-publish']
exec(compile(ast.Module(body=body,type_ignores=[]),'previous-case-generators','exec'),ns)
sys.argv=sargv
cases=[x for x in ns['cases'] if x['problem']=='E']
cycle,schedule=ns['cycle'],ns['schedule']
def add(inp,out,kind):
    cases.append(dict(problem='E',input=inp,output=str(out),kind=kind))
rng=random.Random(2014122405)
# Extra legally balanced instances: weekly production equals weekly consumption.
count=0
while count<120:
    a=[[rng.randrange(3) for _ in range(7)] for _ in range(2)]
    b=[row[:] for row in a]
    for _ in range(8):
        i,j=rng.randrange(2),rng.randrange(7)
        u,v=rng.randrange(2),rng.randrange(7)
        if b[i][j]:b[i][j]-=1;b[u][v]+=1
    cap=[rng.randrange(3) for _ in range(2)]
    hold=[rng.randrange(1,6) for _ in range(2)];road=rng.randrange(1,6)
    ans=cycle(a,b,cap,hold,road)
    if ans is None:continue
    add(schedule(a,b,cap,hold,road),ans,'balanced_inventory_dp');count+=1
# Published problem-statement sample, distinct from the previously saved fixture.
add('3 3\n0 0 0 0 5 0 0 0 0 0 0 0 0 0 2 4\n0 0 0 0 0 0 0 2 0 0 0 0 0 0 2 1\n0 0 0 0 0 0 0 0 0 3 0 0 0 0 2 5\n1 2 1\n1 3 5\n2 3 1\n',67,'statement_sample')
add(schedule([[0]*7 for _ in range(2)],[[0]*7 for _ in range(2)],[0,0],[1,1],1),0,'boundary_zero_need')
a=[[0]*7 for _ in range(2)];b=[[0]*7 for _ in range(2)];b[0][0]=1
add(schedule(a,b,[0,0],[1,1],1),-1,'robustness_infeasible_outside_promise')
def graph(seed):
    rr=random.Random(seed)
    pairs={(i-1,i) for i in range(1,100)}
    while len(pairs)<500:
        u,v=sorted(rr.sample(range(100),2));pairs.add((u,v))
    es=[(u,v,rr.randrange(1,101)) for u,v in sorted(pairs)]
    d=[[10**12]*100 for _ in range(100)]
    for i in range(100):d[i][i]=0
    for u,v,w in es:d[u][v]=d[v][u]=w
    for k in range(100):
        for i in range(100):
            for j in range(100):d[i][j]=min(d[i][j],d[i][k]+d[k][j])
    return es,d
def full(a,b,es,cap=100,hold=100):
    return '100 500\n'+''.join(' '.join(map(str,a[i]+b[i]+[cap,hold]))+'\n' for i in range(100))+''.join(f'{u+1} {v+1} {w}\n' for u,v,w in es)
def assignment(a):
    # Hungarian assignment on Floyd distances, no residual network or augmenting flow.
    n=len(a);u=[0]*(n+1);v=[0]*(n+1);p=[0]*(n+1);way=[0]*(n+1)
    for i in range(1,n+1):
        p[0]=i;j0=0;dist=[10**12]*(n+1);used=[False]*(n+1)
        while True:
            used[j0]=True;i0=p[j0];delta=10**12;j1=0
            for j in range(1,n+1):
                if used[j]:continue
                cur=a[i0-1][j-1]-u[i0]-v[j]
                if cur<dist[j]:dist[j]=cur;way[j]=j0
                if dist[j]<delta:delta=dist[j];j1=j
            for j in range(n+1):
                if used[j]:u[p[j]]+=delta;v[j]-=delta
                else:dist[j]-=delta
            j0=j1
            if p[j0]==0:break
        while j0:
            j1=way[j0];p[j0]=p[j1];j0=j1
    return -v[0]
for seed in range(4):
    es,d=graph(201412+seed)
    a=[[100]*7 if i<50 else [0]*7 for i in range(100)]
    b=[[0]*7 if i<50 else [100]*7 for i in range(100)]
    ans=assignment([[d[i][j] for j in range(50,100)] for i in range(50)])*700
    add(full(a,b,es),ans,'full_size_assignment_oracle')
es,d=graph(201412)
a=[[0]*7 for _ in range(100)];b=[[0]*7 for _ in range(100)]
a[0]=[100]*7;b[99]=[100]*7
add(full(a,b,es),700*d[0][99],'full_size_shortest_path_oracle')
for day in (0,1):
    a=[[0]*6+[100] for _ in range(100)];b=[[0]*7 for _ in range(100)]
    for row in b:row[day]=100
    add(full(a,b,es,hold=1),10000*(day+1),'full_size_storage_oracle')
add(full([[100]*7 for _ in range(100)],[[100]*7 for _ in range(100)],es),0,'full_size_local_balance_oracle')
# Deduplicate exact input cases without inflating the verification count.
uniq={}
for c in cases:
    if c['input'] in uniq:assert str(c['output']).split()==str(uniq[c['input']]['output']).split()
    uniq[c['input']]=c
cases=list(uniq.values())
(P/'reports/e-mcmf-cases.json').write_text(json.dumps(cases,ensure_ascii=False,indent=2)+'\n')
build=Path('/tmp/csp-201412E-mcmf');build.mkdir(exist_ok=True)
report=dict(contest='201412',problem='E',source_sha256=hashlib.sha256((P/'E.cpp').read_bytes()).hexdigest(),different_inputs=len(cases),categories=dict(collections.Counter(c['kind'] for c in cases)),runs=[],compilation={})
for mode,flags in [('O2',['-O2']),('UBSan',['-O1','-g','-fsanitize=undefined','-fno-sanitize-recover=all'])]:
    exe=build/mode
    cmd=['clang++','-std=c++17','-Wall','-Wextra','-I/tmp/csp-personal-compat',*flags,str(P/'E.cpp'),'-o',str(exe)]
    r=subprocess.run(cmd,text=True,capture_output=True);assert r.returncode==0 and not r.stderr,r.stderr
    report['compilation'][mode]='passed without diagnostics'
    counts=collections.Counter();stresses=[];begin=time.monotonic()
    for c in cases:
        start=time.monotonic();r=subprocess.run([str(exe)],input=c['input'],text=True,capture_output=True,timeout=60)
        seconds=time.monotonic()-start
        assert not r.returncode and not r.stderr and r.stdout.split()==str(c['output']).split(),(mode,c['kind'],r.returncode,r.stdout,r.stderr,c['input'])
        counts[c['kind']]+=1
        if c['kind'].startswith('full_size') or c['kind']=='constructive_stress':stresses.append(dict(kind=c['kind'],seconds=seconds,expected=str(c['output'])))
    report['runs'].append(dict(mode=mode,cases=sum(counts.values()),counts=dict(counts),seconds=time.monotonic()-begin,stress=stresses))
report['capacity']=dict(vertices_max=702,residual_arcs_max=18200,first_edge_index=0,last_edge_index_max=18199,N=710,M=18210)
report['oracle']='Prior exhaustive cyclic inventory/production DP plus 120 legally balanced instances; Floyd shortest distances and Hungarian weekly transportation assignment; analytic max-size storage/local-balance cases.'
report['algorithm']='Successive shortest augmenting paths by SPFA, augmenting the complete bottleneck; int capacities, ll costs/distances/answer, circular N-slot queue, i^1 residual pairs.'
report['note']='No online resubmission. This report concerns only E; original C 90 Wrong Answer remains unresolved. One infeasible robustness case intentionally lies outside the promised feasible domain.'
(P/'reports/e-mcmf-report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False,indent=2))
