#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll x,y;
    char c;
};
int n,m;
vector<node> p;
int main(){
    scanf("%d%d",&n,&m);
    p.resize(n);
    for(auto &v:p){
        scanf("%lld%lld %c",&v.x,&v.y,&v.c);
    }
    while(m--){
        ll a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        int last=0;
        bool ok=true;
        for(auto &v:p){
            ll val=a+b*v.x+c*v.y;
            int s=val>0?1:-1;
            if(v.c=='B')s=-s;
            if(!val || (last && last!=s))ok=false;
            last=s;
        }
        puts(ok?"Yes":"No");
    }
    return 0;
}
