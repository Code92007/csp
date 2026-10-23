from third_support import *
import random,json,subprocess,string
rng.seed(9200703)
def case(k,data,out,tol=None):check(k,data,out,tol);report[k]=report.get(k,0)+1
# Symbolic polynomial oracle for differentiation.
for _ in range(100):
 n=rng.randrange(1,5)
 def tree(d):
  if not d or rng.random()<.35:
   if rng.random()<.6:
    i=rng.randrange(n);e=[0]*n;e[i]=1;return 'x'+str(i+1),{tuple(e):1}
   c=rng.randrange(-10,11);return str(c),{(0,)*n:c}
  a,p=tree(d-1);b,q=tree(d-1);op=rng.choice('+-*');r={}
  if op=='*':
   for e,c in p.items():
    for f,v in q.items():
     t=tuple(x+y for x,y in zip(e,f));r[t]=r.get(t,0)+c*v
  else:
   r=p.copy()
   for e,c in q.items():r[e]=r.get(e,0)+(c if op=='+' else -c)
  return a+' '+b+' '+op,r
 expr,poly=tree(4);rows=[];out=[]
 for j in range(8):
  v=rng.randrange(n);a=[rng.randrange(-4,5) for i in range(n)];val=0
  for e,c in poly.items():
   if not e[v]:continue
   term=c*e[v]
   for i in range(n):term*=a[i]**(e[i]-(i==v))
   val+=term
  rows.append(' '.join(map(str,[v+1]+a)));out.append(str(val%1000000007))
 case('202309C',f'{n} 8\n{expr}\n'+'\n'.join(rows),'\n'.join(out))
