from fifth_support import *
import heapq, math

def tree(n):
    e=[(i,rng.randrange(i)) for i in range(1,n)]
    g=[[] for _ in range(n)]
    for u,v in e:g[u].append(v);g[v].append(u)
    return e,g
def path(g,s,t):
    parent={s:-1};order=[s]
    for u in order:
        for v in g[u]:
            if v not in parent:parent[v]=u;order.append(v)
    result=[]
    while t!=-1:result.append(t);t=parent[t]
    return result[::-1]
def run(date):
    for case in range(80):
        if date=='202303':
            n=rng.randint(2,24);ints=[tuple(sorted(rng.sample(range(1,n+1),2))) for _ in range(rng.randint(1,40))];ans=0
            for l in range(1,n):
                for r in range(l+1,n+1):
                    seen=set()
                    for a,b in ints:
                        if l<=a<=b<=r:seen.update(range(a,b+1))
                    ans+=len(seen)==r-l+1
            inp=f'{n} {len(ints)}\n'+''.join(f'{a} {b}\n' for a,b in ints)
        elif date=='202112':
            n=rng.randint(1,35);e,g=tree(n);k1=rng.randrange(n+1);k2=rng.randrange(n+1);ans=0
            for s in range(n):
                for t in range(s,n):
                    p=path(g,s,t);ans+=min(p)>=s-k1 and max(p)<=t+k2
            inp=f'{n} {k1} {k2}\n'+''.join(f'{u+1} {v+1}\n' for u,v in e)
        elif date=='202309':
            n=rng.randint(2,25);e,g=tree(n);w=[rng.randrange(20) for _ in e];b=[rng.randrange(20) for _ in e];initial=w[:];ops=[];out=[];idx={frozenset(edge):i for i,edge in enumerate(e)}
            for turn in range(31):
                if turn:i=rng.randrange(n-1);w[i]=rng.randrange(20);ops.append(f'{i+1} {w[i]}')
                best=0
                for s in range(n):
                    for t in range(s+1,n):
                        p=path(g,s,t);best=max(best,sum(b[idx[frozenset((x,y))]]-w[idx[frozenset((x,y))]] for x,y in zip(p,p[1:])))
                out.append(best)
            inp=f'{n} 30\n'+''.join(f'{u+1} {v+1} {x} {y}\n' for (u,v),x,y in zip(e,initial,b))+'\n'.join(ops)+'\n';ans='\n'.join(map(str,out))
        elif date=='201503':
            n=rng.randint(1,40);e,g=tree(n);price=[rng.randint(1,30) for _ in range(n)];cost={frozenset(edge):rng.randint(1,20) for edge in e};qs=[(rng.randrange(n),rng.randrange(n)) for _ in range(40)];out=[]
            for s,t in qs:
                p=path(g,s,t);low=price[s];v=0
                for x,y in zip(p,p[1:]):low=min(low,price[x]);v+=low*cost[frozenset((x,y))]
                out.append(v)
            inp=f'{n} {len(qs)}\n'+' '.join(map(str,price))+'\n'+''.join(f'{u+1} {v+1} {cost[frozenset((u,v))]}\n' for u,v in e)+''.join(f'{u+1} {v+1}\n' for u,v in qs);ans='\n'.join(map(str,out))
        elif date=='201712':
            n=rng.randint(1,50);e,g=tree(n);parent=[-1]+[v for u,v in e];depth=[0]*n;v=[rng.randint(0,1000) for _ in range(n)];f=[rng.randint(0,100) for _ in range(n)];length=[0]+[rng.randint(1,20) for _ in e];dp=[0]*n
            for u in range(1,n):depth[u]=depth[parent[u]]+length[u]
            for u in range(n-1,-1,-1):
                p=parent[u]
                while p>=0:dp[p]=max(dp[p],dp[u]+v[p]-(f[p]-(depth[u]-depth[p]))**2);p=parent[p]
            inp='1\n'+str(n)+'\n'+''.join(f'{parent[u]+1} {length[u]} {v[u]} {f[u]}\n' for u in range(n));ans=sum(dp)%10**18
        elif date=='201809':
            n=rng.randint(1,100);l=rng.randint(0,250);r=l+rng.randint(0,150);k=[rng.randrange(998244353) for _ in range(n)];a=[1]
            for j in range(1,r+1):a.append(sum(k[i-1]*a[j-i] for i in range(1,min(j,n)+1))%998244353)
            inp=f'{n} {l} {r}\n'+' '.join(map(str,k))+'\n';ans='\n'.join(map(str,a[l:r+1]))
        elif date=='201512':
            n=rng.randint(1,16);a=[rng.randrange(1<<n) for _ in range(n)];b=rng.randrange(1<<n);queries=[rng.randrange(200) for _ in range(20)];states=[b]
            for i in range(max(queries)):states.append(sum((bin(row&states[-1]).count("1")%2)<<j for j,row in enumerate(a)))
            fmt=lambda x:''.join(str(x>>j&1) for j in range(n))
            inp=str(n)+'\n'+'\n'.join(map(fmt,a))+'\n'+fmt(b)+'\n'+str(len(queries))+'\n'+'\n'.join(map(str,queries))+'\n';ans='\n'.join(fmt(states[k]) for k in queries)
        elif date=='201604':
            n=rng.randint(2,8);p=rng.randint(1,min(6,n-1));e=[(i,i+1,rng.randrange(10)) for i in range(n-1)]
            for u in range(n):
                for v in range(u+2,min(n,u+p+1)):
                    if len(e)<15 and rng.randrange(3)==0:e.append((u,v,rng.randrange(10)))
            selected=set(rng.sample(range(n),rng.randint(2,n)));ans=10**9
            for mask in range(1<<len(e)):
                cost=0;par=list(range(n))
                def root(u):
                    while par[u]!=u:u=par[u]
                    return u
                for i,(u,v,w) in enumerate(e):
                    if mask>>i&1:cost+=w;par[root(u)]=root(v)
                if len({root(u) for u in selected})==1:ans=min(ans,cost)
            inp=f'1\n{n} {len(e)} {p}\n'+''.join('1' if i in selected else '0' for i in range(n))+'\n'+''.join(f'{u+1} {v+1} {w}\n' for u,v,w in e)
        elif date=='201403':
            n=rng.randint(1,7);jobs=[[rng.randint(1,10) for _ in range(4)] for _ in range(n)];ans=10**9
            for choices in itertools.product(range(5),repeat=n):
                x=y=z=serial=0
                for (a,b,c,d),ch in zip(jobs,choices):
                    if ch==0:x+=a
                    elif ch==1:y+=a
                    elif ch==2:x+=c;z+=c
                    elif ch==3:y+=c;z+=c
                    else:serial+=min(b,d)
                ans=min(ans,serial+max(x,y,z))
            inp=str(n)+'\n'+''.join(' '.join(map(str,j))+'\n' for j in jobs)
        elif date=='201703':
            n=rng.randint(2,5);m=rng.randint(2,5);a,b,q,x=[rng.randint(1,50) for _ in range(4)];initial=x;v=[];h=[]
            for i in range((n-1)*m):x=(a*x+b)%q;v.append(x)
            for i in range((n-2)*(m-1)):x=(a*x+b)%q;h.append(x)
            ans=min(sum(v[row*m+col] for col,row in enumerate(heights))+sum(sum(h[row*(m-1)+col] for row in range(min(heights[col],heights[col+1]),max(heights[col],heights[col+1]))) for col in range(m-1)) for heights in itertools.product(range(n-1),repeat=m))
            inp=f'{n} {m} {a} {b} {q} {initial}\n'
        elif date=='202109':
            m=80;mod=rng.randint(2,1000);T=rng.randrange(2);values={};history=[[]];current=[];last=0;count=0;ops=[];out=[]
            for day in range(1,m+1):
                op=rng.randint(1,3) if current else 1
                if op==1:
                    x=0 if current and rng.randrange(4)==0 else rng.randint(1,mod-1)
                    ops.append(f'1 {x^(T*last)}')
                    if x:count+=1;values[count]=x;current=current+[count]
                    else:current=current[:-1]
                else:
                    possible=[i for i,h in enumerate(history) if h]+([day] if current else []);s=rng.choice(possible);h=current if s==day else history[s];l=rng.randint(1,len(h));r=rng.randint(l,len(h));members=h[l-1:r]
                    if op==2:
                        y=rng.randrange(mod);ops.append(f'2 {s} {l} {r} {y^(T*last)}')
                        for u in members:values[u]=values[u]*y%mod
                    else:last=sum(values[u] for u in members)%mod;ops.append(f'3 {s} {l} {r}');out.append(last)
                history.append(current[:])
            inp=f'{m} {mod} {T}\n'+'\n'.join(ops)+'\n';ans='\n'.join(map(str,out))
        else:raise ValueError(date)
        check(date,inp,ans)
    print(date,report[date],flush=True)
