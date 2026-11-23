#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100;
struct block{
    int fa,id,len;
};
int n,m,k;
ll delay;
char s[N];
vector<vector<int>> g,d;
vector<block> e{{-1,0,1}};
vector<int> cur;
vector<map<ll,int>> q;
bool better(int a,int b){
    if(e[a].len!=e[b].len)return e[a].len>e[b].len;
    return e[a].id<e[b].id;
}
void advance(int u,ll t){
    auto it=q[u].upper_bound(t);
    if(it!=q[u].begin())cur[u]=prev(it)->second;
    q[u].erase(q[u].begin(),it);
}
void schedule(int u,ll t,int x){
    auto it=q[u].lower_bound(t);
    int pre=it==q[u].begin()?cur[u]:prev(it)->second;
    if(!better(x,pre))return;
    if(it!=q[u].end() && it->first==t && !better(x,it->second))return;
    while(it!=q[u].end() && !better(it->second,x)){
        it=q[u].erase(it);
    }
    q[u][t]=x;
}
int main(){
    scanf("%d%d",&n,&m);
    g.resize(n);
    for(int i=0;i<m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    scanf("%lld%d",&delay,&k);
    d.assign(n,vector<int>(n,-1));
    for(int st=0;st<n;++st){
        vector<int> v{st};
        d[st][st]=0;
        for(size_t p=0;p<v.size();++p){
            for(int &u:g[v[p]]){
                if(d[st][u]>=0)continue;
                d[st][u]=d[st][v[p]]+1;
                v.push_back(u);
            }
        }
    }
    cur.resize(n);
    q.resize(n);
    fgets(s,N,stdin);
    for(int i=0;i<k;++i){
        fgets(s,N,stdin);
        int u,id;
        ll t;
        bool make=sscanf(s,"%d%lld%d",&u,&t,&id)==3;
        --u;
        advance(u,t);
        if(make){
            int x=e.size();
            e.push_back({cur[u],id,e[cur[u]].len+1});
            cur[u]=x;
            auto it=q[u].begin();
            while(it!=q[u].end() && !better(it->second,x)){
                it=q[u].erase(it);
            }
            for(int v=0;v<n;++v){
                if(v!=u && d[u][v]>=0)schedule(v,t+delay*d[u][v],x);
            }
        }
        else{
            vector<int> ans;
            for(int p=cur[u];p!=-1;p=e[p].fa){
                ans.push_back(e[p].id);
            }
            reverse(ans.begin(),ans.end());
            printf("%d",(int)ans.size());
            for(int &x:ans){
                printf(" %d",x);
            }
            putchar('\n');
        }
    }
    return 0;
}
