from second_support import *
import random,json,itertools,datetime,collections
rng=random.Random(9200712)
def case(k,data,out):check(k,data,out);report[k]=report.get(k,0)+1
for _ in range(100):
 n=100;a=[rng.choice([0,0,rng.randrange(-100,101)]) for i in range(n)];b=[rng.choice([0,0,rng.randrange(-100,101)]) for i in range(n)];u=[(i+1,x) for i,x in enumerate(a) if x];v=[(i+1,x) for i,x in enumerate(b) if x];case('202006B',f'{n} {len(u)} {len(v)}\n'+'\n'.join(f'{i} {x}' for i,x in u+v),sum(x*y for x,y in zip(a,b)))
for _ in range(100):
 points={(x,y) for x in range(-5,6) for y in range(-5,6) if rng.random()<.7};out=[0]*5
 for x,y in points:
  if all((x+dx,y+dy) in points for dx,dy in [(1,0),(-1,0),(0,1),(0,-1)]):out[sum((x+dx,y+dy) in points for dx in [-1,1] for dy in [-1,1])]+=1
 case('201912B',str(len(points))+'\n'+'\n'.join(f'{x} {y}' for x,y in points),'\n'.join(map(str,out)))
for _ in range(100):
 n=rng.randrange(1,25);lists=[]
 for who in range(2):
  x=1;rows=[]
  for i in range(n):y=x+rng.randrange(1,8);rows.append((x,y));x=y+rng.randrange(1,8)
  lists.append(rows)
 a,b=lists;ans=sum(max(0,min(y,v)-max(x,u)) for x,y in a for u,v in b);case('201809B',str(n)+'\n'+'\n'.join(f'{x} {y}' for x,y in a+b),ans)
for n in range(1,31):
 for k in range(1,10):
  alive=[True]*n;i=0;number=0;left=n
  while left>1:
   if alive[i]:
    number+=1
    if number%k==0 or str(number).endswith(str(k)):alive[i]=False;left-=1
   i=(i+1)%n
  case('201712B',f'{n} {k}',alive.index(True)+1)
for _ in range(100):
 n=rng.randrange(1,40);a=list(range(1,n+1));ops=[]
 for j in range(30):
  old=rng.randrange(n);new=rng.randrange(n);p=a[old];ops.append(f'{p} {new-old}')
  while old<new:a[old],a[old+1]=a[old+1],a[old];old+=1
  while old>new:a[old],a[old-1]=a[old-1],a[old];old-=1
 case('201703B',f'{n}\n30\n'+'\n'.join(ops),' '.join(map(str,a)))
shapes=[[(0,0),(0,1),(0,2),(0,3)],[(0,0),(1,0),(2,0),(3,0)],[(0,0),(0,1),(1,0),(1,1)],[(0,0),(0,1),(0,2),(1,1)],[(0,0),(1,0),(1,1),(1,2)],[(0,0),(0,1),(1,1),(1,2)]]
for _ in range(100):
 board=[[0]*10 for i in range(4)]+[[rng.randrange(2) for j in range(10)] for i in range(11)];original=[r[:] for r in board];shape=rng.choice(shapes);dy=rng.randrange(4-max(x for x,y in shape));dx=rng.randrange(4-max(y for x,y in shape));shape=[(x+dy,y+dx) for x,y in shape];col=rng.randrange(7);fall=min(min([15-r]+[y-r for y in range(r+1,15) if board[y][col+c]])-1 for r,c in shape)
 for r,c in shape:board[r+fall][col+c]=1
 small=[[int((r,c) in shape) for c in range(4)] for r in range(4)];case('201604B','\n'.join(' '.join(map(str,r)) for r in original+small)+f'\n{col+1}','\n'.join(' '.join(map(str,r)) for r in board))
for _ in range(100):
 n=rng.randrange(1,15);m=rng.randrange(1,15);a=[[rng.randrange(1,5) for j in range(m)] for i in range(n)];remove=set()
 for i in range(n):
  for j in range(m):
   for dx,dy in [(0,1),(1,0)]:
    cells=[];x,y=i,j
    while x<n and y<m and a[x][y]==a[i][j]:cells.append((x,y));x+=dx;y+=dy
    if len(cells)>=3:remove.update(cells)
 out=[[0 if (i,j) in remove else a[i][j] for j in range(m)] for i in range(n)];case('201512B',f'{n} {m}\n'+'\n'.join(' '.join(map(str,r)) for r in a),'\n'.join(' '.join(map(str,r)) for r in out))
for _ in range(100):
 y=rng.randrange(1900,2016);d=rng.randrange(1,366);date=datetime.date(y,1,1)+datetime.timedelta(days=d-1);case('201509B',f'{y}\n{d}',f'{date.month}\n{date.day}')
for _ in range(100):
 a=rng.choices(range(30),k=100);order=sorted(set(a),key=lambda x:(-a.count(x),x));case('201503B','100\n'+' '.join(map(str,a)),'\n'.join(f'{x} {a.count(x)}' for x in order))
for _ in range(100):
 n=rng.randrange(1,30);a=[[i*n+j for j in range(n)] for i in range(n)];order=sorted(itertools.product(range(n),repeat=2),key=lambda p:(sum(p),p[0] if sum(p)%2 else -p[0]));case('201412B',str(n)+'\n'+'\n'.join(' '.join(map(str,r)) for r in a),' '.join(str(a[i][j]) for i,j in order))
for _ in range(100):
 rects=[]
 for j in range(20):x,xx=sorted(rng.sample(range(20),2));y,yy=sorted(rng.sample(range(20),2));rects.append((x,y,xx,yy))
 ans=sum(any(x<=i<xx and y<=j<yy for x,y,xx,yy in rects) for i in range(20) for j in range(20));case('201409B','20\n'+'\n'.join(' '.join(map(str,r)) for r in rects),ans)
for _ in range(100):
 n=10;rects=[]
 for j in range(n):x,xx=sorted(rng.sample(range(20),2));y,yy=sorted(rng.sample(range(20),2));rects.append((x,y,xx,yy))
 priority=list(range(n));queries=[];out=[]
 for time in range(30):
  x,y=rng.randrange(20),rng.randrange(20);queries.append((x,y));cand=[i for i,(a,b,c,d) in enumerate(rects) if a<=x<=c and b<=y<=d]
  if cand:i=max(cand,key=lambda i:priority[i]);priority[i]=n+time;out.append(str(i+1))
  else:out.append('IGNORED')
 case('201403B','10 30\n'+'\n'.join(' '.join(map(str,r)) for r in rects+queries),'\n'.join(out))
for _ in range(100):
 digits=''.join(rng.choices('0123456789',k=9));r=sum(int(d)*(i+1) for i,d in enumerate(digits))%11;correct='0123456789X'[r];given=rng.choice([correct,rng.choice('0123456789X')]);prefix=digits[0]+'-'+digits[1:4]+'-'+digits[4:]+'-';case('201312B',prefix+given,'Right' if correct==given else prefix+correct)
