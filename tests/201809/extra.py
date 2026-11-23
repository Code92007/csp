"""Independent direct recurrences and analytic maximum cases; no legacy executable."""
import importlib.util
import random
from pathlib import Path

M = 998244353

def case(letter, data, out, kind='boundary', label=''):
    return dict(problem=letter, input=data, output=str(out), kind=kind, label=label)

def cases():
    spec = importlib.util.spec_from_file_location('optimized', '/tmp/csp-style-publish/tests/optimized_regressions.py')
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    for m,l,r,k in mod.recurrence_cases(random.Random(20180920261025)):
        out='\n'.join(mod.direct_recurrence(m,l,r,k))
        yield case('E',mod.recurrence_input(m,l,r,k),out,'retained_independent')
    a=[1,10000]*500
    out=[sum(a[max(0,i-1):min(1000,i+2)])//len(a[max(0,i-1):min(1000,i+2)]) for i in range(1000)]
    yield case('A','1000\n'+' '.join(map(str,a)), ' '.join(map(str,out)), 'stress','1000 alternating prices')
    rows=''.join(f'{i*4+1} {i*4+3}\n' for i in range(2000))
    yield case('B','2000\n'+rows+rows,4000,'stress','2000 identical disjoint intervals')
    # Maximum document with shallow branches; selector query paths are checked by explicit ancestor-subsequence enumeration.
    tags=['div' if i%3==0 else 'p' for i in range(100)]
    parents=[-1]+[0 if i%10==1 else i-1 for i in range(1,100)]
    dep=[0]*100
    for i in range(1,100):dep[i]=dep[parents[i]]+1
    rows=['..'*dep[i]+tags[i]+f' #n{i}' for i in range(100)]
    qs=['DIV','p','div p','div div p','#n0 p','#N0 p','#n99','#n1 #n9','p div p','p p p']
    out=[]
    for q in qs:
        s=q.split();found=[]
        for u in range(100):
            chain=[];v=u
            while v>=0:chain.append(v);v=parents[v]
            chain.reverse()
            def match(v,t):return f'#n{v}'==t if t[0]=='#' else tags[v]==t.lower()
            states={0}
            for v in chain[:-1]:
                states|={k+1 for k in states if k<len(s)-1 and match(v,s[k])}
            if len(s)-1 in states and match(u,s[-1]):found.append(u+1)
        out.append(str(len(found))+''.join(' '+str(v) for v in found))
    yield case('C','100 10\n'+'\n'.join(rows+qs)+'\n','\n'.join(out),'stress','100 nodes; mixed tag/id/descendant queries')
    # At every valid position average 1 forces the lexicographically minimal all-one vector.
    for b in ([1]*300,[100]*300):
        # Iterative forward state propagation + backwards viable layers, independent of memoized DFS order.
        n=len(b);layers=[];start={(x,y) for x in range(1,2*b[0]+1) for y in (2*b[0]-x,2*b[0]+1-x) if y>0}
        layers.append(start)
        for i in range(1,n-1):
            layer={(y,z) for x,y in layers[-1] for z in range(max(1,3*b[i]-x-y),3*b[i]+3-x-y)}
            layers.append(layer)
        good={v for v in layers[-1] if sum(v)//2==b[-1]};viable=[good]
        for i in range(n-2,0,-1):
            good={(x,y) for x,y in layers[i-1] if any((y,z) in good for z in range(max(1,3*b[i]-x-y),3*b[i]+3-x-y))}
            viable.append(good)
        viable.reverse();x,y=min(viable[0]);a=[x,y]
        for i in range(1,n-1):
            a.append(min(z for z in range(max(1,3*b[i]-sum(a[-2:])),3*b[i]+3-sum(a[-2:])) if (a[-1],z) in viable[i]))
        yield case('D',str(n)+'\n'+' '.join(map(str,b)),' '.join(map(str,a)),'stress','300 equal observed prices '+str(b[0]))
    # Full coefficient and output bounds; closed forms independently determine every output.
    l=10**12;r=l+300000;m=100000
    for typ in ('zero','periodic','geometric'):
        k=[0]*m
        if typ=='periodic':k[-1]=1
        if typ=='geometric':k[0]=M-1
        out=['0' if typ=='zero' else str(int(i%m==0)) if typ=='periodic' else str(1 if i%2==0 else M-1) for i in range(l,r+1)]
        yield case('E',mod.recurrence_input(m,l,r,k),'\n'.join(out),'stress','m=100000; 300001 outputs; '+typ)
    # All coefficients nonzero; until m the sequence is 1,1,2,4,... .
    m=100000;l=1;r=m
    yield case('E',mod.recurrence_input(m,l,r,[1]*m),'\n'.join(str(pow(2,i-1,M)) for i in range(l,r+1)),'stress','100000 nonzero coefficients; dense inverse')
