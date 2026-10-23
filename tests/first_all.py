from first_support import *
import random,json,itertools,math,bisect,collections,functools
rng=random.Random(9200701)
def case(k,data,out,tol=None):check(k,data,out,tol);report[k]=report.get(k,0)+1
for _ in range(60):
 a=[rng.randrange(1,10**9+1) for i in range(100)];case('202603A','100\n'+' '.join(map(str,a)),sum(bin(x)[2:].count('0')==bin(x)[2:].count('1') for x in a))
for _ in range(60):
 n=20;m=30;a=[rng.randrange(16) for i in range(n)];S=[sorted(rng.sample(range(1,n+1),rng.randrange(1,n+1))) for i in range(m)];T=[s[:] if rng.random()<.3 else sorted(rng.sample(range(1,n+1),rng.randrange(1,n+1))) for s in S];out=[]
 for s,t in zip(S,T):
  f=lambda u:functools.reduce(int.__xor__,(a[i-1] for i in u),0);out.append('correct' if (set(s)==set(t))==(f(s)==f(t)) else 'wrong')
 case('202512A',f'{n} {m}\n'+' '.join(map(str,a))+'\n'+'\n'.join(str(len(s))+' '+' '.join(map(str,s)) for s in S+T),'\n'.join(out))
for _ in range(60):
 a=rng.randrange(1,1001);r=a*100;points=[(rng.randrange(-r,r+1),rng.randrange(-r,r+1)) for j in range(100)]+[(r,0),(-r,0),(0,r),(0,-r)];inside=sum(x*x+y*y<=r*r for x,y in points)
 case('202509A',f'{len(points)} {a}\n'+'\n'.join(f'{x/100:.2f} {y/100:.2f}' for x,y in points),4*inside/len(points),1e-7)
for _ in range(60):
 qs=[];out=[]
 for j in range(20):
  mu=rng.randrange(1001);n=rng.randrange(mu,1001);sigma=rng.choice([1,2,4,5,10,20,25,50,100]);qs.append((mu,sigma,n));z=f'{(n-mu)/sigma:.2f}';whole,frac=z.split('.');out.append(f'{int(whole)*10+int(frac[0])+1} {int(frac[1])+1}')
 case('202506A','20\n'+'\n'.join(' '.join(map(str,q)) for q in qs),'\n'.join(out))
for _ in range(60):
 b,c=rng.randrange(-20,21),rng.randrange(-20,21);l=rng.randrange(999);r=rng.randrange(l+2,1001);ans=2*sum(x*x+b*x+c for x in range(l,r+1) if x%2==0);case('202503A',f'{b} {c} {l} {r}',ans)
for _ in range(60):
 n=rng.randrange(1,101);rows=[];out=[]
 for j in range(20):
  x,y=rng.randrange(1,n+1),rng.randrange(1,n+1);s=''.join(rng.choices('fblr',k=100));rows.append(f'{x} {y} {s}')
  for ch in s:
   if ch in 'fb':y=max(1,min(n,y+(1 if ch=='f' else -1)))
   else:x=max(1,min(n,x+(1 if ch=='r' else -1)))
  out.append(f'{x} {y}')
 case('202412A',f'{n} 20\n'+'\n'.join(rows),'\n'.join(out))
for _ in range(60):
 strings=[''.join(rng.choices('abAB01*#',k=rng.randrange(6,21))) for i in range(100)];out=[]
 for s in strings:
  kinds={0 if c.isalpha() else 1 if c.isdigit() else 2 for c in s};out.append(0 if len(kinds)<3 else 2 if max(s.count(c) for c in s)<=2 else 1)
 case('202409A','100\n'+'\n'.join(strings),'\n'.join(map(str,out)))
for _ in range(60):
 n,m=rng.randrange(1,15),rng.randrange(1,15);size=n*m;p=rng.choice([x for x in range(1,size+1) if size%x==0]);q=size//p;a=[rng.randrange(-1000,1001) for i in range(size)];out=[a[i*q:(i+1)*q] for i in range(p)];case('202406A',f'{n} {m} {p} {q}\n'+' '.join(map(str,a)),'\n'.join(' '.join(map(str,r)) for r in out))
