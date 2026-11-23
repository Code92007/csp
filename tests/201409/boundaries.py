from functools import lru_cache

def generate(root,repo):
    out=[]
    def add(p,s,a):out.append(dict(problem=p,kind='boundary',input=s,output=a))
    add('A','6\n0 1 2 4 6 7\n','3\n')
    add('B','100\n'+'0 0 100 100\n'*100,'10000\n')
    add('C','aBc\n0\n4\nABC\nabCdef\nacb\nA\n','ABC\nabCdef\n')
    add('D','1000 1 2 0\n1 1\n1000 1000 100\n1000 1000 100\n','399600\n')
    # Literal exact cover of cells, independent of the row-transfer DP.
    for n,m in [(1,7),(2,7),(3,7),(4,6),(5,3),(6,4)]:
        target=(1<<(n*m))-1
        moves=[[] for _ in range(n*m)]
        for x in range(n-1):
            for y in range(m-1):
                cells=[x*m+y,x*m+y+1,(x+1)*m+y,(x+1)*m+y+1]
                for miss in range(4):
                    mask=sum(1<<c for j,c in enumerate(cells) if j!=miss)
                    for j,c in enumerate(cells):
                        if j!=miss:moves[c].append(mask)
        @lru_cache(None)
        def ways(mask):
            if mask==target:return 1
            missing=target^mask
            pos=(missing&-missing).bit_length()-1
            return sum(ways(mask|a) for a in moves[pos] if not(a&mask))
        add('E',f'{n} {m}\n',str(ways(0)%1000000007)+'\n')
    n=999999999999999
    add('E',f'{n} 2\n',str(pow(2,n//3,1000000007))+'\n')
    return out
