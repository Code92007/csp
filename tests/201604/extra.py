"""Independent enumerations and analytic boundary/maximum cases."""
import random
from collections import deque

def case(c,data,out,kind='boundary',label=''):
    return dict(problem=c,input=data,output=str(out),kind=kind,label=label)

def network(n,p,terminal,edges):
    return f'{n} {len(edges)} {p}\n'+terminal+'\n'+''.join(f'{u} {v} {w}\n' for u,v,w in edges)

def brute(n,term,edges):
    ans=10**18
    for S in range(1<<len(edges)):
        fa=list(range(n))
        def find(x):
            while x!=fa[x]:x=fa[x]
            return x
        cost=0
        for i,(u,v,w) in enumerate(edges):
            if S>>i&1:cost+=w;fa[find(u-1)]=find(v-1)
        if cost>=ans:continue
        if len({find(i) for i in range(n) if term[i]=='1'})==1:ans=cost
    return ans

def cases():
    yield case('A','1000\n'+' '.join(str(i%2*10000) for i in range(1000)),998,'stress','1000 alternating values')
    yield case('A','1\n0\n',0)
    paths=['','/','../../../../','.../a.././../b','/'*1000,'x/'*499]
    base='/a/b'
    out=['/a/b','/','/','/a/b/.../b','/','/a/b'+'/x'*499]
    yield case('C',str(len(paths))+'\n'+base+'\n'+'\n'.join(paths)+'\n','\n'.join(out),'boundary','empty path; root clipping; 1000-character line')
    # Two safe cells allow oscillation; leaving their pair is forbidden until time 101.
    data='100 100 3\n2 1 1 100\n2 2 1 100\n1 3 1 100\n'
    yield case('D',data,298,'stress','time boundary 100; 100x100; required oscillation')
    rng=random.Random(20160420261124)
    for _ in range(120):
        n=rng.randint(2,7);p=rng.randint(1,min(6,n-1));term=['0']*n
        for u in rng.sample(range(n),rng.randint(2,n)):term[u]='1'
        edges=[(u,u+1,rng.randint(0,10)) for u in range(1,n)]
        for u in range(1,n+1):
            for v in range(u+2,min(n,u+p)+1):
                if len(edges)<13 and rng.randrange(3)==0:edges.append((u,v,rng.randint(0,10)))
        text=''.join(term);ans=brute(n,text,edges)
        yield case('E','1\n'+network(n,p,text,edges),ans,'retained_independent')
    # Multiple datasets with shrinking/changing p detect stale state tables, terminal and edge costs.
    tests=[];out=[]
    for p in (6,1,4,2,6):
        n=7;term='1000001';edges=[(u,u+1,1) for u in range(1,n)]
        if p>1:edges.append((1,1+p,0))
        tests.append(network(n,p,term,edges));out.append(brute(n,term,edges))
    yield case('E','5\n'+''.join(tests),'\n'.join(map(str,out)),'boundary','five cases with changing window sizes')
    for typ in ('allzero','allone','endpoints'):
        n=500;p=6;term='1'*n if typ!='endpoints' else '1'+'0'*(n-2)+'1'
        edges=[(u,v,0 if typ=='allzero' else 1) for u in range(1,n+1) for v in range(u+1,min(n,u+p)+1)]
        ans=0 if typ=='allzero' else n-1 if typ=='allone' else (n-1+p-1)//p
        yield case('E','1\n'+network(n,p,term,edges),ans,'stress','500 vertices p=6 full bandwidth '+typ)
