#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
struct info{
    int mn,mx,lo,hi;
};
info merge(info a,info b){
    return {min(a.mn,b.mn),max(a.mx,b.mx),
            min(a.lo,b.lo),max(a.hi,b.hi)};
}
struct query{
    int op,id,l,r,x;
};
int n,m,k;
vector<query> q;
vector<int> v;
struct segtree{
    struct node{
        int l,r,tag,val;
        info s;
        bool own,mark;
    };
    vector<node> e;
    #define l(p) e[p].l
    #define r(p) e[p].r
    void build(int p,int x,int y){
        l(p)=x;r(p)=y;
        e[p].s={0,0,INF,0};
        if(x==y)return;
        int mid=(x+y)/2;
        build(p*2,x,mid);
        build(p*2+1,mid+1,y);
    }
    void owner(int p,int id){
        e[p].s={id,id,id>0?id:INF,id>0?id:0};
        e[p].tag=id;
        e[p].own=true;
    }
    void op(int p,int x){
        e[p].val=x;
        e[p].mark=true;
    }
    void pushup(int p){
        e[p].s=merge(e[p*2].s,e[p*2+1].s);
    }
    void pushdown(int p){
        if(e[p].own){
            owner(p*2,e[p].tag);
            owner(p*2+1,e[p].tag);
            e[p].own=false;
        }
        if(e[p].mark){
            op(p*2,e[p].val);
            op(p*2+1,e[p].val);
            e[p].mark=false;
        }
    }
    info query(int p,int x,int y){
        if(x<=l(p) && r(p)<=y)return e[p].s;
        pushdown(p);
        int mid=(l(p)+r(p))/2;
        if(y<=mid)return query(p*2,x,y);
        if(x>mid)return query(p*2+1,x,y);
        return merge(query(p*2,x,y),query(p*2+1,x,y));
    }
    int find(int p,int x,int y,int id){
        auto &s=e[p].s;
        if(r(p)<x || l(p)>y || !s.hi)return -1;
        if(s.lo==id && s.hi==id)return -1;
        if(l(p)==r(p))return l(p);
        pushdown(p);
        int u=find(p*2,x,y,id);
        return u!=-1?u:find(p*2+1,x,y,id);
    }
    void update(int p,int x,int y,int id,bool write,int val){
        if(x<=l(p) && r(p)<=y){
            owner(p,id);
            if(write)op(p,val);
            return;
        }
        pushdown(p);
        int mid=(l(p)+r(p))/2;
        if(x<=mid)update(p*2,x,y,id,write,val);
        if(y>mid)update(p*2+1,x,y,id,write,val);
        pushup(p);
    }
    P read(int p,int x){
        if(l(p)==r(p)){
            int id=e[p].s.mn;
            return id>0?P(id,e[p].val):P(0,0);
        }
        pushdown(p);
        int mid=(l(p)+r(p))/2;
        return x<=mid?read(p*2,x):read(p*2+1,x);
    }
}tr;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    q.resize(k);
    v.push_back(1);
    v.push_back(m+1);
    for(auto &e:q){
        scanf("%d",&e.op);
        if(e.op==3){
            scanf("%d",&e.l);
            e.r=e.l;
        }
        else{
            scanf("%d%d%d",&e.id,&e.l,&e.r);
            if(!e.op)scanf("%d",&e.x);
        }
        v.push_back(e.l);
        v.push_back(e.r+1);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int len=v.size()-1;
    tr.e.resize(len*4+4);
    tr.build(1,0,len-1);
    for(auto &e:q){
        int l=lower_bound(v.begin(),v.end(),e.l)-v.begin();
        int r=lower_bound(v.begin(),v.end(),e.r+1)-v.begin()-1;
        if(e.op==3){
            auto [id,val]=tr.read(1,l);
            printf("%d %d\n",id,val);
        }
        else if(!e.op){
            int pos=tr.find(1,l,r,e.id);
            int end=pos==-1?r:pos-1;
            if(end<l)puts("-1");
            else{
                tr.update(1,l,end,e.id,true,e.x);
                printf("%d\n",v[end+1]-1);
            }
        }
        else{
            info s=tr.query(1,l,r);
            int id=e.op==1?e.id:-e.id;
            bool ok=(s.mn==id && s.mx==id);
            puts(ok?"OK":"FAIL");
            if(ok)tr.update(1,l,r,-id,false,0);
        }
    }
    return 0;
}
