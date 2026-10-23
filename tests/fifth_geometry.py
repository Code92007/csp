from fifth_support import *
import math
def run(date):
    for _ in range(60):
        if date=='202406':
            n=rng.randint(1,30);rects=[];queries=[];out=[]
            for i in range(n):a,b=sorted([rng.randint(1,n),rng.randint(1,n)]);c,d=sorted([rng.randint(1,n),rng.randint(1,n)]);rects.append((a,b,c,d,rng.randint(1,n)))
            for i in range(40):
                a,b=sorted([rng.randint(1,n),rng.randint(1,n)]);c,d=sorted([rng.randint(1,n),rng.randint(1,n)]);queries.append((a,b,c,d));out.append(max([0]+[v for x,y,z,t,v in rects if x<=b and y>=a and z<=d and t>=c]))
            inp=f'{n} {len(queries)}\n'+''.join(' '.join(map(str,x))+'\n' for x in rects+queries);ans='\n'.join(map(str,out))
        elif date=='202104':
            n=rng.randint(2,6);m=rng.randint(1,4);routes=[];periods=[];lines=[]
            for i in range(m):
                stops=rng.sample(range(n),rng.randint(2,n));time=0;offset={};items=[]
                for s in stops:
                    offset[time]=s;w=rng.randint(1,3);time+=w;items.extend([s+1,w])
                routes.append(offset);periods.append(time);lines.append(str(len(stops))+' '+' '.join(map(str,items)))
            active=[False]*m;arrival=[None]*n
            for t in range((m+1)*(max(periods)**2+max(periods))):
                positions=[routes[i].get(t%periods[i],-1) for i in range(m)]
                for i in range(m):
                    if positions[i]==0:active[i]=True
                for i in range(m):
                    if active[i] and positions[i]>=0:
                        for j in range(m):
                            if positions[j]==positions[i]:active[j]=True
                for i in range(m):
                    if active[i] and positions[i]>=0 and arrival[positions[i]] is None:arrival[positions[i]]=t
            inp=f'{n} {m}\n'+'\n'.join(lines)+'\n';ans='\n'.join('inf' if t is None else str(t) for t in arrival[1:])
        elif date=='202206':
            n=rng.randint(1,20);points=[[rng.uniform(-10,10),rng.uniform(-10,10)] for i in range(n)];initial=[p[:] for p in points];ops=[];out=[]
            for turn in range(70):
                op=rng.randint(1,7);l=rng.randrange(n);r=rng.randrange(l,n);a,b=rng.uniform(-5,5),rng.uniform(-5,5);theta=rng.uniform(-1.4,1.4);scale=rng.uniform(-1.2,1.2)
                if op==6:ops.append(f'6 {l+1} {r+1}');out.extend([sum(p[j] for p in points[l:r+1])/(r-l+1) for j in range(2)]);continue
                if op==7:ops.append(f'7 {l+1} {r+1} {a} {b}');out.append(sum((x-a)**2+(y-b)**2 for x,y in points[l:r+1]));continue
                if op==1:ops.append(f'1 {l+1} {r+1} {a} {b}')
                elif op in (2,3):ops.append(f'{op} {l+1} {r+1} {a} {b} {theta if op==2 else scale}')
                else:ops.append(f'{op} {l+1} {r+1} {theta} {b}')
                for i in range(l,r+1):
                    x,y=points[i]
                    if op==1:x,y=x+a,y+b
                    elif op==2:x,y=a+(x-a)*math.cos(theta)-(y-b)*math.sin(theta),b+(x-a)*math.sin(theta)+(y-b)*math.cos(theta)
                    elif op==3:x,y=a+(x-a)*scale,b+(y-b)*scale
                    else:
                        dot=x*math.cos(theta)+(y-b)*math.sin(theta);px,py=dot*math.cos(theta),b+dot*math.sin(theta)
                        x,y=(2*px-x,2*py-y) if op==4 else (px,py)
                    points[i]=[x,y]
            inp=f'{n} {len(ops)}\n'+''.join(f'{x} {y}\n' for x,y in initial)+'\n'.join(ops)+'\n';ans='\n'.join(map(str,out))
        else:raise ValueError(date)
        check(date,inp,ans)
    print(date,report[date],flush=True)
