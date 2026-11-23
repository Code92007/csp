#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=1e5+10;
int n,X,k,m,ans,need[N];
vector<P>watch[N];
struct node{
    int u,v,ver;
    bool ok;
    vector<int>g;
};
vector<node>seg;
mt19937 rng(random_device{}());
struct BIT{
    int n,pw,tr[N];
    void init(int m){
        n=m;
        pw=1;
        while((pw<<1)<=n){
            pw<<=1;
        }
        memset(tr,0,(n+1)*sizeof(*tr));
    }
    void add(int x,int v){
        for(int i=x;i<=n;i+=i&-i){
            tr[i]+=v;
        }
    }
    int sum(int x){
        int ans=0;
        for(int i=x;i;i-=i&-i){
            ans+=tr[i];
        }
        return ans;
    }
    int kth(int k){
        int x=0;
        for(int i=pw;i;i>>=1){
            if(x+i<=n && k>tr[x+i]){
                x+=i;
                k-=tr[x];
            }
        }
        return x+1;
    }
}tr;
namespace HLD{
    int tim,fa[N],dep[N],sz[N],son[N],top[N],dfn[N],at[N],ord[N];
    vector<int>g[N];
    void build(){
        int cnt=1;
        ord[1]=1;
        for(int i=1;i<=cnt;++i){
            int u=ord[i];
            sz[u]=1;
            for(int &v:g[u]){
                if(v==fa[u])continue;
                fa[v]=u;
                dep[v]=dep[u]+1;
                ord[++cnt]=v;
            }
        }
        for(int i=n;i>1;--i){
            int u=ord[i],p=fa[u];
            sz[p]+=sz[u];
            if(sz[u]>sz[son[p]])son[p]=u;
        }
        vector<P>st;
        st.push_back(P(1,1));
        while(!st.empty()){
            P p=st.back();
            st.pop_back();
            for(int u=p.first;u;u=son[u]){
                top[u]=p.second;
                dfn[u]=++tim;
                at[tim]=u;
                for(int &v:g[u]){
                    if(fa[v]==u && v!=son[u]){
                        st.push_back(P(v,v));
                    }
                }
            }
        }
    }
    int lca(int u,int v){
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]]){
                swap(u,v);
            }
            u=fa[top[u]];
        }
        return dep[u]<dep[v]?u:v;
    }
    int dist(int u,int v){
        return dep[u]+dep[v]-2*dep[lca(u,v)];
    }
}
using namespace HLD;
void refresh(int id){
    node &s=seg[id];
    ++s.ver;
    vector<P>part;
    int u=s.u,v=s.v;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]){
            swap(u,v);
        }
        part.push_back(P(dfn[top[u]],dfn[u]));
        u=fa[top[u]];
    }
    if(dep[u]>dep[v]){
        swap(u,v);
    }
    if(u!=v){
        part.push_back(P(dfn[u]+1,dfn[v]));
    }
    vector<int>cnt;
    int tot=0;
    for(auto &[l,r]:part){
        int c=tr.sum(r)-tr.sum(l-1);
        cnt.push_back(c);
        tot+=c;
    }
    if(tot<=1){
        s.ok=1;
        for(int &i:s.g){
            if(--need[i]==0)++ans;
        }
        return;
    }
    uniform_int_distribution<int> rx(1,tot),ry(1,tot-1);
    int x=rx(rng),y=ry(rng);
    if(y>=x)++y;
    for(int i=0;i<2;++i){
        int rank=i?y:x;
        for(int j=0;j<(int)part.size();++j){
            if(rank>cnt[j]){
                rank-=cnt[j];
            }
            else{
                int p=tr.kth(tr.sum(part[j].first-1)+rank);
                watch[at[p]].push_back(P(id,s.ver));
                break;
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&X);
    for(int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    build();
    scanf("%d",&k);
    vector<int>sta(k);
    for(int &u:sta){
        scanf("%d",&u);
    }
    scanf("%d",&m);
    seg.reserve(2*m+k*(k-1)/2);
    map<P,int>ids;
    for(int i=0;i<m;++i){
        int s,t;
        scanf("%d%d",&s,&t);
        int len=dist(s,t);
        vector<P>p;
        p.push_back(P(0,s));
        p.push_back(P(len,t));
        for(int &u:sta){
            int d=dist(s,u);
            if(d+dist(u,t)==len){
                p.push_back(P(d,u));
            }
        }
        sort(p.begin(),p.end());
        p.erase(unique(p.begin(),p.end()),p.end());
        for(int j=1;j<(int)p.size();++j){
            if(p[j].first-p[j-1].first<=1)continue;
            int u=p[j-1].second,v=p[j].second;
            if(u>v){
                swap(u,v);
            }
            auto [it,ok]=ids.emplace(P(u,v),(int)seg.size());
            if(ok){
                seg.push_back({u,v,0,0,{}});
            }
            seg[it->second].g.push_back(i);
            ++need[i];
        }
    }
    ids.clear();
    for(int i=0;i<m;++i){
        if(!need[i])++ans;
    }
    tr.init(n);
    for(int u=2;u<=n;++u){
        tr.add(dfn[u],1);
    }
    for(int i=0;i<(int)seg.size();++i){
        refresh(i);
    }
    int q,last=0;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==2){
            printf("%d\n",ans);
            last=ans;
        }
        else{
            int u,v;
            scanf("%d%d",&u,&v);
            u^=X*last;
            v^=X*last;
            if(dep[u]<dep[v]){
                swap(u,v);
            }
            tr.add(dfn[u],-1);
            auto cur=std::move(watch[u]);
            for(auto &[id,ver]:cur){
                if(!seg[id].ok && seg[id].ver==ver){
                    refresh(id);
                }
            }
        }
    }
    return 0;
}
