#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> poly;
const int mod=998244353;
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
void ntt(poly &a,bool op){
    static poly w{0,1},iw{0,1};
    int n=a.size();
    while((int)w.size()<n){
        int h=w.size();
        w.resize(h*2);iw.resize(h*2);
        int x=qpow(3,(mod-1)/(h*2)),y=qpow(x,mod-2);
        w[h]=iw[h]=1;
        for(int j=1;j<h;++j){
            w[h+j]=(ll)w[h+j-1]*x%mod;
            iw[h+j]=(ll)iw[h+j-1]*y%mod;
        }
    }
    if(!op){
        for(int h=n/2;h;h>>=1){
            for(int p=0;p<n;p+=h*2){
                for(int j=0;j<h;++j){
                    int u=a[p+j],v=a[p+j+h];
                    int x=u+v,y=u-v;
                    if(x>=mod)x-=mod;
                    if(y<0)y+=mod;
                    a[p+j]=x;
                    a[p+j+h]=(ll)y*w[h+j]%mod;
                }
            }
        }
    }
    else{
        for(int h=1;h<n;h<<=1){
            for(int p=0;p<n;p+=h*2){
                for(int j=0;j<h;++j){
                    int u=a[p+j],v=(ll)a[p+j+h]*iw[h+j]%mod;
                    int x=u+v,y=u-v;
                    if(x>=mod)x-=mod;
                    if(y<0)y+=mod;
                    a[p+j]=x,a[p+j+h]=y;
                }
            }
        }
        int v=qpow(n,mod-2);
        for(int &x:a){
            x=(ll)x*v%mod;
        }
    }
}
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
    ntt(a,0);ntt(b,0);
    for(int i=0;i<n;++i){
        a[i]=(ll)a[i]*b[i]%mod;
    }
    ntt(a,1);
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
        ntt(f,0);ntt(g,0);
        for(int i=0;i<n;++i){
            g[i]=(ll)g[i]*f[i]%mod;
        }
        ntt(g,1);
        fill(g.begin(),g.begin()+h,0);
        ntt(g,0);
        for(int i=0;i<n;++i){
            g[i]=(ll)g[i]*f[i]%mod;
        }
        ntt(g,1);
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
            ntt(v,0);
            for(int &x:v){
                x=(ll)x*x%mod;
            }
            ntt(v,1);
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
                ntt(f,0);ntt(g,0);
            }
            q.resize(n);
            ntt(q,0);
            for(int i=0;i<n;++i){
                q[i]=(ll)q[i]*g[i]%mod;
            }
            ntt(q,1);
            q.resize(k);
            reverse(q.begin(),q.end());
            q.resize(n);
            ntt(q,0);
            for(int i=0;i<n;++i){
                q[i]=(ll)q[i]*f[i]%mod;
            }
            ntt(q,1);
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
