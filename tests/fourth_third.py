from fourth_support import *
import itertools
MOD=998244353
def run():
    def mul(a,b):return [(a[0]*b[0]+a[1]*b[2])%MOD,(a[0]*b[1]+a[1]*b[3])%MOD,(a[2]*b[0]+a[3]*b[2])%MOD,(a[2]*b[1]+a[3]*b[3])%MOD]
    def command():
        op=rng.randrange(1,4);return (op,[rng.randrange(10) for i in range(4)])
    def line(c):return str(c[0])+(' '+' '.join(map(str,c[1])) if c[0]!=3 else '')
    for _ in range(110):
        n=rng.randrange(1,90);a=[command() for i in range(n)];initial=a[:];ops=[];out=[]
        for j in range(40):
            if j%3==0:
                i=rng.randrange(n);a[i]=command();ops.append(f'1 {i+1} '+line(a[i]))
            else:
                l=rng.randrange(n);r=rng.randrange(l,n);ops.append(f'2 {l+1} {r+1}');live=[]
                for c in a[l:r+1]:
                    if c[0]==3:
                        if live:live.pop()
                    else:live.append(c)
                dq=collections.deque()
                for op,mat in live:
                    if op==1:dq.appendleft(mat)
                    else:dq.append(mat)
                ans=[1,0,0,1]
                for mat in dq:ans=mul(ans,mat)
                out.append(' '.join(map(str,ans)))
        case('202312D',f'{n} {len(ops)}\n'+'\n'.join(map(line,initial))+'\n'+'\n'.join(ops)+'\n','\n'.join(out))
    directions=[(1,0),(1,1),(0,1),(-1,1),(-1,0),(-1,-1),(0,-1),(1,-1)]
    for _ in range(120):
        n=rng.randrange(1,15);m=rng.randrange(1,15);p=rng.randrange(1,min(n*m,50)+1);points=rng.sample(list(itertools.product(range(1,n+1),range(1,m+1))),p);initial=points[:];ops=[]
        for j in range(35):
            u=rng.randrange(1,n+1);v=rng.randrange(1,m+1);t=rng.randrange(1,8);ops.append((u,v,t));boundary=min(u-1,v-1,n-u,m-v);k=0
            for dist in range(1,boundary+1):
                if any((u+dist*dx,v+dist*dy) in points for dx,dy in directions):k=dist;break
            if k:
                for i,(x,y) in enumerate(points):
                    for d,(dx,dy) in enumerate(directions):
                        if (x,y)==(u+k*dx,v+k*dy):dd=directions[(d+t)%8];points[i]=(u+k*dd[0],v+k*dd[1]);break
        ans=0
        for i,(x,y) in enumerate(points,1):ans^=i*x+y
        data=f'{n} {m} {p} {len(ops)}\n'+''.join(f'{x} {y}\n' for x,y in initial)+''.join(f'{u} {v} {t}\n' for u,v,t in ops)
        case('202309D',data,ans)
    for _ in range(160):
        n=rng.randrange(1,8);k=rng.randrange(1,4);edges={(u,rng.randrange(u)) for u in range(1,n)}
        for u in range(n):
            for v in range(u):
                if rng.randrange(3)==0:edges.add((u,v))
        cost=[[rng.randrange(10) for j in range(k)] for i in range(n)];edgecost={(u,v):[[rng.randrange(10) for j in range(k)] for i in range(k)] for u,v in edges};best=10**9
        for labels in itertools.product(range(k),repeat=n):
            val=sum(cost[i][labels[i]] for i in range(n))+sum(a[labels[u]][labels[v]] for (u,v),a in edgecost.items());best=min(best,val)
        data=f'{n} {len(edges)} {k}\n'+''.join(' '.join(map(str,row))+'\n' for row in cost)+''.join(f'{u} {v} '+' '.join(str(x) for row in a for x in row)+'\n' for (u,v),a in edgecost.items())
        case('202305D',data,best)
    for _ in range(100):
        a=[0]*50;ops=[];out=[];digits=rng.choice([4,8,32,128])
        def addr(x):
            s=format(x,'0'+str(digits)+'x');return ':'.join(s[i:i+4] for i in range(0,digits,4))
        for j in range(50):
            op=rng.randrange(1,4);l=rng.randrange(50);r=rng.randrange(l,50)
            if op==1:
                who=rng.randrange(1,6);ok=0 in a[l:r+1] and all(x in (0,who) for x in a[l:r+1]);out.append('YES' if ok else 'NO');ops.append(f'1 {who} {addr(l)} {addr(r)}')
                if ok:a[l:r+1]=[who]*(r-l+1)
            elif op==2:out.append(str(a[l]));ops.append(f'2 {addr(l)}')
            else:out.append(str(a[l]) if len(set(a[l:r+1]))==1 else '0');ops.append(f'3 {addr(l)} {addr(r)}')
        case('202303D',f'{digits*4} {len(ops)}\n'+'\n'.join(ops)+'\n','\n'.join(out))
    for _ in range(100):
        mirrors={};ops=[];out=[]
        for j in range(40):
            op=rng.randrange(1,4)
            if op==1 or not mirrors:
                # Separated x bands prevent intersections; width <= 4.
                x=j*6;y=rng.randrange(-10,11);length=rng.randrange(1,5);slope=rng.choice([-1,1]);ratio=rng.choice([0.5,0.75]);mirrors[len(ops)+1]=(x,y,x+length,y+slope*length,ratio,slope);ops.append(f'1 {x} {y} {x+length} {y+slope*length} {ratio}')
            elif op==2:
                index=rng.choice(list(mirrors));del mirrors[index];ops.append(f'2 {index}')
            else:
                x=rng.randrange(-10,250);y=rng.randrange(-15,16);direction=rng.randrange(4);intensity=rng.choice([1,2,16,256]);time=rng.randrange(1,100)
                points={(a+d,b+s*d):(ratio,s) for a,b,c,e,ratio,s in mirrors.values() for d in range(1,c-a)}
                if (x,y) in points:continue
                ops.append(f'3 {x} {y} {direction} {intensity} {time}')
                for step in range(time):
                    dx,dy=directions[direction*2];x+=dx;y+=dy
                    if (x,y) in points:
                        ratio,s=points[x,y];intensity*=ratio
                        vx,vy=dx,dy;vx,vy=(vy,vx) if s==1 else (-vy,-vx);direction=[(1,0),(0,1),(-1,0),(0,-1)].index((vx,vy))
                    if intensity<1:break
                out.append('0 0 0' if intensity<1 else f'{x} {y} {int(intensity)}')
        case('202206D',str(len(ops))+'\n'+'\n'.join(ops)+'\n','\n'.join(out))
    for _ in range(120):
        size=40;owner=[0]*(size+1);value=[0]*(size+1);ops=[];out=[]
        for j in range(80):
            op=rng.randrange(4);l=rng.randrange(1,size+1);r=rng.randrange(l,size+1);who=rng.randrange(1,5)
            if op==0:
                x=rng.randrange(-10,11);ops.append(f'0 {who} {l} {r} {x}');last=-1
                for i in range(l,r+1):
                    if owner[i]>0 and owner[i]!=who:break
                    owner[i]=who;value[i]=x;last=i
                out.append(str(last))
            elif op in (1,2):
                required=who if op==1 else -who;ok=all(owner[i]==required for i in range(l,r+1));ops.append(f'{op} {who} {l} {r}');out.append('OK' if ok else 'FAIL')
                if ok:
                    for i in range(l,r+1):owner[i]=-required
            else:ops.append(f'3 {l}');out.append(f'{owner[l]} {value[l]}' if owner[l]>0 else '0 0')
        case('202112D',f'4 {size} {len(ops)}\n'+'\n'.join(ops)+'\n','\n'.join(out))
    for _ in range(80):
        n=rng.randrange(1,6);k=rng.randrange(1,6);weights=[rng.randrange(1,10) for i in range(n)];p=[x/sum(weights) for x in weights];dp={(0,0):1.0};expected=0.0
        for steps in range(1,n*k+1):
            nxt=collections.defaultdict(float)
            for (mask,coins),prob in dp.items():
                for i,pi in enumerate(p):
                    s=mask|(1<<i);c=coins+(1 if mask>>i&1 else 0);mass=prob*pi
                    if c>=k*(n-bin(s).count('1')):expected+=steps*mass
                    else:nxt[s,c]+=mass
            dp=nxt
        check('202109D',f'{n} {k}\n'+' '.join(map(str,p))+'\n',expected,1e-8);report['202109D']=report.get('202109D',0)+1
