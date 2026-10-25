# -*- coding: utf-8 -*-
"""Build a portable static blog from local Markdown. No network or DB."""
from pathlib import Path
from collections import Counter
import hashlib, json, re, shutil
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
# Version both requests so a new deployment cannot reuse a previous index
# with a different set of solutions and verification records.
revision=hashlib.sha256((output/'content.json').read_bytes()).hexdigest()[:16]
app=(output/'app.js').read_text(encoding='utf-8')
assert app.count("fetch('content.json')")==1
app=app.replace("fetch('content.json')",f"fetch('content.json?v={revision}')")
(output/'app.js').write_text(app,encoding='utf-8')
app_revision=hashlib.sha256(app.encode('utf-8')).hexdigest()[:16]
html=(output/'index.html').read_text(encoding='utf-8')
assert html.count('src="app.js"')==1
(output/'index.html').write_text(html.replace('src="app.js"',f'src="app.js?v={app_revision}"'),encoding='utf-8')
print(f'已生成 {output}；{index["stats"]["complete_contests"]} 篇完整题解，{len(posts)-index["stats"]["complete_contests"]} 篇草稿。')