# Generate a legal stream, including repeated/overlapping copy and long literals.
for _ in range(100):
 stream=[];out=[]
 for j in range(rng.randrange(2,20)):
  if not out or rng.random()<.5:
   size=rng.choice([1,4,60,61,256,300]);data=[rng.randrange(256) for i in range(size)];z=size-1
   if size<=60:stream.append(z<<2)
   else:
    b=max(1,(z.bit_length()+7)//8);stream.append((59+b)<<2);stream.extend(z.to_bytes(b,'little'))
   stream+=data;out+=data
  else:
   offset=rng.randrange(1,min(len(out),2047)+1);kind=rng.choice([1,2]);size=rng.randrange(4,12) if kind==1 else rng.randrange(1,65)
   if kind==1:stream.extend([1|((size-4)<<2)|((offset>>8)<<5),offset&255])
   else:stream.extend([2|((size-1)<<2),offset&255,offset>>8])
   block=out[-offset:];out.extend((block*((size+offset-1)//offset))[:size])
 size=len(out);header=[]
 while size>=128:header.append((size&127)|128);size>>=7
 header.append(size);stream=header+stream
 case('202305C',str(len(stream))+'\n'+bytes(stream).hex(),'\n'.join(bytes(out[i:i+8]).hex() for i in range(0,len(out),8)))
# Evaluate LDAP trees separately per user; verify empty result lines too.
for _ in range(100):
 n=rng.randrange(1,25);dns=rng.sample(range(1,1000),n);users=[{k:rng.randrange(1,6) for k in range(1,8) if rng.random()<.5} for i in range(n)]
 def gen(d):
  if not d or rng.random()<.4:
   a=rng.randrange(1,10);b=rng.randrange(1,7);op=rng.choice(':~');return f'{a}{op}{b}',lambda u:a in u and ((u[a]==b) if op==':' else (u[a]!=b))
  x,f=gen(d-1);y,g=gen(d-1);op=rng.choice('&|');return op+'('+x+')('+y+')',lambda u:(f(u) and g(u)) if op=='&' else (f(u) or g(u))
 es=[gen(4) for i in range(10)];rows=[f'{d} {len(u)} '+' '.join(f'{a} {b}' for a,b in sorted(u.items())) for d,u in zip(dns,users)];expected='\n'.join(' '.join(map(str,sorted(d for d,u in zip(dns,users) if f(u)))) for e,f in es)
 data=f'{n}\n'+'\n'.join(rows)+'\n10\n'+'\n'.join(e for e,f in es);case('202303C',data,expected)
 got=subprocess.check_output([str(binary('202303C'))],input=data,text=True);assert got.rstrip('\n')==expected.rstrip('\n')
# Separate association scan and role checks.
for _ in range(100):
 n=8;roles=[];rows=[]
 for i in range(n):
  role=[rng.sample(['a','b','c','*'],rng.randrange(1,5)),rng.sample(['x','y','z','*'],rng.randrange(1,5)),rng.sample(['foo','bar','baz'],rng.randrange(4))];roles.append(role);rows.append(f'r{i} '+' '.join(str(len(a))+' '+' '.join(a) for a in role))
 assoc=[(rng.randrange(n),[(rng.choice('ug'),rng.choice(['aa','bb','cc'])) for j in range(rng.randrange(1,6))]) for i in range(12)];qs=[];out=[]
 for j in range(20):
  u=rng.choice(['aa','bb','cc','dd']);groups=rng.sample(['aa','bb','cc','dd'],rng.randrange(5));v=rng.choice('abcd');t=rng.choice('xyzw');name=rng.choice(['foo','bar','baz','qux']);qs.append(' '.join([u,str(len(groups))]+groups+[v,t,name]));ok=False
  for ri,asgn in assoc:
   if any((kind=='u' and key==u) or (kind=='g' and key in groups) for kind,key in asgn):
    a,b,c=roles[ri];ok|=(v in a or '*' in a) and (t in b or '*' in b) and (not c or name in c)
  out.append(str(int(ok)))
 data=f'{n} 12 20\n'+'\n'.join(rows)+'\n'+'\n'.join(f'r{i} {len(a)} '+' '.join(k+' '+v for k,v in a) for i,a in assoc)+'\n'+'\n'.join(qs);case('202206C',data,'\n'.join(out))
# Verify encoding with a mode graph; parity by evaluating all generator roots.
for _ in range(100):
 text=''.join(rng.choices(string.ascii_letters+string.digits,k=rng.randrange(1,80)));w=rng.randrange(1,40);s=rng.randrange(-1,9);k=0 if s==-1 else 2**(s+1);switch={(0,1):[27],(0,2):[28],(1,0):[28,28],(1,2):[28],(2,0):[28],(2,1):[27]};mode=0;tokens=[]
 for ch in text:
  target=0 if ch.isupper() else 1 if ch.islower() else 2;tokens+=switch.get((mode,target),[]);tokens.append(ord(ch)-ord(['A','a','0'][target]));mode=target
 if len(tokens)%2:tokens.append(29)
 data=[0]+[a*30+b for a,b in zip(tokens[::2],tokens[1::2])]
 while (len(data)+k)%w:data.append(900)
 data[0]=len(data);inp=f'{w} {s}\n{text}\n';got=list(map(int,subprocess.check_output([str(binary('202112C'))],input=inp,text=True).split()));assert got[:len(data)]==data and len(got)==len(data)+k
 for j in range(1,k+1):
  root=pow(3,j,929);v=0
  for x in got:v=(v*root+x)%929
  assert v==0
 report['202112C']=report.get('202112C',0)+1
# Full timestamp event table instead of ring buffer.
for _ in range(80):
 n=rng.randrange(1,6);p=rng.randrange(1,5);T=rng.randrange(5,60);dt=.1;a=[[-70+rng.random()*10,-14,.02,.2,-65,2] for i in range(n)];initial=[x[:] for x in a];r=[rng.randrange(1,32768) for i in range(p)];edges=[(rng.randrange(n+p),rng.randrange(n),rng.randrange(1,40),rng.randrange(1,6)) for j in range(rng.randrange(1,20))];events=[[0.]*n for t in range(T+6)];count=[0]*n;seed=1
 for t in range(1,T+1):
  fired=[]
  for i in range(p):
   seed=(seed*1103515245+12345)%2**64
   if r[i]>(seed//65536)%32768:fired.append(n+i)
  for i,(v,u,aa,b,c,d) in enumerate(a):
   nv=v+dt*(.04*v*v+5*v+140-u)+events[t][i];nu=u+dt*aa*(b*v-u)
   if nv>=30:nv=c;nu+=d;fired.append(i);count[i]+=1
   a[i][0]=nv;a[i][1]=nu
  for src,dst,w,D in edges:
   if src in fired:events[t+D][dst]+=w
 inp=f'{n} {len(edges)} {p} {T}\n{dt}\n'+'\n'.join('1 '+' '.join(map(str,x)) for x in initial)+'\n'+'\n'.join(map(str,r))+'\n'+'\n'.join(' '.join(map(str,e)) for e in edges);expected=f'{min(x[0] for x in a):.3f} {max(x[0] for x in a):.3f}\n{min(count)} {max(count)}';case('202109C',inp,expected,.0011)
# Array-based DHCP oracle with no event heap, owner map or ordered sets.
for _ in range(100):
 n=rng.randrange(1,8);lo=2;hi=9;default=5;a=[[0,'',0] for i in range(n)];rows=[];out=[];time=0
 for j in range(100):
  time+=rng.randrange(1,4);u=rng.choice(['a','b','c','d']);recv=rng.choice(['H','G','*']);kind=rng.choice(['DIS','REQ','OTH']);addr=rng.randrange(0,n+2);end=rng.choice([0,time+rng.randrange(-3,15)]);rows.append(f'{time} {u} {recv} {kind} {addr} {end}')
  for x in a:
   if x[0] in [1,2] and x[2]<=time:
    if x[0]==1:x[:]=[0,'',0]
    else:x[0]=3;x[2]=0
  if recv not in ['H','*'] and kind!='REQ':continue
  if kind not in ['DIS','REQ'] or recv=='*' and kind!='DIS' or recv=='H' and kind=='DIS':continue
  if kind=='REQ' and recv!='H':
   for x in a:
    if x[0]==1 and x[1]==u:x[:]=[0,'',0]
   continue
  if kind=='DIS':
   candidates=[i for i,x in enumerate(a) if x[1]==u] or [i for i,x in enumerate(a) if x[0]==0] or [i for i,x in enumerate(a) if x[0]==3]
   if not candidates:continue
   addr=candidates[0]+1;a[addr-1][0:2]=[1,u]
  else:
   if not 1<=addr<=n or a[addr-1][1]!=u:out.append(f'H {u} NAK {addr} 0');continue
   a[addr-1][0]=2
  expiry=time+(default if end==0 else max(lo,min(hi,end-time)));a[addr-1][2]=expiry;out.append(f'H {u} '+('OFR' if kind=='DIS' else 'ACK')+f' {addr} {expiry}')
 case('202104C',f'{n} {default} {hi} {lo} H\n{len(rows)}\n'+'\n'.join(rows),'\n'.join(out))
