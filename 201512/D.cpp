#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=10010,M=1e5+10;
int n,m,pos[N],st[M],ans[M],top,cnt;
bool vis[M];
vector<vector<P>> g;
int main(){
    scanf("%d%d",&n,&m);
    g.assign(n+1,vector<P>());
    memset(vis,0,sizeof vis);
    memset(pos,0,sizeof pos);
    top=cnt=0;
    for(int i=0;i<m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    int odd=0;
    for(int u=1;u<=n;++u){
        sort(g[u].begin(),g[u].end());
        odd+=g[u].size()%2;
    }
    if(odd && (odd!=2 || g[1].size()%2==0)){
        puts("-1");
        return 0;
    }
    st[++top]=1;
    while(top){
        int u=st[top];
        int &i=pos[u];
        while(i<(int)g[u].size() && vis[g[u][i].second]){
            ++i;
        }
        if(i==(int)g[u].size()){
            ans[cnt++]=u;
            --top;
        }
        else{
            auto [v,id]=g[u][i++];
            vis[id]=true;
            st[++top]=v;
        }
    }
    if(cnt!=m+1){
        puts("-1");
        return 0;
    }
    reverse(ans,ans+cnt);
    for(int i=0;i<cnt;++i){
        printf("%d%c",ans[i],i+1==cnt?'\n':' ');
    }
    return 0;
}
