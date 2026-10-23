from third_support import *
import random,json,datetime,calendar,posixpath,subprocess,re
from collections import Counter
rng.seed(9200704)
def case(k,data,out):check(k,data,out);report[k]=report.get(k,0)+1
# Generate semantic paragraph/list blocks first, then independently render characters.
for _ in range(120):
 w=rng.randrange(4,20);raw=[];rendered=[]
 for b in range(rng.randrange(1,15)):
  if b:raw+=[' '*rng.randrange(5) for i in range(rng.randrange(1,4))];rendered.append('')
  islist=rng.choice([False,True])
  for item in range(rng.randrange(1,5) if islist else 1):
   parts=[]
   for j in range(rng.randrange(1,5)):
    t=''.join(rng.choices('ab     ',k=rng.randrange(1,60))).strip()
    if not t and (not islist or j):t='x'
    parts.append(t)
    raw.append(('* ' if j==0 else '  ')+(' '*rng.randrange(3))+t+(' '*rng.randrange(3)) if islist else ' '*rng.randrange(3)+t+' '*rng.randrange(3))
   text=' '.join(x for x in parts if x);width=w-3 if islist else w;lines=['']
   for ch in text:
    if len(lines[-1])==width:
     if ch==' ':continue
     lines.append('')
    lines[-1]+=ch
   rendered+=lines
 case('202006C',str(w)+'\n'+'\n'.join(raw)+'\n',len(rendered))
# Generate chemistry AST and expand into flat formula for the other side.
elements=['H','He','Na','Cl','O','C','N','Aa']
def formula(d):
 text='';cnt=Counter()
 for j in range(rng.randrange(1,4)):
  if d and rng.random()<.4:s,c=formula(d-1);s='('+s+')'
  else:s=rng.choice(elements);c=Counter({s:1})
  k=rng.randrange(1,6);text+=s+(str(k) if k!=1 else '');cnt.update({e:v*k for e,v in c.items()})
 return text,cnt
for _ in range(100):
 rows=[];outs=[]
 for j in range(10):
  left=[];cnt=Counter()
  for i in range(rng.randrange(1,5)):
   f,c=formula(3);k=rng.randrange(1,5);left.append((str(k) if k>1 else '')+f);cnt.update({e:v*k for e,v in c.items()})
  bad=rng.choice([False,True]);r=cnt.copy()
  if bad:r[rng.choice(elements)]+=1
  right=''.join(e+(str(v) if v!=1 else '') for e,v in r.items());rows.append('+'.join(left)+'='+right);outs.append('N' if bad else 'Y')
 case('201912C','10\n'+'\n'.join(rows),'\n'.join(outs))
# Forward matching along root-to-node ancestor chains, instead of reverse greedy.
for _ in range(100):
 n=rng.randrange(1,50);parents=[0];depth=[0];tags=[];ids=[];rows=[]
 for i in range(n):
  p=rng.randrange(i) if i else -1;parents.append(p+1);dep=0 if p<0 else depth[p+1]+1;depth.append(dep);tag=rng.choice(['div','p','body']);tags.append(tag);ident=('#ID'+str(i)) if rng.random()<.5 else '';ids.append(ident);rows.append('..'*dep+tag+(' '+ident if ident else ''))
 # Input requires preorder; create a preorder permutation and remap line numbers.
 children=[[] for i in range(n+1)]
 for i in range(1,n+1):children[parents[i]].append(i)
 order=[]
 def walk(v):
  if v:order.append(v)
  for c in children[v]:walk(c)
 walk(0);qs=[];out=[]
 for j in range(10):
  sel=[rng.choice(['div','P','body','#ID'+str(rng.randrange(n))]) for k in range(rng.randrange(1,5))];qs.append(' '.join(sel));ans=[]
  def match(v,s):return ids[v-1]==s if s.startswith('#') else tags[v-1]==s.lower()
  for line,v in enumerate(order,1):
   if not match(v,sel[-1]):continue
   chain=[];u=parents[v]
   while u:chain.append(u);u=parents[u]
   k=0
   for u in reversed(chain):
    if k<len(sel)-1 and match(u,sel[k]):k+=1
   if k==len(sel)-1:ans.append(line)
  out.append(' '.join(map(str,[len(ans)]+ans)))
 case('201809C',f'{n} 10\n'+'\n'.join(rows[i-1] for i in order)+'\n'+'\n'.join(qs),'\n'.join(out))
