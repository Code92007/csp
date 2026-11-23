from pathlib import Path
import ast,hashlib,json,subprocess,sys
r=Path(__file__).resolve().parents[1];w=r.parent
scope={'__file__':str(r/'reports/verify.py')}
sys.argv=[str(r/'reports/verify.py')]
src=(r/'reports/verify.py').read_text().split('# An exact duplicate')[0]
exec(compile(src,str(r/'reports/verify.py'),'exec'),scope)
cases=[x for x in scope['cases'] if x['problem'] in 'CDE' or (x['problem']=='B' and x['kind']=='saved_sample')]
records=[]
for mode,flags in [('O2',['-O2']),('UBSan',['-O1','-g','-fsanitize=undefined','-fno-sanitize-recover=all'])]:
    for c in 'BCDE':
        exe=w/'.build/202509-prep'/f'{c}-followup-{mode}'
        p=subprocess.run(['clang++','-std=c++17','-Wall','-Wextra','-I/tmp/csp202609-check/include',*flags,str(r/f'{c}.cpp'),'-o',str(exe)],text=True,capture_output=True)
        assert p.returncode==0 and not p.stderr,p.stderr
        n=0
        for x in cases:
            if x['problem']!=c:continue
            p=subprocess.run([str(exe)],input=x['input'],text=True,capture_output=True,timeout=30)
            assert p.returncode==0 and not p.stderr,(c,p.stderr)
            assert p.stdout.split()==x['output'].split(),(c,p.stdout,x['output'])
            n+=1
        records.append(dict(mode=mode,problem=c,inputs=n,result='passed'))
report=dict(changes='B字模整体单行；C pos/p、pad/w、bits/b、key/k、val/v、get/f；动态表d避免与位数b重名；D成组短赋值及查询结果局部变量；E二分右界显式ll转换、check结果先存P res。',before_sha256=json.loads((r/'reports/style-before.json').read_text()),after_sha256={c:hashlib.sha256((r/f'{c}.cpp').read_bytes()).hexdigest() for c in 'BCDE'},checks=records,history='report.json保留前一版源码哈希和全量1442输入记录；本次仅补跑受影响B/C/D/E。')
(r/'reports/style-followup-report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False,indent=2))
