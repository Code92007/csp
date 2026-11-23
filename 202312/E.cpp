#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef vector<unordered_map<ui,int>> layer;
const int N=105,M=5;
int n,m,l,k,col[N];
vector<P> g[N],rg[N];
vector<layer> calc(int s,vector<P> edges[N]){
    vector<layer> dp(M,layer(n));
    dp[0][s][1u<<col[s]]=0;
    for(int d=0;d<M-1 && d+1<l;++d){
        for(int u=0;u<n;++u){
            for(auto &[S,val]:dp[d][u]){
                for(auto &[v,w]:edges[u]){
                    int c=col[v];
                    if(S>>c&1)continue;
                    int &best=dp[d+1][v][S|(1u<<c)];
                    best=max(best,val+w);
                }
            }
        }
    }
    return dp;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&l,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&col[i]);
    }
    vector<int> a(m),b(m),w(m);
    for(int &x:a){
        scanf("%d",&x);
    }
    for(int &x:b){
        scanf("%d",&x);
    }
    for(int &x:w){
        scanf("%d",&x);
    }
    for(int i=0;i<m;++i){
        g[a[i]].push_back({b[i],w[i]});
        rg[b[i]].push_back({a[i],w[i]});
    }
    auto f=calc(0,g),h=calc(n-1,rg);
    int ans=0;
    for(int u=0;u<n;++u){
        for(int d=0;d<M && d<l;++d){
            if(f[d][u].empty())continue;
            int cap=min(M-1,l-1-d);
            vector<pair<int,ui>> v;
            for(int i=0;i<=cap;++i){
                for(auto &[S,val]:h[i][u]){
                    v.push_back({val,S});
                }
            }
            sort(v.rbegin(),v.rend());
            int len=(v.size()+63)/64;
            if(!len)continue;
            vector<vector<ull>> bad(k,vector<ull>(len));
            for(int i=0;i<(int)v.size();++i){
                ui S=v[i].second;
                while(S){
                    int c=__builtin_ctz(S);
                    S&=S-1;
                    bad[c][i/64]|=1ull<<(i%64);
                }
            }
            for(auto &[key,val]:f[d][u]){
                ui S=key^(1u<<col[u]);
                vector<int> colors;
                while(S){
                    colors.push_back(__builtin_ctz(S));
                    S&=S-1;
                }
                for(int i=0;i<len;++i){
                    ull ex=0;
                    for(int &c:colors){
                        ex|=bad[c][i];
                    }
                    ull ok=~ex;
                    if(!ok)continue;
                    int pos=i*64+__builtin_ctzll(ok);
                    if(pos<(int)v.size())ans=max(ans,val+v[pos].first);
                    break;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
