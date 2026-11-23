#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=710,M=18210,K=7;
const ll INF=0x3f3f3f3f3f3f3f3fll;
struct MCMF{
    struct edge{
        int v,nxt,w;
        ll cost;
    }e[M];
    int head[N],pre[N],q[N],cnt;
    ll dis[N],ans;
    bool vis[N];
    void init(){
        cnt=0;
        memset(head,-1,sizeof head);
    }
    void add(int x,int y,int z,int w){
        e[cnt]={y,head[x],z,w};
        head[x]=cnt++;
    }
    void add2(int x,int y,int z,int w){
        add(x,y,z,w);
        add(y,x,0,-w);
    }
    bool spfa(int s,int t){
        memset(dis,(int)INF,sizeof dis);
        memset(vis,0,sizeof vis);
        int l=0,r=1;
        q[0]=s;
        dis[s]=0;
        vis[s]=1;
        while(l!=r){
            int u=q[l];
            l=(l+1)%N;
            vis[u]=0;
            for(int i=head[u];i!=-1;i=e[i].nxt){
                int v=e[i].v;
                if(!e[i].w || dis[v]<=dis[u]+e[i].cost)continue;
                dis[v]=dis[u]+e[i].cost;
                pre[v]=i;
                if(!vis[v]){
                    vis[v]=1;
                    q[r]=v;
                    r=(r+1)%N;
                }
            }
        }
        return dis[t]!=INF;
    }
    int augment(int s,int t,int num){
        for(int v=t;v!=s;v=e[pre[v]^1].v){
            num=min(num,e[pre[v]].w);
        }
        for(int v=t;v!=s;v=e[pre[v]^1].v){
            int i=pre[v];
            e[i].w-=num;
            e[i^1].w+=num;
            ans+=(ll)num*e[i].cost;
        }
        return num;
    }
    ll mcmf(int s,int t,int need){
        ans=0;
        while(need && spfa(s,t)){
            need-=augment(s,t,need);
        }
        return need?-1:ans;
    }
}f;
int n,m,s,t,sum,a[K],b[K];
int main(){
    scanf("%d%d",&n,&m);
    s=K*n,t=s+1;
    f.init();
    for(int i=0;i<n;++i){
        for(int &x:a){
            scanf("%d",&x);
        }
        for(int &x:b){
            scanf("%d",&x);
        }
        int c,w;
        scanf("%d%d",&c,&w);
        for(int j=0;j<K;++j){
            f.add2(s,K*i+j,a[j],0);
            f.add2(K*i+j,t,b[j],0);
            f.add2(K*i+j,K*i+(j+1)%K,c,w);
            sum+=b[j];
        }
    }
    while(m--){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        --u,--v;
        for(int j=0;j<K;++j){
            f.add2(K*u+j,K*v+j,1e9,w);
            f.add2(K*v+j,K*u+j,1e9,w);
        }
    }
    printf("%lld\n",f.mcmf(s,t,sum));
    return 0;
}
