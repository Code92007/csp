#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1010,M=1e5+10,mod=1e9+7;
int n,a[N],ed[M];
ll dp[N];
vector<int>d[M];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    int m=a[n]-a[1];
    for(int i=1;i<=m;++i){
        for(int j=i;j<=m;j+=i){
            d[j].push_back(i);
        }
    }
    memset(ed,-1,sizeof ed);
    dp[1]=1;
    for(int l=1;l<n;++l){
        for(int r=l+1;r<=n;++r){
            int x=a[r]-a[l],cnt=0;
            for(int &v:d[x]){
                cnt+=(v<x && ed[v]!=l);
            }
            dp[r]=(dp[r]+dp[l]*cnt)%mod;
            for(int &v:d[x]){
                ed[v]=l;
            }
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}
