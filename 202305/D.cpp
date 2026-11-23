#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> V;
const int N=10010;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n,m,k,dfn[N],low[N],fa[N],cnt[N],sep[N],st[N];
int ord[N],label[N],top,tot;
bool del[N];
queue<int> q;
map<int,V>::iterator it[N];
V cost;
vector<map<int,V>> g;
vector<int> core;
ll ans=INF;
void connect(int u,int v,const V &a){
    V b(k,vector<ll>(k));
    for(int i=0;i<k;++i){
        for(int j=0;j<k;++j){
            b[j][i]=a[i][j];
        }
    }
    g[u][v]=a;
    g[v][u]=b;
}
int check(){
    memset(dfn,0,sizeof dfn);
    memset(low,0,sizeof low);
    memset(fa,-1,sizeof fa);
    memset(cnt,0,sizeof cnt);
    memset(sep,0,sizeof sep);
    top=tot=0;
    st[++top]=0;
    dfn[0]=low[0]=++tot;
    it[0]=g[0].begin();
    while(top){
        int u=st[top];
        if(it[u]==g[u].end()){
            --top;
            if(fa[u]!=-1){
                int p=fa[u];
                low[p]=min(low[p],low[u]);
                if(low[u]>=dfn[p])++sep[p];
            }
            continue;
        }
        int v=(it[u]++)->first;
        if(v==fa[u])continue;
        if(dfn[v])low[u]=min(low[u],dfn[v]);
        else{
            fa[v]=u;
            ++cnt[u];
            dfn[v]=low[v]=++tot;
            it[v]=g[v].begin();
            st[++top]=v;
        }
    }
    for(int u=0;u<n;++u){
        int cnts=fa[u]==-1?cnt[u]:sep[u]+1;
        if(m-n+1-(int)g[u].size()+cnts==0)return u;
    }
    return -1;
}
ll solve(int root){
    fill(fa,fa+n,-2);
    int num=0;
    fa[root]=-1;
    for(int s=0;s<n;++s){
        if(fa[s]!=-2)continue;
        fa[s]=-1;
        ord[num++]=s;
        for(int i=num-1;i<num;++i){
            int u=ord[i];
            for(auto &[v,a]:g[u]){
                if(fa[v]!=-2)continue;
                fa[v]=u;
                ord[num++]=v;
            }
        }
    }
    ll ans=INF;
    for(int s=0;s<k;++s){
        V dp=cost;
        for(auto &[u,a]:g[root]){
            for(int x=0;x<k;++x){
                dp[u][x]+=a[s][x];
            }
        }
        ll sum=cost[root][s];
        for(int i=num-1;i>=0;--i){
            int u=ord[i],p=fa[u];
            if(p==-1){
                sum+=*min_element(dp[u].begin(),dp[u].end());
                continue;
            }
            auto &a=g[p].at(u);
            for(int x=0;x<k;++x){
                ll best=INF;
                for(int y=0;y<k;++y){
                    best=min(best,a[x][y]+dp[u][y]);
                }
                dp[p][x]+=best;
            }
        }
        ans=min(ans,sum);
    }
    return ans;
}
void dfs(int i,ll val){
    if(val>=ans)return;
    if(i==(int)core.size()){
        ans=val;
        return;
    }
    int u=core[i];
    for(int x=0;x<k;++x){
        ll sum=val+cost[u][x];
        for(int j=0;j<i;++j){
            int v=core[j];
            if(g[u].count(v))sum+=g[u].at(v)[x][label[v]];
        }
        label[u]=x;
        dfs(i+1,sum);
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    cost=V(n,vector<ll>(k));
    g.resize(n);
    for(auto &row:cost){
        for(ll &x:row){
            scanf("%lld",&x);
        }
    }
    for(int i=0;i<m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        V a(k,vector<ll>(k));
        for(auto &row:a){
            for(ll &x:row){
                scanf("%lld",&x);
            }
        }
        connect(u,v,a);
    }
    int root=check();
    if(root!=-1){
        printf("%lld\n",solve(root));
        return 0;
    }
    memset(del,0,sizeof del);
    for(int u=0;u<n;++u){
        if(g[u].size()<=2)q.push(u);
    }
    ll sum=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(del[u] || g[u].size()>2)continue;
        del[u]=true;
        if(g[u].empty()){
            sum+=*min_element(cost[u].begin(),cost[u].end());
            continue;
        }
        int v=g[u].begin()->first;
        if(g[u].size()==1){
            auto &a=g[v].at(u);
            for(int x=0;x<k;++x){
                ll best=INF;
                for(int y=0;y<k;++y){
                    best=min(best,a[x][y]+cost[u][y]);
                }
                cost[v][x]+=best;
            }
            g[v].erase(u);
            q.push(v);
        }
        else{
            int w=next(g[u].begin())->first;
            auto &a=g[v].at(u),&b=g[u].at(w);
            V c(k,vector<ll>(k,INF));
            for(int x=0;x<k;++x){
                for(int y=0;y<k;++y){
                    for(int z=0;z<k;++z){
                        c[x][y]=min(c[x][y],a[x][z]+cost[u][z]+b[z][y]);
                    }
                    if(g[v].count(w))c[x][y]+=g[v].at(w)[x][y];
                }
            }
            g[v].erase(u);
            g[w].erase(u);
            connect(v,w,c);
            q.push(v);
            q.push(w);
        }
        g[u].clear();
    }
    for(int u=0;u<n;++u){
        if(!del[u])core.push_back(u);
    }
    dfs(0,sum);
    printf("%lld\n",ans);
    return 0;
}
