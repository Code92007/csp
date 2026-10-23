# -*- coding: utf-8 -*-
from pathlib import Path
import argparse, json, os, shlex, subprocess, sys, math
from content import ROOT as root, articles, problem_items, code_blocks
items=list(problem_items())

def compile_one(item):
    if item['status'] not in ('implemented','partial'):
        raise RuntimeError('该题尚未实现，不能编译或运行：'+item['code_file'])
    target=root/'.build'/item['date']/item['letter']
    target.parent.mkdir(parents=True,exist_ok=True)
    cmd=shlex.split(os.environ.get('CXX','c++'))+['-std=c++17','-O2','-Wall','-Wextra',str(root/item['code_file']),'-o',str(target)]
    subprocess.run(cmd,check=True)
    return target

p=argparse.ArgumentParser()
p.add_argument('action',choices=['list','build','run','check'])
p.add_argument('session',nargs='?')
p.add_argument('problem',nargs='?')
a=p.parse_args()
if a.action=='list':
    for item in items: print(item['date'],item['letter'],item['status'],item['title'])
elif a.action in ('build','run'):
    item=next((x for x in items if x['date']==a.session and x['letter']==(a.problem or '').upper()),None)
    if not item:p.error('请提供有效的年月与 A–E 题号')
    target=compile_one(item)
    if a.action=='run':sys.exit(subprocess.run([str(target)]).returncode)
    print(target)
else:
    for article in articles():
        for letter,code in code_blocks(article).items():
            file=root/article['contest']/(letter+'.cpp')
            if not file.exists() or file.read_text().rstrip()!=code.rstrip():
                raise RuntimeError('文章与 CPP 不一致：'+str(file))
    compiled=cases=0
    for item in items:
        if item['status']=='pending':continue
        target=compile_one(item);compiled+=1
        test_file=root/'tests'/(item['date']+item['letter']+'.json')
        if not test_file.exists():continue
        for case in json.loads(test_file.read_text()):
            result=subprocess.run([str(target)],input=case['input'],text=True,capture_output=True,timeout=10,check=True)
            got,want=result.stdout.split(),case['output'].split()
            if 'abs_tol' in case or 'rel_tol' in case:
                equal=len(got)==len(want) and all(math.isclose(float(x),float(y),abs_tol=case.get('abs_tol',0),rel_tol=case.get('rel_tol',0)) for x,y in zip(got,want))
            elif case.get('exact_output'):equal=result.stdout.rstrip('\n')==case['output'].rstrip('\n')
            else:equal=got==want
            if not equal:
                raise RuntimeError(f'样例不符：{item["code_file"]} {case.get("name", "")}\n{result.stdout}')
            cases+=1
    print(f'编译 {compiled} 题；通过 {cases} 个保存样例；跳过 {len(items)-compiled} 道未实现题。')