# Crontab minute enumeration via Python calendar; random ranges and mixed-case names.
months=['Jan','FEB','mar','Apr','May','Jun','Jul','Aug','Sep','Oct','Nov','DEC'];week=['Sun','Mon','Tue','Wed','Thu','Fri','Sat']
for _ in range(80):
 start=datetime.datetime(rng.choice([1970,1999,2000,2024,2099]),rng.randrange(1,13),rng.randrange(1,25),rng.randrange(24),rng.randrange(60));end=start+datetime.timedelta(minutes=rng.randrange(1,5000));rules=[];rows=[]
 for j in range(5):
  vals=[];fields=[]
  for idx,(lo,hi) in enumerate([(0,59),(0,23),(1,31),(1,12),(0,6)]):
   if rng.random()<.5:vals.append(set(range(lo,hi+1)));fields.append('*');continue
   a,b=sorted(rng.sample(range(lo,hi+1),2));c=rng.randrange(lo,hi+1);vals.append(set(range(a,b+1))|{c})
   def name(x):return rng.choice([str(x),months[x-1]]) if idx==3 else rng.choice([str(x),week[x]]) if idx==4 else str(x)
   fields.append(name(a)+'-'+name(b)+','+name(c))
  rules.append(vals);rows.append(' '.join(fields+[f'cmd{j}']))
 out=[];t=start
 while t<end:
  v=[t.minute,t.hour,t.day,t.month,(t.weekday()+1)%7]
  for j,r in enumerate(rules):
   if all(x in s for x,s in zip(v,r)):out.append(t.strftime('%Y%m%d%H%M')+f' cmd{j}')
  t+=datetime.timedelta(minutes=1)
 case('201712C','5 '+start.strftime('%Y%m%d%H%M')+' '+end.strftime('%Y%m%d%H%M')+'\n'+'\n'.join(rows),'\n'.join(out))
# Generate inline markup and HTML together, including mutual nesting.
def inline():
 plain=lambda:''.join(rng.choices('abc XYZ',k=10)).strip() or 'A'
 forms=[]
 for i in range(rng.randrange(1,5)):
  t=plain();url='https://example.com/'+str(rng.randrange(100));kind=rng.randrange(5)
  if kind==0:forms.append((t,t))
  elif kind==1:forms.append(('_'+t+'_','<em>'+t+'</em>'))
  elif kind==2:forms.append(('['+t+']('+url+')','<a href="'+url+'">'+t+'</a>'))
  elif kind==3:forms.append(('[_'+t+'_]('+url+')','<a href="'+url+'"><em>'+t+'</em></a>'))
  else:forms.append(('_['+t+']('+url+')_','<em><a href="'+url+'">'+t+'</a></em>'))
 return ' '.join(x for x,y in forms),' '.join(y for x,y in forms)
for _ in range(100):
 raw=[];out=[]
 for j in range(rng.randrange(1,12)):
  if raw:raw+=['']*rng.randrange(1,4)
  kind=rng.randrange(3)
  if kind==0:
   k=rng.randrange(1,7);s,h=inline();raw.append('#'*k+' '*rng.randrange(1,4)+s);out.append(f'<h{k}>{h}</h{k}>')
  elif kind==1:
   parts=[inline() for i in range(rng.randrange(1,5))];raw.extend(s for s,h in parts);out.append('<p>'+'\n'.join(h for s,h in parts)+'</p>')
  else:
   parts=[inline() for i in range(rng.randrange(1,5))];raw.extend('* '*rng.randrange(1,2)+s for s,h in parts);out+=['<ul>']+['<li>'+h+'</li>' for s,h in parts]+['</ul>']
 case('201703C','\n'.join(raw)+'\n','\n'.join(out))
# Filesystem lexical normalization using standard posixpath, no disk access.
for _ in range(100):
 cwd='/a/b/c';paths=[''.join('' for j in [])]
 for i in range(9):paths.append(('/' if rng.random()<.5 else '')+'/'.join(rng.choices(['a','b','..','.','','a..','...','_'],k=rng.randrange(1,20))))
 want=[]
 for s in paths:
  s=s if s.startswith('/') else cwd+'/'+s
  normalized=posixpath.normpath(s);normalized='/'+normalized.lstrip('/');want.append(normalized)
 case('201604C','10\n'+cwd+'\n'+'\n'.join(paths)+'\n','\n'.join(want))
