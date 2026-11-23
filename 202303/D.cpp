#include<bits/stdc++.h>
using namespace std;
const int N=200,INF=0x3f3f3f3f;
struct info{
    int mn=0,mx=0,pos=INF;
};
info merge(info a,info b){
    return {min(a.mn,b.mn),max(a.mx,b.mx),min(a.pos,b.pos)};
}
struct segtree{
    int n;
    struct node{
        int l,r,tag=-1;
        info v;
    };
    vector<node> e;
    #define l(p) e[p].l
    #define r(p) e[p].r
    void build(int p,int x,int y){
        l(p)=x;r(p)=y;
        if(x==y)return;
        int mid=(x+y)>>1;
        build(p<<1,x,mid);
        build(p<<1|1,mid+1,y);
    }
    void init(int k){
        n=k;
        e.resize(n*4+4);
        build(1,0,n-1);
    }
    void set(int p,int v){
        e[p].v={v,v,v?v:INF};
        e[p].tag=v;
    }
    void pushup(int p){
        e[p].v=merge(e[p<<1].v,e[p<<1|1].v);
    }
    void pushdown(int p){
        if(e[p].tag==-1)return;
        set(p<<1,e[p].tag);
        set(p<<1|1,e[p].tag);
        e[p].tag=-1;
    }
    info query(int p,int x,int y){
        if(x<=l(p) && r(p)<=y)return e[p].v;
        pushdown(p);
        int mid=(l(p)+r(p))>>1;
        if(y<=mid)return query(p<<1,x,y);
        if(x>mid)return query(p<<1|1,x,y);
        return merge(query(p<<1,x,y),query(p<<1|1,x,y));
    }
    void update(int p,int x,int y,int v){
        if(x<=l(p) && r(p)<=y){
            set(p,v);
            return;
        }
        pushdown(p);
        int mid=(l(p)+r(p))>>1;
        if(x<=mid)update(p<<1,x,y,v);
        if(y>mid)update(p<<1|1,x,y,v);
        pushup(p);
    }
}tr;
struct operation{
    int type,id;
    string l,r;
};
int bits,q;
char s[N];
vector<operation> ops;
vector<string> a;
string read(){
    scanf("%s",s);
    string str=s;
    str.erase(remove(str.begin(),str.end(),':'),str.end());
    return '0'+str;
}
string next(string str){
    const string digit="0123456789abcdef";
    for(int i=str.size()-1;i>=0;--i){
        if(str[i]=='f')str[i]='0';
        else{
            str[i]=digit[digit.find(str[i])+1];
            break;
        }
    }
    return str;
}
int main(){
    scanf("%d%d",&bits,&q);
    ops.resize(q);
    for(operation &op:ops){
        scanf("%d",&op.type);
        if(op.type==1)scanf("%d",&op.id);
        op.l=read();
        op.r=next(op.type==2?op.l:read());
        a.push_back(op.l);
        a.push_back(op.r);
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    tr.init(a.size()-1);
    for(operation &op:ops){
        int x=lower_bound(a.begin(),a.end(),op.l)-a.begin();
        int y=lower_bound(a.begin(),a.end(),op.r)-a.begin()-1;
        info v=tr.query(1,x,y);
        if(op.type==1){
            bool ok=v.mn==0 && (v.mx==0 || (v.mx==op.id && v.pos==op.id));
            puts(ok?"YES":"NO");
            if(ok)tr.update(1,x,y,op.id);
        }
        else printf("%d\n",v.mn==v.mx?v.mn:0);
    }
    return 0;
}