for _ in range(60):
 n,m=30,20;articles=[rng.choices(range(1,m+1),k=rng.randrange(1,40)) for i in range(n)];case('202403A',f'{n} {m}\n'+'\n'.join(str(len(s))+' '+' '.join(map(str,s)) for s in articles),'\n'.join(f'{sum(i in s for s in articles)} {sum(s.count(i) for s in articles)}' for i in range(1,m+1)))
for _ in range(60):
 n,m=30,rng.randrange(1,11);a=[[rng.randrange(-5,6) for j in range(m)] for i in range(n)];out=[]
 for row in a:
  candidates=[j+1 for j,b in enumerate(a) if min(y-x for x,y in zip(row,b))>0];out.append(min(candidates,default=0))
 case('202312A',f'{n} {m}\n'+'\n'.join(' '.join(map(str,r)) for r in a),'\n'.join(map(str,out)))
for _ in range(60):
 shifts=[(rng.randrange(-100000,100001),rng.randrange(-100000,100001)) for i in range(30)];points=[(rng.randrange(-100000,100001),rng.randrange(-100000,100001)) for i in range(20)];out=[]
 for x,y in points:
  for dx,dy in shifts:x+=dx;y+=dy
  out.append(f'{x} {y}')
 case('202309A','30 20\n'+'\n'.join(f'{x} {y}' for x,y in shifts+points),'\n'.join(out))
for _ in range(60):
 pool=[''.join(rng.choices('kqrbnpKQRBNP*',k=64)) for j in range(8)];boards=rng.choices(pool,k=30);out=[boards[:i+1].count(s) for i,s in enumerate(boards)];case('202305A','30\n'+'\n'.join(s[i:i+8] for s in boards for i in range(0,64,8)),'\n'.join(map(str,out)))
for _ in range(60):
 a,b=rng.randrange(1,15),rng.randrange(1,15);rects=[]
 for x in range(-5,16,3):
  for y in range(-5,16,3):
   if rng.random()<.4:rects.append((x,y,x+rng.randrange(1,4),y+rng.randrange(1,4)))
 ans=sum(any(x<=i<xx and y<=j<yy for x,y,xx,yy in rects) for i in range(a) for j in range(b));case('202303A',f'{len(rects)} {a} {b}\n'+'\n'.join(' '.join(map(str,r)) for r in rects),ans)
for _ in range(60):
 a=[rng.randrange(-1000,1001) for i in range(100)];mean=sum(a)/len(a);sd=math.sqrt(sum(x*x for x in a)/len(a)-mean**2);case('202206A','100\n'+' '.join(map(str,a)),'\n'.join(str((x-mean)/sd) for x in a),1e-8)
for _ in range(60):
 N=rng.randrange(2,1000);n=rng.randrange(1,min(N,201));a=sorted(rng.sample(range(1,N),n));case('202112A',f'{n} {N}\n'+' '.join(map(str,a)),sum(bisect.bisect_right(a,x) for x in range(N)))
for _ in range(60):
 n=rng.randrange(1,7);b=sorted(rng.choices(range(4),k=n));sums=[]
 for a in itertools.product(range(4),repeat=n):
  if list(itertools.accumulate(a,max))==b:sums.append(sum(a))
 case('202109A',str(n)+'\n'+' '.join(map(str,b)),f'{max(sums)}\n{min(sums)}')
for _ in range(60):
 n,m,L=rng.randrange(1,20),rng.randrange(1,20),rng.randrange(4,257);a=rng.choices(range(L),k=n*m);case('202104A',f'{n} {m} {L}\n'+' '.join(map(str,a)),' '.join(str(a.count(i)) for i in range(L)))
