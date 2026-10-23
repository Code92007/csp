# -*- coding: utf-8 -*-
"""Build a portable static blog from local Markdown. No network or DB."""
from pathlib import Path
from collections import Counter
import json, re, shutil
from content import ROOT, articles, code_blocks

output=ROOT/'site'
output.mkdir(exist_ok=True)
for source in (ROOT/'web').iterdir():
    target=output/source.name
    if source.is_dir():shutil.copytree(source,target,dirs_exist_ok=True)
    else:shutil.copy2(source,target)
posts=articles()
for post in posts:
    code_blocks(post)
    directory=output/'content'/post['contest']
    directory.mkdir(parents=True,exist_ok=True)
    shutil.copy2(ROOT/post['path'],directory/'README.md')
    for problem in post['problems']:
        shutil.copy2(ROOT/post['contest']/problem['code'],directory/problem['code'])
    # Keep linked verification reports and oracle source available in the blog
    # and preserve their paths relative to the downloadable contest Markdown.
    for href in re.findall(r'\]\((\.\./tests/[A-Za-z0-9_./-]+)\)',post['body']):
        resource=(ROOT/post['contest']/href).resolve()
        relative=resource.relative_to(ROOT.resolve())
        if not resource.is_file():raise FileNotFoundError(resource)
        destination=output/'content'/relative
        destination.parent.mkdir(parents=True,exist_ok=True)
        shutil.copy2(resource,destination)
    post['ready']=sum(p['status']=='implemented' for p in post['problems'])
    post['search']=' '.join([post['title'],post['contest']]+post['tags']+[p['title'] for p in post['problems']]).lower()
plan=ROOT/'docs'/'study-plan.md'
if plan.exists():shutil.copy2(plan,output/'study-plan.md')
index=dict(version=1,articles=posts,stats=dict(contests=len(posts),problems=sum(len(p['problems']) for p in posts),implemented=sum(p['ready'] for p in posts),complete_contests=sum(p['ready']==5 for p in posts)),tags=dict(Counter(t for p in posts for t in set(p['tags']) if t!='CSP')))
(output/'content.json').write_text(json.dumps(index,ensure_ascii=False,separators=(',',':')),encoding='utf-8')
print(f'已生成 {output}；{index["stats"]["complete_contests"]} 篇完整题解，{len(posts)-index["stats"]["complete_contests"]} 篇草稿。')
