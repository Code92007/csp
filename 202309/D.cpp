#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int N=1e5+10,M=4,K=8;
const int dx[K]={1,1,0,-1,-1,-1,0,1};
const int dy[K]={0,1,1,1,0,-1,-1,-1};
const int to[M]={0,2,1,7};
ll n,m;
int p,q;
struct entry{
    P k;
    int id;
    bool operator<(const entry &x)const{
        return k<x.k;
    }
};
typedef set<entry> S;
struct slot{
    ll x,y;
    int id;
    S::iterator at[M];
}a[N];
S g[M];
array<P,M> keys(ll x,ll y){
    return {P(y,x),P(x,y),P(x-y,x),P(x+y,x)};
}
int main(){
    scanf("%lld%lld%d%d",&n,&m,&p,&q);
    for(int i=1;i<=p;++i){
        scanf("%lld%lld",&a[i].x,&a[i].y);
        a[i].id=i;
        auto k=keys(a[i].x,a[i].y);
        for(int j=0;j<M;++j){
            a[i].at[j]=g[j].insert({k[j],i}).first;
        }
    }
    while(q--){
        ll u,v;
        int t;
        scanf("%lld%lld%d",&u,&v,&t);
        ll b=min({u-1,n-u,v-1,m-v});
        if(!b)continue;
        ll len=b+1,d[K];
        int near[K];
        memset(d,0,sizeof d);
        memset(near,0,sizeof near);
        auto k=keys(u,v);
        for(int j=0;j<M;++j){
            auto it=g[j].upper_bound({k[j],0});
            auto check=[&](S::iterator it,int dir){
                if(it->k.first!=k[j].first)return;
                ll dis=abs(it->k.second-k[j].second);
                near[dir]=it->id;
                d[dir]=dis;
                len=min(len,dis);
            };
            if(it!=g[j].end())check(it,to[j]);
            if(it!=g[j].begin()){
                auto pre=prev(it);
                if(pre->k==k[j]){
                    if(pre==g[j].begin())continue;
                    --pre;
                }
                check(pre,(to[j]+4)&7);
            }
        }
        if(len>b)continue;
        int old[K],nxt[K];
        memset(old,0,sizeof old);
        memset(nxt,0,sizeof nxt);
        for(int i=0;i<K;++i){
            if(near[i] && d[i]==len){
                old[i]=near[i];
                nxt[(i+t)&7]=a[near[i]].id;
            }
        }
        int src[M],dst[M],cnt=0,tot=0;
        for(int i=0;i<K;++i){
            if(old[i] && nxt[i])a[old[i]].id=nxt[i];
            else if(old[i])src[cnt++]=old[i];
            else if(nxt[i])dst[tot++]=i;
        }
        S::node_type h[M][M];
        for(int i=0;i<cnt;++i){
            for(int j=0;j<M;++j){
                h[i][j]=g[j].extract(a[src[i]].at[j]);
            }
        }
        for(int i=0;i<cnt;++i){
            int id=src[i],d=dst[i];
            a[id].x=u+len*dx[d];
            a[id].y=v+len*dy[d];
            a[id].id=nxt[d];
            auto k=keys(a[id].x,a[id].y);
            for(int j=0;j<M;++j){
                h[i][j].value().k=k[j];
                a[id].at[j]=g[j].insert(std::move(h[i][j])).position;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=p;++i){
        ans^=a[i].id*a[i].x+a[i].y;
    }
    printf("%lld\n",ans);
    return 0;
}
