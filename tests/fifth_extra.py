from fifth_extended import tree,path
from fifth_support import *
import heapq,math

def run(date):
    for _ in range(60):
        if date=='201912':
            n=rng.randint(1,80);a=list(range(1,n+1));qs=[];out=[];mod=2009731336725594113;magic=[314882150829468584,427197303358170108,1022292690726729920,1698479428772363217,2006101093849356424]
            for t in range(50):
                l=rng.randrange(n);r=rng.randrange(l,n);qs.append((l+1,r+1));s=sum(x%2019 for x in a[l:r+1]);out.append(s)
                for i in range(l,r+1):a[i]=a[i]*magic[s%5]%mod
            inp=f'{n} {len(qs)}\n'+''.join(f'{l} {r}\n' for l,r in qs);ans='\n'.join(map(str,out))
        elif date=='202006':
            n=rng.randint(0,6);goods=[]
            for i in range(n):l=rng.randint(1,3);r=l+rng.randint(2,3);goods.append((l,r,rng.randint(-5,5),rng.randint(-10,10),rng.randint(-20,20)))
            relations=[(rng.randint(1,2),rng.randrange(n),rng.randrange(n)) for i in range(rng.randrange(10))] if n else [];ans=-10**9
            for choices in itertools.product(*([0]+list(range(l,r+1)) for l,r,a,b,c in goods)):
                if any((choices[y]!=0 if z==1 else choices[y] in goods[y][:2]) and choices[x]==0 for z,x,y in relations):continue
                ans=max(ans,sum(a*x*x+b*x+c for x,(l,r,a,b,c) in zip(choices,goods) if x))
            inp=f'{n} {len(relations)}\n'+''.join(' '.join(map(str,g))+'\n' for g in goods)+''.join(f'{z} {x+1} {y+1}\n' for z,x,y in relations)
        elif date=='202409':
            n=rng.randint(1,50);m=8;k=30;colors=[rng.randrange(m) for i in range(n)];boards={1:list(range(n))};ops=[];out=[]
            for id in range(2,k+2):
                x=rng.choice(list(boards));l=rng.randrange(n);r=rng.randrange(l,n);new=[u for u in boards[x] if l<=u<=r];boards[x]=[u for u in boards[x] if u not in new];boards[id]=new;ops.append(f'{x} {l+1} {r+1}');seq=[colors[u] for u in new];out.extend([len(set(seq)),sum(i==0 or seq[i]!=seq[i-1] for i in range(len(seq)))])
            inp=f'{n} {m} {k}\n'+' '.join(str(c+1) for c in colors)+'\n'+'\n'.join(ops)+'\n';ans=' '.join(map(str,out))
        elif date=='202403':
            n=rng.randint(1,45);e,g=tree(n);parents=[-1]+[v for u,v in e];children=[[] for i in range(n)]
            for u,v in e:children[v].append(u)
            data=[rng.randrange(100) for i in range(n)];initial=data[:];alive=set(range(n));ops=[];out=[]
            for t in range(60):
                u=rng.choice(sorted(alive));op=rng.randint(1,2);ops.append(f'{op} {u+1}')
                if op==1:
                    new=[]
                    for v in children[u]:new+=children[v];data[u]+=data[v];alive.remove(v)
                    for v in new:parents[v]=u
                    children[u]=new;out.extend([len(new),data[u]])
                else:
                    dep=1;v=u
                    while parents[v]>=0:dep+=1;v=parents[v]
                    out.append(dep)
            inp=f'{n} {len(ops)}\n'+' '.join(str(v+1) for u,v in e)+'\n'+' '.join(map(str,initial))+'\n'+'\n'.join(ops)+'\n';ans=' '.join(map(str,out))
        elif date=='202603':
            n=rng.randint(2,40);e,g=tree(n);stations=set(rng.sample(range(n),rng.randrange(min(n,20)+1)));plans=[tuple(rng.sample(range(n),2)) for i in range(30)];paths=[path(g,s,t) for s,t in plans];fixed=set();ops=[];out=[];X=rng.randrange(2);last=0;remaining=e[:];rng.shuffle(remaining)
            for turn in range(n):
                count=0
                for p in paths:
                    broken=0;okay=True
                    for a,b in zip(p,p[1:]):
                        broken+=frozenset((a,b)) not in fixed
                        if broken>1:okay=False
                        if b in stations:broken=0
                    count+=okay
                ops.append('2');out.append(count);last=count
                if remaining:
                    u,v=remaining.pop();fixed.add(frozenset((u,v)));ops.append(f'1 {(u+1)^(X*last)} {(v+1)^(X*last)}')
            inp=f'{n} {X}\n'+''.join(f'{u+1} {v+1}\n' for u,v in e)+str(len(stations))+'\n'+' '.join(str(u+1) for u in stations)+'\n'+str(len(plans))+'\n'+''.join(f'{u+1} {v+1}\n' for u,v in plans)+str(len(ops))+'\n'+'\n'.join(ops)+'\n';ans='\n'.join(map(str,out))
        elif date=='202312':
            n=rng.randint(2,9);k=rng.randint(1,9);limit=rng.randint(2,9);colors=[rng.randrange(k) for i in range(n)];edges=[(u,v,rng.randrange(20)) for u in range(n) for v in range(n) if u!=v and rng.randrange(4)==0];g=[[] for i in range(n)]
            for u,v,w in edges:g[u].append((v,w))
            best=[0]
            def dfs(u,used,weight,count):
                if u==n-1:best[0]=max(best[0],weight)
                if count==limit:return
                for v,w in g[u]:
                    if colors[v] not in used:dfs(v,used|{colors[v]},weight+w,count+1)
            dfs(0,{colors[0]},0,1);ans=best[0]
            inp=f'{n} {len(edges)} {limit} {k}\n'+' '.join(map(str,colors))+'\n'+'\n'.join(' '.join(str(e[j]) for e in edges) for j in range(3))+'\n'
        elif date=='202305':
            letters='abcd';target=''.join(rng.sample(list(letters),rng.randint(1,4)));routes=[''.join(rng.choice(letters) for j in range(rng.randint(2,7))) for i in range(rng.randint(1,18))];g={u:[] for u in letters};full=(1<<len(target))-1
            def mask(s):return sum(1<<j for j,c in enumerate(target) if c in s)
            for s in routes:g[s[0]].append((s[-1],mask(s),len(s)-1))
            out=[]
            for s in routes:
                start=(s[-1],mask(s));dist={start:len(s)-1};heap=[(len(s)-1,*start)];answer=-1
                while heap:
                    d,u,seen=heapq.heappop(heap)
                    if d!=dist[(u,seen)]:continue
                    if u==s[0] and seen==full:answer=d;break
                    for v,got,w in g[u]:
                        key=v,seen|got
                        if d+w<dist.get(key,10**9):dist[key]=d+w;heapq.heappush(heap,(d+w,*key))
                out.append(answer)
            inp=f'{len(routes)} {target}\n'+'\n'.join(routes)+'\n';ans='\n'.join(map(str,out))
        elif date=='201509':
            words=list({''.join(rng.choice('ab') for j in range(rng.randint(1,4))) for i in range(rng.randint(1,6))});length=rng.randint(1,10)
            ans=max(sum(sum(s[i:i+len(w)]==w for i in range(len(s)-len(w)+1)) for w in words) for s in map(''.join,itertools.product('ab',repeat=length)))
            inp=f'{len(words)} {length}\n'+'\n'.join(words)+'\n'
        elif date=='201409':
            n=rng.randint(1,5);m=rng.randint(1,5);full=(1<<(n*m))-1
            @functools.lru_cache(None)
            def solve(mask):
                if mask==full:return 1
                free=next(i for i in range(n*m) if not(mask>>i&1));x,y=divmod(free,m);answer=0
                for a in (x-1,x):
                    for b in (y-1,y):
                        if a<0 or b<0 or a+1>=n or b+1>=m:continue
                        cells=[a*m+b,a*m+b+1,(a+1)*m+b,(a+1)*m+b+1]
                        for missing in range(4):
                            piece=sum(1<<c for j,c in enumerate(cells) if j!=missing)
                            if piece>>free&1 and not piece&mask:answer+=solve(mask|piece)
                return answer
            inp=f'{n} {m}\n';ans=solve(0)
        else:raise ValueError(date)
        check(date,inp,ans)
    print(date,report[date],flush=True)
