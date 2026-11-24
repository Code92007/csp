#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=1<<20,H=2,K=1<<16;
int n,m,t,cnt,v[N],tmp[N],ans[N],st[M];
bool ok[N];
int cur,len;
char str[K];
int gc(){
    if(cur==len){
        len=fread(str,1,K,stdin);
        cur=0;
        if(!len)return EOF;
    }
    return str[cur++];
}
int read(){
    int x=0,c=gc();
    while(c<'0' || c>'9'){
        if(c==EOF)return 0;
        c=gc();
    }
    while(c>='0' && c<='9'){
        x=x*10+c-'0';
        c=gc();
    }
    return x;
}
struct rect{
    int xl,xr,yl,yr,rk;
}a[H][N];
struct query{
    int xl,xr,yl,yr,id;
}b[H][N];
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
void solve(int l,int r,int xl,int xr,int ql,int qr,int d){
    if(xl==xr || ql==qr)return;
    rect *p=a[d],*s=a[d^1];
    query *q=b[d],*z=b[d^1];
    if(xr-xl==1){
        rect &x=p[xl];
        for(int i=ql;i<qr;++i){
            query &w=q[i];
            if(x.xl<=w.xr && w.xl<=x.xr && x.yl<=w.yr && w.yl<=x.yr){
                ans[w.id]=v[x.rk];
            }
        }
        return;
    }
    int mid=(l+r)>>1,at=xl;
    if(l<r){
        for(int i=xl;i<xr;++i){
            at+=(p[i].rk<=mid);
        }
        int x=xl,y=at;
        for(int i=xl;i<xr;++i){
            if(p[i].rk<=mid)s[x++]=p[i];
            else s[y++]=p[i];
        }
    }
    else at=xr,s=p;
    int k=xl,qt=ql;
    for(int i=ql;i<qr;++i){
        query &w=q[i];
        while(k<at && s[k].xl<=w.xr){
            rect &x=s[k++];
            tr.add(1,1,n,x.yl,x.yr,x.xr);
        }
        ok[i]=tr.ask(1,1,n,w.yl,w.yr,w.xl);
        qt+=ok[i];
    }
    tr.clear();
    if(l==r){
        for(int i=ql;i<qr;++i){
            if(ok[i])ans[q[i].id]=v[l];
        }
        return;
    }
    int x=ql,y=qt;
    for(int i=ql;i<qr;++i){
        if(ok[i])z[x++]=q[i];
        else z[y++]=q[i];
    }
    solve(l,mid,xl,at,ql,qt,d^1);
    solve(mid+1,r,at,xr,qt,qr,d^1);
}
int main(){
    n=read();m=read();
    for(int i=1;i<=n;++i){
        rect &p=a[0][i];
        p.xl=read();p.xr=read();
        p.yl=read();p.yr=read();
        p.rk=read();
        tmp[p.rk]=1;
    }
    for(int i=n;i;--i){
        if(tmp[i]){
            v[++t]=i;
            tmp[i]=t;
        }
    }
    for(int i=1;i<=n;++i){
        a[0][i].rk=tmp[a[0][i].rk];
    }
    for(int i=1;i<=m;++i){
        query &q=b[0][i];
        q.xl=read();q.xr=read();
        q.yl=read();q.yr=read();
        q.id=i;
    }
    memset(tmp,0,sizeof tmp);
    for(int i=1;i<=n;++i){
        ++tmp[a[0][i].xl];
    }
    for(int i=1;i<=n;++i){
        tmp[i]+=tmp[i-1];
    }
    for(int i=n;i;--i){
        a[1][tmp[a[0][i].xl]--]=a[0][i];
    }
    memset(tmp,0,sizeof tmp);
    for(int i=1;i<=m;++i){
        ++tmp[b[0][i].xr];
    }
    for(int i=1;i<=n;++i){
        tmp[i]+=tmp[i-1];
    }
    for(int i=m;i;--i){
        b[1][tmp[b[0][i].xr]--]=b[0][i];
    }
    solve(1,t,1,n+1,1,m+1,1);
    for(int i=1;i<=m;++i){
        printf("%d\n",ans[i]);
    }
    return 0;
}