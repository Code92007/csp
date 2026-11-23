#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105,M=10005;
const int INF=0x3f3f3f3f;
int n,m,q,sum,mu[N],dp[M];
int main(){
    int a,b;
    scanf("%d%d%d.%d",&n,&m,&a,&b);
    q=a*1000+b;
    for(int i=1;i<=n;++i){
        scanf("%d",&mu[i]);
    }
    memset(dp,INF,sizeof dp);
    dp[0]=0;
    for(int i=1;i<=n;++i){
        scanf("%d.%d",&a,&b);
        int w=a*10+b,v=w*w;
        sum+=mu[i];
        for(int j=sum;j>=mu[i];--j){
            dp[j]=min(dp[j],dp[j-mu[i]]+v);
        }
    }
    ll lim=100000000ll*m*m;
    for(int i=sum;i>=0;--i){
        if(1ll*dp[i]*q*q<=lim){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
