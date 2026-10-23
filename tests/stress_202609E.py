# -*- coding: utf-8 -*-
"""Maximum-size run/output-shape check. This is not an answer oracle."""
from pathlib import Path
import argparse,json,platform,random,resource,subprocess,time
root=Path(__file__).resolve().parents[1]
p=argparse.ArgumentParser()
p.add_argument('--nodes',type=int,default=100000)
p.add_argument('--queries',type=int,default=100000)
a=p.parse_args()
if not 1<=a.nodes<=100000 or not 0<=a.queries<=100000:p.error('nodes: 1..100000; queries: 0..100000')
rng=random.Random(20261023);n=a.nodes;q=a.queries
folder=root/'.build'/'202609';folder.mkdir(parents=True,exist_ok=True)
path=folder/'stress.in';outpath=folder/'stress.out'
with path.open('w') as f:
    f.write(f'{n} 40 4 {q}\n'+'1'*n+'\n'+' '.join(str(rng.randrange(1,41)) for _ in range(n))+'\n')
    for i in range(2,n+1):f.write(f'{i-1} {i} {rng.randrange(1,1000001)}\n')
    for _ in range(q):f.write(str(rng.randrange(1,n+1))+'\n')
with path.open() as inp,outpath.open('w') as out:
    start=time.monotonic()
    result=subprocess.run([str(folder/'E')],stdin=inp,stdout=out,stderr=subprocess.PIPE,text=True,timeout=120)
    elapsed=time.monotonic()-start
lines=sum(1 for _ in outpath.open())
rss=resource.getrusage(resource.RUSAGE_CHILDREN).ru_maxrss
if platform.system()!='Darwin':rss*=1024
report={'case':f'{n}-node chain, 40 colours, k=4, all initially on, {q} toggles','returncode':result.returncode,'seconds':round(elapsed,3),'output_lines':lines,'peak_rss_bytes':rss,'machine_specific':True,'official_judge':'not_submitted','stderr':result.stderr,'validation':'Process completion and output-line count only; large answers not independently checked.'}
(root/'tests'/'stress-202609E-report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
assert result.returncode==0 and lines==q+1,report
print(json.dumps(report,ensure_ascii=False))
