#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=2,K=N*60;
int n,q,h,k,op,u,v,x,tot,rt[N],sz[N];
ll w,ans;
bool full;
struct node{
    int ch[M],cnt[M],dp;
}tr[K];
void pull(int u,int b){
    node &t=tr[u];
    int l=t.ch[0],r=t.ch[1];
    if(b>=h){
        t.dp=max(tr[l].dp,tr[r].dp);
    }
    else if(b>=0 && (k>>b&1)){
        t.dp=tr[l].dp+tr[r].dp;
    }
    else{
        t.dp=max({t.cnt[0],t.cnt[1],tr[l].dp,tr[r].dp});
    }
}
int insert(int u,int x,int s,int b){
    if(!u)u=++tot;
    ++tr[u].cnt[s];
    if(b>=0){
        int c=x>>b&1;
        int v=insert(tr[u].ch[c],x,s,b-1);
        tr[u].ch[c]=v;
    }
    pull(u,b);
    return u;
}
int merge(int u,int v,int b){
    if(!u || !v)return u|v;
    for(int i=0;i<2;++i){
        tr[u].cnt[i]+=tr[v].cnt[i];
    }
    if(b>=0){
        for(int i=0;i<2;++i){
            tr[u].ch[i]=merge(tr[u].ch[i],tr[v].ch[i],b-1);
        }
    }
    pull(u,b);
    return u;
}
void add(int u,int x){
    ++sz[u];
    if(full)return;
    int s=x>>h&1,low=x&((1<<h)-1);
    if(s)low^=k;
    int key=((x>>(h+1))<<h)|low;
    rt[u]=insert(rt[u],key,s,28);
}
int val(int u){
    return full?sz[u]:tr[rt[u]].dp;
}
int main(){
    scanf("%d%lld",&n,&w);
    full=w>=(1ll<<30);
    if(!full){
        while((1ll<<(h+1))<=w){
            ++h;
        }
        k=w-(1ll<<h);
    }
    for(int i=1;i<=n;++i){
        int m;
        scanf("%d",&m);
        while(m--){
            scanf("%d",&x);
            add(i,x);
        }
        ans+=val(i);
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&u,&x);
            ans-=val(u);
            add(u,x);
            ans+=val(u);
        }
        else if(op==2){
            scanf("%d%d",&u,&v);
            ans-=val(u)+val(v);
            sz[u]+=sz[v];
            sz[v]=0;
            if(!full)rt[u]=merge(rt[u],rt[v],28);
            rt[v]=0;
            ans+=val(u);
        }
        else{
            printf("%lld\n",ans);
        }
    }
    return 0;
}
