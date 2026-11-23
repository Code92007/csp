from math import gcd


def cases():
    out = []
    def add(p, data, expected, kind='boundary', **kw):
        out.append(dict(problem=p, input=data, output=str(expected), kind=kind, **kw))
    for b,c,l,r in [(-20,-20,0,1000),(20,20,1,999),(0,0,0,2),(0,0,1,3)]:
        add('A',f'{b} {c} {l} {r}\n',2*sum(x*x+b*x+c for x in range(l,r+1) if x%2==0))
    add('B','1 100\n'+' '.join(['100000']*100)+'\n',100000)
    add('B','10000 100\n'+' '.join(['100000']*100)+'\n',1000000000,'stress',label='max_n_m_unit_optimum')
    ops=['1 v0 x']
    for i in range(1,1000):
        ops.append(f'2 v{i} $v{i-1} $v{i-1}')
    ops.extend(['3 v999','1 v0 abc','3 v999','1 v999 $v999 $v999','3 v999'])
    mod=10**9+7
    answer=[pow(2,999,mod),3*pow(2,999,mod)%mod,6*pow(2,999,mod)%mod]
    add('C',str(len(ops))+'\n'+'\n'.join(ops)+'\n','\n'.join(map(str,answer)),'stress',label='1000_variable_dynamic_chain_and_self_assignment')
    n=1000000
    value=1000000
    # Sum_{1<=l<=r<=n} l*r = ((sum i)^2+sum i^2)/2.
    total=n*(n+1)//2
    diagonal=n*(n+1)*(2*n+1)//6
    add('D',str(n)+'\n'+' '.join([str(value)]*n)+'\n',value*((total*total+diagonal)//2)%998244353,'stress',label='max_constant_gcd')
    add('E','1 5\n-1000000000\n1 1\n2 1 1000000000\n3 1\n2 1 -1000000000\n1 1\n','\n'.join(map(str,[-10**9,-10**9,10**9,10**9,-10**9,-10**9])))
    n=100000
    values=[1]*n
    lines=[f'{n} {n}', ' '.join(map(str,values))]+[f'{i} {i+1}' for i in range(1,n)]
    ops=[]
    answers=[n]
    for i in range(1,n+1):
        ops.append(f'2 {i} 2')
        answers.append(n+i)
    add('E','\n'.join(lines+ops)+'\n','\n'.join(map(str,answers)),'stress',label='100000_node_chain_updates')
    return out
