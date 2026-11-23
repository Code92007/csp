"""Independent installed-subset BFS and event-level nonpreemptive scheduling."""
import heapq,itertools,random
from collections import deque

def case(c,data,out,kind='boundary',label=''):
    return dict(problem=c,input=data,output=str(out),kind=kind,label=label)

def schedule(jobs):
    n=len(jobs);start=((1<<n)-1,());q=[(0,*start)];dist={start:0}
    while q:
        t,S,runs=heapq.heappop(q)
        if dist.get((S,runs))!=t:continue
        if not S and not runs:return t
        busy=0
        for rem,mask in runs:busy|=mask
        for i,(a,b,c,d) in enumerate(jobs):
            if not S>>i&1:continue
            for mask,duration in [(1,a),(2,a),(3,b),(5,c),(6,c),(7,d)]:
                if mask&busy:continue
                ns=S^(1<<i);nr=tuple(sorted(runs+((duration,mask),)));key=(ns,nr)
                if t<dist.get(key,10**9):dist[key]=t;heapq.heappush(q,(t,ns,nr))
        if runs:
            step=min(rem for rem,mask in runs);nr=tuple(sorted((rem-step,mask) for rem,mask in runs if rem>step));key=(S,nr)
            if t+step<dist.get(key,10**9):dist[key]=t+step;heapq.heappush(q,(t+step,S,nr))

def installed(points,n,k,r):
    ans=10**9
    for S in range(1<<(len(points)-n)):
        if bin(S).count("1")>k:continue
        vs=list(range(n))+[n+i for i in range(len(points)-n) if S>>i&1]
        d={0:0};q=deque([0])
        while q:
            u=q.popleft()
            for v in vs:
                if v in d:continue
                if sum((points[u][i]-points[v][i])**2 for i in range(2))<=r*r:d[v]=d[u]+1;q.append(v)
        if 1 in d:ans=min(ans,d[1]-1)
    return ans

def cases():
    yield case('A','500\n'+' '.join(map(str,list(range(-250,0))+list(range(1,251)))),250,'stress','500 values; 250 opposite pairs')
    lines=['tool -a -b -word -c -b final','tool -b old -b','tool -b -a -a','tool -a bad -b x','tool -d -a','tool','tool -c -c -b 123','tool -b '+'x'*248]
    out=['Case 1: -a -b final -c','Case 2: -b old','Case 3: -a -b -a','Case 4: -a','Case 5:','Case 6:','Case 7: -b 123 -c','Case 8: -b '+'x'*248]
    yield case('C','ab:c\n8\n'+'\n'.join(lines)+'\n','\n'.join(out),'boundary','last valid parameter; dash argument; exact 256 character line')
    rng=random.Random(20140320261124)
    for _ in range(60):
        n=rng.randint(2,7);m=rng.randint(1,6);k=rng.randint(1,m);r=rng.randint(2,20)
        # Distinct existing points on an unbroken line ensure original connectivity.
        allp=[(i,0) for i in range(n)];rng.shuffle(allp);pts=allp+[(rng.randint(-2,10),j+1) for j in range(m)]
        shift=10**8-30;pts=[(x+shift,y+shift) for x,y in pts]
        data=f'{n} {m} {k} {r}\n'+''.join(f'{x} {y}\n' for x,y in pts)
        yield case('D',data,installed(pts,n,k,r),'retained_independent')
    pts=[(0,0),(100000000,0),(-100000000,0),(0,100000000)]
    yield case('D','2 2 2 100000000\n'+''.join(f'{x} {y}\n' for x,y in pts),0)
    pts=[(0,0),(99,0)]+[(i,0) for i in range(1,99)]+[(i,1) for i in range(100)]
    yield case('D','100 100 100 1\n'+''.join(f'{x} {y}\n' for x,y in pts),98,'stress','200 positions; all 100 candidate layers')
    for _ in range(70):
        n=rng.randint(1,5);jobs=[tuple(rng.randint(1,5) for _ in range(4)) for i in range(n)]
        data=str(n)+'\n'+''.join(' '.join(map(str,j))+'\n' for j in jobs)
        yield case('E',data,schedule(jobs),'retained_independent','actual resource masks and event-time Dijkstra')
    for job,ans,label in [((10,10,10,10),200,'two equal CPU loads; U=200'),((10,10,1,10),37,'GPU and CPU overlap'),((10,1,10,1),40,'dual CPU serial'),((1,10,10,10),20,'single CPU dominates')]:
        yield case('E','40\n'+(' '.join(map(str,job))+'\n')*40,ans,'stress',label)

    for a,b,c,d in [(10,9,7,8),(10,10,6,10)]:
        n=40;ans=10**9
        # Identical jobs: enumerate serial/GPU/single counts and assign each group to the two CPUs.
        for serial in range(n+1):
            for gpu in range(n-serial+1):
                single=n-serial-gpu
                for x in range(gpu+1):
                    for y in range(single+1):
                        load=x*c+y*a;other=(gpu-x)*c+(single-y)*a
                        ans=min(ans,serial*min(b,d)+max(load,other,gpu*c))
        job=(a,b,c,d)
        yield case('E','40\n'+(' '.join(map(str,job))+'\n')*40,ans,'stress','40 mixed-resource jobs; independent count allocation')
