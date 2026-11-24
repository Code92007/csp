"""Replay independent recurrence cases and test the replacement NTT directly."""
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
import collections
import hashlib
import json
import subprocess
import tempfile
import time

ROOT=Path(__file__).resolve().parents[2]
DIR=ROOT/'201809'
SRC=DIR/'E.cpp'
BUILD=Path(tempfile.mkdtemp(prefix='csp-201809-ntt-',dir='/tmp'))
COMPILER='/opt/homebrew/bin/g++-16'
HARNESS=BUILD/'ntt-unit.cpp'
HARNESS.write_text('#define main recurrence_main\n#include "'+str(SRC)+'"\n#undef main\n'+r'''
int tests=0;
void check(bool ok){
    if(!ok){
        fprintf(stderr,"failed check %d\n",tests);
        exit(1);
    }
    ++tests;
}
poly naive(const poly &a,const poly &b){
    if(a.empty() || b.empty())return {};
    poly c(a.size()+b.size()-1);
    for(int i=0;i<(int)a.size();++i){
        for(int j=0;j<(int)b.size();++j){
            c[i+j]=(c[i+j]+(ll)a[i]*b[j])%mod;
        }
    }
    return c;
}
int main(){
    Init();
    mt19937 rng(2018092026);
    int direct=0,roundtrip=0,convolution=0,inverse=0;
    for(int n=1;n<=128;n<<=1){
        for(int t=0;t<5;++t){
            poly a(n),b(n);
            for(int &x:a){
                x=t==0?0:t==1?mod-1:rng()%mod;
            }
            if(t==2)a[0]=1;
            int w=qpow(3,(mod-1)/n);
            for(int i=0;i<n;++i){
                int pw=qpow(w,i),x=1;
                for(int j=0;j<n;++j){
                    b[i]=(b[i]+(ll)a[j]*x)%mod;
                    x=(ll)x*pw%mod;
                }
            }
            DFT(a,n);
            check(a==b);++direct;
        }
    }
    for(int n=1;n<=N;n<<=1){
        for(int t=0;t<6;++t){
            poly a(n);
            for(int i=0;i<n;++i){
                if(t==0)a[i]=0;
                else if(t==1)a[i]=mod-1;
                else if(t==2)a[i]=(i&1)?mod-1:1;
                else if(t==3)a[i]=i==n-1;
                else a[i]=rng()%mod;
            }
            poly b=a;
            DFT(b,n);IDFT(b,n);
            check(a==b);++roundtrip;
        }
    }
    int sizes[]={1,2,3,31,32,33,63,64,65,127,128,129,257};
    for(int n:sizes){
        for(int m:sizes){
            poly a(n),b(m);
            for(int &x:a){
                x=rng()%mod;
            }
            for(int &x:b){
                x=rng()%mod;
            }
            check(mul(a,b)==naive(a,b));++convolution;
        }
    }
    check(mul({},poly{1}).empty());++convolution;
    for(int t=0;t<2;++t){
        int n=N/2+1,m=N/2;
        poly a(n,t?mod-1:1),b(m,t?mod-1:1);
        poly c=mul(a,b),d(n+m-1);
        for(int i=0;i<n+m-1;++i){
            d[i]=min(min(i+1,n),min(m,n+m-1-i));
        }
        check(c==d);++convolution;
    }
    for(int n:sizes){
        for(int t=0;t<5;++t){
            poly a(n),b(n);
            for(int &x:a){
                x=rng()%mod;
            }
            if(!a[0])a[0]=1;
            b[0]=qpow(a[0],mod-2);
            for(int i=1;i<n;++i){
                int sum=0;
                for(int j=1;j<=i;++j){
                    sum=(sum+(ll)a[j]*b[i-j])%mod;
                }
                b[i]=(ll)(sum?mod-sum:0)*b[0]%mod;
            }
            check(inv(a,n)==b);++inverse;
        }
    }
    printf("{\"direct_dft\":%d,\"roundtrip\":%d,\"convolution\":%d,\"inverse\":%d,\"passed\":%d}\n",
        direct,roundtrip,convolution,inverse,tests);
}
''')
CASES=[t for t in json.loads((DIR/'reports/cases.json').read_text()) if t['problem']=='E']

def mode(name,flags):
    result={'compiler':COMPILER,'flags':flags,'compilation':{},'passed':0,'kinds':{},'stress':[]}
    exe=BUILD/name
    for src,dst,label in [(SRC,exe,'recurrence'),(HARNESS,BUILD/(name+'-unit'),'ntt_unit')]:
        cmd=[COMPILER,'-std=c++17','-Wall','-Wextra',*flags,str(src),'-o',str(dst)]
        p=subprocess.run(cmd,capture_output=True,text=True,timeout=120)
        result['compilation'][label]={'command':cmd,'returncode':p.returncode,'diagnostics':p.stderr}
        assert p.returncode==0,p.stderr
    start=time.monotonic()
    kinds=collections.Counter()
    for i,t in enumerate(CASES):
        tick=time.monotonic()
        p=subprocess.run([str(exe)],input=t['input'],capture_output=True,text=True,timeout=120)
        elapsed=time.monotonic()-tick
        assert p.returncode==0,(name,i,t.get('label'),p.returncode,p.stderr)
        assert p.stdout.split()==str(t['output']).split(),(name,i,t.get('label'),p.stdout[:100],str(t['output'])[:100])
        kinds[t['kind']]+=1
        if t['kind']=='stress':
            result['stress'].append({'label':t.get('label'),'seconds':elapsed,'input_sha256':hashlib.sha256(t['input'].encode()).hexdigest()})
    result['passed']=len(CASES)
    result['kinds']=dict(kinds)
    p=subprocess.run([str(BUILD/(name+'-unit'))],capture_output=True,text=True,timeout=120)
    assert p.returncode==0,(name,p.returncode,p.stderr)
    result['ntt_unit']=json.loads(p.stdout)
    result['unit_stderr']=p.stderr
    result['seconds']=time.monotonic()-start
    return name,result

if __name__=='__main__':
    before=hashlib.sha256(SRC.read_bytes()).hexdigest()
    with ThreadPoolExecutor(max_workers=2) as pool:
        results=dict(pool.map(lambda x:mode(*x),[
            ('o2',['-O2']),
            ('ubsan',['-O1','-fsanitize=undefined','-fno-sanitize-recover=all'])
        ]))
    assert hashlib.sha256(SRC.read_bytes()).hexdigest()==before
    report={
        'source_sha256':{'E':before},'source':'201809/E.cpp','compiler':COMPILER,
        'prior_report':'summary.json','cases':'cases.json','build_directory':str(BUILD),
        'results':results,'source_unchanged_during_tests':True,
        'ntt_capacity':1<<19,'required_max_transform':1<<19,
        'lazy_multiplication_bound':(18*998244353-1)*(998244353-1),
        'unsigned_64_max':(1<<64)-1,
        'notes':[
            '580 independent recurrence cases, 3 saved samples and 4 analytic maximum cases are replayed verbatim.',
            'Direct unit oracle uses the DFT definition, quadratic multiplication and quadratic formal inverse recurrence.',
            'Every power of two from 1 to 524288 is checked by roundtrip with six coefficient patterns.',
            'The input template capacity 1<<18 is enlarged to 1<<19 for this problem.',
            'The unrelated quadratic-residue code, factorials and original main are omitted.',
            'The original OJ record remains attributed to the original source; these are local tests.'
        ]
    }
    (DIR/'reports/e-ntt-report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(report,ensure_ascii=False,indent=2))
