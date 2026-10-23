from fourth_support import *
def first():
    for _ in range(100):
        k=rng.choice([11,13,15,999999999]);n=rng.randrange(1,15);a=[rng.randrange(200) for i in range(n)];original=a[:];ops=[];out=[]
        def add(x,y):
            ans=0;power=1
            while x or y:ans+=((x%k+y%k)%k)*power;x//=k;y//=k;power*=k
            return ans
        def f(x):
            # Enumerate the defining recurrence, independently of the closed formula.
            result=0
            for v in range(1,x+1):result=add(result,v)
            return result
        for j in range(20):
            l=rng.randrange(n);r=rng.randrange(l,n)
            if j%2:
                result=0
                for x in a[l:r+1]:result=add(result,f(x))
                out.append(result);ops.append(f'2 {l+1} {r+1}')
            else:
                v=rng.randrange(100);ops.append(f'1 {l+1} {r+1} {v}')
                for i in range(l,r+1):a[i]=add(a[i],v)
        case('202603D',f'{n} {len(ops)} {k}\n'+' '.join(map(str,original))+'\n'+'\n'.join(ops)+'\n','\n'.join(map(str,out)))
    total=[0,0]
    for b in range(1,81):
        divisors=[x for x in range(1,b*b+1) if b*b%x==0]
        for c in divisors:
            for e in divisors:
                if b**3%(c*e):continue
                d=b**3//(c*e);total[0]+=d
                if len({b*b//c,b,c,d,e,b*b//e})==6:total[1]+=d
        for op in (0,1):case('202512D',f'{op} {b}\n',total[op]%998244353)
    for _ in range(150):
        n=rng.randrange(1,50);edges=[(v,rng.randrange(v)) for v in range(1,n)];g=[[] for i in range(n)]
        for u,v in edges:g[u].append(v);g[v].append(u)
        a=list(range(n));rng.shuffle(a);queries=[];out=[]
        for j in range(30):
            u=rng.randrange(n);v=rng.randrange(n);queries.append((u,v));par={u:-1};todo=[u]
            for x in todo:
                for y in g[x]:
                    if y not in par:par[y]=x;todo.append(y)
            values=set()
            while v!=-1:values.add(a[v]);v=par[v]
            mex=0
            while mex in values:mex+=1
            out.append(mex)
        data=f'{n} {len(queries)}\n'+' '.join(map(str,a))+'\n'+''.join(f'{u+1} {v+1}\n' for u,v in edges+queries)
        case('202509D',data,'\n'.join(map(str,out)))
