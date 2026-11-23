#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,M=2;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n,m,root=1;
struct info{
    ll sum=0,l=-INF,r=-INF,ans=-INF;
};
info merge(info a,info b){
    info c;
    c.sum=a.sum+b.sum;
    c.l=max(a.l,a.sum+b.l);
    c.r=max(b.r,b.sum+a.r);
    c.ans=max({a.ans,b.ans,a.r+b.l});
    return c;
}
struct LinkCutTree{
    bool rev[N];
    int fa[N],ch[N][M],st[N];
    ll val[N],sum[N];
    info mx[N];
    multiset<ll>g[N];
    #define ls(x) (ch[x][0])
    #define rs(x) (ch[x][1])
    #define dir(x) (rs(fa[x])==(x))
    #define isRoot(x) (ls(fa[x])!=(x) && rs(fa[x])!=(x))
    info local(int x){
        ll w=val[x]+sum[x];
        ll best=g[x].empty()?-INF:*g[x].rbegin();
        return {w,w,w,max(w,best)};
    }
    void pushup(int x){
        mx[x]=merge(merge(mx[ls(x)],local(x)),mx[rs(x)]);
    }
    void flip(int x){
        if(!x)return;
        swap(ls(x),rs(x));
        swap(mx[x].l,mx[x].r);
        rev[x]^=1;
    }
    void pushdown(int x){
        if(!rev[x])return;
        flip(ls(x));flip(rs(x));
        rev[x]=0;
    }
    void update(int x){
        int cnt=0,y=x;
        st[++cnt]=y;
        while(!isRoot(y)){
            y=fa[y];
            st[++cnt]=y;
        }
        while(cnt){
            pushdown(st[cnt--]);
        }
    }
    void rotate(int x){
        int y=fa[x],z=fa[y],d=dir(x);
        int w=ch[x][d^1];
        if(!isRoot(y))ch[z][dir(y)]=x;
        fa[x]=z;
        ch[x][d^1]=y;fa[y]=x;
        ch[y][d]=w;
        if(w)fa[w]=y;
        pushup(y);pushup(x);
    }
    void splay(int x){
        update(x);
        while(!isRoot(x)){
            int y=fa[x];
            if(!isRoot(y))rotate(dir(x)==dir(y)?y:x);
            rotate(x);
        }
    }
    void add(int x,int y){
        if(!y)return;
        sum[x]+=max(0ll,mx[y].l);
        g[x].insert(mx[y].ans);
    }
    void del(int x,int y){
        if(!y)return;
        sum[x]-=max(0ll,mx[y].l);
        auto it=g[x].find(mx[y].ans);
        g[x].erase(it);
    }
    void access(int x){
        int y=0,u=x;
        while(u){
            splay(u);
            add(u,rs(u));
            del(u,y);
            rs(u)=y;
            pushup(u);
            y=u;u=fa[u];
        }
        splay(x);
    }
    void makeroot(int x){
        access(x);
        flip(x);
    }
    int findroot(int x){
        access(x);
        pushdown(x);
        while(ls(x)){
            x=ls(x);
            pushdown(x);
        }
        splay(x);
        return x;
    }
    void split(int x,int y){
        makeroot(x);
        access(y);
    }
    void link(int x,int y){
        makeroot(x);
        if(findroot(y)==x)return;
        access(y);
        fa[x]=y;
        add(y,x);
        pushup(y);
    }
    void cut(int x,int y){
        split(x,y);
        if(ls(y)==x && !rs(x)){
            ls(y)=0;fa[x]=0;
            pushup(y);
        }
    }
    void setval(int x,ll w){
        access(x);
        val[x]=w;
        pushup(x);
    }
    ll best(int x){
        makeroot(x);
        access(x);
        return local(x).l;
    }
    ll query(int x){
        makeroot(root);
        access(x);
        return local(x).ans;
    }
}tr;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&tr.val[i]);
        tr.pushup(i);
    }
    for(int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        tr.link(u,v);
    }
    printf("%lld\n",tr.best(root));
    while(m--){
        int op,u;
        scanf("%d%d",&op,&u);
        if(op==1){
            printf("%lld\n",tr.query(u));
            continue;
        }
        if(op==2){
            ll x;
            scanf("%lld",&x);
            tr.setval(u,x);
        }
        if(op==3)root=u;
        if(op==4){
            int v,c,d;
            scanf("%d%d%d",&v,&c,&d);
            tr.cut(u,v);
            tr.link(c,d);
        }
        printf("%lld\n",tr.best(root));
    }
    return 0;
}
