from third_support import *
from fractions import Fraction
def run():
    for _ in range(120):
        n=rng.randrange(3,30);original=[rng.choice(['a','b','c','','#orig']) for i in range(n)];blocks=[];position=1
        while position<=n and len(blocks)<5:
            length=rng.randrange(1,min(5,n-position+1)+1);new=[rng.choice(['x','y','']) for i in range(rng.randrange(1,5))];before=original[position-1:position-1+length]
            declared=position
            if not blocks:declared=max(1,position+rng.randrange(-length+1,length))
            if blocks:declared=max(declared,blocks[-1][0]+len(blocks[-1][1]))
            blocks.append((declared,before,new));position+=length+rng.randrange(3)
        lines=['ignored prelude','# ignored'];offset=0;consumed=0;out=[];valid=True
        for declared,before,new in blocks:
            lines.append(f'@@ -{declared},{len(before)} +1,{len(new)} @@');lines+=['-'+s for s in before]+['+'+s for s in new];lines.append('# ignored inside')
            possible=[]
            for start in range(consumed,n-len(before)+1):
                delta=start-(declared-1+offset)
                if abs(delta)<len(before) and original[start:start+len(before)]==before:possible.append((abs(delta),delta,start))
            if not possible:valid=False;continue
            _,delta,start=min(possible);out+=original[consumed:start]+new;consumed=start+len(before);offset+=delta
        if valid:out+=original[consumed:]
        if rng.randrange(4)==0:lines+=['@@ -01,2 +1,2 @@','-a',' b','+c'];valid=False
        case('202409C',str(n)+'\n'+'\n'.join(original)+'\n'+'\n'.join(lines)+'\n','\n'.join(out) if valid else 'Patch is damaged.')
    for _ in range(130):
        n=rng.randrange(1,8);words=[''.join(rng.choice('abc') for j in range(rng.randrange(1,18))) for i in range(n)];freq=[rng.randrange(1,10) for i in range(n)];target=rng.randrange(3,20);vocab=sorted(set(''.join(words)));sequences=[list(s) for s in words]
        while len(vocab)<target:
            counts=collections.Counter()
            for seq,f in zip(sequences,freq):
                for pair in zip(seq,seq[1:]):counts[pair]+=f
            if not counts:break
            pair=min(counts,key=lambda p:(-counts[p],len(p[0]+p[1]),len(p[0]),p[0]+p[1]));joined=''.join(pair);vocab.append(joined)
            for i,seq in enumerate(sequences):
                out=[];j=0
                while j<len(seq):
                    if tuple(seq[j:j+2])==pair:out.append(joined);j+=2
                    else:out.append(seq[j]);j+=1
                sequences[i]=out
        case('202406C',f'{n} {target}\n'+''.join(f'{s} {f}\n' for s,f in zip(words,freq)),'\n'.join(vocab))
    for _ in range(110):
        rows=rng.randrange(1,9);cols=rng.randrange(1,9);matrix=[[rng.randrange(0,11) for j in range(cols)] for i in range(rows)]
        for j in range(cols):
            if not any(row[j] for row in matrix):matrix[0][j]=1
        if cols>1 and rng.randrange(2):
            for row in matrix:row[-1]=row[0]
        a=[[Fraction(x) for x in row] for row in matrix];rank=0
        for col in range(cols):
            pivot=next((i for i in range(rank,rows) if a[i][col]),None)
            if pivot is None:continue
            a[rank],a[pivot]=a[pivot],a[rank]
            for i in range(rank+1,rows):
                factor=a[i][col]/a[rank][col]
                for j in range(col,cols):a[i][j]-=a[rank][j]*factor
            rank+=1
        formulas=[''.join(chr(97+i)+str(matrix[i][j]) for i in range(rows) if matrix[i][j]) for j in range(cols)]
        case('202403C','1\n'+str(cols)+' '+' '.join(formulas)+'\n','Y' if rank<cols else 'N')
    for _ in range(100):
        n=rng.randrange(1,40);order=[0]+rng.sample(list(range(1,n)),n-1);parent=[-1]*n
        for i in range(1,n):parent[order[i]]=rng.choice(order[:i])
        weight=[rng.randrange(1,20) for i in range(n)]
        def inside(u,v):
            while v!=-1:
                if v==u:return True
                v=parent[v]
            return False
        out=[]
        for target in range(n):
            active=set(range(n));questions=[]
            while len(active)>1:
                total=sum(weight[u] for u in active);chosen=min(active,key=lambda u:(abs(total-2*sum(weight[v] for v in active if inside(u,v))),u));questions.append(chosen+1);answer=inside(chosen,target);active={u for u in active if inside(chosen,u)==answer}
            out.append(' '.join(map(str,questions)))
        case('202312C',f'{n} {n}\n'+' '.join(map(str,weight))+'\n'+' '.join(str(parent[i]+1) for i in range(1,n))+'\n'+'\n'.join(str(i+1) for i in range(n))+'\n','\n'.join(out))