for _ in range(60):
 points=[(x,y,rng.choice('AB')) for x,y in rng.sample(list(itertools.product(range(-20,21),repeat=2)),30)];queries=[];out=[]
 while len(queries)<10:
  a,b,c=[rng.randrange(-10,11) for i in range(3)]
  if not(b or c):continue
  value=[a+b*x+c*y for x,y,t in points]
  if 0 in value:continue
  queries.append((a,b,c));sides=[{v>0 for v,p in zip(value,points) if p[2]==t} for t in 'AB'];out.append('Yes' if len(sides[0])==len(sides[1])==1 and sides[0]!=sides[1] else 'No')
 case('202006A','30 10\n'+'\n'.join(f'{x} {y} {t}' for x,y,t in points)+'\n'+'\n'.join(' '.join(map(str,q)) for q in queries),'\n'.join(out))
for _ in range(60):
 n=rng.randrange(1,667);valid=[x for x in range(1,10000) if x%7 and '7' not in str(x)];last=valid[n-1];out=[sum(x%7==0 or '7' in str(x) for x in range(i+1,last+1,4)) for i in range(4)];case('201912A',str(n),'\n'.join(map(str,out)))
for _ in range(60):
 n=rng.randrange(2,40);a=[rng.randrange(1,10001) for i in range(n)];out=[sum(a[max(0,i-1):min(n,i+2)])//len(a[max(0,i-1):min(n,i+2)]) for i in range(n)];case('201809A',str(n)+'\n'+' '.join(map(str,a)),' '.join(map(str,out)))
for _ in range(60):
 n=rng.randrange(2,40);a=[rng.randrange(1,10001) for i in range(n)];case('201712A',str(n)+'\n'+' '.join(map(str,a)),min(abs(x-y) for i,x in enumerate(a) for y in a[i+1:]))
for _ in range(60):
 n=rng.randrange(1,40);k=rng.randrange(1,10001);a=[rng.randrange(1,1001) for i in range(n)];i=0;ans=0
 while i<n:
  end=i+1
  while end<n and sum(a[i:end])<k:end+=1
  i=end;ans+=1
 case('201703A',f'{n} {k}\n'+' '.join(map(str,a)),ans)
for _ in range(60):
 n=rng.randrange(1,40);a=[]
 for i in range(n):a.append(rng.choice([x for x in range(20) if not a or x!=a[-1]]))
 signs=[1 if y>x else -1 for x,y in zip(a,a[1:])];case('201604A',str(n)+'\n'+' '.join(map(str,a)),sum(x!=y for x,y in zip(signs,signs[1:])))
for _ in range(60):
 n=rng.randrange(10**9+1);case('201512A',str(n),sum(map(int,str(n))))
for _ in range(60):
 a=rng.choices(range(5),k=rng.randrange(1,100));case('201509A',str(len(a))+'\n'+' '.join(map(str,a)),len(list(itertools.groupby(a))))
for _ in range(60):
 n,m=rng.randrange(1,20),rng.randrange(1,20);a=[[rng.randrange(1001) for j in range(m)] for i in range(n)];out=list(zip(*a))[::-1];case('201503A',f'{n} {m}\n'+'\n'.join(' '.join(map(str,r)) for r in a),'\n'.join(' '.join(map(str,r)) for r in out))
for _ in range(60):
 n=100;a=rng.choices(range(1,n+1),k=n);case('201412A',str(n)+'\n'+' '.join(map(str,a)),' '.join(str(a[:i+1].count(x)) for i,x in enumerate(a)))
for _ in range(60):
 a=rng.sample(range(1000),rng.randrange(1,100));case('201409A',str(len(a))+'\n'+' '.join(map(str,a)),sum(abs(x-y)==1 for i,x in enumerate(a) for y in a[i+1:]))
for _ in range(60):
 a=rng.sample([x for x in range(-100,101) if x],rng.randrange(1,150));case('201403A',str(len(a))+'\n'+' '.join(map(str,a)),sum(x+y==0 for i,x in enumerate(a) for y in a[i+1:]))
for _ in range(60):
 a=rng.choices(range(1,100),k=rng.randrange(1,1000));case('201312A',str(len(a))+'\n'+' '.join(map(str,a)),min(set(a),key=lambda x:(-a.count(x),x)))
