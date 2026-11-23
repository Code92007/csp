import datetime

def generate(root,repo):
    out=[]
    def add(p,s,a):out.append(dict(problem=p,kind='boundary',input=s,output=a))
    add('A','10\n1 1 2 2 1 1 2 2 1 1\n','5\n')
    for year in [1900,2000,2004,2100]:
        for day in [59,60,61,365]:
            d=datetime.date(year,1,1)+datetime.timedelta(days=day-1)
            add('B',f'{year} {day}\n',f'{d.month}\n{d.day}\n')
    add('C','3 2\n{{ a }} {{ b }}\n{{ A }}\n{{ a }}\na "{{ b }}"\nb " x y "\n','{{ b }}  x y \n\n{{ b }}\n')
    n=10000
    add('D',f'{n} {n}\n'+''.join(f'{i} {i+1}\n' for i in range(1,n))+f'{n} 1\n',str(n*(n-1)//2)+'\n')
    add('D',f'{n} {n-1}\n'+''.join(f'{i} {i+1}\n' for i in range(1,n)),'0\n')
    length=10**15
    add('E',f'13 {length}\n'+'\n'.join('a'*i for i in range(1,14))+'\n',str(13*length-78)+'\n')
    add('E',f'1 {length}\n'+'a'*100+'\n',str(length-99)+'\n')
    return out
