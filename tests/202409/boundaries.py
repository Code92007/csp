def generate(root,repo):
    cases=[]
    def add(p,s,out):cases.append(dict(problem=p,kind='boundary',input=s,output=out))
    add('A','5\nAa1*bc\nAAA1*2\n123456\naA1#bB\naaa111***\n','2\n1\n0\n2\n1\n')
    add('B','# aZ09 #\n3\n# a#\n#a #\n#Z0#\n4\n0\n1\n2\n1000000000\n','# aZ09 #\n#a 009a#\n# a009 #\n# a009 #\n')
    add('C','1\nx\n@@ -999999999999999999999999,1 +1,1 @@\n-x\n+y\n','Patch is damaged.\n')
    n=5000
    add('D',f'{n} 1\n'+'0 0\n'*n+'0 0 1000000000 1000000000\n','1000000000\n')
    add('D','2 1\n-1000000000 -1000000000\n1000000000 1000000000\n0 0 1000000000 999999999\n','999999999\n')
    n=100000
    add('E',f'{n} {n} {n-1}\n'+' '.join(map(str,range(1,n+1)))+'\n'+''.join(f'1 {i} {i}\n' for i in range(1,n)),'1 1\n'*(n-1))
    return cases
