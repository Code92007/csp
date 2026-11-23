// 候选根算法来源：zlxFTH
// https://www.zhihu.com/question/2043989350854156307/answer/2044499207764105133
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef priority_queue<int,vector<int>,greater<int>> Q;
const int N=1e5+10,M=20;
const int INF=0x3f3f3f3f;
int n,cnt,root,cur,up[M][N],dep[N],to[N],num[N];
int fa[N],sz[N],mn[N];
bool used[N],blk[N];
vector<int>g[N],ans;
Q h[N];
set<int>s[N],red;
int step(int u,int v){
    if(dep[v]>dep[u]){
        int d=dep[v]-dep[u]-1;
        for(int i=0;i<M;++i){
            if(d>>i&1){
                v=up[i][v];
            }
        }
        if(up[0][v]==u)return v;
    }
    return up[0][u];
}
int getmin(int u,int v){
    for(int i=0;i<min(2,(int)g[u].size());++i){
        if(g[u][i]!=v)return g[u][i];
    }
    return INF;
}
int top(int u){
    while(!h[u].empty() && used[h[u].top()]){
        h[u].pop();
    }
    return h[u].empty()?INF:h[u].top();
}
void put(int u){
    assert(u>=1 && u<=n && !used[u]);
    used[u]=1;
    ans.push_back(u);
}
int find(int x){
    int rt=x;
    while(fa[rt]!=rt){
        rt=fa[rt];
    }
    while(x!=rt){
        int y=fa[x];
        fa[x]=rt;
        x=y;
    }
    return rt;
}
int merge(int u,int v){
    u=find(u);
    v=find(v);
    if(u==v)return u;
    if(sz[u]<sz[v]){
        swap(u,v);
    }
    fa[v]=u;
    sz[u]+=sz[v];
    mn[u]=min(mn[u],mn[v]);
    s[u].merge(s[v]);
    s[v].clear();
    return u;
}
int paint(int u){
    if(blk[u])return find(u);
    blk[u]=1;
    mn[u]=min(u,g[u].front());
    s[u].insert(INF);
    int rt=u;
    for(int &v:g[u]){
        if(!blk[v]){
            s[find(rt)].insert(getmin(v,u));
        }
        else{
            int x=find(v);
            s[x].erase(getmin(u,v));
            s[x].insert(INF);
            rt=merge(rt,x);
        }
    }
    return find(rt);
}
void add(int u,int v){
    if(!v)return;
    vector<int>st={u};
    while(!st.empty()){
        int x=st.back();
        st.pop_back();
        if(num[x]>=2)continue;
        num[x]=min(2,num[x]+v);
        for(int &y:g[x]){
            if(to[y]==x){
                st.push_back(y);
            }
        }
    }
}
void seal(int u,int v){
    if(num[u]>num[to[u]])return;
    add(u,1);
    if(v==g[u].front()){
        red.insert(v);
    }
}
void orient(int u,int p){
    vector<P>st={P(u,p)};
    while(!st.empty()){
        auto [x,y]=st.back();
        st.pop_back();
        assert(!to[x]);
        to[x]=y;
        --cnt;
        int v=num[y];
        num[x]=min(2,num[x]+v);
        for(int &z:g[x]){
            if(to[z]==x){
                add(z,v);
            }
            else if(z!=y && !to[z]){
                st.push_back(P(z,x));
            }
        }
    }
}
int next(int rt=0){
    if(rt){
        root=cur=rt;
    }
    while(1){
        int v=top(cur);
        if(v!=INF)return v;
        int id=paint(cur),x=mn[id];
        int a=*s[id].upper_bound(x);
        auto it=red.lower_bound(x);
        int u=0,b=INF;
        if(it!=red.begin()){
            int e=*prev(it);
            if(s[id].count(e)){
                u=to[e];
                b=top(u);
                // 先收缩已经输出完的延迟区域，再比较出口。
                if(b==INF){
                    b=0;
                }
            }
        }
        if(a<b){
            cur=step(a,root);
        }
        else{
            assert(u && b!=INF);
            cur=u;
        }
    }
}
int getroot(){
    int u=1,stop=0;
    while(cnt>1){
        int p=to[u];
        put(u);
        if(p){
            seal(p,u);
        }
        int v=u+1;
        int x=0,y=0;
        bool far=0;
        for(;v<=n;++v){
            x=step(u,v);
            y=x==v?0:step(x,v);
            far=y && y!=v;
            if(num[to[v]]+(int)far>1)continue;
            if(!p && y && to[far?y:x])continue;
            break;
        }
        if(v>n)return p?p:u;
        if(p){
            if(far){
                orient(x,y);
            }
            u=v;
            continue;
        }
        int rt=0;
        if(cnt==2 && y){
            rt=u;
        }
        else if(stop && !to[stop]){
            rt=stop;
        }
        if(rt && next(rt)<v)return rt;
        if(stop && x!=stop){
            seal(u,stop);
        }
        if(!y){
            for(int &z:g[u]){
                if(z!=v && !to[z]){
                    orient(z,u);
                }
            }
            stop=u;
        }
        else{
            if(far && x!=stop){
                stop=0;
            }
            orient(far?x:u,far?y:x);
            seal(x,u);
        }
        u=v;
    }
    return to[u]?to[u]:u;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n==1){
        puts("1");
        return 0;
    }
    for(int i=1;i<=n;++i){
        fa[i]=i;
        sz[i]=1;
        sort(g[i].begin(),g[i].end());
        h[i].push(i);
        for(int &v:g[i]){
            h[i].push(v);
        }
    }
    vector<int>ord={1};
    for(int i=0;i<(int)ord.size();++i){
        int u=ord[i];
        for(int &v:g[u]){
            if(v==up[0][u])continue;
            up[0][v]=u;
            dep[v]=dep[u]+1;
            ord.push_back(v);
        }
    }
    for(int i=1;i<M;++i){
        for(int j=1;j<=n;++j){
            up[i][j]=up[i-1][up[i-1][j]];
        }
    }
    cnt=n;
    int rt=getroot();
    while((int)ans.size()<n){
        put(next(rt));
        rt=0;
    }
    for(int i=0;i<n;++i){
        printf("%d%c",ans[i]," \n"[i==n-1]);
    }
    return 0;
}
