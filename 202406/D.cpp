#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=40010,INF=0x3f3f3f3f;
int n,m,v,b[N],c[N],dp[M],ndp[M];
vector<int>g[N];
int main(){
    scanf("%d%d%d",&n,&m,&v);
    for(int i=0;i<n;++i){
        scanf("%d%d",&b[i],&c[i]);
    }
    for(int i=0;i<m;++i){
        int x,t;
        scanf("%d%d",&x,&t);
        g[t].push_back(x);
    }
    fill(dp,dp+M,-INF);
    dp[0]=0;
    int bound=0;
    for(int i=0;i<n;++i){
        if(g[i].empty())continue;
        sort(g[i].begin(),g[i].end(),greater<int>());
        memcpy(ndp,dp,sizeof dp);
        int sum=0;
        for(int j=1;j<=(int)g[i].size();++j){
            sum+=g[i][j-1];
            int cost=b[i]+j*c[i];
            for(int k=0;k<=bound;++k){
                if(dp[k]==-INF)continue;
                ndp[k+cost]=max(ndp[k+cost],dp[k]+sum-cost);
            }
        }
        bound+=b[i]+c[i]*g[i].size();
        memcpy(dp,ndp,sizeof dp);
    }
    for(int i=0;i<=bound;++i){
        if(dp[i]>=v){
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}
