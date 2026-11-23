#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
int n,a,b;
vector<P> u,v;
int main(){
    scanf("%d%d%d",&n,&a,&b);
    u.resize(a);
    v.resize(b);
    for(auto &[i,x]:u){
        scanf("%d%lld",&i,&x);
    }
    for(auto &[i,x]:v){
        scanf("%d%lld",&i,&x);
    }
    int i=0,j=0;
    ll ans=0;
    while(i<a && j<b){
        if(u[i].first<v[j].first)++i;
        else if(u[i].first>v[j].first)++j;
        else{
            ans+=u[i].second*v[j].second;
            ++i;++j;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
