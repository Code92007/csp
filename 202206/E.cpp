#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N=1<<19,M=3;
int n,q,op,l,r;
ld x[N],y[N];
struct mat{
    ld a[M][M];
    mat(){
        memset(a,0,sizeof a);
    }
};
mat unit(){
    mat a;
    for(int i=0;i<M;++i){
        a.a[i][i]=1;
    }
    return a;
}
mat operator*(const mat &a,const mat &b){
    mat c;
    for(int i=0;i<M;++i){
        for(int k=0;k<M;++k){
            for(int j=0;j<M;++j){
                c.a[i][j]+=a.a[i][k]*b.a[k][j];
            }
        }
    }
    return c;
}
struct info{
    ld cnt=0,x=0,y=0,xx=0,xy=0,yy=0;
};
info operator+(info a,info b){
    if(!a.cnt)return b;
    if(!b.cnt)return a;
    ld cnt=a.cnt+b.cnt,dx=b.x-a.x,dy=b.y-a.y;
    ld w=a.cnt*b.cnt/cnt;
    info c;
    c.cnt=cnt;
    c.x=a.x+dx*b.cnt/cnt;
    c.y=a.y+dy*b.cnt/cnt;
    c.xx=a.xx+b.xx+w*dx*dx;
    c.xy=a.xy+b.xy+w*dx*dy;
    c.yy=a.yy+b.yy+w*dy*dy;
    return c;
}
info trans(const info &s,const mat &t){
    ld a=t.a[0][0],b=t.a[0][1];
    ld c=t.a[1][0],d=t.a[1][1];
    info v;
    v.cnt=s.cnt;
    v.x=a*s.x+b*s.y+t.a[0][2];
    v.y=c*s.x+d*s.y+t.a[1][2];
    v.xx=a*a*s.xx+2*a*b*s.xy+b*b*s.yy;
    v.xy=a*c*s.xx+(a*d+b*c)*s.xy+b*d*s.yy;
    v.yy=c*c*s.xx+2*c*d*s.xy+d*d*s.yy;
    return v;
}
struct segtree{
    struct node{
        int l,r;
        info s;
        mat tag;
        bool ok;
    }e[N<<1];
    #define l(p) e[p].l
    #define r(p) e[p].r
    void pushup(int p){
        e[p].s=e[p<<1].s+e[p<<1|1].s;
    }
    void build(int p,int a,int b){
        l(p)=a;r(p)=b;
        e[p].tag=unit();
        if(a==b){
            e[p].s={1,x[a],y[a],0,0,0};
            return;
        }
        int mid=(a+b)>>1;
        build(p<<1,a,mid);
        build(p<<1|1,mid+1,b);
        pushup(p);
    }
    void change(int p,const mat &t){
        e[p].s=trans(e[p].s,t);
        e[p].tag=t*e[p].tag;
        e[p].ok=1;
    }
    void pushdown(int p){
        if(!e[p].ok)return;
        change(p<<1,e[p].tag);
        change(p<<1|1,e[p].tag);
        e[p].tag=unit();
        e[p].ok=0;
    }
    void update(int p,int a,int b,const mat &t){
        if(a<=l(p) && r(p)<=b){
            change(p,t);
            return;
        }
        pushdown(p);
        int mid=(l(p)+r(p))>>1;
        if(a<=mid)update(p<<1,a,b,t);
        if(b>mid)update(p<<1|1,a,b,t);
        pushup(p);
    }
    info query(int p,int a,int b){
        if(a<=l(p) && r(p)<=b)return e[p].s;
        pushdown(p);
        int mid=(l(p)+r(p))>>1;
        info ans;
        if(a<=mid)ans=ans+query(p<<1,a,b);
        if(b>mid)ans=ans+query(p<<1|1,a,b);
        return ans;
    }
}tr;
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i){
        scanf("%Lf%Lf",&x[i],&y[i]);
    }
    tr.build(1,1,n);
    while(q--){
        scanf("%d%d%d",&op,&l,&r);
        if(op>=6){
            info s=tr.query(1,l,r);
            if(op==6)printf("%.12Lf %.12Lf\n",s.x,s.y);
            else{
                ld a,b;
                scanf("%Lf%Lf",&a,&b);
                ld dx=s.x-a,dy=s.y-b;
                ld ans=s.xx+s.yy+s.cnt*(dx*dx+dy*dy);
                printf("%.12Lf\n",max(0.L,ans));
            }
            continue;
        }
        mat t=unit();
        ld a,b;
        if(op==1){
            scanf("%Lf%Lf",&a,&b);
            t.a[0][2]=a;
            t.a[1][2]=b;
        }
        else if(op==2 || op==3){
            ld x;
            scanf("%Lf%Lf%Lf",&a,&b,&x);
            if(op==2){
                ld c=cosl(x),s=sinl(x);
                t.a[0][0]=t.a[1][1]=c;
                t.a[0][1]=-s;
                t.a[1][0]=s;
            }
            else t.a[0][0]=t.a[1][1]=x;
            t.a[0][2]=a-t.a[0][0]*a-t.a[0][1]*b;
            t.a[1][2]=b-t.a[1][0]*a-t.a[1][1]*b;
        }
        else{
            ld angle,y,c,s;
            scanf("%Lf%Lf",&angle,&y);
            c=cosl(angle);s=sinl(angle);
            ld k=op==4?2:1,d=op==4?1:0;
            t.a[0][0]=k*c*c-d;
            t.a[0][1]=t.a[1][0]=k*c*s;
            t.a[1][1]=k*s*s-d;
            t.a[0][2]=-t.a[0][1]*y;
            t.a[1][2]=y-t.a[1][1]*y;
        }
        tr.update(1,l,r,t);
    }
    return 0;
}
