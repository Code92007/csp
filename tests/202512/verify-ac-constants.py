"""Replay independent A/C cases after equal integer-capacity spelling changes."""
from pathlib import Path
import hashlib,json,subprocess,sys,time
P=Path(__file__).resolve().parents[1];W=P.parent
sys.path.insert(0,str(W/'tools/nightly'))
from retained_oracles import collect
cases=[c for c in collect('/tmp/csp-style-publish','202512') if c['problem'] in 'AC']
for c in 'AC':
    for x in json.loads((Path('/tmp/csp-style-publish/tests')/('202512'+c+'.json')).read_text()):
        cases.append(dict(problem=c,kind='saved_sample',**x))
# Capacity boundary probes, with independently trivial expected answers.
cases.append(dict(problem='A',kind='max_capacity',input='10000 2\n'+'0 '*10000+'\n1 1\n2 1 10000\n1 10000\n2 1 10000\n',output='wrong\ncorrect\n'))
cases.append(dict(problem='C',kind='max_capacity',input='400\n'+('A'*400+'\n')*400+'300001\n50000 '+'2 1 1 1 1 1 '*50000+'\n',output='400 400\n'+('A'*400+'\n')*400))
uniq={}
for c in cases:
    key=(c['problem'],c['input'])
    if key in uniq:assert str(c['output']).split()==str(uniq[key]['output']).split()
    uniq[key]=c
cases=list(uniq.values())
(P/'reports/ac-constants-cases.json').write_text(json.dumps(cases,ensure_ascii=False,indent=2)+'\n')
B=Path('/tmp/csp-202512-constants');B.mkdir(exist_ok=True)
r=dict(contest='202512',source_sha256={c:hashlib.sha256((P/(c+'.cpp')).read_bytes()).hexdigest() for c in 'AC'},changes=dict(A='N=10005 (same integer capacity)',C='M=50010 (same integer capacity)'),compilation={},runs=[],note='Equivalent constant spelling only; historical broad reports retained. No online resubmission.')
for c in 'AC':
    selected=[x for x in cases if x['problem']==c]
    for mode,flags in [('O2',['-O2']),('UBSan',['-O1','-fsanitize=undefined','-fno-sanitize-recover=all'])]:
        exe=B/(c+'-'+mode)
        z=subprocess.run(['clang++','-std=c++17','-Wall','-Wextra','-I/tmp/csp-personal-compat',*flags,str(P/(c+'.cpp')),'-o',str(exe)],text=True,capture_output=True)
        assert not z.returncode and not z.stderr,z.stderr
        r['compilation'][c+':'+mode]='passed without diagnostics'
        begin=time.monotonic()
        for x in selected:
            z=subprocess.run([str(exe)],input=x['input'],text=True,capture_output=True,timeout=30)
            assert not z.returncode and not z.stderr and z.stdout.split()==str(x['output']).split(),(c,mode,x['kind'],z.stdout[:300],z.stderr)
        r['runs'].append(dict(problem=c,mode=mode,passed=len(selected),independent=sum(x['kind']=='retained_independent' for x in selected),saved=sum(x['kind']=='saved_sample' for x in selected),boundary=sum(x['kind']=='max_capacity' for x in selected),seconds=time.monotonic()-begin))
(P/'reports/ac-constants-report.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(r,ensure_ascii=False,indent=2))
