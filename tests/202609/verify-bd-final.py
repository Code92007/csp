"""Focused final-style replay: original independent oracles and saved data."""
from pathlib import Path
import ast,hashlib,json,subprocess,time
P=Path(__file__).resolve().parents[1];W=P.parent
B=Path('/tmp/csp-202609-final');B.mkdir(exist_ok=True)
r=dict(contest='202609',source_sha256={c:hashlib.sha256((P/(c+'.cpp')).read_bytes()).hexdigest() for c in 'BD'},compilation={},runs=[],note='Equivalent style revisions only; no online submission. Independent exhaustive subset/coloring oracles remain the source of small-case expected answers.')
for c,t,count in [('B',2,250),('D',4,600)]:
    pack=W/('CSP45-T'+str(t))
    checker=None
    if c=='D':
        tree=ast.parse((pack/'tools/check_std.py').read_text());body=[]
        for node in tree.body:
            if isinstance(node,ast.If):break
            body.append(node)
        checker={'__file__':str(pack/'tools/check_std.py')}
        exec(compile(ast.Module(body=body,type_ignores=[]),'check_std.py','exec'),checker)
    for mode,flags in [('O2',['-O2']),('UBSan',['-O1','-fsanitize=undefined','-fno-sanitize-recover=all'])]:
        exe=B/(c+'-'+mode)
        cmd=['clang++','-std=c++17','-Wall','-Wextra','-I/tmp/csp-personal-compat',*flags,str(P/(c+'.cpp')),'-o',str(exe)]
        z=subprocess.run(cmd,text=True,capture_output=True);assert not z.returncode and not z.stderr,z.stderr
        r['compilation'][c+':'+mode]='passed without diagnostics'
        start=time.monotonic();z=subprocess.run(['python3',str(pack/'tools/brute_check.py'),str(exe)],text=True,capture_output=True,timeout=240)
        assert not z.returncode and not z.stderr,(c,mode,z.stdout,z.stderr)
        saved=0
        for folder in ['samples','data']:
            for path in sorted((pack/folder).glob('*.in')):
                if c=='D':checker['check'](str(exe),path)
                else:
                    z=subprocess.run([str(exe)],input=path.read_text(),text=True,capture_output=True,timeout=30)
                    assert not z.returncode and not z.stderr and z.stdout.split()==path.with_suffix('.out').read_text().split(),(c,mode,path,z.stderr)
                saved+=1
        r['runs'].append(dict(problem=c,mode=mode,independent=count,saved=saved,passed=count+saved,seconds=time.monotonic()-start))
(P/'reports/bd-final-report.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(r,ensure_ascii=False,indent=2))
