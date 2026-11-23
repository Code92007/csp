#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t i128;
const ll mod=1e18;
const i128 INF=(i128)1<<120;
int t,n;
vector<int> fa,rt;
vector<ll> dep,val,f,xs;
vector<i128> dp;
vector<vector<int>> g;
i128 calc(int i,ll x){
    return (i128)2*dep[i]*x+dp[i]-(i128)dep[i]*dep[i];
}
struct segtree{
    struct node{
        int l,r,id,ls,rs;
    };
    vector<node> e;
    #define l(p) e[p].l
    #define r(p) e[p].r
    int make(int x,int y,int id){
        e.push_back({x,y,id,0,0});
        return e.size()-1;
    }
    int update(int p,int id){
        int mid=(l(p)+r(p))/2;
        if(calc(id,xs[mid])>calc(e[p].id,xs[mid]))swap(id,e[p].id);
        if(l(p)==r(p))return p;
        if(calc(id,xs[l(p)])>calc(e[p].id,xs[l(p)])){
            int u=e[p].ls;
            if(!u)u=make(l(p),mid,id);
            else u=update(u,id);
            e[p].ls=u;
        }
        else if(calc(id,xs[r(p)])>calc(e[p].id,xs[r(p)])){
            int u=e[p].rs;
            if(!u)u=make(mid+1,r(p),id);
            else u=update(u,id);
            e[p].rs=u;
        }
        return p;
    }
    int insert(int p,int id){
        return p?update(p,id):make(0,xs.size()-1,id);
    }
    i128 query(int p,ll x){
        i128 ans=-INF;
        while(p){
            ans=max(ans,calc(e[p].id,x));
            int mid=(l(p)+r(p))/2;
            p=x<=xs[mid]?e[p].ls:e[p].rs;
        }
        return ans;
    }
}tr;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        fa.assign(n+1,0);
        rt.assign(n+1,0);
        dep.assign(n+1,0);
        val.assign(n+1,0);
        f.assign(n+1,0);
        dp.assign(n+1,0);
        g.assign(n+1,vector<int>());
        xs.clear();
        for(int i=1;i<=n;++i){
            ll len;
            scanf("%d%lld%lld%lld",&fa[i],&len,&val[i],&f[i]);
            dep[i]=dep[fa[i]]+len;
            xs.push_back(dep[i]+f[i]);
        }
        sort(xs.begin(),xs.end());
        xs.erase(unique(xs.begin(),xs.end()),xs.end());
        tr.e.clear();
        tr.e.push_back({0,0,0,0,0});
        ll ans=0;
        for(int u=n;u>=1;--u){
            ll x=dep[u]+f[u];
            if(rt[u])dp[u]=max((i128)0,tr.query(rt[u],x)-(i128)x*x+val[u]);
            ans=(ans+(ll)(dp[u]%mod))%mod;
            rt[u]=tr.insert(rt[u],u);
            g[u].push_back(u);
            int p=fa[u];
            if(!p)continue;
            if(g[p].size()<g[u].size()){
                swap(g[p],g[u]);
                swap(rt[p],rt[u]);
            }
            for(int &id:g[u]){
                rt[p]=tr.insert(rt[p],id);
                g[p].push_back(id);
            }
            vector<int>().swap(g[u]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
