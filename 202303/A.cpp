#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a,b,ans,x,y,u,v;
int main(){
    scanf("%d%lld%lld",&n,&a,&b);
    while(n--){
        scanf("%lld%lld%lld%lld",&x,&y,&u,&v);
        ll w=max(0ll,min(a,u)-max(0ll,x));
        ll h=max(0ll,min(b,v)-max(0ll,y));
        ans+=w*h;
    }
    printf("%lld\n",ans);
    return 0;
}
