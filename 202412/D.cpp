#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,a[N],k[N],fa[N],dis[N],q[N];
int find(int x){
    while(x!=fa[x]){
        x=fa[x]=fa[fa[x]];
    }
    return x;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&k[i]);
    }
    for(int i=1;i<=n+1;++i){
        fa[i]=i;
    }
    memset(dis,-1,sizeof dis);
    dis[1]=0;
    int head=0,tail=1;
    q[0]=1;
    while(head<tail){
        int u=q[head++];
        int r=min((ll)n,u+(ll)k[u]);
        for(int j=find(u+1);j<=r;j=find(j)){
            int v=j-a[j];
            if(dis[v]==-1){
                dis[v]=dis[u]+1;
                q[tail++]=v;
            }
            fa[j]=find(j+1);
        }
    }
    printf("%d\n",dis[n]);
    return 0;
}
