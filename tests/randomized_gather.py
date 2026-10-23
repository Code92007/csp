from pathlib import Path
import itertools,heapq,random,subprocess,json,time,os,shlex
ROOT=Path(__file__).resolve().parent
PROJECT=ROOT.parent
oracle=PROJECT/'.build/oracles/202605E'
oracle.parent.mkdir(parents=True,exist_ok=True)
subprocess.run(shlex.split(os.environ.get('CXX','c++'))+['-std=c++17','-O2',str(ROOT/'oracles/202605E.cpp'),'-o',str(oracle)],check=True)
binaries={'solver':PROJECT/'.build/202605/E','oracle':oracle}
rng=random.Random(202605)
def run(name,data):
 p=subprocess.run([str(binaries[name])],input=data,text=True,capture_output=True,timeout=10)
 if p.returncode:raise RuntimeError((name,p.stderr,data))
 return p.stdout.split()
def tree(code):
 n=len(code)+2;degree=[1]*n
 for x in code:degree[x]+=1
 leaves=[x for x in range(n) if degree[x]==1];heapq.heapify(leaves);edges=[]
 for x in code:
  y=heapq.heappop(leaves);edges.append((x,y));degree[x]-=1
  if degree[x]==1:heapq.heappush(leaves,x)
 edges.append(tuple(leaves));return edges
def case(n,edges):
 data=str(n)+'\n'+'\n'.join(f'{a+1} {b+1}' for a,b in edges)+'\n'
 try:
  got=run('solver',data);want=run('oracle',data)
  assert got==want,(data,want,got)
 except Exception:
  (ROOT/'gather-failure.txt').write_text(data);raise
count=0;started=time.monotonic()
case(1,[]);count+=1
for n in range(2,7):
 for code in itertools.product(range(n),repeat=n-2):case(n,tree(code));count+=1
 print('exhaustive',n,count,flush=True)
for n in range(7,11):
 for i in range(150):
  case(n,tree([rng.randrange(n) for j in range(n-2)]));count+=1
 print('random',n,count,flush=True)
(ROOT/'gather-report.json').write_text(json.dumps({'exhaustive_labeled_trees_n_le_6':1442,'random_n_7_to_10':600,'total':count,'seconds':round(time.monotonic()-started,3)},indent=2))
