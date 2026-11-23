#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=1e5+10,K=18;
int n,m,a[N],fa[N],sz[N],bel[N],low[N],ord[N],root[N];
int up[N][K],mn[N][K],head[N],to[N<<1],nxt[N<<1],w[N<<1],cnt;
ll ans[N],dis[N],uc[N],dc[N];
bool del[N];
P qs[N];
struct task{
    int rt;
    vector<int> ids;
};
vector<task> tasks;
void add(int u,int v,int c){
    to[++cnt]=v;
    w[cnt]=c;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
int main(){
    scanf("%d%d",&n,&m);
    a[0]=2e9;
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1,u,v,c;i<n;++i){
        scanf("%d%d%d",&u,&v,&c);
        add(u,v,c);add(v,u,c);
    }
    for(int i=0;i<m;++i){
        scanf("%d%d",&qs[i].first,&qs[i].second);
    }
    fill(mn[0],mn[0]+K,a[0]);
    tasks.resize(1);
    tasks[0].rt=1;
    tasks[0].ids.resize(m);
    iota(tasks[0].ids.begin(),tasks[0].ids.end(),0);
    while(!tasks.empty()){
        task cur=std::move(tasks.back());
        tasks.pop_back();
        if(cur.ids.empty())continue;
        int len=1;
        ord[0]=cur.rt;fa[cur.rt]=0;
        for(int i=0;i<len;++i){
            int u=ord[i];
            for(int j=head[u];j;j=nxt[j]){
                int v=to[j];
                if(del[v] || v==fa[u])continue;
                fa[v]=u;
                ord[len++]=v;
            }
        }
        int c=cur.rt;
        for(int i=len-1;i>=0;--i){
            int u=ord[i],mx=0;
            sz[u]=1;
            for(int j=head[u];j;j=nxt[j]){
                int v=to[j];
                if(del[v] || fa[v]!=u)continue;
                sz[u]+=sz[v];
                mx=max(mx,sz[v]);
            }
            if(max(mx,len-sz[u])<=len/2)c=u;
        }
        len=1;
        ord[0]=c;fa[c]=0;bel[c]=-1;
        dis[c]=uc[c]=dc[c]=0;low[c]=a[c];
        int tot=0;
        for(int j=head[c];j;j=nxt[j]){
            if(!del[to[j]])root[tot++]=to[j];
        }
        for(int i=0;i<len;++i){
            int u=ord[i],p=fa[u];
            up[u][0]=p;mn[u][0]=a[p];
            for(int j=1;j<K;++j){
                int v=up[u][j-1];
                up[u][j]=up[v][j-1];
                mn[u][j]=min(mn[u][j-1],mn[v][j-1]);
            }
            if(p){
                int v=u;
                for(int j=K-1;j>=0;--j){
                    if(up[v][j] && mn[v][j]>=a[u])v=up[v][j];
                }
                int q=fa[v];
                uc[u]=(ll)a[u]*(dis[u]-dis[q])+uc[q];
            }
            int num=0;
            for(int j=head[u];j;j=nxt[j]){
                int v=to[j];
                if(del[v] || v==p)continue;
                fa[v]=u;dis[v]=dis[u]+w[j];
                low[v]=min(low[u],a[v]);
                dc[v]=dc[u]+(ll)w[j]*low[u];
                bel[v]=u==c?num++:bel[u];
                ord[len++]=v;
            }
        }
        vector<vector<int>> pending(tot);
        for(int &id:cur.ids){
            auto [s,t]=qs[id];
            if(s!=c && t!=c && bel[s]==bel[t]){
                pending[bel[s]].push_back(id);
                continue;
            }
            ll res=uc[s];
            int p=low[s];
            if(low[t]>=p)res+=(ll)p*dis[t];
            else{
                int v=t;
                for(int j=K-1;j>=0;--j){
                    if(up[v][j] && low[up[v][j]]<p)v=up[v][j];
                }
                res+=(ll)p*dis[v]+dc[t]-dc[v];
            }
            ans[id]=res;
        }
        del[c]=1;
        for(int i=0;i<tot;++i){
            if(!pending[i].empty()){
                tasks.push_back({root[i],std::move(pending[i])});
            }
        }
    }
    for(int i=0;i<m;++i){
        printf("%lld\n",ans[i]);
    }
    return 0;
}
