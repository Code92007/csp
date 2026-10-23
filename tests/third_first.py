from third_support import *
import string,itertools
def run():
    for _ in range(100):
        n=4;processes=[[] for i in range(n)];memory=[False]*1000;ops=[];out=[]
        for j in range(60):
            p=rng.randrange(n);op=rng.choice(['new','send','delete']) if processes[p] else 'new'
            if op=='new':
                length=rng.randrange(1,9);runs=[];start=0
                while start<len(memory):
                    if memory[start]:start+=1;continue
                    end=start
                    while end<len(memory) and not memory[end]:end+=1
                    if end-start>=length:runs.append((end-start,start))
                    start=end
                _,l=min(runs);memory[l:l+length]=[True]*length;processes[p].append([l,length,0]);ops.append(f'new {p+1} {length}');out.append(l)
            elif op=='send':
                total=0
                for queue in processes[p]:l,length,count=queue;total+=l+count%length;queue[2]+=1
                ops.append(f'send {p+1}');out.append(total)
            else:
                i=rng.randrange(len(processes[p]));l,length,count=processes[p].pop(i);memory[l:l+length]=[False]*length;ops.append(f'delete {p+1} {i+1}')
        case('202603C',f'{n} {len(ops)}\n'+'\n'.join(ops)+'\n','\n'.join(map(str,out)))
    def cw(a):return [list(row) for row in zip(*a[::-1])]
    for _ in range(100):
        z=rng.randrange(1,13);n=rng.randrange(1,z+1);m=rng.randrange(1,z+1);original=[''.join(rng.choice('aB3_') for j in range(m)) for i in range(n)];image=[list(row+'?'*(z-m)) for row in original]+[list('?'*z) for i in range(z-n)];ops=[]
        for j in range(30):
            if rng.randrange(2):
                length=rng.randrange(1,min(z,10)+1);u=rng.randrange(z-length+1);v=rng.randrange(z-length+1);turns=rng.randrange(1,4);whole=rng.randrange(4);ops.append([1,u+1,v+1,length,turns*90,whole]);part=[row[v:v+length] for row in image[u:u+length]]
                for i in range(turns):part=cw(part)
                for i,row in enumerate(part):image[u+i][v:v+length]=row
                for i in range((4-whole)%4):image=cw(image)
            else:
                h=rng.randrange(1,min(z,10)+1);w=rng.randrange(1,min(z,10)+1);u=rng.randrange(z-h+1);l=rng.randrange(z-w+1);flip=rng.choice([-1,1]);ops.append([2,u+1,u+h,l+1,l+w,flip]);part=[row[l:l+w] for row in image[u:u+h]];part=part[::-1] if flip==1 else [row[::-1] for row in part]
                for i,row in enumerate(part):image[u+i][l:l+w]=row
        data=str(z)+'\n'+'\n'.join(''.join(row) for row in image)+f'\n{len(ops)*6+1}\n{len(ops)} '+' '.join(str(x) for op in ops for x in op)+'\n'
        case('202512C',data,f'{n} {m}\n'+'\n'.join(original))
    for _ in range(100):
        codes={'a':'00','b':'01','H':'10','7':'11'};tree='001a1b01H17';capacity=rng.randrange(1,6);fixed=[('rawH','HHH'),('x','y')];dynamic=[];ops=[];out=[]
        def encode(s):
            if rng.randrange(2):return 'H'+s if s.startswith('H') else s
            bits=''.join(codes[c] for c in s);padding=(-len(bits))%8;bits+='0'*padding;return 'H'+''.join(format(int(bits[i:i+8],2),'02x') for i in range(0,len(bits),8))+format(padding,'02x')
        for j in range(30):
            kind=rng.randrange(1,4);table=fixed+dynamic
            if kind==1:
                index=rng.randrange(len(table));header=table[index];ops.append(f'1 {index+1}')
            else:
                value=''.join(rng.choice(list(codes)) for i in range(rng.randrange(1,15)))
                if rng.randrange(2):index=rng.randrange(len(table));key=table[index][0];ops.append(f'{kind} {index+1} {encode(value)}')
                else:key=''.join(rng.choice(list(codes)) for i in range(rng.randrange(1,10)));ops.append(f'{kind} 0 {encode(key)} {encode(value)}')
                header=(key,value)
                if kind==2:dynamic=([header]+dynamic)[:capacity]
            out.append(header[0]+': '+header[1])
        data=f'2 {capacity}\n'+''.join(f'{a} {b}\n' for a,b in fixed)+tree+'\n'+str(len(ops))+'\n'+'\n'.join(ops)+'\n';case('202509C',data,'\n'.join(out))
    alphabet=' 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_'
    def numeric(s):
        x=0
        for c in s.ljust(11):x=x*38+alphabet.index(c)
        return x
    def hash(s,bits):return (numeric(s)*47055833459>>(64-bits))%(1<<bits)
    def short(s):
        s=s.rjust(6);x=alphabet.index(s[0]);x=x*36+'0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'.index(s[1]);x=x*10+int(s[2])
        for c in s[3:]:x=x*26+ord(c)-65
        return x+(1<<25)
    for _ in range(100):
        history=[];messages=[];out=[];names=['ABCD200_'+str(i) for i in range(10)]+['A0BCD','B1XYZ','9Z2AAA','PY4XMCHJZTN']
        def infer(value,bits):
            for name in history[::-1]:
                if hash(name,bits)==value:return '#'+name
            return '###'
        for j in range(35):
            direct=[]
            if rng.randrange(2):
                receiver=rng.choice(names);sender=rng.choice(names);r_literal=receiver in names[10:13] and rng.randrange(2);s_literal=sender in names[10:13] and rng.randrange(2);r=short(receiver) if r_literal else hash(receiver,25);s=short(sender) if s_literal else hash(sender,25);location=rng.choice([0,1,32400]);messages.append('0'+format(r,'028b')+format(s,'028b')+format(location,'015b'));line=(receiver if r_literal else infer(r,25))+' '+(sender if s_literal else infer(s,25))+(f' {location}' if location else '')
                if r_literal:direct.append(receiver)
                if s_literal:direct.append(sender)
            else:
                literal=rng.choice(names);other=rng.choice(names);which=rng.randrange(2);h=hash(other,12);messages.append('1'+format(numeric(literal),'058b')+format(h,'012b')+str(which));line=literal+' '+infer(h,12) if which else infer(h,12)+' '+literal;direct=[literal]
            out.append(line);history+=direct
        case('202506C',str(len(messages))+'\n'+'\n'.join(messages)+'\n','\n'.join(out))
    for _ in range(100):
        definitions=[[] for i in range(8)];direct=[True]*8;values=['']*8;ops=[];out=[]
        def evaluate(u):return values[u] if direct[u] else ''.join(evaluate(v) if isinstance(v,int) else v for v in definitions[u])
        for j in range(50):
            u=rng.randrange(8);op=rng.randrange(1,4)
            if op==3:ops.append(f'3 v{u}');out.append(len(evaluate(u))%1000000007);continue
            expr=[rng.randrange(u) if u and rng.randrange(2) else 'abc'[:rng.randrange(1,4)] for z in range(rng.randrange(1,4))];ops.append(f'{op} v{u} '+' '.join(f'$v{x}' if isinstance(x,int) else x for x in expr))
            if op==1:values[u]=''.join(evaluate(x) if isinstance(x,int) else x for x in expr);direct[u]=True
            else:definitions[u]=expr;direct[u]=False
        case('202503C',str(len(ops))+'\n'+'\n'.join(ops)+'\n','\n'.join(map(str,out)))
    for _ in range(100):
        ways=rng.choice([1,2,4,8]);groups=rng.choice([1,2,4]);cache=[{} for i in range(groups)];ops=[];out=[]
        for time in range(60):
            op=rng.randrange(2);address=rng.randrange(60);ops.append((op,address));group=cache[(address//ways)%groups]
            if address in group:old,dirty=group[address];group[address]=(time,dirty or op);continue
            if len(group)==ways:
                victim=min(group,key=lambda x:group[x][0]);_,dirty=group.pop(victim)
                if dirty:out.append(f'1 {victim}')
            out.append(f'0 {address}');group[address]=(time,op)
        case('202412C',f'{ways} {groups} {len(ops)}\n'+''.join(f'{op} {a}\n' for op,a in ops),'\n'.join(out))
