# -*- coding: utf-8 -*-
"""Refresh only the generated progress table in the project's README."""
from content import ROOT,articles
import re
posts=articles()
start='<!-- contest-index:start -->';end='<!-- contest-index:end -->'
rows=['| 年月 | 题解文章 | 完整实现 | 部分分实现 | 待编写 |','|---|---|---:|---:|---:|']
for a in posts:
    states=[p['status'] for p in a['problems']]
    rows.append(f'| {a["contest"]} | [{a["title"]}]({a["path"]}) | {states.count("implemented")} | {states.count("partial")} | {states.count("pending")} |')
path=ROOT/'README.md';text=path.read_text(encoding='utf-8')
before,rest=text.split(start,1);_,after=rest.split(end,1)
text=before+start+'\n\n'+'\n'.join(rows)+'\n\n'+end+after
states=[p['status'] for a in posts for p in a['problems']]
progress=f'全工程目前有 {states.count("implemented")} 份完整实现、{states.count("partial")} 份部分分实现，剩余 {states.count("pending")} 题待补充。'
if 'pending' in states:
    progress+='未完成源码包含明确的 `#error`，不能提交。'
text=re.sub(r'全工程目前有 [^\n]+',progress,text)
path.write_text(text,encoding='utf-8')
print('已更新 README 的场次进度表。')
rows=['# 第五题目录（从新到旧）','',
      '范围是本工程已有的 32 个年月题组，不表示已经收录 CSP 历史上的全部场次。每篇保留五题结构；前四题已按 D、C、B、A 顺序补齐。',
      '', '目前 E：32 份完整实现；202605E 已补充原题完整规模算法，并保留小规模对拍基准。完整实现指代码覆盖题意所述操作，不表示已通过官方评测；具体样例、随机对拍与性能边界见文章和 tests/。',
      '', '| 场次 | 第五题 | 状态 | 主要标签 |', '|---|---|---|---|']
for a in posts:
    p=a['problems'][4]
    state={'implemented':'完整实现，未获官方 AC','partial':'部分分：n≤10','pending':'待编写'}[p['status']]
    rows.append(f'| {a["contest"]} | [{p["title"]}](../{a["path"]}#problem-e) | {state} | {"、".join(p["tags"])} |')
rows+=['','## 如何使用','',
       '每篇 E 都包含题意、算法推导、正确性说明、复杂度和代码。独立源码位于对应年月目录的 E.cpp；前四题可从 problem-order.md 按题号查阅。',
       '', '每天只有 2–3 小时时，建议把这份目录作为查阅资料。当前目标是超过 200 分，练习主线仍应是稳定做对前两题，再争取第三题或第四题的部分分；无需按目录一次学完第五题。',
       '', '可先阅读 201312 的反向图、202403 的链表与树状数组、202409 的启发式分裂，再按需要进入自动机、网络流、动态树和多项式。',
       '', '## 验证入口','', '先运行 `make check` 编译已有实现并核对保存样例，再运行 `make random-fifth` 重现本轮第五题的随机对拍。大型运行检查可按需运行 `python3 tests/stress_fifth.py 202406`，其结果依赖机器与构造，不能代替正式评测。',
       '', '202605E 原题与 Bonus 的规则、参考资料和验证范围见对应文章。运行 `make random-gather` 可重现 2042 组独立对拍，`make stress-gather` 可重现十万点构造。']
(ROOT/'docs'/'fifth-problems.md').write_text('\n'.join(rows)+'\n',encoding='utf-8')
print('已更新第五题目录。')
rows=['# 按题号阅读（D → C → B → A）','','同题号按场次从新到旧。这里列出本工程既有的 32 场，A–D 已全部补齐。','']
for letter in 'DCBA':
    rows += [f'## 第 {ord(letter)-64} 题（{letter}）','', '| 场次 | 题目 | 状态 | 标签 |','|---|---|---|---|']
    for a in posts:
        p=a['problems'][ord(letter)-65]
        label={'implemented':'已实现','partial':'部分分','pending':'待编写'}[p['status']]
        rows.append(f'| {a["contest"]} | [{p["title"]}](../{a["path"]}#{p["anchor"]}) | {label} | {"、".join(p["tags"])} |')
    rows.append('')
(ROOT/'docs'/'problem-order.md').write_text('\n'.join(rows)+'\n',encoding='utf-8')
