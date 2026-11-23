#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4,M=5,K=1e5+10;
const ll mod=998244353;
typedef array<ll,M> V;
typedef array<V,M> A;
ll n;
int len,keep,fa[K];
char t[K],c[M]="1246";
string s;
vector<int> g[N]={{1},{2},{0,3},{3,2}};
A unit(){
    A a;
    memset(a.data(),0,sizeof a);
    for(int i=0;i<M;++i){
        a[i][i]=1;
    }
    return a;
}
A mul(const A &a,const A &b){
    A c;
    memset(c.data(),0,sizeof c);
    for(int i=0;i<M;++i){
        for(int j=0;j<M;++j){
            for(int k=0;k<M;++k){
                c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
            }
        }
    }
    return c;
}
V calc(const A &a,const V &b){
    V c;
    memset(c.data(),0,sizeof c);
    for(int i=0;i<M;++i){
        for(int j=0;j<M;++j){
            c[i]=(c[i]+a[i][j]*b[j])%mod;
        }
    }
    return c;
}
struct node{
    array<string,N> pre,suf;
    bool operator==(const node &b)const{
        return pre==b.pre && suf==b.suf;
    }
};
ll match(const string &t){
    ll ans=0;
    int j=0;
    for(const char &c:t){
        while(j && c!=s[j]){
            j=fa[j-1];
        }
        if(c==s[j])++j;
        if(j==len){
            ++ans;
            j=fa[j-1];
        }
    }
    return ans;
}
int main(){
    scanf("%lld%s",&n,t);
    s=t;
    len=s.size();
    keep=len-1;
    for(int i=1,j=0;i<len;++i){
        while(j && s[i]!=s[j]){
            j=fa[j-1];
        }
        if(s[i]==s[j])++j;
        fa[i]=j;
    }
    node state;
    V cnt;
    memset(cnt.data(),0,sizeof cnt);
    cnt[N]=1;
    for(int i=0;i<N;++i){
        if(keep)state.pre[i]=state.suf[i]=string(1,c[i]);
        cnt[i]=(s==string(1,c[i]));
    }
    deque<node> q;
    q.push_back(state);
    vector<A> tr;
    ll time=0;
    while(time<n){
        node next;
        A a;
        memset(a.data(),0,sizeof a);
        a[N][N]=1;
        for(int i=0;i<N;++i){
            for(int &j:g[i]){
                ++a[i][j];
                next.pre[i]+=state.pre[j];
                next.suf[i]+=state.suf[j];
            }
            if((int)next.pre[i].size()>keep)next.pre[i].resize(keep);
            if((int)next.suf[i].size()>keep){
                next.suf[i].erase(0,next.suf[i].size()-keep);
            }
            if(g[i].size()==2){
                a[i][N]=match(state.suf[g[i][0]]+state.pre[g[i][1]]);
            }
        }
        cnt=calc(a,cnt);
        state=std::move(next);
        tr.push_back(a);
        ++time;
        if(q.size()==6 && state==q.front()){
            ll rem=n-time;
            int pos=tr.size()-6;
            A a=unit();
            for(int j=pos;j<pos+6;++j){
                a=mul(tr[j],a);
            }
            ll k=rem/6;
            while(k){
                if(k&1)cnt=calc(a,cnt);
                a=mul(a,a);
                k>>=1;
            }
            for(int j=0;j<rem%6;++j){
                cnt=calc(tr[pos+j],cnt);
            }
            break;
        }
        q.push_back(state);
        if(q.size()>6)q.pop_front();
    }
    printf("%lld\n",cnt[0]);
    return 0;
}
