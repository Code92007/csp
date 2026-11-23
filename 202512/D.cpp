#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10,M=5,K=3200,L=75;
const int mod=998244353;
typedef array<int,M> A;
int op,n,lim,cnt,mn[N];
ll ans;
vector<int>pr,f[M];
vector<A>g[K];
A calc(int p,int e){
    ll pw[L];
    pw[0]=1;
    for(int i=1;i<=3*e;++i){
        pw[i]=pw[i-1]*p%mod;
    }
    A res;
    res.fill(0);
    for(int x=-e;x<=e;++x){
        for(int y=-e;y<=e;++y){
            if(x+y>e)continue;
            int w=pw[e-x-y];
            res[0]=(res[0]+w)%mod;
            if(!x)res[1]=(res[1]+w)%mod;
            if(x==y)res[2]=(res[2]+w)%mod;
            if(x==-y)res[3]=(res[3]+w)%mod;
            if(y==-2*x)res[4]=(res[4]+w)%mod;
        }
    }
    return res;
}
int main(){
    scanf("%d%d",&op,&n);
    lim=sqrt(n);
    for(int i=2;i<=n;++i){
        if(!mn[i]){
            mn[i]=i;
            pr.push_back(i);
        }
        for(int &p:pr){
            if(p>mn[i] || 1ll*p*i>n)break;
            mn[i*p]=p;
        }
    }
    for(int &p:pr){
        if(p>lim)break;
        ll x=p;
        for(int e=1;x<=n;++e){
            g[p].push_back(calc(p,e));
            x*=p;
        }
    }
    cnt=op?M:1;
    for(int j=0;j<cnt;++j){
        f[j].resize(n+1);
        f[j][1]=1;
    }
    ans=op?0:1;
    for(int i=2;i<=n;++i){
        int p=mn[i],r=i,e=0;
        while(r%p==0){
            r/=p;
            ++e;
        }
        A v;
        if(p<=lim)v=g[p][e-1];
        else{
            ll p2=1ll*p*p%mod,p3=p2*p%mod;
            v[0]=(p3+2*p2+3ll*p+2)%mod;
            v[1]=(p2+p+1)%mod;
            v[2]=(p3+p)%mod;
            v[3]=3ll*p%mod;
            v[4]=p;
        }
        for(int j=0;j<cnt;++j){
            f[j][i]=1ll*f[j][r]*v[j]%mod;
        }
        ll val=f[0][i];
        if(op){
            val+=-2ll*f[1][i]-f[2][i]-f[3][i]-2ll*f[4][i]+5ll*i;
        }
        ans=(ans+val)%mod;
    }
    printf("%lld\n",(ans+mod)%mod);
    return 0;
}
