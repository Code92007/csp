#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=16,mod=1e9+7;
int n,x,dp[M],nd[M],ans[N];
vector<int> a;
int main(){
    while(scanf("%d",&x)==1){
        a.push_back(x);
    }
    if(a.empty())return 0;
    int l=a.size()>1;
    n=*max_element(a.begin()+l,a.end());
    dp[0]=1;
    for(int len=0;len<n;++len){
        memset(nd,0,sizeof nd);
        for(int S=0;S<16;++S){
            for(int d=0;d<4;++d){
                if(!len && !d)continue;
                if(!d && (S&2))continue;
                if(d==1 && !(S&1))continue;
                if(d==2 && (S&8))continue;
                if(d==3 && !(S&4))continue;
                int to=S|(1<<d);
                nd[to]=(nd[to]+dp[S])%mod;
            }
        }
        memcpy(dp,nd,sizeof dp);
        ans[len+1]=dp[15];
    }
    for(int i=l;i<(int)a.size();++i){
        printf("%d\n",ans[a[i]]);
    }
    return 0;
}
