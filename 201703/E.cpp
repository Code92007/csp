#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,h;
ll a,b,q,x;
vector<int> v,w;
vector<ll> dp;
int gen(){
    x=(a*x+b)%q;
    return x;
}
int main(){
    scanf("%d%d%lld%lld%lld%lld",&n,&m,&a,&b,&q,&x);
    h=n-1;
    v.resize(h*m);
    w.resize((h-1)*(m-1));
    for(int i=0;i<h;++i){
        for(int j=0;j<m;++j){
            v[j*h+i]=gen();
        }
    }
    for(int i=0;i<h-1;++i){
        for(int j=0;j<m-1;++j){
            w[j*(h-1)+i]=gen();
        }
    }
    dp.resize(h);
    for(int i=0;i<h;++i){
        dp[i]=v[i];
    }
    for(int j=1;j<m;++j){
        int off=(j-1)*(h-1);
        for(int i=1;i<h;++i){
            dp[i]=min(dp[i],dp[i-1]+w[off+i-1]);
        }
        for(int i=h-2;i>=0;--i){
            dp[i]=min(dp[i],dp[i+1]+w[off+i]);
        }
        for(int i=0;i<h;++i){
            dp[i]+=v[j*h+i];
        }
    }
    printf("%lld\n",*min_element(dp.begin(),dp.end()));
    return 0;
}
