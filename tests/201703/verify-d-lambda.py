"""GNU16 focused replay after the local comparator capture spelling changed."""
from pathlib import Path
import collections,hashlib,json,runpy,subprocess,sys,time
P=Path(__file__).resolve().parents[1];W=P.parent;R=Path('/tmp/csp-style-publish')
sys.path.insert(0,str(W/'tools/nightly'))
from retained_oracles import collect
cases=[c for c in collect(R,'201703') if c['problem']=='D']
for x in json.loads((R/'tests/201703D.json').read_text()):cases.append(dict(problem='D',kind='saved_sample',**x))
cases += [c for c in runpy.run_path(str(P/'reports/boundaries.py'))['generate'](W,R) if c['problem']=='D']
n=100000;es=[]
for step in range(17):
    gap=1<<step
    for u in range(1,n-gap+1,gap*2):es.append((u,u+gap,step+1))
cases.append(dict(problem='D',kind='recursion_boundary',input=f'{n} {len(es)}\n'+''.join(f'{u} {v} {z}\n' for u,v,z in es),output='17\n'))
cases=list({c['input']:c for c in cases}.values())
B=Path('/tmp/csp-201703D-lambda');B.mkdir(exist_ok=True)
r=dict(problem='201703D',previous_source_sha256='b7c62ee770bba184db3451f9a337e889b0ee3850ae0de05382761696b94c3b9f',source_sha256=hashlib.sha256((P/'D.cpp').read_bytes()).hexdigest(),change='sort comparator [] changed to user-preferred [&]; no actual variable capture is required by this body.',different_inputs=len(cases),case_kinds=dict(collections.Counter(c['kind'] for c in cases)),case_input_output_sha256=hashlib.sha256(json.dumps(cases,sort_keys=True).encode()).hexdigest(),compilation={},runs=[],note='Original evaluation records remain historical. Only local comparator spelling changed; no online resubmission.')
for mode,flags in [('O2',['-O2']),('UBSan',['-O1','-g','-fsanitize=undefined','-fno-sanitize-recover=all'])]:
    exe=B/mode
    cmd=['/opt/homebrew/bin/g++-16','-std=c++17',*flags,'-Wall','-Wextra',str(P/'D.cpp'),'-o',str(exe)]
    z=subprocess.run(cmd,text=True,capture_output=True);assert not z.returncode and not z.stderr,z.stderr
    r['compilation'][mode]=dict(command=cmd,returncode=z.returncode,stderr=z.stderr,passed=True)
    start=time.monotonic();samples=[]
    for c in cases:
        z=subprocess.run([str(exe)],input=c['input'],text=True,capture_output=True,timeout=10)
        assert not z.returncode and not z.stderr and z.stdout.split()==str(c['output']).split(),(mode,c['kind'],z.stdout,z.stderr)
        if c['kind']=='saved_sample':samples.append(dict(passed=True,returncode=z.returncode,stdout=z.stdout,expected_output=c['output'],stderr=z.stderr))
    r['runs'].append(dict(mode=mode,passed=len(cases),seconds=time.monotonic()-start,saved_samples=samples))
assert r['source_sha256']==hashlib.sha256((P/'D.cpp').read_bytes()).hexdigest()
(P/'reports/d-lambda-report.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(r,ensure_ascii=False,indent=2))
