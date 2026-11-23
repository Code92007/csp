"""Small direct tree walks plus analytic maximum trees; stdlib calendar oracle."""
import calendar,datetime,random
from collections import deque

def case(c,data,out,kind='boundary',label=''):
    return dict(problem=c,input=data,output=str(out),kind=kind,label=label)

def treecase(n,prices,edges,qs):
    return f'{n} {len(qs)}\n'+' '.join(map(str,prices))+'\n'+''.join(f'{u} {v} {w}\n' for u,v,w in edges)+''.join(f'{s} {t}\n' for s,t in qs)

def cases():
    n=m=1000
    rows=[' '.join(str((i*1000+j)%1001) for j in range(m)) for i in range(n)]
    out=[' '.join(str((i*1000+j)%1001) for i in range(n)) for j in range(m-1,-1,-1)]
    yield case('A','1000 1000\n'+'\n'.join(rows),'\n'.join(out),'stress','1000x1000 rotation')
    yield case('B','1000\n'+' '.join(map(str,range(1000))),'\n'.join(f'{i} 1' for i in range(1000)),'stress','1000 distinct values tied by frequency')
    for c in range(1,8):
        out=[]
        for y in range(1850,2051):
            ds=[d for d in range(1,calendar.monthrange(y,2)[1]+1) if datetime.date(y,2,d).isoweekday()==c]
            out.append(f'{y}/02/{ds[4]:02d}' if len(ds)>=5 else 'none')
        yield case('C',f'2 5 {c} 1850 2050\n','\n'.join(out),'boundary','all years fifth weekday in February')
    n=m=10000
    parents=list(range(1,n))+[1]*(m-1)+[n]
    yield case('D',f'{n} {m}\n'+' '.join(map(str,parents)),n+1,'stress','10000-switch chain with terminal leaves')
    rng=random.Random(20150320261124)
    for _ in range(180):
        n=rng.randint(1,35);prices=[rng.choice([1,1000000,rng.randint(1,1000000)]) for _ in range(n)]
        edges=[(rng.randint(1,v-1),v,rng.randint(1,10000)) for v in range(2,n+1)]
        g=[[] for _ in range(n)]
        for u,v,w in edges:g[u-1].append((v-1,w));g[v-1].append((u-1,w))
        qs=[];out=[]
        for _ in range(50):
            s=rng.randrange(n);t=rng.randrange(n);qs.extend([(s+1,t+1),(t+1,s+1)])
            for s,t in [(s,t),(t,s)]:
                fa=[None]*n;fa[s]=(s,0);q=deque([s])
                while q:
                    u=q.popleft()
                    for v,w in g[u]:
                        if fa[v] is None:fa[v]=(u,w);q.append(v)
                path=[];u=t
                while u!=s:path.append((u,fa[u][1]));u=fa[u][0]
                low=prices[s];ans=0
                for v,w in path[::-1]:ans+=low*w;low=min(low,prices[v])
                out.append(ans)
        yield case('E',treecase(n,prices,edges,qs),'\n'.join(map(str,out)),'retained_independent')
    n=100000;qs=[(rng.randint(1,n),rng.randint(1,n)) for _ in range(n)]
    for typ in ('decreasing','constant','star'):
        prices=[n-i for i in range(n)] if typ!='constant' else [1000000]*n
        if typ=='star':prices[0]=1000000;edges=[(1,i,10000) for i in range(2,n+1)]
        else:edges=[(i,i+1,10000) for i in range(1,n)]
        out=[]
        for s,t in qs:
            if typ=='constant':ans=abs(s-t)*1000000*10000
            elif typ=='decreasing':
                ans=(t-s)*(2*n-s-t+3)//2*10000 if s<t else (s-t)*(n-s+1)*10000
            elif s==t:ans=0
            elif s==1:ans=1000000*10000
            elif t==1:ans=prices[s-1]*10000
            else:ans=prices[s-1]*20000
            out.append(ans)
        yield case('E',treecase(n,prices,edges,qs),'\n'.join(map(str,out)),'stress','100000 vertices/queries; '+typ)
    yield case('E','1 1\n1000000\n1 1\n',0)
