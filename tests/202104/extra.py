"""Analytical maxima and independent number-theory boundary answers."""
import math


def cases():
    yield dict(problem='A',kind='stress',label='500x500 image and 256 levels',input='500 500 256\n'+'255 '*250000+'\n',output='0 '*255+'250000')
    yield dict(problem='B',kind='stress',label='600x600 uniform equality threshold',input='600 256 100 200\n'+'200 '*360000+'\n',output='360000')
    n=10000
    data=[f'{n} 1000000000 1000000000 1000000000 h',str(n)]
    data.extend(f'{i} a{i} * DIS 0 0' for i in range(1,n+1))
    ans=[f'h a{i} OFR {i} {1000000000+i}' for i in range(1,n+1)]
    yield dict(problem='C',kind='stress',label='10000 addresses and leases crossing signed int',input='\n'.join(data)+'\n',output='\n'.join(ans))
    n=1000;span=(n-1)*100;ways=[0]*n
    for d in range(1,span+1):
        k=d//math.gcd(d,100)
        if k<n and d<100*k:ways[k]+=1
    dp=[1]+[0]*(n-1)
    for i in range(1,n):dp[i]=sum(dp[i-k]*ways[k] for k in range(1,i+1))%1000000007
    yield dict(problem='D',kind='stress',label='1000 equally spaced obstacles',input=str(n)+'\n'+' '.join(str(i*100) for i in range(n))+'\n',output=str(dp[-1]))
    for d in [2,99991,100000]:
        ways=sum(d%i==0 for i in range(1,d))
        yield dict(problem='D',kind='boundary',input=f'2\n0 {d}\n',output=str(ways))
    n=m=500
    route=str(n)+' '+' '.join(f'{i} 1000000' for i in range(1,n+1))+'\n'
    yield dict(problem='E',kind='stress',label='500 stations and 500 dense routes',input=f'{n} {m}\n'+route*m,output='\n'.join(str(i*1000000) for i in range(1,n)))
    a,b=1999999,1999997
    k=1000000*pow(b,-1,a)%a;t=b*k
    assert t>=1000000 and t%a==1000000 and t%b==0
    yield dict(problem='E',kind='boundary',input='4 2\n2 1 1000000 2 999999\n2 2 999999 3 999998\n',output=f'1000000\n{t+999999}\ninf\n')
