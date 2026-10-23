# -*- coding: utf-8 -*-
"""Independent small-input oracles for the implemented 202609 solutions."""
from pathlib import Path
from decimal import Decimal, localcontext
from collections import deque
import itertools, json, random, subprocess
root = Path(__file__).resolve().parents[1]
rng = random.Random(20261023)
counts = {}

def run(letter, data):
    binary = root / '.build' / '202609' / letter
    result = subprocess.run([str(binary)], input=data, text=True, capture_output=True, check=True, timeout=10)
    return result.stdout.split()

for _ in range(100):
    sigma = rng.randint(1000, 10000)
    table = sorted(set([0, 1000] + [rng.randint(1, 999) for _ in range(10)]))
    with localcontext() as ctx:
        ctx.prec = 80
        z = Decimal(1000) / Decimal(sigma)
        chosen = min(range(len(table)), key=lambda i: (abs(z - Decimal(table[i]) / 1000), i))
    f = lambda x: f'{x // 1000}.{x % 1000:03}'
    values = [f'0.{500 + i:03d}' for i in range(len(table))]
    data = f'1 2 {len(table)}\n1.000\n{f(sigma)}\n' + ' '.join(map(f, table)) + '\n' + ' '.join(values) + '\n'
    assert run('A', data) == [values[chosen]], data
assert run('A', '1 2 2\n1.000\n2.000\n0.400 0.600\n0.655 0.726\n') == ['0.655']
counts['A'] = 101

for _ in range(120):
    n = rng.randint(1, 9)
    m, q = rng.randint(1, 10), rng.randint(500, 1000)
    gains = [rng.randint(1, 25) for _ in range(n)]
    sigma = [rng.randint(1, 30) for _ in range(n)]
    best = 0
    for mask in range(1 << n):
        risk = sum(sigma[i] ** 2 for i in range(n) if mask >> i & 1)
        gain = sum(gains[i] for i in range(n) if mask >> i & 1)
        if risk * q * q <= 100 * m * m * 1000000: best = max(best, gain)
    data = f'{n} {m} {q//1000}.{q%1000:03}\n' + ' '.join(map(str,gains)) + '\n' + ' '.join(f'{x//10}.{x%10}' for x in sigma) + '\n'
    assert run('B',data) == [str(best)], data
counts['B'] = 120

for _ in range(100):
    n,m,T = rng.randint(1,10),rng.randint(1,5),rng.randint(1,10)
    quantum = [rng.randint(1,7) for _ in range(m)]
    original = [rng.randint(1,20) for _ in range(n)]
    preferred = [{c for c in range(m) if rng.randrange(2)} for _ in range(n)]
    lines = [f'{n} {m} {T}', ' '.join(map(str,quantum))]
    lines += [f'{original[i]} {len(preferred[i])} ' + ' '.join(str(c+1) for c in sorted(preferred[i])) for i in range(n)]
    queues = [deque() for _ in range(m)]
    for i in range(n):queues[i%m].append(i)
    work = original[:]
    first = [-1]*n
    answer = [None]*n
    running = [None]*m
    used = [0]*m
    now, done = 0,0
    while done<n:
        shift=now//T
        for c in range(m):
            if running[c] is None and queues[(c+shift)%m]:
                i=queues[(c+shift)%m].popleft();running[c]=i;used[c]=0
                if first[i]<0:first[i]=now
        for c in range(m):
            if running[c] is None:continue
            i=running[c];work[i]=max(0,work[i]-(2 if c in preferred[i] else 1));used[c]+=1
            if work[i]==0 or used[c]==quantum[c]:
                if work[i]==0:answer[i]=now+1-first[i];done+=1
                else:queues[(c+shift)%m].append(i)
                running[c]=None
        now+=1
        assert now<=sum(original)+1
    data='\n'.join(lines)+'\n'
    assert run('C',data)==list(map(str,answer)),data
counts['C']=100

for _ in range(240):
    n=rng.randint(1,15);k=rng.randint(2,7);op=rng.randrange(2)
    values=rng.sample(range(1,250),n)
    if _==0:values=[100,200,400,140,290];n=5;k=2;op=1
    graph=[[] for _ in values]
    for i,j in itertools.combinations(range(n),2):
        x,y=sorted([values[i],values[j]],reverse=True)
        conflict=(x==k*y) if op==0 else (x//y==k)
        if conflict:graph[i].append(j);graph[j].append(i)
    colour=[-1]*n;ok=True
    for s in range(n):
        if colour[s]!=-1:continue
        colour[s]=0;todo=[s]
        for v in todo:
            for u in graph[v]:
                if colour[u]<0:colour[u]=colour[v]^1;todo.append(u)
                elif colour[u]==colour[v]:ok=False
    expected=1 if not any(graph) else 2 if ok else 3
    data=f'{n} {k} {op}\n'+' '.join(map(str,values))+'\n'
    result=list(map(int,run('D',data)));g=result[0];pos=1;groups=[]
    assert g==expected,(data,result,expected)
    for i in range(g):
        count=result[pos];pos+=1;groups.append(result[pos:pos+count]);pos+=count
    assert pos==len(result) and sorted(sum(groups,[]))==sorted(values),(data,result)
    for group in groups:
        for x,y in itertools.combinations(group,2):
            x,y=max(x,y),min(x,y)
            assert (x!=k*y if op==0 else x//y!=k),(data,result)
counts['D']=240

for _ in range(140):
    n=rng.randint(1,12);m=rng.randint(1,5);k=rng.randint(1,4);q=rng.randint(0,20)
    colours=[rng.randrange(m) for _ in range(n)];lights=[rng.randrange(2) for _ in range(n)]
    graph=[[] for _ in range(n)];edges=[]
    for v in range(1,n):
        u=rng.randrange(v);w=rng.randint(1,12);edges.append((u,v,w));graph[u].append((v,w));graph[v].append((u,w))
    paths=[]
    for s in range(n):
        todo=[(s,-1,0,1<<colours[s])]
        for v,parent,distance,mask in todo:
            if v>=s and distance%k==0 and bin(mask).count("1")==1:paths.append((s,v))
            for u,w in graph[v]:
                if u!=parent:todo.append((u,v,distance+w,mask^(1<<colours[u])))
    toggles=[rng.randrange(n) for _ in range(q)]
    data=f'{n} {m} {k} {q}\n'+''.join(map(str,lights))+'\n'+' '.join(str(x+1) for x in colours)+'\n'
    data+=''.join(f'{u+1} {v+1} {w}\n' for u,v,w in edges)+''.join(f'{v+1}\n' for v in toggles)
    count=lambda:sum(lights[u] and lights[v] for u,v in paths)
    expected=[count()]
    for v in toggles:lights[v]^=1;expected.append(count())
    assert run('E',data)==list(map(str,expected)),data
counts['E']=140
report={'seed':20261023,'randomized_cases':counts,'total':sum(counts.values()),'official_judge':'not_submitted'}
(root/'tests'/'randomized-report.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False))
