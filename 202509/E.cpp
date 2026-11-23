#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
const int N=5e5+10;
int n;
ll m,sum,a[N],b[N];
P operator+(P x,P y){
    return {x.first+y.first,x.second+y.second};
}
P operator-(P x){
    return {-x.first,-x.second};
}
pair<ll,ll> check(ll k){
    priority_queue<P,vector<P>,greater<P>> q;
    P dp={0,0};
    for(int i=1;i<=n;++i){
        q.push({a[i],0});
        P val={b[i]-k,-1};
        P cur=q.top()+val;
        if(cur<P{0,0}){
            dp=dp+cur;
            q.pop();
            q.push(-val);
        }
    }
    ll cnt=-dp.second;
    return {dp.first+k*cnt,cnt};
}
int main(){
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    for(int i=1;i<=n;++i){
        scanf("%lld",&b[i]);
        sum+=b[i];
    }
    if(sum<=m){
        printf("%d\n",n);
        return 0;
    }
    ll l=0,r=(ll)2e9+1;
    while(l+1<r){
        ll mid=(l+r)/2;
        P res=check(mid);
        if(res.first<=m)l=mid;
        else r=mid;
    }
    auto [cost,cnt]=check(l);
    printf("%lld\n",cnt+(m-cost)/r);
    return 0;
}
