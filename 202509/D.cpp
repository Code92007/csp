#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=2e5+10,M=3,INF=0x3f3f3f3f;
int n,m,z,a[N],fa[N],bel[N],ord[N],sub[N];
int mn[N],sn[N],id[N],out[N],b[N];
vector<int>g[N];
P best[M];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        sub[i]=a[i];
        if(!a[i])z=i;
    }
    for(int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);g[v].push_back(u);
    }
    int cnt=1;
    ord[1]=z;
    for(int i=1;i<=cnt;++i){
        int u=ord[i];
        for(int &v:g[u]){
            if(v==fa[u])continue;
            fa[v]=u;
            bel[v]=u==z?v:bel[u];
            ord[++cnt]=v;
        }
    }
    memset(mn,INF,sizeof mn);
    memset(sn,INF,sizeof sn);
    for(int i=n;i;--i){
        int u=ord[i],p=fa[u];
        if(!p)continue;
        sub[p]=min(sub[p],sub[u]);
        if(sub[u]<mn[p]){
            sn[p]=mn[p];mn[p]=sub[u];
            id[p]=u;
        }
        else sn[p]=min(sn[p],sub[u]);
    }
    fill(best,best+M,P(INF,0));
    for(int &v:g[z]){
        P p=P(sub[v],v);
        for(P &q:best){
            if(p<q)swap(p,q);
        }
    }
    out[z]=INF;
    for(int i=1;i<=n;++i){
        int u=ord[i];
        b[u]=u==z?INF:min(out[u],mn[u]);
        for(int &v:g[u]){
            if(v==fa[u])continue;
            if(u==z)out[v]=INF;
            else out[v]=min(out[u],id[u]==v?sn[u]:mn[u]);
        }
    }
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        if(bel[u] && bel[u]==bel[v]){
            puts("0");
            continue;
        }
        int ans=min(b[u],b[v]);
        for(P &p:best){
            if(p.second!=bel[u] && p.second!=bel[v]){
                ans=min(ans,p.first);
            }
        }
        printf("%d\n",ans==INF?n:ans);
    }
    return 0;
}
