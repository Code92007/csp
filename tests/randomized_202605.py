# -*- coding: utf-8 -*-
"""Independent small-instance models. Compile via make check before running."""
from pathlib import Path
from collections import deque
from itertools import permutations
import json, random, subprocess
root=Path(__file__).resolve().parents[1]
rng=random.Random(20261023)
counts={}
def run(letter,text):
    result=subprocess.run([str(root/'.build'/'202605'/letter)],input=text,text=True,capture_output=True,timeout=15,check=True)
    return list(map(int,result.stdout.split()))

# Every fractional digit, on both even and odd integral parts.
a=[(x,b) for x in range(10) for b in range(10)]
text=str(len(a))+'\n'+'\n'.join(f'{x}.{b}' for x,b in a)+'\n'
want=[x+(b>=5) for x,b in a]+[round(x+b/10) for x,b in a]
assert run('A',text)==want
counts['A']=1

for _ in range(100):
    n=rng.randint(10,300);k=rng.randint(1,5);m=rng.randint(1,8)
    best=0
    for robots in range(n+1):
        t=n
        for day in range(m):
            t-=(t*k+99)//100
            t-=robots
            if t<0:break
        else:best=robots
    assert run('B',f'{n} {k} {m}\n')==[best]
counts['B']=100

# This oracle uses absolute waiting-start times and a fixed generous timeline,
# independent of the implementation's quiet-period termination rule.
for _ in range(90):
    n=rng.randint(1,6);m=rng.randint(1,6)
    specs=[];lines=[f'{n} {m}']
    for i in range(n):
        kind=rng.choice('XABC');start=rng.randint(1,4);w=rng.randint(1,4)
        resources=rng.sample(range(m),rng.randint(1,m));lengths=[rng.randint(1,4) for r in resources]
        specs.append((kind,start,w,list(zip(resources,lengths))))
        words=[kind,str(start)]+([] if kind=='X' else [str(w)])+[str(len(resources))]
        words += [str(v) for r,t in zip(resources,lengths) for v in (r+1,t)]
        lines.append(' '.join(words))
    owner=[-1]*m;cursor=[0]*n;left=[0]*n;since=[None]*n;release=[False]*n;gain=[0]*n;end=[-1]*n
    for now in range(1,1001):
        normal=[[] for _ in range(m)];force=[[] for _ in range(m)]
        running={i for i in range(n) if left[i]>0 and end[i]<0}
        for i,(kind,start,w,tasks) in enumerate(specs):
            if end[i]>=0 or now<start or left[i]>0:continue
            if since[i] is None:since[i]=now;release[i]=False
            r=tasks[cursor[i]][0]
            (force if kind=='C' and now-since[i]>=w else normal)[r].append(i)
        for r in range(m):
            if force[r]:
                owner[r]=max(force[r]);running.update(force[r])
                for i in force[r]:left[i]=specs[i][3][cursor[i]][1]
            elif owner[r]<0 and normal[r]:
                i=min(normal[r]);owner[r]=i;running.add(i);left[i]=specs[i][3][cursor[i]][1]
        drop=set()
        for i,(kind,start,w,tasks) in enumerate(specs):
            if end[i]>=0 or now<start or i in running:continue
            if kind=='B' and now-since[i]+1>=w:
                left[i]=tasks[cursor[i]][1];running.add(i)
            if kind=='A' and not release[i] and now-since[i]+1>=w:drop.add(i);release[i]=True
        for i in running:
            gain[i]+=owner.count(i);left[i]-=1
            if not left[i]:
                cursor[i]+=1;since[i]=None
                if cursor[i]==len(specs[i][3]):end[i]=now;drop.add(i)
        owner=[-1 if i in drop else i for i in owner]
        if all(e>=0 for e in end):break
    expected=[v for i in range(n) for v in (gain[i],end[i]-specs[i][1]+1 if end[i]>=0 else -1)]
    text='\n'.join(lines)+'\n'
    assert run('C',text)==expected,(text,run('C',text),expected)
counts['C']=90

for _ in range(110):
    n=rng.randint(1,13);b=[rng.randrange(8) for _ in range(n)]
    queries=[(l,r) for l in range(n) for r in range(l,n)]
    expected=[]
    for l,r in queries:
        dp=[0]*(r-l+2)
        for end in range(l,r+1):
            for start in range(l,end+1):
                value=0
                for pos in range(start,end+1,2):value^=b[pos]
                dp[end-l+1]=max(dp[end-l+1],dp[start-l]+(value==0))
        expected.append(dp[-1])
    text=f'{n} {len(queries)}\n'+' '.join(map(str,b))+'\n'+''.join(f'{l+1} {r+1}\n' for l,r in queries)
    assert run('D',text)==expected,(text,run('D',text),expected)
counts['D']=110

# Exhaustive operation search retains every reachable sequence and enumerates
# every block permutation, rather than using the DP's lexicographic dominance.
for _ in range(24):
    n=rng.randint(2,6);edges=[(rng.randrange(i),i) for i in range(1,n)]
    graph=[set() for _ in range(n)]
    for u,v in edges:graph[u].add(v);graph[v].add(u)
    stars=[graph[u]|{u} for u in range(n)]
    visited=set();todo=deque()
    for c in range(n):
        for seq in permutations(stars[c]):
            state=(c,seq);visited.add(state);todo.append(state)
    answer=None
    while todo:
        u,old=todo.popleft();used=set(old)
        if len(old)==n:
            if answer is None or old<answer:answer=old
            continue
        for c in graph[u]|{u}:
            blocks=[old]+[(v,) for v in stars[c]-used]
            for order in permutations(blocks):
                seq=tuple(v for block in order for v in block);state=(c,seq)
                if state not in visited:visited.add(state);todo.append(state)
    text=str(n)+'\n'+''.join(f'{u+1} {v+1}\n' for u,v in edges)
    assert run('E',text)==[v+1 for v in answer],(text,run('E',text),answer)
counts['E_exhaustive_operations']=24
report={'seed':20261023,'cases':counts,'total':sum(counts.values()),'official_judge':'not_submitted','E_validation_scope':'24 small exhaustive-operation cases; full solver in 202605/E.cpp'}
(root/'tests'/'randomized-202605-report.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False))
