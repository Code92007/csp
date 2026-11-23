#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n,m;
vector<vector<ll>> a,b;
int main(){
    scanf("%d%d",&n,&m);
    a.assign(n,vector<ll>(n,INF));
    b=a;
    for(int i=0;i<n;++i){
        a[i][i]=0;
    }
    for(int i=0;i<m;++i){
        int op,u,v;
        ll w;
        scanf("%d%d%d%lld",&op,&u,&v,&w);
        --u;
        --v;
        auto &g=op?a:b;
        g[u][v]=g[v][u]=min(g[u][v],w);
    }
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            if(a[i][k]==INF)continue;
            for(int j=0;j<n;++j){
                if(a[k][j]<INF)a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    vector<ll> dis(n*2,INF);
    vector<bool> vis(n*2);
    dis[0]=0;
    for(int i=0;i<n*2;++i){
        int x=-1;
        for(int j=0;j<n*2;++j){
            if(!vis[j] && (x==-1 || dis[j]<dis[x]))x=j;
        }
        if(x==-1 || dis[x]==INF)break;
        vis[x]=true;
        int u=x/2,op=x%2;
        for(int v=0;v<n;++v){
            if(b[u][v]<INF)dis[v*2]=min(dis[v*2],dis[x]+b[u][v]);
            if(!op && v!=u && a[u][v]<INF){
                ll w=a[u][v];
                dis[v*2+1]=min(dis[v*2+1],dis[x]+w*w);
            }
        }
    }
    printf("%lld\n",min(dis[n*2-2],dis[n*2-1]));
    return 0;
}
