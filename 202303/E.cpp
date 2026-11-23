#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
struct range{
    int n,val;
    bool mn;
    vector<int> tr;
    void init(int k,bool flag){
        n=k;
        mn=flag;
        val=mn?INF:-INF;
        tr.assign(n*2,val);
    }
    int merge(int a,int b){
        return mn?min(a,b):max(a,b);
    }
    void add(int x,int v){
        x+=n;
        tr[x]=merge(tr[x],v);
        for(x>>=1;x;x>>=1){
            tr[x]=merge(tr[x<<1],tr[x<<1|1]);
        }
    }
    int query(int l,int r){
        if(l>r)return val;
        int ans=val;
        for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
            if(l&1)ans=merge(ans,tr[l++]);
            if(r&1)ans=merge(ans,tr[--r]);
        }
        return ans;
    }
};
struct BIT{
    int n;
    vector<int> tr;
    void init(int k){
        n=k;
        tr.assign(n+1,0);
    }
    void add(int x){
        for(;x<=n;x+=x&-x){
            ++tr[x];
        }
    }
    int sum(int x){
        int ans=0;
        for(;x>0;x-=x&-x){
            ans+=tr[x];
        }
        return ans;
    }
};
int n,m;
ll solve(int l,int r,vector<P> v){
    if(l==r || v.empty())return 0;
    int mid=(l+r)>>1,len=r-l+1;
    vector<P> a,b,c;
    vector<int> far(len),near(len);
    for(int i=l;i<=r;++i){
        far[i-l]=i-1;
        near[i-l]=i+1;
    }
    for(auto &[x,y]:v){
        if(y<=mid){
            a.push_back({x,y});
            far[x-l]=max(far[x-l],y);
        }
        else if(x>mid){
            b.push_back({x,y});
            near[y-l]=min(near[y-l],x);
        }
        else c.push_back({x,y});
    }
    vector<int> right(mid-l+1),left(r-mid);
    range reach,ends;
    reach.init(len,false);
    ends.init(len,true);
    for(auto &[x,y]:c){
        ends.add(x-l,y);
    }
    for(int i=mid;i>=l;--i){
        int x=far[i-l];
        x=max(x,reach.query(i+1-l,min(mid,x+1)-l));
        reach.add(i-l,x);
        int y=ends.query(i-l,min(mid,x+1)-l);
        if(x==mid)y=min(y,mid+1);
        right[i-l]=y;
    }
    reach.init(len,true);
    ends.init(len,false);
    for(auto &[x,y]:c){
        ends.add(y-l,x);
    }
    for(int i=mid+1;i<=r;++i){
        int x=near[i-l];
        x=min(x,reach.query(max(mid+1,x-1)-l,i-1-l));
        reach.add(i-l,x);
        int y=ends.query(max(mid+1,x-1)-l,i-l);
        if(x==mid+1)y=max(y,mid);
        left[i-mid-1]=y;
    }
    vector<P> events;
    for(int i=l;i<=mid;++i){
        events.push_back({right[i-l],i});
    }
    sort(events.begin(),events.end());
    BIT bit;
    bit.init(mid-l+1);
    size_t p=0;
    ll ans=0;
    for(int i=mid+1;i<=r;++i){
        while(p<events.size() && events[p].first<=i){
            bit.add(events[p++].second-l+1);
        }
        int x=min(mid,left[i-mid-1]);
        ans+=bit.sum(x-l+1);
    }
    ans+=solve(l,mid,std::move(a));
    ans+=solve(mid+1,r,std::move(b));
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    vector<P> v(m);
    for(auto &[l,r]:v){
        scanf("%d%d",&l,&r);
    }
    printf("%lld\n",solve(1,n,std::move(v)));
    return 0;
}
