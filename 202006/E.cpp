#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3fll;
struct flow{
    struct edge{
        int v,rev;
        ll cap;
    };
    vector<vector<edge>> g;
    vector<int> dep,cur;
    void init(int n){
        g.resize(n);
        dep.resize(n);
        cur.resize(n);
    }
    void add(int u,int v,ll c){
        edge a={v,(int)g[v].size(),c};
        edge b={u,(int)g[u].size(),0};
        g[u].push_back(a);
        g[v].push_back(b);
    }
    ll dfs(int u,int t,ll f){
        if(u==t)return f;
        for(int &i=cur[u];i<(int)g[u].size();++i){
            auto &e=g[u][i];
            if(e.cap && dep[e.v]==dep[u]+1){
                ll val=dfs(e.v,t,min(f,e.cap));
                if(val){
                    e.cap-=val;
                    g[e.v][e.rev].cap+=val;
                    return val;
                }
            }
        }
        return 0;
    }
    ll run(int s,int t){
        ll ans=0;
        while(true){
            fill(dep.begin(),dep.end(),-1);
            queue<int> q;
            q.push(s);
            dep[s]=0;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(auto &e:g[u]){
                    if(e.cap && dep[e.v]<0){
                        dep[e.v]=dep[u]+1;
                        q.push(e.v);
                    }
                }
            }
            if(dep[t]<0)return ans;
            fill(cur.begin(),cur.end(),0);
            while(ll val=dfs(s,t,INF)){
                ans+=val;
            }
        }
    }
}f;
int n,m,s,t;
ll sum;
void weight(int u,ll x){
    if(x>0){
        f.add(s,u,x);
        sum+=x;
    }
    else if(x<0)f.add(u,t,-x);
}
int main(){
    scanf("%d%d",&n,&m);
    s=n*2;
    t=s+1;
    f.init(t+1);
    for(int i=0;i<n;++i){
        ll l,r,a,b,c;
        scanf("%lld%lld%lld%lld%lld",&l,&r,&a,&b,&c);
        auto calc=[&](ll x){
            return a*x*x+b*x+c;
        };
        ll in=max(calc(l+1),calc(r-1));
        if(a<0){
            ll mid=-b/(2*a);
            for(ll x=mid-2;x<=mid+2;++x){
                if(l<x && x<r)in=max(in,calc(x));
            }
        }
        ll out=max(calc(l),calc(r));
        weight(i,in);
        weight(i+n,out-in);
        f.add(i+n,i,INF);
    }
    while(m--){
        int z,x,y;
        scanf("%d%d%d",&z,&x,&y);
        f.add(y-1+(z==2?n:0),x-1,INF);
    }
    printf("%lld\n",sum-f.run(s,t));
    return 0;
}
