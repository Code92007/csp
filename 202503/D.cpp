#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
const int mod=998244353;
int n;
ll ans;
vector<P>g,h;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int x;
        scanf("%d",&x);
        h.clear();
        h.push_back(P(x,i));
        for(auto &[v,sum]:g){
            int d=gcd(v,x);
            P &w=h.back();
            if(w.first==d){
                w.second=(w.second+sum)%mod;
            }
            else h.push_back(P(d,sum));
        }
        g.swap(h);
        for(auto &[v,sum]:g){
            ans=(ans+sum*i%mod*v)%mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
