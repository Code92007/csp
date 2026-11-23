#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2010;
struct node{
    int x,l,r;
}e[N<<1];
int n,m,tot,tim,in[N],out[N];
ll w[N];
vector<int> g[N];
void dfs(int u){
    in[u]=tim++;
    for(int &v:g[u]){
        dfs(v);
    }
    out[u]=tim;
}
bool anc(int t,int x){
    return in[x]<=in[t] && in[t]<out[x];
}
int build(const vector<int> &v){
    int p=++tot;
    if(v.size()==1)return p;
    vector<ll> sum(n+1);
    for(const int &u:v){
        sum[in[u]+1]=w[u];
    }
    for(int i=1;i<=n;++i){
        sum[i]+=sum[i-1];
    }
    ll best=-1;
    int x=0;
    for(const int &u:v){
        ll d=abs(sum[n]-2*(sum[out[u]]-sum[in[u]]));
        if(best==-1 || d<best || (d==best && u<x)){
            best=d;
            x=u;
        }
    }
    vector<int> a,b;
    for(const int &u:v){
        if(anc(u,x))a.push_back(u);
        else b.push_back(u);
    }
    e[p].x=x;
    e[p].l=build(a);
    e[p].r=build(b);
    return p;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&w[i]);
    }
    for(int i=2;i<=n;++i){
        int p;
        scanf("%d",&p);
        g[p].push_back(i);
    }
    dfs(1);
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    int root=build(v);
    while(m--){
        int t,u=root;
        scanf("%d",&t);
        bool first=true;
        while(e[u].x){
            int x=e[u].x;
            if(!first)putchar(' ');
            first=false;
            printf("%d",x);
            bool yes=anc(t,x);
            u=yes?e[u].l:e[u].r;
        }
        putchar('\n');
    }
    return 0;
}
