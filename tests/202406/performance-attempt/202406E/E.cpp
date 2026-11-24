#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1<<19,M=3,K=(N<<1)+1,INF=0x3f3f3f3f;
int n,m,b=1,h;
bool rev;
struct rect{
    int xl,xr,yl,yr,v;
};
rect a[N];
int ord[N],st[K],pos[K];
int x[N<<1],y[N<<1],fa[N<<1];
vector<int>pool;
struct env{
    int off=0,n=0;
    int x(int i)const{
        return pool[off+i];
    }
    int val(int i)const{
        return pool[off+2*n+i];
    }
    int top()const{
        return n?pool[off+n+1]:0;
    }
    int query(int l,int r)const{
        if(!n || r<x(0) || l>=x(n-1))return 0;
        if(l<=x(0) && r>=x(n-1))return top();
        auto it=pool.begin()+off;
        if(l==r){
            int p=upper_bound(it,it+n,l)-it-1;
            return val(p);
        }
        int a=max(0,(int)(upper_bound(it,it+n,l)-it)-1);
        int b=upper_bound(it,it+n,r)-it;
        int ans=0,pos=off+n;
        for(a+=n,b+=n;a<b;a>>=1,b>>=1){
            if(a&1){
                ans=max(ans,pool[pos+a]);
                a++;
            }
            if(b&1){
                b--;
                ans=max(ans,pool[pos+b]);
            }
        }
        return ans;
    }
};
env save(int n){
    int off=pool.size();
    if(!n)return env();
    pool.resize(off+3*n);
    copy(x,x+n,pool.begin()+off);
    copy(y,y+n,pool.begin()+off+2*n);
    int p=off+n;
    for(int i=n-1;i;--i){
        pool[p+i]=max(pool[p+2*i],pool[p+2*i+1]);
    }
    return {off,n};
}
int find(int x){
    while(fa[x]!=x){
        fa[x]=fa[fa[x]];
        x=fa[x];
    }
    return x;
}
env build(const vector<int> &id,int l,int r){
    if(l==r)return env();
    if(r-l==1){
        rect &v=a[id[l]];
        x[0]=v.yl;x[1]=v.yr+1;
        y[0]=v.v;y[1]=0;
        return save(2);
    }
    int cnt=0;
    for(int i=l;i<r;++i){
        rect &v=a[id[i]];
        x[cnt]=v.yl;x[cnt+1]=v.yr+1;
        cnt+=2;
    }
    sort(x,x+cnt);
    cnt=unique(x,x+cnt)-x;
    iota(fa,fa+cnt+1,0);
    memset(y,0,cnt*sizeof *y);
    for(int i=l;i<r;++i){
        rect &p=a[id[i]];
        int l=lower_bound(x,x+cnt,p.yl)-x;
        int r=lower_bound(x,x+cnt,p.yr+1)-x;
        for(int j=find(l);j<r;j=find(j)){
            y[j]=p.v;
            fa[j]=find(j+1);
        }
    }
    int n=0,pre=0;
    for(int i=0;i<cnt;++i){
        if(y[i]!=pre){
            pre=y[i];
            x[n]=x[i];y[n++]=pre;
        }
    }
    return save(n);
}
env merge(env a,env b,env c){
    env v[M];
    v[0]=a,v[1]=b,v[2]=c;
    int cnt=0,id=0;
    for(int i=0;i<M;++i){
        if(v[i].n){
            ++cnt;
            id=i;
        }
    }
    if(!cnt)return env();
    if(cnt==1)return v[id];
    int at[M],cur[M];
    memset(at,0,sizeof at);
    memset(cur,0,sizeof cur);
    int pre=0;
    int n=0;
    while(1){
        int p=INF;
        for(int i=0;i<M;++i){
            if(at[i]<v[i].n)p=min(p,v[i].x(at[i]));
        }
        if(p==INF)break;
        for(int i=0;i<M;++i){
            if(at[i]<v[i].n && v[i].x(at[i])==p){
                cur[i]=v[i].val(at[i]++);
            }
        }
        int val=max({cur[0],cur[1],cur[2]});
        if(val!=pre){
            x[n]=p;y[n]=val;
            ++n;
            pre=val;
        }
    }
    for(env &old:v){
        if(old.n!=n)continue;
        bool ok=1;
        for(int i=0;i<old.n && ok;++i){
            ok=(old.x(i)==x[i] && old.val(i)==y[i]);
        }
        if(ok)return old;
    }
    return save(n);
}
struct segtree{
    struct node{
        int l,r;
        env cover,all;
    }e[N<<1];
    #define l(p) e[p].l
    #define r(p) e[p].r
    void init(int p,int x,int y){
        l(p)=x;r(p)=y;
        if(x==y)return;
        int mid=(x+y)>>1;
        init(p<<1,x,mid);
        init(p<<1|1,mid+1,y);
    }
    int query(int p,int a,int b,int c,int d,int ans){
        if(e[p].all.top()<=ans)return ans;
        if(a<=l(p) && r(p)<=b){
            return max(ans,e[p].all.query(c,d));
        }
        if(e[p].cover.top()>ans){
            ans=max(ans,e[p].cover.query(c,d));
        }
        int mid=(l(p)+r(p))>>1;
        bool x=a<=mid,y=b>mid;
        if(x && y){
            if(e[p<<1].all.top()>=e[p<<1|1].all.top()){
                ans=query(p<<1,a,b,c,d,ans);
                ans=query(p<<1|1,a,b,c,d,ans);
            }
            else{
                ans=query(p<<1|1,a,b,c,d,ans);
                ans=query(p<<1,a,b,c,d,ans);
            }
        }
        else if(x)ans=query(p<<1,a,b,c,d,ans);
        else ans=query(p<<1|1,a,b,c,d,ans);
        return ans;
    }
}tr;
int count(int x,int y){
    int ans=0;
    for(int l=x+b-1,r=y+b;l<r;l>>=1,r>>=1){
        if(l&1)++ans,++l;
        if(r&1)++ans,--r;
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    while(b<n){
        b<<=1;
        ++h;
    }
    tr.init(1,1,b);
    iota(ord,ord+n,0);
    ll x=0,y=0;
    for(int i=0;i<n;++i){
        rect &p=a[i];
        scanf("%d%d%d%d%d",&p.xl,&p.xr,&p.yl,&p.yr,&p.v);
        x+=count(p.xl,p.xr);
        y+=count(p.yl,p.yr);
    }
    rev=y<x;
    for(int i=0;i<n;++i){
        rect &p=a[i];
        if(rev){
            swap(p.xl,p.yl);
            swap(p.xr,p.yr);
        }
        for(int l=p.xl+b-1,r=p.xr+b;l<r;l>>=1,r>>=1){
            if(l&1){
                ++st[l+1];
                ++l;
            }
            if(r&1){
                --r;
                ++st[r+1];
            }
        }
    }
    for(int i=1;i<=2*b;++i){
        st[i]+=st[i-1];
    }
    vector<int>id(st[2*b]);
    copy(st,st+2*b+1,pos);
    sort(ord,ord+n,[](int x,int y){
        return a[x].v>a[y].v;
    });
    for(int j=0;j<n;++j){
        int i=ord[j];
        rect &p=a[i];
        for(int l=p.xl+b-1,r=p.xr+b;l<r;l>>=1,r>>=1){
            if(l&1){
                id[pos[l]++]=i;
                ++l;
            }
            if(r&1){
                --r;
                id[pos[r]++]=i;
            }
        }
    }
    pool.reserve(size_t(6)*n*(h+1));
    for(int i=2*b-1;i;--i){
        tr.e[i].cover=build(id,st[i],st[i+1]);
        if(i>=b)tr.e[i].all=tr.e[i].cover;
        else{
            tr.e[i].all=merge(tr.e[i].cover,tr.e[i<<1].all,tr.e[i<<1|1].all);
        }
    }
    vector<int>().swap(id);
    while(m--){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(rev){
            swap(a,c);
            swap(b,d);
        }
        printf("%d\n",tr.query(1,a,b,c,d,0));
    }
    return 0;
}
