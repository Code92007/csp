from pathlib import Path
import hashlib,json,subprocess,sys
r=Path(__file__).resolve().parents[1];w=r.parent
scope={'__file__':str(r/'reports/verify.py')};sys.argv=[str(r/'reports/verify.py')]
exec(compile((r/'reports/verify.py').read_text().split('# An exact duplicate')[0],str(r/'reports/verify.py'),'exec'),scope)
cases=[c for c in scope['cases'] if c['problem']=='E'];runs=[]
for mode,flags in [('O2',['-O2']),('UBSan',['-O1','-g','-fsanitize=undefined','-fno-sanitize-recover=all'])]:
    exe=w/'.build/202412-prep'/f'E-sizeof-{mode}'
    p=subprocess.run(['clang++','-std=c++17','-Wall','-Wextra','-I/tmp/csp202609-check/include',*flags,str(r/'E.cpp'),'-o',str(exe)],text=True,capture_output=True);assert not p.returncode and not p.stderr,p.stderr
    for c in cases:
        p=subprocess.run([str(exe)],input=c['input'],text=True,capture_output=True,timeout=90);assert not p.returncode and not p.stderr,p.stderr
        assert p.stdout.split()==c['output'].split(),(p.stdout,c['output'])
    runs.append(dict(mode=mode,inputs=len(cases),result='passed'))
report=dict(**json.loads((r/'reports/e-sizeof-before.json').read_text()),after_sha256=hashlib.sha256((r/'E.cpp').read_bytes()).hexdigest(),change='两处memcpy的sizeof(int)分别改为sizeof *a与sizeof *b；每个元素仍为int。',runs=runs)
(r/'reports/e-sizeof-followup-report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n');print(json.dumps(report,ensure_ascii=False,indent=2))
