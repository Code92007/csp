from pathlib import Path
import random,subprocess,time,json
R=Path(__file__).resolve().parent
rng=random.Random(92007605)
report={}
for shape in ['ascending_path','descending_path','shuffled_path','star_center_1','star_center_n','random_tree','broom']:
 n=100000
 if 'path' in shape:
  labels=list(range(1,n+1))
  if shape=='descending_path':labels.reverse()
  if shape=='shuffled_path':rng.shuffle(labels)
  edges=list(zip(labels,labels[1:]))
 elif shape=='star_center_1':edges=[(1,x) for x in range(2,n+1)]
 elif shape=='star_center_n':edges=[(n,x) for x in range(1,n)]
 elif shape=='broom':
  labels=list(range(1,n+1));rng.shuffle(labels)
  edges=[(labels[i],labels[i+1]) for i in range(n//2)]+[(labels[n//2],labels[i]) for i in range(n//2+1,n)]
 else:
  labels=list(range(1,n+1));rng.shuffle(labels)
  edges=[(labels[rng.randrange(i)],labels[i]) for i in range(1,n)]
 data=str(n)+'\n'+'\n'.join(f'{u} {v}' for u,v in edges)+'\n'
 t=time.monotonic();p=subprocess.run([str(R.parent/'.build/202605/E')],input=data,text=True,capture_output=True,timeout=30)
 elapsed=time.monotonic()-t
 assert p.returncode==0,(shape,p.stderr)
 out=list(map(int,p.stdout.split()));assert sorted(out)==list(range(1,n+1)),shape
 if shape.startswith('star') or shape in ['ascending_path','descending_path']:assert out==list(range(1,n+1)),shape
 report[shape]={'n':n,'seconds':round(elapsed,3),'permutation_checked':True,'sorted_answer_checked':shape.startswith('star') or shape in ['ascending_path','descending_path']}
 print(shape,report[shape],flush=True)
(R/'gather-stress-report.json').write_text(json.dumps(report,indent=2))
