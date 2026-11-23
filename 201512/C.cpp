#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=110,M=4;
const int dx[M]={1,-1,0,0},dy[M]={0,0,1,-1};
int n,m,k;
char a[N][N];
bool vis[N][N];
bool wall(char c){
    return c=='-' || c=='|' || c=='+';
}
int main(){
    scanf("%d%d%d",&m,&n,&k);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            a[i][j]='.';
        }
    }
    while(k--){
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(!op){
            int u,v;
            scanf("%d%d",&u,&v);
            bool row=(y==v);
            if(x>u)swap(x,u);
            if(y>v)swap(y,v);
            for(int i=y;i<=v;++i){
                for(int j=x;j<=u;++j){
                    char &c=a[i][j];
                    if(c=='+' || (row?c=='|':c=='-'))c='+';
                    else c=row?'-':'|';
                }
            }
        }
        else{
            char c;
            scanf(" %c",&c);
            memset(vis,0,sizeof vis);
            queue<P> q;
            q.push({x,y});
            vis[y][x]=true;
            while(!q.empty()){
                auto [u,v]=q.front();
                q.pop();
                a[v][u]=c;
                for(int i=0;i<M;++i){
                    int x=u+dx[i],y=v+dy[i];
                    if(x<0 || x>=m || y<0 || y>=n)continue;
                    if(vis[y][x] || wall(a[y][x]))continue;
                    vis[y][x]=true;
                    q.push({x,y});
                }
            }
        }
    }
    for(int y=n-1;y>=0;--y){
        puts(a[y]);
    }
    return 0;
}
