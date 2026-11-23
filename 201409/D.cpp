#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=4;
int n,m,k,d;
ll ans;
int dx[M]={1,-1,0,0},dy[M]={0,0,1,-1};
vector<int> dis,q;
vector<ll> need;
int main(){
    scanf("%d%d%d%d",&n,&m,&k,&d);
    dis.assign(n*n,-1);
    need.resize(n*n);
    for(int i=0;i<m;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        int u=(x-1)*n+y-1;
        if(dis[u]<0){
            dis[u]=0;
            q.push_back(u);
        }
    }
    for(int i=0;i<k;++i){
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        need[(x-1)*n+y-1]+=c;
    }
    for(int i=0;i<d;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        dis[(x-1)*n+y-1]=-2;
    }
    for(size_t p=0;p<q.size();++p){
        int u=q[p];
        ans+=need[u]*dis[u];
        for(int i=0;i<M;++i){
            int x=u/n+dx[i],y=u%n+dy[i];
            if(x<0 || x>=n || y<0 || y>=n)continue;
            int v=x*n+y;
            if(dis[v]!=-1)continue;
            dis[v]=dis[u]+1;
            q.push_back(v);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
