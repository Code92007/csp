"""Independent boundary constructions for 202506; no baseline output oracle."""
def generate(root,repo):
    cases=[]
    def add(p,name,data,answer):
        cases.append(dict(problem=p,kind='boundary',name=name,input=data,output=str(answer)))
    rows=[]
    answer=[]
    for sig in [1,2,4,5,10,20,25,50,100]:
        for mu in [0,100]:
            for delta in [0,1,2,3]:
                rows.append(f'{mu} {sig} {mu+delta}')
                value=100*delta//sig
                answer.append(f'{value//10+1} {value%10+1}')
    add('A','all-denominators',str(len(rows))+'\n'+'\n'.join(rows)+'\n','\n'.join(answer))
    add('B','single-cell','1 1\n1 1\n',1)
    add('B','corner-one-step','100 1\n1 1\n',3)
    add('B','full-board','100 100\n1 1\n',10000)
    def short(s):
        def digit(c):return 0 if c==' ' else ord(c)-ord('0')+1 if c.isdigit() else ord(c)-ord('A')+11
        value=digit(s[0])*36+(ord(s[1])-ord('0') if s[1].isdigit() else ord(s[1])-ord('A')+10)
        value=value*10+int(s[2])
        for c in s[3:]:value=value*26+ord(c)-ord('A')
        return (1<<25)+value
    u,v='AB1CDE','CD2FGH'
    count=100000
    messages=[]
    answer=[]
    for i in range(count):
        pos=i%32768
        messages.append('0'+format(short(u),'028b')+format(short(v),'028b')+format(pos,'015b'))
        answer.append(u+' '+v+(f' {pos}' if pos else ''))
    add('C','maximum-messages',str(count)+'\n'+'\n'.join(messages)+'\n','\n'.join(answer))
    add('D','too-short','8 0\n',0)
    add('D','exact-patterns','9 0\n',1)
    add('D','separated-patterns','10 1\n4\n',1)
    count=1000000
    add('D','million-holes',f'{count} {count}\n'+' '.join(map(str,range(1,count+1)))+'\n',0)
    n=100000
    edges=''.join(f'{i} {i+1}\n' for i in range(1,n))
    allpoints=str(n)+' '+' '.join(map(str,range(1,n+1)))+'\n'
    data=f'{n} {n-1} 3\n'+edges+allpoints+'1 1\n2 1 '+str(n)+'\n'
    answer=[sum(max(i,n-1-i) for i in range(n)),n-1,n]
    add('E','maximum-chain',data,'\n'.join(map(str,answer)))
    edges=''.join(f'1 {i}\n' for i in range(2,n+1))
    add('E','maximum-star',f'{n} {n-1} 1\n'+edges+allpoints,1+(n-1)**2)
    edges=''.join(f'{i} {i+1}\n' for i in range(1,n))+f'{n} 1\n'
    add('E','maximum-cycle',f'{n} {n} 1\n'+edges+allpoints,n*(n-1))
    return cases
