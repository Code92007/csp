from fourth_support import *
def run():
    for _ in range(100):
        n=rng.randrange(2,8);edges=[(rng.randrange(2),u,rng.randrange(u),rng.randrange(1,6)) for u in range(1,n)]
        for u in range(n):
            for v in range(u):
                if rng.randrange(5)==0:edges.append((rng.randrange(2),u,v,rng.randrange(1,6)))
        g=[[] for i in range(n)]
        for t,u,v,w in edges:g[u].append((v,w,t));g[v].append((u,w,t))
        d={(0,0):0};heap=[(0,0,0)];answer=None
        while heap:
            cost,u,small=heapq.heappop(heap)
            if cost!=d[u,small]:continue
            if u==n-1:answer=cost;break
            for v,w,t in g[u]:
                length=small+w if t else 0;value=cost+((small+w)**2-small**2 if t else w)
                if value<2000 and value<d.get((v,length),10**9):d[v,length]=value;heapq.heappush(heap,(value,v,length))
        case('201712D',f'{n} {len(edges)}\n'+''.join(f'{t} {u+1} {v+1} {w}\n' for t,u,v,w in edges),answer)
    for _ in range(100):
        n=rng.randrange(1,10);edges=[(u,rng.randrange(u),rng.randrange(1,30)) for u in range(1,n)];d=[[10**6]*n for i in range(n)]
        for i in range(n):d[i][i]=0
        for u,v,w in edges:d[u][v]=d[v][u]=w
        for u in range(n):
            for v in range(u):
                if rng.randrange(5)==0:w=rng.randrange(1,30);edges.append((u,v,w));d[u][v]=d[v][u]=min(d[u][v],w)
        for k in range(n):
            for i in range(n):
                for j in range(n):d[i][j]=min(d[i][j],max(d[i][k],d[k][j]))
        case('201703D',f'{n} {len(edges)}\n'+''.join(f'{u+1} {v+1} {w}\n' for u,v,w in edges),d[0][-1])
    for _ in range(100):
        n=rng.randrange(2,7);m=rng.randrange(2,7);hazards={}
        for u in range(1,n*m-1):
            if rng.randrange(4)==0:a=rng.randrange(6);b=rng.randrange(a,10);hazards[u]=(a,b)
        frontier={0};answer=None
        for t in range(40):
            if n*m-1 in frontier:answer=t;break
            nxt=set()
            for u in frontier:
                for dx,dy in [(1,0),(-1,0),(0,1),(0,-1)]:
                    x=u//m+dx;y=u%m+dy;v=x*m+y
                    if 0<=x<n and 0<=y<m and not (v in hazards and hazards[v][0]<=t+1<=hazards[v][1]):nxt.add(v)
            frontier=nxt
        if answer is None:continue
        case('201604D',f'{n} {m} {len(hazards)}\n'+''.join(f'{u//m+1} {u%m+1} {a} {b}\n' for u,(a,b) in hazards.items()),answer)
    for _ in range(100):
        n=rng.randrange(2,7);all_edges=list(itertools.combinations(range(n),2));edges=rng.sample(all_edges,rng.randrange(1,min(len(all_edges),9)+1));g=[[] for i in range(n)]
        for i,(u,v) in enumerate(edges):g[u].append((v,i));g[v].append((u,i))
        def dfs(u,mask,path):
            if mask==(1<<len(edges))-1:return path
            for v,e in sorted(g[u]):
                if not(mask>>e&1):
                    result=dfs(v,mask|(1<<e),path+[v])
                    if result:return result
        answer=dfs(0,0,[0]);out='-1' if answer is None else ' '.join(str(u+1) for u in answer)
        case('201512D',f'{n} {len(edges)}\n'+''.join(f'{u+1} {v+1}\n' for u,v in edges),out)
    for _ in range(100):
        n=rng.randrange(1,15);edges=[(u,v) for u in range(n) for v in range(n) if rng.randrange(5)==0];reach=[[i==j for j in range(n)] for i in range(n)]
        for u,v in edges:reach[u][v]=True
        for k in range(n):
            for i in range(n):
                for j in range(n):reach[i][j]|=reach[i][k] and reach[k][j]
        answer=sum(reach[i][j] and reach[j][i] for i in range(n) for j in range(i))
        case('201509D',f'{n} {len(edges)}\n'+''.join(f'{u+1} {v+1}\n' for u,v in edges),answer)
    for _ in range(80):
        n=rng.randrange(1,15);m=rng.randrange(1,15);parent=[rng.randrange(u) for u in range(1,n)]+[rng.randrange(n) for i in range(m)];g=[[] for i in range(n+m)]
        for u,v in enumerate(parent,1):g[u].append(v);g[v].append(u)
        answer=0
        for start in range(n+m):
            d={start:0};todo=[start]
            for u in todo:
                for v in g[u]:
                    if v not in d:d[v]=d[u]+1;todo.append(v)
            answer=max(answer,max(d.values()))
        case('201503D',f'{n} {m}\n'+' '.join(str(x+1) for x in parent)+'\n',answer)
    for _ in range(80):
        n=rng.randrange(2,7);edges=[(u,rng.randrange(u),rng.randrange(1,20)) for u in range(1,n)]
        for u,v in rng.sample(list(itertools.combinations(range(n),2)),rng.randrange(1,min(4,n*(n-1)//2)+1)):edges.append((u,v,rng.randrange(1,20)))
        best=10**9
        for selected in itertools.combinations(edges,n-1):
            par=list(range(n))
            def root(u):
                while u!=par[u]:u=par[u]
                return u
            for u,v,w in selected:par[root(u)]=root(v)
            if len({root(i) for i in range(n)})==1:best=min(best,sum(w for u,v,w in selected))
        case('201412D',f'{n} {len(edges)}\n'+''.join(f'{u+1} {v+1} {w}\n' for u,v,w in edges),best)
    for _ in range(80):
        n=rng.randrange(3,9);blocked=set(rng.sample(range(n*n),rng.randrange(n)));sources=rng.sample(sorted(set(range(n*n))-blocked),rng.randrange(1,n));best={}
        for start in sources:
            d={start:0};todo=[start]
            for u in todo:
                for dx,dy in [(1,0),(-1,0),(0,1),(0,-1)]:
                    x=u//n+dx;y=u%n+dy;v=x*n+y
                    if 0<=x<n and 0<=y<n and v not in blocked and v not in d:d[v]=d[u]+1;todo.append(v)
            for u,value in d.items():best[u]=min(best.get(u,10**9),value)
        customers=[(rng.choice(list(best)),rng.randrange(1,10)) for i in range(15)];answer=sum(best[u]*c for u,c in customers)
        data=f'{n} {len(sources)} {len(customers)} {len(blocked)}\n'+''.join(f'{u//n+1} {u%n+1}\n' for u in sources)+''.join(f'{u//n+1} {u%n+1} {c}\n' for u,c in customers)+''.join(f'{u//n+1} {u%n+1}\n' for u in blocked)
        case('201409D',data,answer)
    for _ in range(80):
        n=rng.randrange(2,6);m=rng.randrange(1,4);radius=rng.randrange(2,8);points=rng.sample(list(itertools.product(range(10),repeat=2)),n+m);k=rng.randrange(1,m+1);best=10**9
        for mask in range(1<<m):
            if bin(mask).count('1')>k:continue
            allowed=set(range(n))|{n+i for i in range(m) if mask>>i&1};d={0:0};todo=[0]
            for u in todo:
                for v in allowed:
                    if v not in d and sum((a-b)**2 for a,b in zip(points[u],points[v]))<=radius**2:d[v]=d[u]+1;todo.append(v)
            if 1 in d:best=min(best,d[1]-1)
        if best==10**9:continue
        case('201403D',f'{n} {m} {k} {radius}\n'+''.join(f'{x} {y}\n' for x,y in points),best)
    for n in range(1,9):
        answer=0
        for digits in itertools.product(range(4),repeat=n):
            if digits[0]==0 or set(digits)!={0,1,2,3}:continue
            if max(i for i,x in enumerate(digits) if x==0)<min(i for i,x in enumerate(digits) if x==1) and max(i for i,x in enumerate(digits) if x==2)<min(i for i,x in enumerate(digits) if x==3):answer+=1
        case('201312D',f'{n}\n',answer)
    queries=[rng.randrange(4,1001) for i in range(80)];answer=[sum(math.comb(n-1,t)*(t-1)*(n-t-1) for t in range(2,n-1))%1000000007 for n in queries]
    case('201312D',str(len(queries))+'\n'+'\n'.join(map(str,queries))+'\n','\n'.join(map(str,answer)))
