#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=2e5+10,M=20;
int n,m,q,tot,tim;
int dfn[N],low[N],fa[N],pe[N],pos[N],in[N],out[N],pre[N];
int up[M][N],mark[N],sub[N],mx[N],vp[N];
vector<P>g[N];
vector<int>tr[N],vs,dfs;
void build(){
    tot=n;
    pe[1]=-1;
    dfn[1]=low[1]=++tim;
    dfs.push_back(1);
    vs.push_back(1);
    while(!dfs.empty()){
        int u=dfs.back();
        if(pos[u]<(int)g[u].size()){
            auto [v,id]=g[u][pos[u]++];
            if(id==pe[u])continue;
            if(!dfn[v]){
                fa[v]=u;
                pe[v]=id;
                dfn[v]=low[v]=++tim;
                vs.push_back(v);
                dfs.push_back(v);
            }
            else low[u]=min(low[u],dfn[v]);
        }
        else{
            dfs.pop_back();
            int p=fa[u];
            if(!p)continue;
            low[p]=min(low[p],low[u]);
            if(low[u]>=dfn[p]){
                ++tot;
                tr[tot].push_back(p);
                tr[p].push_back(tot);
                int v=0;
                while(v!=u){
                    v=vs.back();
                    vs.pop_back();
                    tr[tot].push_back(v);
                    tr[v].push_back(tot);
                }
            }
        }
    }
    vector<P>st;
    st.push_back(P(1,0));
    tim=0;
    while(!st.empty()){
        auto [u,flag]=st.back();
        st.pop_back();
        if(flag){
            out[u]=tim;
            continue;
        }
        in[u]=++tim;
        pre[u]=pre[up[0][u]]+(u<=n);
        for(int j=1;j<M;++j){
            up[j][u]=up[j-1][up[j-1][u]];
        }
        st.push_back(P(u,1));
        for(int &v:tr[u]){
            if(v==up[0][u])continue;
            up[0][v]=u;
            st.push_back(P(v,0));
        }
    }
}
bool anc(int u,int v){
    return in[u]<=in[v] && out[v]<=out[u];
}
int lca(int u,int v){
    if(anc(u,v))return u;
    if(anc(v,u))return v;
    for(int j=M-1;j>=0;--j){
        if(up[j][u] && !anc(up[j][u],v))u=up[j][u];
    }
    return up[0][u];
}
bool cmp(int x,int y){
    return in[x]<in[y];
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(P(v,i));
        g[v].push_back(P(u,i));
    }
    build();
    for(int id=1;id<=q;++id){
        int c;
        scanf("%d",&c);
        vector<int>v(c);
        for(int &x:v){
            scanf("%d",&x);
            mark[x]=id;
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=1;i<c;++i){
            v.push_back(lca(v[i-1],v[i]));
        }
        v.push_back(1);
        sort(v.begin(),v.end(),cmp);
        v.erase(unique(v.begin(),v.end()),v.end());
        vector<int>st;
        for(int &u:v){
            sub[u]=(mark[u]==id);
            mx[u]=0;
            while(!st.empty() && !anc(st.back(),u)){
                st.pop_back();
            }
            vp[u]=st.empty()?0:st.back();
            st.push_back(u);
        }
        ll ans=1ll*(n-1)*c;
        for(int i=(int)v.size()-1;i>=0;--i){
            int u=v[i],p=vp[u];
            int best=max(mx[u],c-sub[u]);
            if(u<=n)ans+=best-(c-(mark[u]==id));
            if(p){
                int cnt=pre[u]-pre[p]-(u<=n);
                ans-=1ll*cnt*min(sub[u],c-sub[u]);
                sub[p]+=sub[u];
                mx[p]=max(mx[p],sub[u]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
