#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uint64_t ull;
const int B=1024;
struct node{
    int id,low,high;
};
struct counter{
    int n,k1,k2;
    int m;
    vector<int>bit;
    vector<ull>vis,full;
    vector<int>pre;
    vector<node>a,b,tmp;
    void radix(vector<node> &v,bool high){
        if(v.size()<2048){
            if(high){
                sort(v.begin(),v.end(),[](const node &x,const node &y){
                    return x.high<y.high;
                });
            }
            else{
                sort(v.begin(),v.end(),[](const node &x,const node &y){
                    return x.id<y.id;
                });
            }
            return;
        }
        tmp.resize(v.size());
        for(int b:{0,10}){
            array<int,B>cnt;
            cnt.fill(0);
            for(const node &x:v){
                ++cnt[((high?x.high:x.id)>>b)&1023];
            }
            int sum=0;
            for(int &val:cnt){
                int sz=val;
                val=sum;
                sum+=sz;
            }
            for(const node &x:v){
                tmp[cnt[((high?x.high:x.id)>>b)&1023]++]=x;
            }
            v.swap(tmp);
        }
    }
    ll sweep(){
        if(a.empty() || b.empty())return 0;
        ll ans=0;
        if(min(a.size(),b.size())<=24){
            for(const node &x:a){
                for(const node &y:b){
                    if(x.id<y.id && x.high<=y.id+k2 && x.id<=y.low+k1)++ans;
                }
            }
            return ans;
        }
        int mx=0,mn=n+1;
        for(const node &x:a){
            mx=max(mx,x.high);
            mn=min(mn,x.high);
        }
        int cnt=0;
        for(const node &y:b){
            cnt+=(y.id+k2>=mx);
        }
        if(cnt>=max(32,m/8)){
            for(const node &x:a){
                full[(x.id-1)>>6]|=ull(1)<<((x.id-1)&63);
            }
            pre[0]=0;
            for(int i=0;i<m;++i){
                pre[i+1]=pre[i]+__builtin_popcountll(full[i]);
            }
            size_t len=0;
            int lim=0;
            for(const node &y:b){
                if(y.id+k2>=mx){
                    int lim=min(y.id-1,y.low+k1);
                    int idx=lim>>6;
                    ull S=(ull(1)<<(lim&63))-1;
                    ans+=pre[idx]+__builtin_popcountll(full[idx]&S);
                }
                else{
                    b[len++]=y;
                    lim=max(lim,y.id+k2);
                }
            }
            b.resize(len);
            for(const node &x:a){
                full[(x.id-1)>>6]=0;
            }
            if(b.empty())return ans;
            len=0;
            mn=n+1;
            mx=0;
            for(const node &x:a){
                if(x.high<=lim){
                    a[len++]=x;
                    mn=min(mn,x.high);
                    mx=max(mx,x.high);
                }
            }
            a.resize(len);
            if(a.empty())return ans;
            if(min(a.size(),b.size())<=24){
                for(const node &x:a){
                    for(const node &y:b){
                        if(x.id<y.id && x.high<=y.id+k2 && x.id<=y.low+k1)++ans;
                    }
                }
                return ans;
            }
        }
        if(mn!=mx)radix(a,true);
        radix(b,false);
        size_t num=0;
        int last=-1,done=-1,res=0;
        for(const node &y:b){
            int lim=min(y.id-1,y.low+k1);
            int full=lim>>6,rem=lim&63;
            while(num<a.size() && a[num].high<=y.id+k2){
                int lab=a[num++].id-1;
                int idx=lab>>6;
                vis[idx]|=ull(1)<<(lab&63);
                for(int x=idx+1;x<=m;x+=x&-x){
                    ++bit[x];
                }
            }
            if(last!=lim || done!=int(num)){
                res=__builtin_popcountll(vis[full]&((ull(1)<<rem)-1));
                for(int x=full;x>0;x-=x&-x){
                    res+=bit[x];
                }
                last=lim;
                done=int(num);
            }
            ans+=res;
        }
        for(size_t i=0;i<num;++i){
            int idx=(a[i].id-1)>>6;
            if(!vis[idx])continue;
            vis[idx]=0;
            for(int x=idx+1;x<=m && bit[x];x+=x&-x){
                bit[x]=0;
            }
        }
        return ans;
    }
    counter(int x,int y,int z):n(x),k1(y),k2(z),
        m((n+63)/64),bit(m+1),vis(m+1),
        full(m+1),pre(m+1){
        a.reserve(n);
        b.reserve(n);
        tmp.reserve(n);
    }
    ll calc(const node*v,int sz){
        if(sz<2)return 0;
        a.clear();
        b.clear();
        for(int i=0;i<sz;++i){
            node x=v[i];
            if(x.low>=x.id-k1)a.push_back(x);
            if(x.high<=x.id+k2)b.push_back(x);
        }
        return sweep();
    }
    ll cross(const node*left,int nl,const node*right,int nr){
        a.clear();
        b.clear();
        for(int i=0;i<nl;++i){
            if(left[i].low>=left[i].id-k1)a.push_back(left[i]);
        }
        for(int i=0;i<nr;++i){
            if(right[i].high<=right[i].id+k2)b.push_back(right[i]);
        }
        return sweep();
    }
    ll both(const node*left,int nl,const node*right,int nr){
        return cross(left,nl,right,nr)+cross(right,nr,left,nl);
    }
};
int n,k1,k2;
vector<int>head,g,lab;
void build(){
    head.resize(n+2);
    g.resize(2*(n-1));
    vector<pair<int,int>>edges(n-1);
    for(auto &e:edges){
        scanf("%d%d",&e.first,&e.second);
        ++head[e.first];
        ++head[e.second];
    }
    int tot=0;
    for(int i=1;i<=n+1;++i){
        int degree=head[i];
        head[i]=tot;
        tot+=degree;
    }
    vector<int>cur=head;
    for(const auto &e:edges){
        g[cur[e.first]++]=e.second;
        g[cur[e.second]++]=e.first;
    }
}
void relabel(){
    lab.resize(n+1);
    vector<int>id(n+1),st{1};
    id[1]=-1;
    int tot=0;
    while(!st.empty()){
        int u=st.back();
        st.pop_back();
        id[u]=++tot;
        lab[tot]=u;
        for(int e=head[u];e<head[u+1];++e){
            int v=g[e];
            if(!id[v]){
                id[v]=-1;
                st.push_back(v);
            }
        }
    }
    vector<int>nh(n+2),ng(g.size());
    int cnt=0;
    for(int u=1;u<=n;++u){
        nh[u]=cnt;
        for(int e=head[lab[u]];e<head[lab[u]+1];++e){
            ng[cnt++]=id[g[e]];
        }
    }
    nh[n+1]=cnt;
    head.swap(nh);
    g.swap(ng);
}
int main(){
    scanf("%d%d%d",&n,&k1,&k2);
    build();
    if(k1>=n-1 && k2>=n-1){
        printf("%lld\n",1LL*n*(n+1)/2);
        return 0;
    }
    relabel();
    counter c(n,k1,k2);
    vector<int>fa(n+1),sz(n+1),big(n+1),ord,q{1};
    vector<unsigned char>del(n+1);
    vector<node>all;
    vector<pair<int,int>>br;
    ord.reserve(n);
    all.reserve(n);
    q.reserve(n);
    ll ans=n;
    while(!q.empty()){
        int start=q.back();
        q.pop_back();
        ord.clear();
        ord.push_back(start);
        fa[start]=0;
        int lo=n+1,hi=0;
        for(size_t i=0;i<ord.size();++i){
            int u=ord[i];
            lo=min(lo,lab[u]);
            hi=max(hi,lab[u]);
            sz[u]=1;
            big[u]=0;
            for(int e=head[u];e<head[u+1];++e){
                int v=g[e];
                if(!del[v] && v!=fa[u]){
                    fa[v]=u;
                    ord.push_back(v);
                }
            }
        }
        int sum=int(ord.size()),rt=start;
        if(min(k1,k2)>=hi-lo-1){
            ans+=1LL*sum*(sum-1)/2;
            continue;
        }
        for(int i=sum-1;i>=0;--i){
            int u=ord[i],p=fa[u];
            if(max(big[u],sum-sz[u])<=sum/2)rt=u;
            if(p){
                sz[p]+=sz[u];
                big[p]=max(big[p],sz[u]);
            }
        }
        br.clear();
        for(int e=head[rt];e<head[rt+1];++e){
            int v=g[e];
            if(!del[v])br.push_back({fa[v]==rt?sz[v]:sum-sz[rt],v});
        }
        if(br.size()<=3){
            sort(br.begin(),br.end(),[](const pair<int,int> &x,const pair<int,int> &y){
                return x.first>y.first;
            });
        }
        int val=lab[rt];
        all.clear();
        all.push_back({val,val,val});
        ord.clear();
        ord.push_back(rt);
        for(const auto &x:br){
            int v=x.second;
            int start=int(all.size());
            fa[v]=rt;
            ord.push_back(v);
            all.push_back({lab[v],min(lab[v],val),max(lab[v],val)});
            for(size_t i=start;i<all.size();++i){
                node x=all[i];
                int u=ord[i];
                for(int f=head[u];f<head[u+1];++f){
                    int v=g[f];
                    if(!del[v] && v!=fa[u]){
                        fa[v]=u;
                        ord.push_back(v);
                        all.push_back({lab[v],min(x.low,lab[v]),max(x.high,lab[v])});
                    }
                }
            }
            if(br.size()>3)ans-=c.calc(all.data()+start,int(all.size())-start);
        }
        if(br.size()<=3){
            for(size_t i=1;i<all.size();++i){
                const node &v=all[i];
                if(v.low>=min(val,v.id)-k1 && v.high<=max(val,v.id)+k2)++ans;
            }
            if(br.size()>=2){
                int first=br[0].first;
                ans+=c.both(all.data()+1,first,all.data()+first+1,sum-first-1);
            }
            if(br.size()==3){
                int first=br[0].first,second=br[1].first;
                ans+=c.both(all.data()+first+1,second,
                            all.data()+first+second+1,br[2].first);
            }
        }
        else{
            ans+=c.calc(all.data(),int(all.size()));
        }
        del[rt]=1;
        for(int e=head[rt];e<head[rt+1];++e){
            if(!del[g[e]])q.push_back(g[e]);
        }
    }
    printf("%lld\n",ans);
}
