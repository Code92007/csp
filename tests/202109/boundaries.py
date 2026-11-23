import math

def generate(root,repo):
    out=[]
    def add(p,s,a,tol=None):
        v=dict(problem=p,kind='boundary',input=s,output=a)
        if tol is not None:v['abs_tol']=tol
        out.append(v)
    add('A','100\n'+'100 '*100+'\n','10000\n100\n')
    add('B','500000\n'+'0 10000 '*250000+'\n','250000\n')
    add('C','1 0 0 1\n0.1\n1 -65 -13 0.02 0.2 -65 8\n','-65.300 -65.300\n0 0\n',0.00051)
    n,k=16,5
    # Exchangeable cards permit an independent DP indexed only by set size.
    dp=[[0.0]*(n*k+1) for _ in range(n+1)]
    for h in range(n-1,-1,-1):
        for c in range((n-h)*k-1,-1,-1):
            dp[h][c]=1+h/n*dp[h][c+1]+(n-h)/n*dp[h+1][c]
    add('D',f'{n} {k}\n'+'0.0625 '*n+'\n',str(dp[0][0])+'\n',1e-9)
    add('D','1 5\n1\n','1\n',1e-9)
    # Long historical chain and overlapping lazy multiplies; arithmetic is exact.
    n=299995;p=1073741789
    rows=[f'{n+5} {p} 0']+['1 1000000000']*n
    rows += [f'2 {n} 1 {n} 1000000000',f'3 {n} 1 {n}',f'2 {n} 1 {n} 0',f'3 {n} 1 {n}',f'3 {n} 1 1']
    ans=n*1000000000*1000000000%p
    add('E','\n'.join(rows)+'\n',f'{ans}\n0\n0\n')
    return out
