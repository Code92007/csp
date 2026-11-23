from pathlib import Path
import argparse,hashlib,json,os,subprocess
root=Path(__file__).resolve().parents[1]
parser=argparse.ArgumentParser();parser.add_argument('--previous',type=Path);args=parser.parse_args()
executables=[]
for label,source in ([('before_arrays',args.previous)] if args.previous else [])+[('global_arrays',root/'E.cpp')]:
    exe=Path('/tmp')/('csp-202406-E-memory-'+label)
    r=subprocess.run(['clang++','-std=c++17','-O2','-I/tmp/csp-personal-compat',str(source),'-o',str(exe)],capture_output=True,text=True);assert not r.returncode,r.stderr
    executables.append((label,exe))
cases=json.loads((root/'reports/cases.json').read_text())
report={'source_sha256':hashlib.sha256((root/'E.cpp').read_bytes()).hexdigest(),'prior_source_sha256':hashlib.sha256(args.previous.read_bytes()).hexdigest() if args.previous else None,'note':'macOS wait4 ru_maxrss in bytes; local analytic maximum tests, not a universal upper bound','measurements':[]}
for c in cases:
    if c['problem']!='E' or c['kind']!='stress':continue
    data=Path('/tmp/csp-202406-memory.in');data.write_text(c['input'])
    for label,exe in executables:
        with data.open() as stream:
            p=subprocess.Popen([str(exe)],stdin=stream,stdout=subprocess.DEVNULL,stderr=subprocess.PIPE,text=True)
            _, status, usage=os.wait4(p.pid,0)
            p.returncode=os.waitstatus_to_exitcode(status)
        assert p.returncode==0,p.stderr.read()
        rss=usage.ru_maxrss
        report['measurements'].append(dict(case=c['label'],variant=label,max_rss_bytes=rss))
(root/'reports/array-memory.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(report)
