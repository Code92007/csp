#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const int M=1005;
int n,m;
ll sum,dp[M];
ld g[M];
bool cmp(P x,P y){
    return 1ll*x.second*y.first>1ll*y.second*x.first;
}
int main(){
    scanf("%d%d",&n,&m);
    vector<P>a;
    for(int i=1;i<=n;++i){
        int op,t,x,y;
        scanf("%d%d%d%d",&op,&t,&x,&y);
        sum+=t;
        if(!op){
            a.push_back(P(x,y));
        }
        else{
            for(int j=m;j>=x;--j){
                dp[j]=max(dp[j],dp[j-x]+y);
            }
        }
    }
    sort(a.begin(),a.end(),cmp);
    int used=0;
    for(P &x:a){
        for(int j=0;j<x.first && used<m;++j){
            g[used+1]=g[used]+(ld)x.second/x.first;
            ++used;
        }
    }
    while(used<m){
        g[used+1]=g[used];
        ++used;
    }
    ld ans=0;
    for(int j=0;j<=m;++j){
        ans=max(ans,dp[j]+g[m-j]);
    }
    printf("%.8Lf\n",sum-ans);
    return 0;
}
