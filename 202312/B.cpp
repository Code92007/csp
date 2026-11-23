#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int q,k;
ll n;
int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%lld%d",&n,&k);
        ll ans=1;
        for(ll p=2;p<=n/p;++p){
            int cnt=0;
            ll v=1;
            while(n%p==0){
                n/=p;
                v*=p;
                ++cnt;
            }
            if(cnt>=k)ans*=v;
        }
        if(n>1 && k<=1)ans*=n;
        printf("%lld\n",ans);
    }
    return 0;
}
