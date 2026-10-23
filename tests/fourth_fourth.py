from fourth_support import *
import itertools,heapq
def run():
    for _ in range(100):
        a=sorted(rng.sample(range(13),rng.randrange(2,7)));n=len(a)
        def solve(l):
            if l==n-1:return {frozenset()}
            results=set()
            for r in range(l+1,n):
                length=a[r]-a[l]
                for d in range(1,length):
                    if length%d:continue
                    trees=set(range(a[l]+d,a[r],d))
                    if trees&set(a):continue
                    for rest in solve(r):results.add(frozenset(trees|set(rest)))
            return results
        case('202104D',str(n)+'\n'+' '.join(map(str,a))+'\n',len(solve(0)))
    substitution={'1':'2','2':'4','4':'16','6':'64'};expanded=['1']
    for i in range(27):expanded.append(''.join(substitution[c] for c in expanded[-1]))
    for _ in range(110):
        n=rng.randrange(28);s=expanded[n];length=rng.randrange(1,min(len(s)+2,250));start=rng.randrange(max(1,len(s)-length+1));pattern=s[start:start+length]
        if rng.randrange(4)==0:pattern=''.join(rng.choice('1246') for i in range(length))
        count=0;position=s.find(pattern)
        while position>=0:count+=1;position=s.find(pattern,position+1)
        case('202006D',f'{n}\n{pattern}\n',count%998244353)
    for _ in range(80):
        n=rng.randrange(2,9);edges=[(u,v) for u in range(n) for v in range(u+1) if rng.randrange(4)==0];g=[[] for i in range(n)]
        for u,v in edges:g[u].append(v);g[v].append(u)
        delay=rng.randrange(1,6);chains=[(0,) for i in range(n)];events=[];serial=0;ops=[];out=[];time=0;new_id=1
        def best(a,b):return a if (len(a),-a[-1])>(len(b),-b[-1]) else b
        def send(u,t):
            nonlocal serial
            for v in g[u]:serial+=1;heapq.heappush(events,(t+delay,serial,v,chains[u]))
        def advance(t):
            while events and events[0][0]<=t:
                now=events[0][0];incoming={}
                while events and events[0][0]==now:
                    _,_,v,c=heapq.heappop(events);incoming[v]=best(incoming.get(v,chains[v]),c)
                for v,c in incoming.items():
                    if best(c,chains[v])!=chains[v]:chains[v]=c;send(v,now)
        for j in range(20):
            time+=rng.randrange(1,5);advance(time)
            for z in range(rng.randrange(4)):
                u=rng.randrange(n);ops.append(f'{u+1} {time} {new_id}');chains[u]+= (new_id,);new_id+=1;send(u,time)
            for z in range(rng.randrange(1,4)):
                u=rng.randrange(n);ops.append(f'{u+1} {time}');out.append(str(len(chains[u]))+' '+' '.join(map(str,chains[u])))
        data=f'{n} {len(edges)}\n'+''.join(f'{u+1} {v+1}\n' for u,v in edges)+f'{delay} {len(ops)}\n'+'\n'.join(ops)+'\n'
        case('201912D',data,'\n'.join(out))
    for _ in range(100):
        n=rng.randrange(2,8);a=[rng.randrange(1,12) for i in range(n)];b=[sum(a[max(0,i-1):min(n,i+2)])//len(a[max(0,i-1):min(n,i+2)]) for i in range(n)]
        def search(path):
            if len(path)==n:return path if sum(path[-2:])//2==b[-1] else None
            i=len(path)-1
            for x in range(max(1,3*b[i]-sum(path[-2:])),3*b[i]+3-sum(path[-2:])):
                found=search(path+[x])
                if found:return found
        answer=None
        for x in range(1,2*b[0]+1):
            for y in (2*b[0]-x,2*b[0]+1-x):
                if y>0:answer=search([x,y])
                if answer:break
            if answer:break
        case('201809D',str(n)+'\n'+' '.join(map(str,b))+'\n',' '.join(map(str,answer)))
