#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000+10,M=1e5+10;
struct edge{
    int u,v,w;
    bool operator<(const edge &e)const{
        return w<e.w;
    }
}e[M];
int n,m,fa[N],sz[N];
ll ans;
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        fa[i]=i,sz[i]=1;
    }
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    sort(e,e+m);
    for(int i=0;i<m;++i){
        int u=find(e[i].u),v=find(e[i].v);
        if(u==v)continue;
        if(sz[u]<sz[v])swap(u,v);
        fa[v]=u;
        sz[u]+=sz[v];
        ans+=e[i].w;
    }
    printf("%lld\n",ans);
    return 0;
}
