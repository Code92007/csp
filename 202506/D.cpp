#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=10;
typedef array<int,N> A;
typedef array<A,N> Mat;
const int M=4,K=30,H=1e5;
const int mod=998244353;
int n,m;
ll u=1,w,z;
Mat tr,pw[K];
A a,b;
vector<int>g;
vector<array<int,M>>dp;
unordered_map<int,array<int,M>>mp;
A mul(const A &x,const Mat &y){
    A res;
    for(int j=0;j<N;++j){
        ull sum=0;
        for(int k=0;k<N;++k){
            sum+=(ull)x[k]*y[k][j];
        }
        res[j]=sum%mod;
    }
    return res;
}
int step(int s,char c){
    if(s==9)return 9;
    string p=s<3?"ccf":"cspark";
    int off=s<3?0:3;
    string t=p.substr(0,s-off)+c;
    for(int len=(int)p.size();len>=0;--len){
        if(t.size()>=(size_t)len &&
           t.compare(t.size()-len,len,p,0,len)==0){
            return off+len;
        }
    }
    return off;
}
array<int,M> f(const A &x,const A &y){
    array<int,M>res;
    res.fill(0);
    for(int s=0;s<N;++s){
        if(s<3)res[0]=(res[0]+x[s])%mod;
        if(s>=3 && s<9)res[1]=(res[1]+x[s])%mod;
        if(s<9)res[2]=(res[2]+y[s])%mod;
        res[3]=(res[3]+x[s])%mod;
    }
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    int pre=0;
    for(int i=0;i<m;++i){
        int x;
        scanf("%d",&x);
        g.push_back(x-pre-1);
        pre=x;
    }
    g.push_back(n-pre);
    for(int s=0;s<N;++s){
        for(char c='a';c<='z';++c){
            ++tr[s][step(s,c)];
        }
    }
    pw[0]=tr;
    for(int i=1;i<K;++i){
        for(int j=0;j<N;++j){
            pw[i][j]=mul(pw[i-1][j],pw[i-1]);
        }
    }
    dp.resize(min(n,H)+1);
    a[0]=b[3]=1;
    for(int i=0;i<(int)dp.size();++i){
        dp[i]=f(a,b);
        a=mul(a,tr);b=mul(b,tr);
    }
    for(int &len:g){
        array<int,M>v;
        if(len<(int)dp.size())v=dp[len];
        else if(mp.count(len))v=mp[len];
        else{
            a.fill(0);b.fill(0);
            a[0]=b[3]=1;
            for(int i=0;i<K;++i){
                if(len>>i&1){
                    a=mul(a,pw[i]);b=mul(b,pw[i]);
                }
            }
            v=mp[len]=f(a,b);
        }
        auto [x,y,c,t]=v;
        ll cur=(t-x-y+2ll*mod)%mod;
        z=(z*t+w*(t-c+mod)+u*cur)%mod;
        w=(w*c+u*y)%mod;
        u=u*x%mod;
    }
    printf("%lld\n",z);
    return 0;
}
