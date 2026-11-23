import importlib.util,random

def generate(root,repo):
    out=[]
    def add(p,s,a):out.append(dict(problem=p,kind='boundary',input=s,output=a))
    add('A','1000 10\n'+('1 '*9+'1\n')*1000,'0\n'*1000)
    add('B','6\n10000000000 10\n9999999967 2\n1 2\n99980001 2\n8589934592 32\n8589934592 34\n','10000000000\n1\n1\n99980001\n8589934592\n1\n')
    n=2000
    # Equal-weight star: the smallest surviving leaf is always asked first.
    targets=[1,2,n]
    s=f'{n} 3\n'+'1 '*n+'\n'+'1 '*(n-1)+'\n'+' '.join(map(str,targets))+'\n'
    lines=[' '.join(map(str,range(2,n+1))),'2',' '.join(map(str,range(2,n+1)))]
    add('C',s,'\n'.join(lines)+'\n')
    spec=importlib.util.spec_from_file_location('treasure',repo/'tests/treasure_regressions.py')
    mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)
    rng=random.Random(2026112404)
    for i in range(700):
        s,a=mod.random_case(rng,i)
        out.append(dict(problem='D',kind='independent_stack',input=s,output=a))
    n=100000
    add('D',f'{n} 3\n'+'1 0 0 0 0\n'*n+f'2 1 {n}\n1 {n} 3\n2 1 {n}\n','0 0 0 0\n0 0 0 0\n')
    add('D',f'{n} 3\n'+'3\n'*n+f'2 1 {n}\n1 {n} 1 998244352 998244352 998244352 998244352\n2 1 {n}\n','1 0 0 1\n998244352 998244352 998244352 998244352\n')
    add('E','9 8 9 30\n0 1 2 3 4 5 6 7 29\n0 1 2 3 4 5 6 7\n1 2 3 4 5 6 7 8\n1 2 3 4 5 6 7 8\n','36\n')
    return out
