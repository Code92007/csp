import importlib.util,random

def generate(root,repo):
    out=[]
    def add(p,s,a,kind='boundary',tol=None):
        v=dict(problem=p,kind=kind,input=s,output=a)
        if tol is not None:v['abs_tol']=tol
        out.append(v)
    add('A','4 10 10\n-5 -5 0 0\n0 0 5 5\n5 0 10 5\n0 5 10 10\n','100\n')
    add('B','100000 1000000000 1\n'+'100000 100000\n'*100000,'100000\n')
    spec=importlib.util.spec_from_file_location('ldap',repo/'tests/ldap_regressions.py')
    mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)
    rng=random.Random(2026112403)
    for i in range(600):
        s,a=mod.small_case(rng)
        add('C',s,a,'independent_ldap')
    for name in ['unique_attributes','deep_expression']:
        s,a=mod.maximum_case(name)
        add('C',s,a,'maximum_ldap')
    lo=':'.join(['0000']*32);hi=':'.join(['ffff']*32)
    s=f'512 6\n2 {hi}\n1 1000000000 {lo} {hi}\n3 {lo} {hi}\n1 1000000000 {lo} {hi}\n2 {hi}\n1 1 {hi} {hi}\n'
    add('D',s,'0\nYES\n1000000000\nNO\n1000000000\nNO\n')
    n=200000
    add('E',f'{n} {n-1}\n'+''.join(f'{i} {i+1}\n' for i in range(1,n)),str(n*(n-1)//2)+'\n')
    add('E',f'{n} {n}\n'+''.join(f'{i} {i}\n' for i in range(1,n+1)),str(n*(n-1)//2)+'\n')
    return out
