from fourth_support import *
def ticket(n, holes):
    prefixes=['','c','cc','cs','csp','cspa','cspar'];trans={}
    for s in prefixes:
        counts=collections.Counter()
        for ch in 'abcdefghijklmnopqrstuvwxyz':
            word=s+ch;hit=1 if word.endswith('ccf') else 2 if word.endswith('cspark') else 0
            tail=max((x for x in prefixes if word.endswith(x)),key=len)
            counts[(tail,hit)]+=1
        trans[s]=counts
    dp={('',0):1}
    for i in range(1,n+1):
        nxt=collections.defaultdict(int)
        for (s,flag),ways in dp.items():
            if i in holes:nxt[('',flag)]+=ways;continue
            for (tail,hit),count in trans[s].items():
                f=flag
                if hit==1:f=max(f,1)
                if hit==2 and f==1:f=2
                nxt[(tail,f)]+=ways*count
        dp={key:value%998244353 for key,value in nxt.items()}
    return sum(value for (s,f),value in dp.items() if f==2)%998244353
def run():
    for _ in range(70):
        n=rng.randrange(9,60);holes=set(rng.sample(range(1,n+1),rng.randrange(1,min(n,12)+1)))
        case('202506D',f'{n} {len(holes)}\n'+' '.join(map(str,sorted(holes)))+'\n',ticket(n,holes))
    n=100009;holes={100004}
    case('202506D',f'{n} 1\n100004\n',ticket(n,holes))
    for _ in range(130):
        n=rng.randrange(1,35);a=[rng.randrange(1,101) for i in range(n)];answer=0
        for l in range(n):
            g=0
            for r in range(l,n):g=math.gcd(g,a[r]);answer+=(l+1)*(r+1)*g
        case('202503D',str(n)+'\n'+' '.join(map(str,a))+'\n',answer%998244353)
    for _ in range(150):
        n=rng.randrange(1,50);a=[rng.randrange(i+1) for i in range(n)];a[-1]=0;k=[rng.randrange(1,n+2) for i in range(n)]
        d=[-1]*n;d[0]=0;todo=[0]
        for u in todo:
            for landing in range(u+1,min(n,u+k[u]+1)):
                v=landing-a[landing]
                if d[v]<0:d[v]=d[u]+1;todo.append(v)
        case('202412D',str(n)+'\n'+' '.join(map(str,a))+'\n'+' '.join(map(str,k))+'\n',d[-1])
    for _ in range(120):
        n=rng.randrange(1,15);m=rng.randrange(1,15);points=[(rng.randrange(15),rng.randrange(15)) for i in range(n)];stations=[(rng.randrange(15),rng.randrange(15),rng.randrange(10),rng.randrange(1,20)) for i in range(m)];d=[[10**9]*n for i in range(n)]
        for i in range(n):d[i][i]=0
        for x,y,r,t in stations:
            covered=[i for i,(a,b) in enumerate(points) if abs(a-x)<=r and abs(b-y)<=r]
            for u in covered:
                for v in covered:
                    if u!=v:d[u][v]=min(d[u][v],t)
        for k in range(n):
            for i in range(n):
                for j in range(n):d[i][j]=min(d[i][j],d[i][k]+d[k][j])
        data=f'{n} {m}\n'+''.join(f'{x} {y}\n' for x,y in points)+''.join(f'{x} {y} {r} {t}\n' for x,y,r,t in stations)
        case('202409D',data,'Nan' if d[0][-1]==10**9 else d[0][-1])
    for _ in range(100):
        n=rng.randrange(1,5);m=rng.randrange(1,11);b=[rng.randrange(1,5) for i in range(n)];c=[rng.randrange(1,4) for i in range(n)];goods=[(rng.randrange(5,31),rng.randrange(n)) for i in range(m)];options=[]
        for mask in range(1<<m):
            selected=[goods[i] for i in range(m) if mask>>i&1];used={t for a,t in selected};cost=sum(b[t] for t in used)+sum(c[t] for a,t in selected);net=sum(a for a,t in selected)-cost;options.append((cost,net))
        target=rng.randrange(1,max(net for cost,net in options)+1);answer=min(cost for cost,net in options if net>=target)
        data=f'{n} {m} {target}\n'+''.join(f'{x} {y}\n' for x,y in zip(b,c))+''.join(f'{x} {y}\n' for x,y in goods)
        case('202406D',data,answer)
    for _ in range(120):
        positions=sorted(rng.sample(range(1,80),rng.randrange(1,20)));water={x:rng.randrange(1,5) for x in positions};initial=water.copy();ops=[];out=[]
        while water and len(ops)<30:
            p=rng.choice(list(water));ops.append(p);water[p]+=1
            while any(w>=5 for w in water.values()):
                p=min(x for x,w in water.items() if w>=5);ordered=sorted(water);i=ordered.index(p);neighbors=ordered[max(0,i-1):i]+ordered[i+1:i+2];del water[p]
                for x in neighbors:water[x]+=1
            out.append(len(water))
        data=f'80 {len(initial)} {len(ops)}\n'+''.join(f'{x} {w}\n' for x,w in initial.items())+'\n'.join(map(str,ops))+'\n'
        case('202403D',data,'\n'.join(map(str,out)))
