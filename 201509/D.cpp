#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,size_t> P;
int n,m;
ll ans;
vector<vector<int>> g,rg;
vector<bool> vis;
vector<int> order;
int main(){
    scanf("%d%d",&n,&m);
    g.resize(n);rg.resize(n);
    for(int i=0;i<m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        u--,v--;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    vis.resize(n);
    for(int i=0;i<n;++i){
        if(vis[i])continue;
        vector<P> st{{i,0}};
        vis[i]=true;
        while(!st.empty()){
            int u=st.back().first;
            size_t &p=st.back().second;
            if(p==g[u].size()){
                order.push_back(u);
                st.pop_back();
            }
            else{
                int v=g[u][p++];
                if(!vis[v]){
                    vis[v]=true;
                    st.push_back({v,0});
                }
            }
        }
    }
    fill(vis.begin(),vis.end(),false);
    for(auto it=order.rbegin();it!=order.rend();++it){
        if(vis[*it])continue;
        vector<int> v{*it};
        vis[*it]=true;
        for(size_t i=0;i<v.size();++i){
            for(int &u:rg[v[i]]){
                if(vis[u])continue;
                vis[u]=true;
                v.push_back(u);
            }
        }
        ll sz=v.size();
        ans+=sz*(sz-1)/2;
    }
    printf("%lld\n",ans);
    return 0;
}
