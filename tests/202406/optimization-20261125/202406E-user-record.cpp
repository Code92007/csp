#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=1<<20;
int n,m,t,cnt,v[N],id[N],ord[N],tmp[N],buf[N],ans[N],st[M];
bool ok[N];
struct rect{
    int xl,xr,yl,yr,v,rk;
}a[N];
struct query{
    int xl,xr,yl,yr;
}b[N];
struct segtree{
    int mx[M],tag[M];
    void add(int p,int l,int r,int x,int y,int w){
        if(tag[p]>=w)return;
        if(!mx[p])st[++cnt]=p;
        mx[p]=max(mx[p],w);
        if(x<=l && r<=y){
            tag[p]=w;
            return;
        }
        int mid=(l+r)>>1;
        if(x<=mid)add(p<<1,l,mid,x,y,w);
        if(y>mid)add(p<<1|1,mid+1,r,x,y,w);
    }
    bool ask(int p,int l,int r,int x,int y,int w){
        if(mx[p]<w)return 0;
        if(tag[p]>=w || (x<=l && r<=y))return 1;
        int mid=(l+r)>>1;
        if(x<=mid && ask(p<<1,l,mid,x,y,w))return 1;
        if(y>mid && ask(p<<1|1,mid+1,r,x,y,w))return 1;
        return 0;
    }
    void clear(){
        while(cnt){
            int p=st[cnt--];
            mx[p]=tag[p]=0;
        }
    }
}tr;
void solve(int l,int r,int xl,int xr,int ql,int qr){
    if(xl==xr || ql==qr)return;
    if(xr-xl==1){
        rect &p=a[id[xl]];
        for(int i=ql;i<qr;++i){
            int j=ord[i];
            query &q=b[j];
            if(p.xl<=q.xr && q.xl<=p.xr && p.yl<=q.yr && q.yl<=p.yr){
                ans[j]=p.v;
            }
        }
        return;
    }
    int mid=(l+r)>>1,at=xl;
    if(l<r){
        for(int i=xl;i<xr;++i){
            at+=(a[id[i]].rk<=mid);
        }
        int x=xl,y=at;
        for(int i=xl;i<xr;++i){
            int j=id[i];
            if(a[j].rk<=mid)tmp[x++]=j;
            else tmp[y++]=j;
        }
        copy(tmp+xl,tmp+xr,id+xl);
    }
    else at=xr;
    int p=xl,qt=ql;
    for(int i=ql;i<qr;++i){
        int j=ord[i];
        query &q=b[j];
        while(p<at && a[id[p]].xl<=q.xr){
            rect &x=a[id[p++]];
            tr.add(1,1,n,x.yl,x.yr,x.xr);
        }
        ok[j]=tr.ask(1,1,n,q.yl,q.yr,q.xl);
        qt+=ok[j];
    }
    tr.clear();
    if(l==r){
        for(int i=ql;i<qr;++i){
            int j=ord[i];
            if(ok[j])ans[j]=v[l];
        }
        return;
    }
    int x=ql,y=qt;
    for(int i=ql;i<qr;++i){
        int j=ord[i];
        if(ok[j])buf[x++]=j;
        else buf[y++]=j;
    }
    copy(buf+ql,buf+qr,ord+ql);
    solve(l,mid,xl,at,ql,qt);
    solve(mid+1,r,at,xr,qt,qr);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        rect &p=a[i];
        scanf("%d%d%d%d%d",&p.xl,&p.xr,&p.yl,&p.yr,&p.v);
        tmp[p.v]=1;
    }
    for(int i=n;i;--i){
        if(tmp[i]){
            v[++t]=i;
            tmp[i]=t;
        }
    }
    for(int i=1;i<=n;++i){
        a[i].rk=tmp[a[i].v];
    }
    for(int i=1;i<=m;++i){
        query &q=b[i];
        scanf("%d%d%d%d",&q.xl,&q.xr,&q.yl,&q.yr);
    }
    memset(tmp,0,sizeof tmp);
    for(int i=1;i<=n;++i){
        ++tmp[a[i].xl];
    }
    for(int i=1;i<=n;++i){
        tmp[i]+=tmp[i-1];
    }
    for(int i=n;i;--i){
        id[tmp[a[i].xl]--]=i;
    }
    memset(tmp,0,sizeof tmp);
    for(int i=1;i<=m;++i){
        ++tmp[b[i].xr];
    }
    for(int i=1;i<=n;++i){
        tmp[i]+=tmp[i-1];
    }
    for(int i=m;i;--i){
        ord[tmp[b[i].xr]--]=i;
    }
    solve(1,t,1,n+1,1,m+1);
    for(int i=1;i<=m;++i){
        printf("%d\n",ans[i]);
    }
    return 0;
}
