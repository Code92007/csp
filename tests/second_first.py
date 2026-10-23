from second_support import *
import random,json,math,itertools,bisect,collections
from fractions import Fraction
rng=random.Random(9200702)
def case(k,data,out,tol=None):check(k,data,out,tol);report[k]=report.get(k,0)+1
for _ in range(100):
 n=rng.randrange(1,8);m=rng.randrange(1,16);tasks=[(rng.randrange(2),50,rng.randrange(1,6),rng.randrange(1,40)) for i in range(n)];dp={0:Fraction(0)}
 for o,t,a,b in tasks:
  new={}
  for cost,gain in dp.items():
   for cups in ([0,a] if o else range(a+1)):
    if cost+cups<=m:new[cost+cups]=max(new.get(cost+cups,Fraction(-1)),gain+Fraction(cups*b,a))
  dp=new
 case('202603B',f'{n} {m}\n'+'\n'.join(' '.join(map(str,t)) for t in tasks),float(50*n-max(dp.values())),1e-6)
for _ in range(30):
 keys=[rng.randrange(8) for i in range(rng.randrange(1,50))];out=[]
 for x in range(512):
  for k in reversed(keys):
   A=x//64;B=x//8%8;C=x%8;b=A;c=B^((b*b+k*k)%8)^k;a=C^((c*c+k*k)%8)^k;x=64*a+8*b+c
  out.append(x)
 case('202512B',f'512 {len(keys)}\n'+' '.join(map(str,keys))+'\n'+' '.join(map(str,range(512))),' '.join(map(str,out)))
pat=['111111111','100100101','100111110','100001100','111111100']
for _ in range(60):
 n=rng.randrange(9,13);L=256;a=[[rng.randrange(20) for j in range(n)] for i in range(n)];x=rng.randrange(n-4);y=rng.randrange(n-8)
 for i in range(5):
  for j in range(9):a[x+i][y+j]=rng.randrange(12,20) if pat[i][j]=='1' else rng.randrange(10)
 out=[]
 for k in range(L):
  if any(all((a[i+u][j+v]>=k)==(pat[u][v]=='1') for u in range(5) for v in range(9)) for i in range(n-4) for j in range(n-8)):out.append(k)
 case('202509B',f'{n} {L}\n'+'\n'.join(' '.join(map(str,r)) for r in a),'\n'.join(map(str,out)))
for _ in range(100):
 n=rng.randrange(1,12);k=rng.randrange(1,10);x,y=rng.randrange(n),rng.randrange(n);seen={(x,y)};front=seen.copy()
 for j in range(k):
  front={(a+dx,b+dy) for a,b in front for dx in [-2,-1,1,2] for dy in [-2,-1,1,2] if abs(dx)+abs(dy)==3 and 0<=a+dx<n and 0<=b+dy<n};seen|=front
 case('202506B',f'{n} {k}\n{x+1} {y+1}',len(seen))
