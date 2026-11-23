#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int M=10;
struct order{
    int op,p;
    ll num;
    bool ok;
};
vector<order> a(1);
map<int,P> g;
char s[M];
ll buy,sell,ans=-1;
int price;
int main(){
    while(scanf("%s",s)==1){
        order e{0,0,0,true};
        if(s[0]=='c'){
            int x;
            scanf("%d",&x);
            a[x].ok=false;
            e.ok=false;
        }
        else{
            int x,y;
            scanf("%d.%d%lld",&x,&y,&e.num);
            e.op=s[0]=='b';
            e.p=x*100+y;
        }
        a.push_back(e);
    }
    for(auto &e:a){
        if(!e.ok || !e.num)continue;
        P &v=g[e.p];
        if(e.op){
            v.first+=e.num;
            buy+=e.num;
        }
        else v.second+=e.num;
    }
    for(auto &[p,v]:g){
        sell+=v.second;
        ll num=min(buy,sell);
        if(num>=ans){
            ans=num;
            price=p;
        }
        buy-=v.first;
    }
    ans=max(0ll,ans);
    printf("%d.%02d %lld\n",price/100,price%100,ans);
    return 0;
}
