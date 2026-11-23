#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=1e6+5,M=21,K=2;
int n,q,pre[N],up[M][N];
struct Hash{
    size_t operator()(ull x)const{
        x+=0x9e3779b97f4a7c15ull;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9ull;
        x=(x^(x>>27))*0x94d049bb133111ebull;
        return x^(x>>31);
    }
};
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i){
        scanf("%d",&pre[i]);
        if(i>1){
            pre[i]^=pre[i-2];
        }
    }
    unordered_map<int,int,Hash>mp[K];
    for(auto &x:mp){
        x.reserve(n/2+1);
    }
    int best=n+1;
    for(int i=n;i>=1;--i){
        auto &h=mp[i&1];
        h[pre[i]]=i;
        int x=i>1?pre[i-2]:0;
        auto it=h.find(x);
        if(it!=h.end()){
            best=min(best,it->second);
        }
        up[0][i]=best+1;
    }
    for(auto &x:mp){
        x.clear();
        x.rehash(0);
    }
    for(int i=0;i<M;++i){
        up[i][n+1]=up[i][n+2]=n+2;
    }
    for(int i=1;i<M;++i){
        for(int j=1;j<=n;++j){
            up[i][j]=up[i-1][up[i-1][j]];
        }
    }
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        int ans=0;
        for(int i=M-1;i>=0;--i){
            if(up[i][l]<=r+1){
                ans+=1<<i;
                l=up[i][l];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
