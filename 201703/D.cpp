#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
};
int n,m;
vector<edge> e;
vector<int> fa,sz;
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
    scanf("%d%d",&n,&m);
    e.resize(m);
    for(edge &v:e){
        scanf("%d%d%d",&v.u,&v.v,&v.w);
    }
    sort(e.begin(),e.end(),[&](const edge &a,const edge &b){
        return a.w<b.w;
    });
    fa.resize(n+1);
    sz.assign(n+1,1);
    iota(fa.begin(),fa.end(),0);
    if(n==1){
        puts("0");
        return 0;
    }
    for(edge &v:e){
        int x=find(v.u),y=find(v.v);
        if(x!=y){
            if(sz[x]<sz[y])swap(x,y);
            fa[y]=x;
            sz[x]+=sz[y];
        }
        if(find(1)==find(n)){
            printf("%d\n",v.w);
            break;
        }
    }
    return 0;
}
