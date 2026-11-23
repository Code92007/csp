#include<bits/stdc++.h>
using namespace std;
const int N=55,M=4,K=N*N;
int n,m,s,t,ans,dx[M]={-1,1,0,0},dy[M]={0,0,-1,1};
char a[N][N];
bool vis[K],can[K];
vector<int> g[K],h[K];
bool ok(char c,int d){
    if(c=='+' || c=='S' || c=='T')return true;
    if(c=='-')return d>=2;
    if(c=='|')return d<2;
    return c=='.' && d==1;
}
void bfs(int s,vector<int> g[],bool vis[]){
    queue<int> q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int &v:g[u]){
            if(vis[v])continue;
            vis[v]=true;
            q.push(v);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%s",a[i]);
    }
    for(int x=0;x<n;++x){
        for(int y=0;y<m;++y){
            char c=a[x][y];
            int u=x*m+y;
            if(c=='S')s=u;
            if(c=='T')t=u;
            if(c=='#')continue;
            for(int d=0;d<4;++d){
                int i=x+dx[d],j=y+dy[d];
                if(!ok(c,d) || i<0 || i>=n || j<0 || j>=m)continue;
                if(a[i][j]=='#')continue;
                int v=i*m+j;
                g[u].push_back(v);
                h[v].push_back(u);
            }
        }
    }
    bfs(s,g,vis);
    if(!vis[t]){
        puts("I'm stuck!");
        return 0;
    }
    bfs(t,h,can);
    for(int u=0;u<n*m;++u){
        ans+=(vis[u] && !can[u]);
    }
    printf("%d\n",ans);
    return 0;
}
