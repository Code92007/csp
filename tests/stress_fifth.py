from pathlib import Path
import random,subprocess,time,json,sys
R=Path(__file__).resolve().parent
rng=random.Random(20261023)
def generate(date,f):
    def put(s):f.write(s+'\n')
    if date=='201403':
        put('40')
        for i in range(40):put(' '.join(str(rng.randint(5,10)) for j in range(4)))
    elif date=='201512':
        n=1000;put(str(n))
        # Unit diagonal upper triangular matrix is guaranteed invertible.
        for i in range(n):put('0'*i+'1'+''.join(rng.choice('01') for j in range(n-i-1)))
        put(''.join(rng.choice('01') for i in range(n)));put('100')
        for i in range(100):put(str(rng.randrange(10**9)))
    elif date=='201809':
        put('100000 1000000000000 1000000300000');put(' '.join(str(rng.randrange(998244353)) for i in range(100000)))
    elif date=='201912':
        put('1000000 100000')
        for i in range(100000):a,b=sorted([rng.randint(1,1000000),rng.randint(1,1000000)]);put(f'{a} {b}')
    elif date=='202305':
        put('100000 abcdefghij')
        for i in range(100000):put(''.join(rng.choice('abcdefghijklmnopqrstuvwxyz') for j in range(10)))
    elif date=='202312':
        n=100;k=30;m=5000;put(f'{n} {m} 9 {k}');colors=[0]+[rng.randint(1,k-2) for i in range(n-2)]+[k-1];put(' '.join(map(str,colors)));e=[]
        while len(e)<m:
            u,v=rng.randrange(n),rng.randrange(n)
            if colors[u]!=colors[v]:e.append((u,v,rng.randint(1,1000000)))
        for j in range(3):put(' '.join(str(a[j]) for a in e))
    elif date=='202406':
        n=500000;put(f'{n} {n}')
        for i in range(n):a,b=sorted([rng.randint(1,n),rng.randint(1,n)]);c,d=sorted([rng.randint(1,n),rng.randint(1,n)]);put(f'{a} {b} {c} {d} {rng.randint(1,n)}')
        for i in range(n):a,b=sorted([rng.randint(1,n),rng.randint(1,n)]);c,d=sorted([rng.randint(1,n),rng.randint(1,n)]);put(f'{a} {b} {c} {d}')
    elif date=='202509':
        n=500000;put(f'{n} 100000000000000')
        for j in range(2):put(' '.join(str(rng.randint(1,10**9)) for i in range(n)))
    elif date=='202112':
        n=500000;put(f'{n} 10000 20000');vertices=list(range(1,n+1));rng.shuffle(vertices)
        for i in range(1,n):put(f'{vertices[i-1]} {vertices[i]}')
    elif date=='201604':
        n=500;p=6;put('1');edges=[(u,v) for u in range(1,n+1) for v in range(u+1,min(n,u+p)+1)];put(f'{n} {len(edges)} {p}');put(''.join('1' if rng.randrange(4)==0 else '0' for i in range(n)))
        for u,v in edges:put(f'{u} {v} {rng.randint(0,1000000)}')
    else:raise ValueError(date)
report=json.loads((R/'fifth-stress-report.json').read_text()) if (R/'fifth-stress-report.json').exists() else {}
for date in sys.argv[1:]:
    source=R.parent/'.build'/'fifth-stress-input.txt'
    with source.open('w') as f:generate(date,f)
    started=time.monotonic()
    try:
        with source.open() as inp:(p:=subprocess.run([str(R.parent/'.build'/date/'E')],stdin=inp,stdout=subprocess.DEVNULL,stderr=subprocess.PIPE,timeout=90))
        result={'seconds':round(time.monotonic()-started,3),'exit_code':p.returncode,'note':'生成器见 stress.py；仅检查完成运行，不替代正确性评测'}
    except subprocess.TimeoutExpired:result={'seconds':90,'timeout':True}
    report[date]=result;(R/'fifth-stress-report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2));print(date,result,flush=True)
