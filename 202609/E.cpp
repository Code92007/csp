#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int N=1e5+10;
int n,m,k,q,tot,fa[N],sz[N],ord[N],dis[N];
ll bit[N],mask[N],ans;
bool vis[N];
char s[N];
vector<P>g[N];
struct node{
    ll mask;
    int rt,id,dis;
};
vector<node>rec[N];
struct Hash{
    int mask;
    vector<ll>key;
    vector<int>val;
    void init(int n){
        int s=2;
        while(s<n*2){
            s<<=1;
        }
        mask=s-1;
        key.assign(s,-1);
        val.assign(s,0);
    }
    int pos(ll x){
        ull h=x+0x9e3779b97f4a7c15ull;
        h=(h^(h>>30))*0xbf58476d1ce4e5b9ull;
        h=(h^(h>>27))*0x94d049bb133111ebull;
        int p=(h^(h>>31))&mask;
        while(key[p]!=-1 && key[p]!=x){
            p=(p+1)&mask;
        }
        return p;
    }
    void ins(ll x){
        key[pos(x)]=x;
    }
    void add(ll x,int v){
        val[pos(x)]+=v;
    }
    int get(ll x){
        int p=pos(x);
        return key[p]==x?val[p]:0;
    }
}all[N],sub[N];
int getrt(int s){
    int cnt=1;
    ord[1]=s;
    fa[s]=0;
    for(int i=1;i<=cnt;++i){
        int u=ord[i];
        sz[u]=1;
        for(auto &[v,w]:g[u]){
            if(vis[v] || v==fa[u])continue;
            fa[v]=u;
            ord[++cnt]=v;
        }
    }
    int rt=s,mn=cnt;
    for(int i=cnt;i;--i){
        int u=ord[i],mx=cnt-sz[u];
        for(auto &[v,w]:g[u]){
            if(!vis[v] && fa[v]==u){
                mx=max(mx,sz[v]);
            }
        }
        if(mx<mn){
            mn=mx;
            rt=u;
        }
        if(fa[u]){
            sz[fa[u]]+=sz[u];
        }
    }
    return rt;
}
void solve(int u){
    int rt=getrt(u);
    vis[rt]=1;
    all[rt].init(sz[u]);
    all[rt].ins(bit[rt]<<2);
    rec[rt].push_back({bit[rt],rt,0,0});
    for(auto &[v,w]:g[rt]){
        if(vis[v])continue;
        int id=++tot,cnt=1;
        ord[1]=v;
        fa[v]=rt;
        dis[v]=w%k;
        mask[v]=bit[rt]^bit[v];
        for(int i=1;i<=cnt;++i){
            int x=ord[i];
            for(auto &[y,z]:g[x]){
                if(vis[y] || y==fa[x])continue;
                fa[y]=x;
                ord[++cnt]=y;
                dis[y]=(dis[x]+z)%k;
                mask[y]=mask[x]^bit[y];
            }
        }
        sub[id].init(cnt);
        for(int i=1;i<=cnt;++i){
            int x=ord[i];
            ll key=(mask[x]<<2)|dis[x];
            rec[x].push_back({mask[x],rt,id,dis[x]});
            all[rt].ins(key);
            sub[id].ins(key);
        }
    }
    for(auto &[v,w]:g[rt]){
        if(!vis[v]){
            solve(v);
        }
    }
}
ll ask(int u){
    ll res=0;
    for(auto &x:rec[u]){
        ll base=x.mask^bit[x.rt];
        int d=(k-x.dis)%k;
        for(int i=0;i<m;++i){
            ll key=((base^(1ll<<i))<<2)|d;
            res+=all[x.rt].get(key);
            if(x.id){
                res-=sub[x.id].get(key);
            }
        }
    }
    return res;
}
void add(int u,int v){
    for(auto &x:rec[u]){
        ll key=(x.mask<<2)|x.dis;
        all[x.rt].add(key,v);
        if(x.id){
            sub[x.id].add(key,v);
        }
    }
}
int main(){
    scanf("%d%d%d%d%s",&n,&m,&k,&q,s+1);
    for(int i=1;i<=n;++i){
        int c;
        scanf("%d",&c);
        bit[i]=1ll<<(c-1);
    }
    for(int i=1;i<n;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back(P(v,w));
        g[v].push_back(P(u,w));
    }
    solve(1);
    for(int i=1;i<=n;++i){
        if(s[i]=='1'){
            ans+=ask(i)+1;
            add(i,1);
        }
    }
    printf("%lld\n",ans);
    while(q--){
        int u;
        scanf("%d",&u);
        if(s[u]=='1'){
            ans-=ask(u);
            add(u,-1);
        }
        else{
            ans+=ask(u)+1;
            add(u,1);
        }
        s[u]^=1;
        printf("%lld\n",ans);
    }
    return 0;
}
