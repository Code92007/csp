#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5010;
const ll INF=0x3f3f3f3f3f3f3f3fll;
struct station{
    ll x,y,r,c;
    bool vis;
}e[N];
int n,m;
ll x[N],y[N],d[N];
bool vis[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%lld%lld",&x[i],&y[i]);
    }
    for(int i=0;i<m;++i){
        scanf("%lld%lld%lld%lld",&e[i].x,&e[i].y,&e[i].r,&e[i].c);
    }
    memset(d,(int)INF,sizeof d);
    d[0]=0;
    for(int i=0;i<n;++i){
        int u=-1;
        for(int j=0;j<n;++j){
            if(!vis[j] && (u==-1 || d[j]<d[u]))u=j;
        }
        if(u==-1 || d[u]==INF)break;
        vis[u]=true;
        if(u==n-1)break;
        for(int j=0;j<m;++j){
            station &s=e[j];
            bool in=abs(x[u]-s.x)<=s.r && abs(y[u]-s.y)<=s.r;
            if(s.vis || !in)continue;
            s.vis=true;
            ll val=d[u]+s.c;
            for(int v=0;v<n;++v){
                bool near=abs(x[v]-s.x)<=s.r && abs(y[v]-s.y)<=s.r;
                if(!vis[v] && val<d[v] && near)d[v]=val;
            }
        }
    }
    if(d[n-1]==INF)puts("Nan");
    else printf("%lld\n",d[n-1]);
    return 0;
}
