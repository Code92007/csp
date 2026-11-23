#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n;
ll ans=INF;
vector<ll> a;
int main(){
    scanf("%d",&n);
    a.resize(n);
    for(ll &x:a){
        scanf("%lld",&x);
    }
    sort(a.begin(),a.end());
    for(int i=1;i<n;++i){
        ans=min(ans,a[i]-a[i-1]);
    }
    printf("%lld\n",ans);
    return 0;
}
