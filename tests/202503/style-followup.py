from pathlib import Path
import hashlib,json,subprocess,time
root=Path(__file__).resolve().parents[1]
cases=[c for c in json.loads((root/'reports/cases.json').read_text()) if c['problem'] in 'CD']
report={'original_report':'summary.json','source_sha256':{},'changes':{'C':'Repeated conditional expression stored in ll v before accumulation','D':'Short reference to nonempty h.back(), used only before possible push_back'},'results':{}}
for letter in 'CD':
    report['source_sha256'][letter]=hashlib.sha256((root/(letter+'.cpp')).read_bytes()).hexdigest()
    for name,flags in [('opt',['-O2']),('ubsan',['-O1','-fsanitize=undefined','-fno-sanitize-recover=all'])]:
        exe=Path('/tmp')/('csp-202503-'+letter+'-'+name+'-style')
        cmd=['clang++','-std=c++17','-Wall','-Wextra','-I/tmp/csp-personal-compat',*flags,str(root/(letter+'.cpp')),'-o',str(exe)]
        built=subprocess.run(cmd,text=True,capture_output=True);assert built.returncode==0,built.stderr
        count=0
        for c in cases:
            if c['problem']!=letter:continue
            result=subprocess.run([str(exe)],input=c['input'],text=True,capture_output=True,timeout=90)
            assert result.returncode==0 and result.stdout.split()==str(c['output']).split(),(letter,name,result.stderr)
            count+=1
        report['results'][letter+':'+name]={'passed':count,'compile_stderr':built.stderr}
(root/'reports/style-followup.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(report)