for _ in range(100):
 n=rng.randrange(1,20);m=rng.randrange(1,7);a=[rng.randrange(30) for i in range(m)]
 from functools import lru_cache
 @lru_cache(None)
 def rec(left,maxportion):
  if not left:return 0
  if not maxportion:return -10**9
  return max(rec(left-k*maxportion,maxportion-1)+k*a[maxportion-1] for k in range(left//maxportion+1))
 case('202503B',f'{n} {m}\n'+' '.join(map(str,a)),rec(n,m))
for _ in range(100):
 n=rng.randrange(1,20);a=[rng.randrange(15) for i in range(n+1)];b=[rng.randrange(30) for i in range(n)];out=[]
 for fail in range(n):
  for initial in range(sum(a)+1):
   energy=initial;ok=True
   for i,cost in enumerate(a):
    if energy<cost:ok=False;break
    energy-=cost
    if i<n and i!=fail:energy+=b[i]
   if ok:out.append(initial);break
 case('202412B',f'{n}\n'+' '.join(map(str,a))+'\n'+' '.join(map(str,b)),' '.join(map(str,out)))
for _ in range(100):
 chars=list('abc XYZ09');to=chars.copy();rng.shuffle(to);mapping=dict(zip(chars,to));s=''.join(rng.choices(chars,k=30));ks=[rng.randrange(1,1000000001) for j in range(10)];out=[]
 for k in ks:
  result=''
  for c in s:
   cycle=[c];cur=mapping[c]
   while cur!=c:cycle.append(cur);cur=mapping[cur]
   result+=cycle[k%len(cycle)]
  out.append('#'+result+'#')
 case('202409B','#'+s+'#\n'+str(len(chars))+'\n'+'\n'.join('#'+a+b+'#' for a,b in mapping.items())+'\n10\n'+' '.join(map(str,ks)),'\n'.join(out))
for _ in range(100):
 rows=rng.randrange(1,7);cols=rng.randrange(1,7);size=rows*cols;a=[[rng.randrange(-1000,1001) for j in range(cols)] for i in range(rows)];original=[r[:] for r in a];ops=[];out=[];factors=[i for i in range(1,size+1) if size%i==0]
 for j in range(30):
  typ=rng.randrange(1,4)
  if typ==1:
   p=rng.choice(factors);q=size//p;flat=sum(a,[]);a=[flat[i:i+q] for i in range(0,size,q)];ops.append(f'1 {p} {q}')
  elif typ==2:a=list(map(list,zip(*a)));ops.append('2 0 0')
  else:i=rng.randrange(len(a));k=rng.randrange(len(a[0]));out.append(a[i][k]);ops.append(f'3 {i} {k}')
 case('202406B',f'{rows} {cols} 30\n'+'\n'.join(' '.join(map(str,r)) for r in original)+'\n'+'\n'.join(ops),'\n'.join(map(str,out)))
for _ in range(100):
 a=rng.choices(['ab','Ab','cD','CD','Ef','a'],k=30);b=rng.choices(['aB','Cd','eF','hi','Hi','a'],k=25);u=set(x.lower() for x in a);v=set(x.lower() for x in b);case('202403B','30 25\n'+' '.join(a)+'\n'+' '.join(b),f'{len(u&v)}\n{len(u|v)}')
for _ in range(100):
 rows=[];out=[]
 for j in range(10):
  n=1;answer=1;k=rng.randrange(2,11)
  for p in [2,3,5,7,11,13,17,19]:
   e=rng.randrange(12)
   while n*p**e>10**10:e-=1
   n*=p**e
   if e>=k:answer*=p**e
  if n==1:n=2
  rows.append(f'{n} {k}');out.append(answer)
 case('202312B','10\n'+'\n'.join(rows),'\n'.join(map(str,out)))
for _ in range(100):
 n=40;ops=[(1,rng.choice([.5,1,2])) if i%2 else (2,rng.random()*6.2) for i in range(n)];qs=[];out=[]
 for j in range(10):
  l=rng.randrange(n);r=rng.randrange(l,n);x=rng.randrange(-1000000,1000001);y=rng.randrange(-1000000,1000001);qs.append(f'{l+1} {r+1} {x} {y}')
  for typ,v in ops[l:r+1]:
   if typ==1:x*=v;y*=v
   else:x,y=x*math.cos(v)-y*math.sin(v),x*math.sin(v)+y*math.cos(v)
  out.append(f'{x} {y}')
 case('202309B','40 10\n'+'\n'.join(f'{t} {v}' for t,v in ops)+'\n'+'\n'.join(qs),'\n'.join(out),.00001)
for _ in range(100):
 n=rng.randrange(1,12);d=rng.randrange(1,6);Q,K,V=[[[rng.randrange(-1000,1001) for j in range(d)] for i in range(n)] for t in range(3)];w=[rng.randrange(-1000,1001) for i in range(n)];large=[[sum(Q[i][a]*K[j][a] for a in range(d))*w[i] for j in range(n)] for i in range(n)];out=[[sum(large[i][j]*V[j][b] for j in range(n)) for b in range(d)] for i in range(n)];case('202305B',f'{n} {d}\n'+'\n'.join(' '.join(map(str,r)) for M in [Q,K,V] for r in M)+'\n'+' '.join(map(str,w)),'\n'.join(' '.join(map(str,r)) for r in out))
for _ in range(100):
 n=rng.randrange(1,15);k=rng.randrange(1,5);a=[(rng.randrange(k,20),rng.randrange(1,15)) for i in range(n)];m=rng.randrange(1,1000);ans=next(t for t in range(k,21) if sum(max(0,x-t)*c for x,c in a)<=m);case('202303B',f'{n} {m} {k}\n'+'\n'.join(f'{t} {c}' for t,c in a),ans)
for _ in range(100):
 L=rng.randrange(3,15);S=rng.randrange(1,min(L,5)+1);grid=[[rng.randrange(2) for j in range(L+1)] for i in range(L+1)];trees=[(i,j) for i in range(L+1) for j in range(L+1) if grid[i][j]];x,y=rng.randrange(L-S+1),rng.randrange(L-S+1);b=[r[y:y+S+1] for r in grid[x:x+S+1]];b[0][0]=1;ans=sum(all(grid[x+i][y+j]==b[i][j] for i in range(S+1) for j in range(S+1)) for x in range(L-S+1) for y in range(L-S+1));case('202206B',f'{len(trees)} {L} {S}\n'+'\n'.join(f'{x} {y}' for x,y in trees)+'\n'+'\n'.join(' '.join(map(str,r)) for r in reversed(b)),ans)
for _ in range(150):
 N=rng.randrange(2,1000);n=rng.randrange(1,N);a=sorted(rng.sample(range(1,N),n));r=N//(n+1);ans=sum(abs(x//r-bisect.bisect_right(a,x)) for x in range(N));case('202112B',f'{n} {N}\n'+' '.join(map(str,a)),ans)
for _ in range(150):
 n=rng.randrange(1,80);a=[rng.randrange(30) for i in range(n)];ans=max(sum(x>=p and (i==0 or a[i-1]<p) for i,x in enumerate(a)) for p in range(1,31));case('202109B',f'{n}\n'+' '.join(map(str,a)),ans)
for _ in range(100):
 n=rng.randrange(1,20);r=rng.randrange(1,25);L=256;t=rng.randrange(2,256);a=[[rng.randrange(256) for j in range(n)] for i in range(n)];ans=0
 for i in range(n):
  for j in range(n):
   cells=[a[x][y] for x in range(n) for y in range(n) if abs(x-i)<=r and abs(y-j)<=r];ans+=sum(cells)<=len(cells)*t
 case('202104B',f'{n} {L} {r} {t}\n'+'\n'.join(' '.join(map(str,row)) for row in a),ans)