# Flood components are rebuilt with disjoint sets after each draw.
for _ in range(100):
 m=rng.randrange(2,12);n=rng.randrange(2,12);a=[['.']*m for i in range(n)];rows=[]
 for j in range(25):
  cells=[(x,y) for y in range(n) for x in range(m) if a[y][x] not in '-|+']
  if rng.random()<.6 or not cells:
   if rng.choice([True,False]):x,xx=sorted(rng.sample(range(m),2));y=yy=rng.randrange(n);symbol='-'
   else:y,yy=sorted(rng.sample(range(n),2));x=xx=rng.randrange(m);symbol='|'
   rows.append(f'0 {x} {y} {xx} {yy}')
   for v in range(y,yy+1):
    for u in range(x,xx+1):a[v][u]='+' if a[v][u]=='+' or a[v][u] in '-|' and a[v][u]!=symbol else symbol
  else:
   x,y=rng.choice(cells);c=rng.choice('ABC');rows.append(f'1 {x} {y} {c}');parent=list(range(m*n))
   def find(x):
    while parent[x]!=x:x=parent[x]
    return x
   for u,v in cells:
    for xx,yy in [(u-1,v),(u,v-1)]:
     if (xx,yy) in cells:parent[find(v*m+u)]=find(yy*m+xx)
   root=find(y*m+x)
   for u,v in cells:
    if find(v*m+u)==root:a[v][u]=c
 case('201512C',f'{m} {n} {len(rows)}\n'+'\n'.join(rows),'\n'.join(''.join(x) for x in reversed(a)))
# Nonrecursive substitution, whitespace and undefined/case-sensitive variables.
for _ in range(100):
 values={'a':'{{ b }}','b':'  B  ','Name':'test','empty':''};lines=[''.join(rng.choice(['text ','{{ a }}','{{ b }}','{{ name }}','{{ Name }}','{{ empty }}',' ']) for i in range(12)) for j in range(10)];out=[re.sub(r'\{\{ (\w+) \}\}',lambda m:values.get(m[1],''),s) for s in lines];case('201509C','10 4\n'+'\n'.join(lines)+'\n'+'\n'.join(k+' "'+v+'"' for k,v in values.items()),'\n'.join(out))
for _ in range(100):
 a=rng.randrange(1,13);b=rng.randrange(1,6);c=rng.randrange(1,8);y1=rng.randrange(1850,2045);y2=min(2050,y1+rng.randrange(1,10));out=[]
 for y in range(y1,y2+1):
  ds=[d for d in range(1,calendar.monthrange(y,a)[1]+1) if datetime.date(y,a,d).isoweekday()==c];out.append(f'{y}/{a:02d}/{ds[b-1]:02d}' if len(ds)>=b else 'none')
 case('201503C',f'{a} {b} {c} {y1} {y2}','\n'.join(out))
for _ in range(100):
 records=[];active=set();lines=[]
 for j in range(50):
  if active and rng.random()<.2:
   idx=rng.choice(sorted(active));active.remove(idx);lines.append(f'cancel {idx+1}');records.append(None)
  else:
   typ=rng.choice(['buy','sell']);p=rng.randrange(1,1000);q=rng.randrange(1,100000001);lines.append(f'{typ} {p//100}.{p%100:02d} {q}');records.append((typ,p,q));active.add(j)
 best=(-1,-1)
 for p in {records[i][1] for i in active}:
  buys=sum(q for i in active for t,pp,q in [records[i]] if t=='buy' and pp>=p);sells=sum(q for i in active for t,pp,q in [records[i]] if t=='sell' and pp<=p);best=max(best,(min(buys,sells),p))
 v,p=best;case('201412C','\n'.join(lines),f'{p//100}.{p%100:02d} {v}')
for _ in range(100):
 pattern=''.join(rng.choices('aAbBcC',k=rng.randrange(1,5)));mode=rng.randrange(2);lines=[''.join(rng.choices('aAbBcC',k=rng.randrange(1,35))) for j in range(30)];out=[s for s in lines if (pattern in s if mode else pattern.lower() in s.lower())];case('201409C',f'{pattern}\n{mode}\n30\n'+'\n'.join(lines),'\n'.join(out))
for _ in range(100):
 spec={c:rng.randrange(2) for c in 'abcde'};fmt=''.join(c+':'*v for c,v in spec.items());rows=[];out=[]
 for j in range(20):
  words=rng.choices(['-a','-b','-c','-d','-e','-z','--a','abc','123','-','-8'],k=rng.randrange(1,20));rows.append('cmd '+' '.join(words));found={};i=0
  while i<len(words):
   s=words[i];i+=1
   if len(s)!=2 or s[0]!='-' or s[1] not in spec:break
   if spec[s[1]]:
    if i==len(words):break
    found[s[1]]=words[i];i+=1
   else:found[s[1]]=None
  out.append(f'Case {j+1}:'+''.join(' -'+c+(' '+v if v is not None else '') for c,v in sorted(found.items())))
 case('201403C',fmt+'\n20\n'+'\n'.join(rows),'\n'.join(out))
for _ in range(160):
 n=rng.randrange(1,50);a=[rng.randrange(1,10**9) if rng.random()<.1 else rng.randrange(1,30) for i in range(n)];ans=max(min(a[i:j])*(j-i) for i in range(n) for j in range(i+1,n+1));case('201312C',f'{n}\n'+' '.join(map(str,a)),ans)
