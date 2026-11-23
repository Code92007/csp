#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=20,K=N*22;
int n,m,a[N],rt[N],dep[N],fa[N][M];
vector<int> g[N],ord;
struct segtree{
    struct node{
        int l,r,ls,rs,cnt;
    }e[K];
    #define l(p) e[p].l
    #define r(p) e[p].r
    int tot;
    int build(int x,int y){
        int p=++tot;
        l(p)=x;r(p)=y;
        if(x==y)return p;
        int mid=(x+y)/2;
        e[p].ls=build(x,mid);
        e[p].rs=build(mid+1,y);
        return p;
    }
    int update(int old,int x){
        int p=++tot;
        e[p]=e[old];
        ++e[p].cnt;
        if(l(p)==r(p))return p;
        int mid=(l(p)+r(p))/2;
        if(x<=mid)e[p].ls=update(e[old].ls,x);
        else e[p].rs=update(e[old].rs,x);
        return p;
    }
    int query(int x,int y,int z,int w){
        while(l(x)<r(x)){
            int mid=(l(x)+r(x))/2;
            int u=e[x].ls,v=e[y].ls;
            int s=e[z].ls,t=e[w].ls;
            int cnt=e[u].cnt+e[v].cnt-e[s].cnt-e[t].cnt;
            if(cnt==mid-l(x)+1){
                x=e[x].rs,y=e[y].rs;
                z=e[z].rs,w=e[w].rs;
            }
            else{
                x=u,y=v,z=s,w=t;
            }
        }
        return l(x);
    }
}tr;
int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    int d=dep[u]-dep[v];
    for(int i=0;i<M;++i){
        if(d>>i&1)u=fa[u][i];
    }
    if(u==v)return u;
    for(int i=M-1;i>=0;--i){
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i];
            v=fa[v][i];
        }
    }
    return fa[u][0];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rt[0]=tr.build(0,n);
    ord.push_back(1);
    for(int i=0;i<(int)ord.size();++i){
        int u=ord[i];
        rt[u]=tr.update(rt[fa[u][0]],a[u]);
        for(int j=1;j<M;++j){
            fa[u][j]=fa[fa[u][j-1]][j-1];
        }
        for(int &v:g[u]){
            if(v==fa[u][0])continue;
            fa[v][0]=u;
            dep[v]=dep[u]+1;
            ord.push_back(v);
        }
    }
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        int w=lca(u,v);
        int ans=tr.query(rt[u],rt[v],rt[w],rt[fa[w][0]]);
        printf("%d\n",ans);
    }
    return 0;
}
