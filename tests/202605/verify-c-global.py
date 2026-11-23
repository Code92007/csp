from pathlib import Path
import argparse,ast,collections,hashlib,json,subprocess,time
W=Path(__file__).resolve().parents[2];D=W/'202605';ap=argparse.ArgumentParser();ap.add_argument('--repo',default='/tmp/csp-style-publish');args=ap.parse_args();repo=Path(args.repo)
original=repo/'tests/randomized_202605.py';tree=ast.parse(original.read_text());body=[];found=False
def subkey(t):
 value=t.slice
 if isinstance(value,ast.Index):value=value.value
 return value.value if isinstance(value,ast.Constant) else None
for node in tree.body:
 body.append(node)
 if isinstance(node,ast.Assign) and any(isinstance(t,ast.Subscript) and isinstance(t.value,ast.Name) and t.value.id=='counts' and subkey(t)=='C' for t in node.targets):found=True;break
assert found,'Could not safely stop after C oracle; no original module code was executed'
class CaptureAssert(ast.NodeTransformer):
 def visit_Assert(self,node):
  c=node.test
  if isinstance(c,ast.Compare) and isinstance(c.left,ast.Call) and isinstance(c.left.func,ast.Name) and c.left.func.id=='run':
   return ast.Expr(ast.Call(ast.Name('capture',ast.Load()),c.left.args+[c.comparators[0]],[]))
  return node
cases=[]
def capture(letter,data,expected):
 if letter=='C':cases.append(dict(problem='C',kind='retained_independent',input=data,output=' '.join(map(str,expected))))
scope=dict(__file__=str(original),__name__='c_oracle_capture',capture=capture);module=CaptureAssert().visit(ast.Module(body=body,type_ignores=[]));ast.fix_missing_locations(module);exec(compile(module,str(original),'exec'),scope)
assert len(cases)==90,len(cases)
for c in json.loads((repo/'tests/202605C.json').read_text()):cases.append(dict(problem='C',kind='saved_sample',**c))
lines=['10 40']
for i in range(10):lines.append('X 1 4 '+' '.join(f'{4*i+j} 1' for j in range(1,5)))
cases.append(dict(problem='C',kind='array_boundary',input='\n'.join(lines)+'\n',output='10 4\n'*10))
cases=list({c['input']:c for c in cases}.values());results=[]
for mode,flags in [('O2',['-O2']),('UBSan',['-O1','-g','-fsanitize=undefined','-fno-sanitize-recover=all'])]:
 binary=W/'.build/202605-c-global'/mode;binary.parent.mkdir(parents=True,exist_ok=True)
 r=subprocess.run(['clang++','-std=c++17','-Wall','-Wextra','-Wshadow','-I/tmp/csp202609-check/include',*flags,str(D/'C.cpp'),'-o',str(binary)],capture_output=True,text=True);assert not r.returncode and not r.stderr,r.stderr
 start=time.monotonic()
 for c in cases:
  r=subprocess.run([str(binary)],input=c['input'],capture_output=True,text=True,timeout=30)
  assert not r.returncode and not r.stderr and r.stdout.split()==c['output'].split(),(mode,c,r.stdout,r.stderr)
 results.append(dict(mode=mode,inputs=len(cases),passed=True,compile_stderr='',seconds=time.monotonic()-start))
report=dict(problem='202605C',previous_sha256=json.loads((D/'reports/c-global-before.json').read_text())['C'],source_sha256=hashlib.sha256((D/'C.cpp').read_bytes()).hexdigest(),distinct_inputs=len(cases),case_kinds=dict(collections.Counter(c['kind'] for c in cases)),case_sha256=hashlib.sha256(json.dumps(cases,sort_keys=True).encode()).hexdigest(),oracle_sha256=hashlib.sha256(original.read_bytes()).hexdigest(),compilation='C++17 O2/UBSan -Wall -Wextra -Wshadow no diagnostics',results=results,change='Move ok/drop/low/high/held arrays to globals; preserve all five memset calls inside every round; event remains local.',oracle='Retained independent model uses absolute waiting-start times and fixed 1000-unit timeline; maximum n=10/m=40 nonconflicting resource chains have analytic gain 10 and duration 4.',note='Local style followup; earlier reports remain historical and no online resubmission.')
(D/'reports/c-global-followup-report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n');print(json.dumps(report,ensure_ascii=False,indent=2))
