#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> poly;
const int N=1<<19,mod=998244353;
int m,d;
ll l,r;
int qpow(int a,ll n){
    int res=1;
    for(;n;n>>=1,a=(ll)a*a%mod){
        if(n&1)res=(ll)res*a%mod;
    }
    return res;
}
int size(int x){
    int n=1;
    while(n<x){
        n<<=1;
    }
    return n;
}
namespace Poly{
    int w[N];
    ull F[N];
    void Init(){
        for(int i=1;i<N;i<<=1){
            w[i]=1;
            int t=qpow(3,(mod-1)/i/2);
            for(int j=1;j<i;++j){
                w[i+j]=(ll)w[i+j-1]*t%mod;
            }
        }
    }
    int Mod(int x){
        return x<mod?x:x-mod;
    }
    void DFT(poly &f,int n){
        f.resize(n);
        for(int i=0,j=0;i<n;++i){
            F[i]=f[j];
            for(int k=n>>1;(j^=k)<k;k>>=1){
            }
        }
        if(n<=4){
            for(int i=1;i<n;i<<=1){
                for(int j=0;j<n;j+=i<<1){
                    for(int k=0;k<i;++k){
                        ull t=F[j+k+i]*w[i+k]%mod;
                        F[j+k+i]=F[j+k]+mod-t;
                        F[j+k]+=t;
                    }
                }
            }
        }
        else{
            for(int j=0;j<n;j+=2){
                int t=F[j+1];
                F[j+1]=Mod(F[j]+mod-t);
                F[j]=Mod(F[j]+t);
            }
            for(int j=0;j<n;j+=4){
                int x=F[j+2],y=F[j+3]*w[3]%mod;
                F[j+2]=F[j]+mod-x;F[j]+=x;
                F[j+3]=F[j+1]+mod-y;F[j+1]+=y;
            }
            for(int i=4;i<n;i<<=1){
                for(int j=0;j<n;j+=i<<1){
                    int *W=w+i;
                    ull *a=F+j,*b=F+j+i;
                    for(int k=0;k<i;k+=4,W+=4,a+=4,b+=4){
                        int t0=(ull)W[0]*b[0]%mod;
                        int t1=(ull)W[1]*b[1]%mod;
                        int t2=(ull)W[2]*b[2]%mod;
                        int t3=(ull)W[3]*b[3]%mod;
                        b[0]=a[0]+mod-t0;a[0]+=t0;
                        b[1]=a[1]+mod-t1;a[1]+=t1;
                        b[2]=a[2]+mod-t2;a[2]+=t2;
                        b[3]=a[3]+mod-t3;a[3]+=t3;
                    }
                }
            }
        }
        for(int i=0;i<n;++i){
            f[i]=F[i]%mod;
        }
    }
    void IDFT(poly &f,int n){
        f.resize(n);
        reverse(f.begin()+1,f.end());
        DFT(f,n);
        int v=qpow(n,mod-2);
        for(int &x:f){
            x=(ll)x*v%mod;
        }
    }
}
using namespace Poly;
poly mul(poly a,poly b){
    if(a.empty() || b.empty())return {};
    int len=a.size()+b.size()-1;
    if(min(a.size(),b.size())<=32){
        poly c(len);
        for(int i=0;i<(int)a.size();++i){
            for(int j=0;j<(int)b.size();++j){
                c[i+j]=(c[i+j]+(ll)a[i]*b[j])%mod;
            }
        }
        return c;
    }
    int n=size(len);
    a.resize(n);b.resize(n);
    DFT(a,a.size());DFT(b,b.size());
    for(int i=0;i<n;++i){
        a[i]=(ll)a[i]*b[i]%mod;
    }
    IDFT(a,a.size());
    a.resize(len);
    return a;
}
poly inv(const poly &a,int len){
    poly b{qpow(a[0],mod-2)};
    while((int)b.size()<len){
        int h=b.size(),n=h*2;
        poly f=b,g(n);
        f.resize(n);
        copy_n(a.begin(),min(n,(int)a.size()),g.begin());
        DFT(f,f.size());DFT(g,g.size());
        for(int i=0;i<n;++i){
            g[i]=(ll)g[i]*f[i]%mod;
        }
        IDFT(g,g.size());
        fill(g.begin(),g.begin()+h,0);
        DFT(g,g.size());
        for(int i=0;i<n;++i){
            g[i]=(ll)g[i]*f[i]%mod;
        }
        IDFT(g,g.size());
        b.resize(n);
        for(int i=h;i<n;++i){
            b[i]=g[i]?mod-g[i]:0;
        }
    }
    b.resize(len);
    return b;
}
struct rem{
    int m,n;
    poly c,b,f,g;
    rem(const poly &a):m(a.size()-1),n(size(m*2-1)),
        c(a.rbegin(),a.rend()),b(inv(a,m)){}
    poly square(const poly &a){
        int len=a.size()*2-1;
        poly v;
        if(a.size()<=32)v=mul(a,a);
        else{
            v=a;
            v.resize(size(len));
            DFT(v,v.size());
            for(int &x:v){
                x=(ll)x*x%mod;
            }
            IDFT(v,v.size());
            v.resize(len);
        }
        if(len<=m)return v;
        int k=len-m;
        poly q(v.rbegin(),v.rbegin()+k);
        if(k<m-1 || m<=32){
            poly t(b.begin(),b.begin()+k);
            q=mul(q,t);
            q.resize(k);
            reverse(q.begin(),q.end());
            t=mul(q,c);
            v.resize(m);
            for(int i=0;i<m;++i){
                v[i]-=t[i];
                if(v[i]<0)v[i]+=mod;
            }
        }
        else{
            if(f.empty()){
                f=c;g=b;
                f.resize(n);g.resize(n);
                DFT(f,f.size());DFT(g,g.size());
            }
            q.resize(n);
            DFT(q,q.size());
            for(int i=0;i<n;++i){
                q[i]=(ll)q[i]*g[i]%mod;
            }
            IDFT(q,q.size());
            q.resize(k);
            reverse(q.begin(),q.end());
            q.resize(n);
            DFT(q,q.size());
            for(int i=0;i<n;++i){
                q[i]=(ll)q[i]*f[i]%mod;
            }
            IDFT(q,q.size());
            v.resize(m);
            for(int i=0;i<m;++i){
                v[i]-=q[i];
                if(v[i]<0)v[i]+=mod;
            }
        }
        return v;
    }
    void shift(poly &a){
        if((int)a.size()<m){
            a.insert(a.begin(),0);
            return;
        }
        int t=a.back();
        for(int i=m-1;i>=0;--i){
            int v=i?a[i-1]:0;
            v=(v-(ll)t*c[i])%mod;
            if(v<0)v+=mod;
            a[i]=v;
        }
    }
};
int main(){
    Init();
    scanf("%d%lld%lld",&m,&l,&r);
    d=r-l+1;
    poly c(m+1);
    c[0]=1;
    for(int i=1,k;i<=m;++i){
        scanf("%d",&k);
        c[i]=k?mod-k:0;
    }
    if(m==1){
        int k=c[1]?mod-c[1]:0,a=qpow(k,l);
        for(int i=0;i<d;++i){
            printf("%d\n",a);
            a=(ll)a*k%mod;
        }
        return 0;
    }
    poly a{1};
    if(l){
        rem tr(c);
        int h=0;
        while((1ll<<(h+1))<=l){
            ++h;
        }
        for(int i=h;i>=0;--i){
            a=tr.square(a);
            if((l>>i)&1)tr.shift(a);
        }
    }
    int len=a.size();
    poly b=inv(c,len+d-1);
    reverse(a.begin(),a.end());
    poly ans=mul(a,b);
    for(int i=0;i<d;++i){
        printf("%d\n",ans[len-1+i]);
    }
    return 0;
}
