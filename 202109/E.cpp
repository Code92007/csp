#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10,M=20,K=2;
struct LCT{
    struct node{
        int ch[K],fa;
        ll v,sum,mul=1;
        bool rev;
    }e[N];
    int top,st[N];
    ll mod;
    void init(int p){
        mod=p;
    }
    bool root(int x){
        int p=e[x].fa;
        return e[p].ch[0]!=x && e[p].ch[1]!=x;
    }
    void pushup(int x){
        e[x].sum=(e[x].v+e[e[x].ch[0]].sum+e[e[x].ch[1]].sum)%mod;
    }
    void multiply(int x,ll v){
        if(!x)return;
        e[x].v=e[x].v*v%mod;
        e[x].sum=e[x].sum*v%mod;
        e[x].mul=e[x].mul*v%mod;
    }
    void flip(int x){
        if(!x)return;
        swap(e[x].ch[0],e[x].ch[1]);
        e[x].rev^=1;
    }
    void pushdown(int x){
        if(e[x].rev){
            flip(e[x].ch[0]);
            flip(e[x].ch[1]);
            e[x].rev=false;
        }
        if(e[x].mul!=1){
            multiply(e[x].ch[0],e[x].mul);
            multiply(e[x].ch[1],e[x].mul);
            e[x].mul=1;
        }
    }
    void rotate(int x){
        int p=e[x].fa,g=e[p].fa;
        int d=(e[p].ch[1]==x),v=e[x].ch[d^1];
        if(!root(p))e[g].ch[e[g].ch[1]==p]=x;
        e[x].fa=g;
        e[x].ch[d^1]=p;
        e[p].fa=x;
        e[p].ch[d]=v;
        if(v)e[v].fa=p;
        pushup(p);
        pushup(x);
    }
    void splay(int x){
        top=0;
        int y=x;
        st[++top]=y;
        while(!root(y)){
            y=e[y].fa;
            st[++top]=y;
        }
        for(int i=top;i;--i){
            pushdown(st[i]);
        }
        while(!root(x)){
            int p=e[x].fa,g=e[p].fa;
            if(!root(p)){
                bool same=(e[p].ch[1]==x)==(e[g].ch[1]==p);
                rotate(same?p:x);
            }
            rotate(x);
        }
    }
    void access(int x){
        for(int y=0,u=x;u;y=u,u=e[u].fa){
            splay(u);
            e[u].ch[1]=y;
            pushup(u);
        }
        splay(x);
    }
    void path(int u,int v){
        access(u);
        flip(u);
        access(v);
    }
}tr;
int m,p,t,now,tot,last,up[N][M],dep[N],tail[N];
int at(int u,int d){
    int k=dep[u]-d;
    for(int i=0;i<M;++i){
        if(k>>i&1)u=up[u][i];
    }
    return u;
}
int main(){
    scanf("%d%d%d",&m,&p,&t);
    tr.init(p);
    for(int day=1;day<=m;++day){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x;
            scanf("%d",&x);
            x^=t*last;
            if(!x)now=up[now][0];
            else{
                int u=++tot;
                up[u][0]=now;
                dep[u]=dep[now]+1;
                for(int i=1;i<M;++i){
                    up[u][i]=up[up[u][i-1]][i-1];
                }
                tr.e[u].v=tr.e[u].sum=x%p;
                tr.e[u].fa=now;
                now=u;
            }
        }
        else{
            int s,l,r;
            scanf("%d%d%d",&s,&l,&r);
            int end=s==day?now:tail[s];
            int u=at(end,l),v=at(end,r);
            tr.path(u,v);
            if(op==2){
                int y;
                scanf("%d",&y);
                y^=t*last;
                tr.multiply(v,y%p);
            }
            else{
                last=tr.e[v].sum;
                printf("%d\n",last);
            }
        }
        tail[day]=now;
    }
    return 0;
}
