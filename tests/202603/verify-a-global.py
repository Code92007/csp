"""Recheck the 202603A global-variable revision without rerunning B or C.

Requires normal and UBSan A executables in .build/202603-prep/refactored.
Uses only the A generators and run helper of verify-abc.py through its AST.
"""
from pathlib import Path
from collections import Counter
import ast
import hashlib
import json

REPORT=Path(__file__).resolve().parent
ROOT=REPORT.parents[1]
source=ROOT/'202603/A.cpp'
source_hash=hashlib.sha256(source.read_bytes()).hexdigest()
old=json.loads((REPORT/'abc-boundary-report.json').read_text())
script=REPORT/'verify-abc.py'
tree=ast.parse(script.read_text())
prefix=[]
for node in tree.body:
    if isinstance(node,ast.FunctionDef) and node.name=='b_oracle':break
    prefix.append(node)
runner=next(node for node in tree.body if isinstance(node,ast.FunctionDef) and node.name=='run')
scope={'__file__':str(script),'__name__':'a_only_recheck'}
exec(compile(ast.fix_missing_locations(ast.Module(body=prefix+[runner],type_ignores=[])),
             str(script),'exec'),scope)
extra=scope['cases']
assert len(extra)==862 and all(x['problem']=='A' for x in extra)
retained=[]
for i,case in enumerate(json.loads((ROOT/'.build/202603-prep/cases.json').read_text())):
    if case['problem']=='A':
        retained.append(dict(case,name=f'retained-{i:03d}',answer=case['output'],ubsan=True))
assert len(retained)==62
all_cases=retained+extra
results=[scope['run']('',all_cases),scope['run']('-ubsan',[c for c in all_cases if c['ubsan']])]
for result in results:
    result.pop('max_B_absolute_error',None)
assert source_hash==hashlib.sha256(source.read_bytes()).hexdigest(),'Source changed during validation'
digest=hashlib.sha256()
for case in all_cases:
    digest.update(case['input'].encode())
    digest.update(b'\0')
    digest.update(str(case['answer']).encode())
    digest.update(b'\0')
report=dict(problem='202603A',revision='n,ans,x,cnt,len at global scope; cnt=len=0 before each input',
            source_sha256={'A.cpp':source_hash},previous_source_sha256={'A.cpp':old['source_sha256']['A.cpp']},
            oracle_sha256=hashlib.sha256(script.read_bytes()).hexdigest(),
            recheck_script_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
            case_sha256=digest.hexdigest(),retained_inputs=len(retained),additional_inputs=len(extra),
            total_inputs=len(all_cases),distinct_input_texts=len({c['input'] for c in all_cases}),
            results=results,
            compilation='Apple Clang C++17, -O2 -Wall -Wextra; UBSan -O1 -g -fsanitize=undefined -fno-sanitize-recover=all. No compiler warnings or sanitizer diagnostics.',
            note='Only A was rebuilt and rechecked for this revision. B/C validation and source hashes remain the historical entries in abc-boundary-report.json. UBSan repeats a subset and does not add independent inputs.')
(REPORT/'a-global-report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
# Preserve every existing validation result and historical hash; only append a pointer.
old['subsequent_A_validation']=dict(report='a-global-report.json',source_sha256=source_hash,
                                   note='The global-variable revision of A was separately rebuilt and rechecked; original A/B/C results above are retained unchanged.')
(REPORT/'abc-boundary-report.json').write_text(json.dumps(old,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False,indent=2))
