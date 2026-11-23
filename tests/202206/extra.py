"""Analytical limits and independent direct geometric transformations."""
import math,random


def cases():
    yield dict(problem='A', kind='boundary', input='1000\n'+'-1000 '*500+'1000 '*500+'\n',
               output='-1\n'*500+'1\n'*500, abs_tol=1e-4)
    points=[(i*100,i*100) for i in range(1000)]
    rows=[' '.join('1' if i==j==0 else '0' for j in range(51)) for i in range(50,-1,-1)]
    yield dict(problem='B',kind='stress',label='1000 sparse trees and S=50',
               input='1000 1000000000 50\n'+''.join(f'{x} {y}\n' for x,y in points)+'\n'.join(rows)+'\n',output='1000')
    data=['500 500 5000']
    data.extend(f'r{i} 1 read 1 door 0' for i in range(500))
    data.extend(f'r{i} 1 g g{i}' for i in range(500))
    groups=' '.join('g'+str(i) for i in range(100,500))
    data.extend('x 400 '+groups+(' read door name' if i%2==0 else ' write door name') for i in range(5000))
    yield dict(problem='C',kind='stress',label='500 roles and 5000 queries of 400 groups',
               input='\n'.join(data)+'\n',output='1\n0\n'*2500)
    data=['100000','1 0 0 300000 300000 0.8']
    data.extend(f'3 -1 {i} 0 1000 500000' for i in range(1,100000))
    yield dict(problem='D',kind='stress',label='300000 total mirror length and 100000 operations',
               input='\n'.join(data)+'\n',output=''.join(f'{i} 499999 800\n' for i in range(1,100000)))
    yield dict(problem='D',kind='boundary',input='6\n1 0 0 2 2 0.5\n3 -1 0 0 10 4\n3 -1 1 0 10 2\n3 -1 2 0 10 4\n2 1\n3 -1 1 0 10 2\n',output='3 0 10\n1 1 5\n3 2 10\n1 1 10\n')
    rng=random.Random(20220620261124)
    for turn in range(200):
        n=rng.randint(1,25)
        points=[[rng.randint(-50,50),rng.randint(-50,50)] for i in range(n)]
        data=[f'{n} 100']+[' '.join(map(str,p)) for p in points]
        ans=[]
        for j in range(100):
            op=j%7+1;l=rng.randrange(n);r=rng.randrange(l,n)
            a,b=rng.randint(-25,25),rng.randint(-25,25)
            if op==6:
                data.append(f'6 {l+1} {r+1}')
                ans.extend(str(sum(p[k] for p in points[l:r+1])/(r-l+1)) for k in (0,1));continue
            if op==7:
                data.append(f'7 {l+1} {r+1} {a} {b}')
                ans.append(str(sum((x-a)**2+(y-b)**2 for x,y in points[l:r+1])));continue
            t=rng.choice([0,0.4,-0.7,1.2]);s=rng.choice([0,-1,0.5,1])
            data.append(f'{op} {l+1} {r+1} {a} {b}'+(f' {t if op==2 else s}' if op in (2,3) else '') if op<=3 else f'{op} {l+1} {r+1} {t} {b}')
            for i in range(l,r+1):
                x,y=points[i]
                if op==1:points[i]=[x+a,y+b]
                elif op==2:points[i]=[a+(x-a)*math.cos(t)-(y-b)*math.sin(t),b+(x-a)*math.sin(t)+(y-b)*math.cos(t)]
                elif op==3:points[i]=[a+(x-a)*s,b+(y-b)*s]
                else:
                    dot=x*math.cos(t)+(y-b)*math.sin(t)
                    u,v=dot*math.cos(t),b+dot*math.sin(t)
                    points[i]=[2*u-x,2*v-y] if op==4 else [u,v]
        yield dict(problem='E',kind='retained_independent',input='\n'.join(data)+'\n',output='\n'.join(ans),abs_tol=1e-3,rel_tol=1e-3)
    n=500000
    data=[f'{n} 20000']+[f'{999998+(i%2)} {999998-(i%2)}' for i in range(1,n+1)]
    ans=[]
    for i in range(5000):
        l=i*97%n+1;r=min(n,l+10000+i%123)
        cnt=r-l+1;odd=(r+1)//2-l//2
        data.extend([f'1 {l} {r} 1 -1',f'6 {l} {r}',f'7 {l} {r} 999999.5 999996.5',f'1 {l} {r} -1 1'])
        ans.extend([str(999999+odd/cnt),str(999997-odd/cnt),str(cnt/2)])
    yield dict(problem='E',kind='stress',label='500000 large close points; 20000 partial operations',
               input='\n'.join(data)+'\n',output='\n'.join(ans),abs_tol=1e-3,rel_tol=1e-3,timeout=120)
