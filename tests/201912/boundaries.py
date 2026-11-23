def generate(root,repo):
    out=[]
    def add(p,s,a):out.append(dict(problem=p,kind='boundary',input=s,output=a))
    # Independent direct enumeration of the largest reporting game.
    cnt=[0]*4;x=0;spoken=0
    while spoken<666:
        x+=1
        if x%7==0 or '7' in str(x):cnt[(x-1)%4]+=1
        else:spoken+=1
    add('A','666\n','\n'.join(map(str,cnt))+'\n')
    pts=[(x,y) for x in range(-2,3) for y in range(-2,3)]
    add('B','25\n'+''.join(f'{x} {y}\n' for x,y in pts),'0\n0\n0\n0\n9\n')
    add('C','4\n2K4(ON(SO3)2)2=K8O28N4S8\n1000000000H=H1000000000\nCo=CO\n2H2+O2=2H2O\n','Y\nY\nN\nY\n')
    n=500;k=30000
    rows=[f'{n} {n-1}']+[f'{i} {i+1}' for i in range(1,n)]+[f'1 {k}']
    rows += [f'1 {i} {i}' for i in range(1,k)]+[f'{n} 1000000000']
    add('D','\n'.join(rows)+'\n',str(k)+' '+' '.join(map(str,range(k)))+'\n')
    n=1000000;p=2009731336725594113
    magic=[314882150829468584,427197303358170108,1022292690726729920,1698479428772363217,2006101093849356424]
    mul=1;answers=[]
    for l,r in [(1,n),(1,n),(n-10,n)]:
        val=sum((i*mul%p)%2019 for i in range(l,r+1))
        answers.append(str(val));mul=mul*magic[val%5]%p
    add('E',f'{n} 3\n1 {n}\n1 {n}\n{n-10} {n}\n','\n'.join(answers)+'\n')
    return out
