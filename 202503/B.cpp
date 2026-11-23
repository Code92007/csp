#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10010,M=110;
int n,m;
ll a[M],dp[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m && j<=i;++j){
            dp[i]=max(dp[i],dp[i-j]+a[j]);
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}
