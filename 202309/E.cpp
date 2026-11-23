#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10,M=2;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n,m;
ll b[N];
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
struct LCT{
    struct node{
        int ch[M],fa;
        bool rev;
        ll w;
        multiset<ll>f,g;
        info v;
    }e[N];
    int st[N];
    bool isroot(int u){
        int p=e[u].fa;
        return e[p].ch[0]!=u && e[p].ch[1]!=u;
    }
    info local(int u){
        ll x=0,y=0;
        auto it=e[u].f.rbegin();
        if(it!=e[u].f.rend()){
            x=max(0ll,*it);
            ++it;
        }
        if(it!=e[u].f.rend())y=max(0ll,*it);
        ll w=e[u].w;
        ll ans=e[u].g.empty()?-INF:*e[u].g.rbegin();
        return {w,w+x,w+x,max(ans,w+x+y)};
    }
    void pushup(int u){
        e[u].v=merge(merge(e[e[u].ch[0]].v,local(u)),e[e[u].ch[1]].v);
    }
    void flip(int u){
        if(!u)return;
        swap(e[u].ch[0],e[u].ch[1]);
        swap(e[u].v.l,e[u].v.r);
        e[u].rev^=1;
    }
    void pushdown(int u){
        if(e[u].rev){
            flip(e[u].ch[0]);
            flip(e[u].ch[1]);
            e[u].rev=0;
        }
    }
    void rotate(int u){
        int p=e[u].fa,g=e[p].fa;
        int d=e[p].ch[1]==u,v=e[u].ch[d^1];
        if(!isroot(p))e[g].ch[e[g].ch[1]==p]=u;
        e[u].fa=g;
        e[u].ch[d^1]=p;
        e[p].fa=u;
        e[p].ch[d]=v;
        if(v)e[v].fa=p;
        pushup(p);
        pushup(u);
    }
    void splay(int u){
        int cnt=0,v=u;
        st[++cnt]=v;
        while(!isroot(v)){
            v=e[v].fa;
            st[++cnt]=v;
        }
        while(cnt){
            pushdown(st[cnt--]);
        }
        while(!isroot(u)){
            int p=e[u].fa,g=e[p].fa;
            if(!isroot(p)){
                bool same=((e[p].ch[1]==u)==(e[g].ch[1]==p));
                rotate(same?p:u);
            }
            rotate(u);
        }
    }
    void add(int u,int v){
        if(!v)return;
        e[u].f.insert(e[v].v.l);
        e[u].g.insert(e[v].v.ans);
    }
    void del(int u,int v){
        if(!v)return;
        e[u].f.erase(e[u].f.find(e[v].v.l));
        auto it=e[u].g.find(e[v].v.ans);
        e[u].g.erase(it);
    }
    void access(int u){
        int v=0,x=u;
        while(x){
            splay(x);
            add(x,e[x].ch[1]);
            del(x,v);
            e[x].ch[1]=v;
            pushup(x);
            v=x;
            x=e[x].fa;
        }
        splay(u);
    }
    void makeroot(int u){
        access(u);
        flip(u);
    }
    void link(int u,int v){
        makeroot(u);
        access(v);
        e[u].fa=v;
        add(v,u);
        pushup(v);
    }
    void update(int u,ll x){
        access(u);
        e[u].w=x;
        pushup(u);
    }
    ll query(int u){
        makeroot(1);
        access(u);
        return local(u).ans;
    }
}tr;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        tr.pushup(i);
    }
    for(int i=1;i<n;++i){
        int u,v;
        ll w;
        scanf("%d%d%lld%lld",&u,&v,&w,&b[i]);
        int p=n+i;
        tr.e[p].w=b[i]-w;
        tr.pushup(p);
        tr.link(u,p);
        tr.link(p,v);
    }
    printf("%lld\n",max(0ll,tr.query(1)));
    while(m--){
        int id;
        ll x;
        scanf("%d%lld",&id,&x);
        tr.update(n+id,b[id]-x);
        printf("%lld\n",max(0ll,tr.query(1)));
    }
    return 0;
}
