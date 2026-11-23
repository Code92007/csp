def generate(root,repo):
    out=[]
    def add(p,s,a):out.append(dict(problem=p,kind='boundary',input=s,output=a))
    add('A','3 10\n15 1 1\n','2\n')
    n=1000
    add('B',f'{n} 1000\n'+'1 999\n1 -999\n'*500,' '.join(map(str,range(1,n+1)))+'\n')
    add('C','_see [docs](url) now_\n\n* [_docs_](url)\n* plain\n\n###### last\n', '<p><em>see <a href="url">docs</a> now</em></p>\n<ul>\n<li><a href="url"><em>docs</em></a></li>\n<li>plain</li>\n</ul>\n<h6>last</h6>\n')
    n=100000
    add('D',f'{n} {n-1}\n'+''.join(f'{i} {i+1} 1\n' for i in range(1,n)),'1\n')
    for n,m in [(5000,5000),(2,5000),(5000,2)]:
        add('E',f'{n} {m} 1 0 1000000007 7\n',str(m*7)+'\n')
    return out
