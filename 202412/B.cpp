#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n;
ll a[N],b[N],c[N],pre[N],suf[N],sum;
int main(){
    scanf("%d",&n);
    for(int i=0;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;++i){
        scanf("%lld",&b[i]);
    }
    for(int i=0;i<=n;++i){
        sum+=a[i]-b[i];
        c[i]=sum;
        pre[i]=i?max(pre[i-1],c[i]):c[i];
    }
    suf[n+1]=-INF;
    for(int i=n;i>=0;--i){
        suf[i]=max(suf[i+1],c[i]);
    }
    for(int i=1;i<=n;++i){
        printf("%lld%c",max(pre[i-1],suf[i]+b[i]),i==n?'\n':' ');
    }
    return 0;
}
