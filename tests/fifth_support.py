from pathlib import Path
import random, subprocess, json, re, functools, itertools, collections, sys
R=Path(__file__).resolve().parent
rng=random.Random(920072026)
report={}
def same(date,a,b):
    if date=="202206":return len(a)==len(b) and all(abs(float(x)-float(y))<=1e-3*max(1,abs(float(y))) for x,y in zip(a,b))
    return a==b
def check(date,inp,expected):
    p=subprocess.run([str(R.parent/'.build'/date/'E')],input=inp,text=True,capture_output=True,timeout=15)
    got=p.stdout.split(); want=str(expected).split()
    if p.returncode or not same(date,got,want):
        (R.parent/'.build'/'fifth-failure.json').write_text(json.dumps(dict(date=date,input=inp,expected=str(expected),stdout=p.stdout,stderr=p.stderr),ensure_ascii=False,indent=2))
        raise AssertionError((date,inp,expected,p.stdout,p.stderr))
    report[date]=report.get(date,0)+1
def random_first():
    for _ in range(120):
        n=rng.randint(1,8);a=[rng.randint(1,30) for _ in range(n)];b=[rng.randint(1,30) for _ in range(n)];budget=rng.randint(1,300)
        dp={(0,0):0}
        for x,y in zip(a,b):
            nd={}
            for (stock,done),cost in dp.items():
                for make in (0,1):
                    for finish in (0,1):
                        if stock+make>=finish:
                            key=stock+make-finish,done+finish;v=cost+make*x+finish*y
                            nd[key]=min(nd.get(key,10**9),v)
            dp=nd
        expected=max(done for (stock,done),v in dp.items() if stock==0 and v<=budget)
        check('202509',f'{n} {budget}\n'+ ' '.join(map(str,a))+'\n'+' '.join(map(str,b))+'\n',expected)
    def color_cost(a,W):
        n=len(a);dp=[n+1]*(1<<n);dp[0]=0;stable=[]
        for mask in range(1,1<<n):
            ix=[i for i in range(n) if mask>>i&1]
            if all((a[i]^a[j])>=W for i,j in itertools.combinations(ix,2)):stable.append(mask)
        for mask in range(1,1<<n):
            for s in stable:
                if s&mask==s:dp[mask]=min(dp[mask],1+dp[mask^s])
        return dp[-1]
    for _ in range(100):
        W=rng.choice([1,2,3,4,5,7,8,9,15,16,100,2**30]);packs=[[rng.randrange(32) for _ in range(rng.randrange(3))] for _ in range(3)]
        lines=[f'3 {W}']+[str(len(a))+' '+' '.join(map(str,a)) for a in packs];ops=[];out=[];active=list(range(3))
        for i in range(9):
            if sum(map(len,packs))<8 and rng.randrange(3):
                u=rng.choice(active);x=rng.randrange(32);packs[u].append(x);ops.append(f'1 {u+1} {x}')
            elif len(active)>1:
                u,v=rng.sample(active,2);packs[u]+=packs[v];packs[v]=[];active.remove(v);ops.append(f'2 {u+1} {v+1}')
            ops.append('3');out.append(sum(color_cost(packs[u],W) for u in active))
        check('202512','\n'.join(lines+[str(len(ops))]+ops)+'\n','\n'.join(map(str,out)))
    for _ in range(160):
        n=rng.randint(1,12);a=[rng.randint(1,20) for _ in range(n)];b=[rng.randint(1,10) for _ in range(n)];expected=0
        for p in range(1,n):
            @functools.lru_cache(None)
            def solve(l,r):
                if l<0 and r==n:return 0
                choices=[]
                if l>=0:choices.append(max(a[l],solve(l-1,r)-b[l]))
                if r<n:choices.append(max(a[r],solve(l,r+1)-b[r]))
                return min(choices)
            expected^=solve(p-1,p)
        check('202412',f'{n}\n'+' '.join(map(str,a))+'\n'+' '.join(map(str,b))+'\n1\n0\n',expected)
    for _ in range(100):
        n=rng.randint(1,12);edges={(i,rng.randrange(i)) for i in range(1,n)}
        for i in range(n):
            for j in range(i):
                if rng.randrange(5)==0:edges.add((i,j))
        sets=[rng.sample(range(n),rng.randint(1,n)) for _ in range(8)];out=[]
        for marked in sets:
            total=0
            for removed in range(n):
                seen={removed};best=0
                for u in range(n):
                    if u in seen:continue
                    stack=[u];seen.add(u);value=0
                    while stack:
                        x=stack.pop();value+=x in marked
                        for a,b in edges:
                            v=b if a==x else a if b==x else -1
                            if v>=0 and v not in seen:seen.add(v);stack.append(v)
                    best=max(best,value)
                total+=best
            out.append(total)
        inp=f'{n} {len(edges)} {len(sets)}\n'+''.join(f'{u+1} {v+1}\n' for u,v in edges)+''.join(str(len(a))+' '+' '.join(str(x+1) for x in a)+'\n' for a in sets)
        check('202506',inp,'\n'.join(map(str,out)))
    for _ in range(120):
        n=rng.randint(2,10);weights=[rng.randint(-10,10) for _ in range(n)];edges={(i,rng.randrange(i)) for i in range(1,n)};root=0
        initial=weights[:];initial_edges=edges.copy();ops=[];out=[]
        def best(u,required):
            parents={root:-1};order=[root]
            for x in order:
                for a,b in edges:
                    v=b if a==x else a if b==x else -1
                    if v>=0 and v!=parents[x]:parents[v]=x;order.append(v)
            nodes=[u]
            for x in nodes:nodes.extend(v for v in order if parents[v]==x)
            candidates=[]
            for mask in range(1,1<<len(nodes)):
                selected={nodes[i] for i in range(len(nodes)) if mask>>i&1}
                if required and u not in selected:continue
                inside=sum(a in selected and b in selected for a,b in edges)
                if inside==len(selected)-1:candidates.append(sum(weights[x] for x in selected))
            return max(candidates)
        out.append(best(root,True))
        for i in range(20):
            op=rng.randint(1,4);u=rng.randrange(n)
            if op==1:ops.append(f'1 {u+1}');out.append(best(u,False));continue
            if op==2:
                w=rng.randint(-10,10);weights[u]=w;ops.append(f'2 {u+1} {w}')
            elif op==3:root=u;ops.append(f'3 {u+1}')
            else:
                a,b=rng.choice(sorted(edges));edges.remove((a,b));part={a};stack=[a]
                for x in stack:
                    for c,d in edges:
                        v=d if c==x else c if d==x else -1
                        if v>=0 and v not in part:part.add(v);stack.append(v)
                c=rng.choice(sorted(part));d=rng.choice(sorted(set(range(n))-part));edges.add((c,d));ops.append(f'4 {a+1} {b+1} {c+1} {d+1}')
            out.append(best(root,True))
        inp=f'{n} {len(ops)}\n'+' '.join(map(str,initial))+'\n'+''.join(f'{a+1} {b+1}\n' for a,b in initial_edges)+'\n'.join(ops)+'\n'
        check('202503',inp,'\n'.join(map(str,out)))
