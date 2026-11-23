#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,bool> P;
const int N=5e5+10;
int n,m,op,u,head[N],tail[N],nxt[N],cnt[N];
int dep[N],dfn[N],out[N],tot;
ll a[N];
vector<int> g[N];
struct BIT{
    int n,tr[N];
    void init(int x){
        n=x;
        memset(tr,0,sizeof tr);
    }
    void add(int x,int v){
        for(;x<=n;x+=x&-x){
            tr[x]+=v;
        }
    }
    int sum(int x){
        int ans=0;
        for(;x;x-=x&-x){
            ans+=tr[x];
        }
        return ans;
    }
}bit;
void append(int u,int l,int r){
    if(!l)return;
    if(tail[u])nxt[tail[u]]=l;
    else head[u]=l;
    tail[u]=r;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;++i){
        int p;
        scanf("%d",&p);
        g[p].push_back(i);
        append(p,i,i);
        ++cnt[p];
    }
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    vector<P> st;
    st.push_back({1,false});
    dep[1]=1;
    while(!st.empty()){
        auto [x,ed]=st.back();
        st.pop_back();
        if(ed){
            out[x]=tot;
            continue;
        }
        dfn[x]=++tot;
        st.push_back({x,true});
        for(int &v:g[x]){
            dep[v]=dep[x]+1;
            st.push_back({v,false});
        }
    }
    bit.init(n);
    while(m--){
        scanf("%d%d",&op,&u);
        if(op==2){
            int ans=dep[u]+bit.sum(dfn[u]);
            printf("%d\n",ans);
        }
        else{
            int v=head[u];
            head[u]=tail[u]=cnt[u]=0;
            while(v){
                int next=nxt[v];
                nxt[v]=0;
                a[u]+=a[v];
                append(u,head[v],tail[v]);
                cnt[u]+=cnt[v];
                bit.add(dfn[v],-1);
                bit.add(out[v]+1,1);
                v=next;
            }
            printf("%d %lld\n",cnt[u],a[u]);
        }
    }
    return 0;
}
