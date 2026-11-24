#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t i128;
const int N=1e5+10,M=N*18;
const ll mod=1e18;
const i128 INF=(i128)1<<120;
int t,n,k,fa[N],rt[N],head[N],tail[N],nxt[N],sz[N];
ll dep[N],val[N],f[N],xs[N];
i128 dp[N];
i128 calc(int i,ll x){
    return (i128)2*dep[i]*x+dp[i]-(i128)dep[i]*dep[i];
}
struct segtree{
    int tot;
    struct node{
        int l,r,id,ls,rs;
    }e[M];
    #define l(p) e[p].l
    #define r(p) e[p].r
    int make(int x,int y,int id){
        e[++tot]={x,y,id,0,0};
        return tot;
    }
    int update(int p,int id){
        int mid=(l(p)+r(p))/2;
        if(calc(id,xs[mid])>calc(e[p].id,xs[mid])){
            swap(id,e[p].id);
        }
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
        return p?update(p,id):make(0,k-1,id);
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
        memset(rt,0,sizeof rt);
        memset(head,0,sizeof head);
        memset(tail,0,sizeof tail);
        memset(nxt,0,sizeof nxt);
        memset(sz,0,sizeof sz);
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;++i){
            ll len;
            scanf("%d%lld%lld%lld",&fa[i],&len,&val[i],&f[i]);
            dep[i]=dep[fa[i]]+len;
            xs[i-1]=dep[i]+f[i];
        }
        sort(xs,xs+n);
        k=unique(xs,xs+n)-xs;
        tr.tot=0;
        ll ans=0;
        for(int u=n;u>=1;--u){
            ll x=dep[u]+f[u];
            if(rt[u]){
                dp[u]=max((i128)0,tr.query(rt[u],x)-(i128)x*x+val[u]);
            }
            ans=(ans+(ll)(dp[u]%mod))%mod;
            rt[u]=tr.insert(rt[u],u);
            if(head[u])nxt[tail[u]]=u;
            else head[u]=u;
            tail[u]=u;
            ++sz[u];
            int p=fa[u];
            if(!p)continue;
            if(sz[p]<sz[u]){
                swap(head[p],head[u]);
                swap(tail[p],tail[u]);
                swap(sz[p],sz[u]);
                swap(rt[p],rt[u]);
            }
            for(int id=head[u];id;id=nxt[id]){
                rt[p]=tr.insert(rt[p],id);
            }
            if(head[u]){
                nxt[tail[p]]=head[u];
                tail[p]=tail[u];
            }
            sz[p]+=sz[u];
            head[u]=tail[u]=sz[u]=rt[u]=0;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
