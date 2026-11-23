#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> mat;
const int N=105,M=26;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n;
ll m;
char s[N];
namespace AC{
    struct node{
        int ch[M],fail,w;
    }e[N];
    int tot;
    void insert(const char *t){
        int u=0;
        for(int i=0;t[i];++i){
            int c=t[i]-'a';
            if(!e[u].ch[c])e[u].ch[c]=++tot;
            u=e[u].ch[c];
        }
        ++e[u].w;
    }
    void build(){
        queue<int> q;
        for(int &v:e[0].ch){
            if(v)q.push(v);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            e[u].w+=e[e[u].fail].w;
            for(int c=0;c<M;++c){
                int v=e[u].ch[c];
                if(v){
                    e[v].fail=e[e[u].fail].ch[c];
                    q.push(v);
                }
                else e[u].ch[c]=e[e[u].fail].ch[c];
            }
        }
    }
}
using namespace AC;
mat mul(const mat &a,const mat &b){
    int len=a.size();
    mat c(len,vector<ll>(len,-INF));
    for(int i=0;i<len;++i){
        for(int k=0;k<len;++k){
            if(a[i][k]==-INF)continue;
            for(int j=0;j<len;++j){
                if(b[k][j]!=-INF){
                    c[i][j]=max(c[i][j],a[i][k]+b[k][j]);
                }
            }
        }
    }
    return c;
}
int main(){
    scanf("%d%lld",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%100s",s);
        insert(s);
    }
    build();
    int len=tot+1;
    mat a(len,vector<ll>(len,-INF));
    for(int u=0;u<len;++u){
        for(int &v:e[u].ch){
            a[u][v]=e[v].w;
        }
    }
    vector<ll> dp(len,-INF);
    dp[0]=0;
    while(m){
        if(m&1){
            vector<ll> v(len,-INF);
            for(int i=0;i<len;++i){
                if(dp[i]==-INF)continue;
                for(int j=0;j<len;++j){
                    if(a[i][j]!=-INF){
                        v[j]=max(v[j],dp[i]+a[i][j]);
                    }
                }
            }
            dp.swap(v);
        }
        m>>=1;
        if(m)a=mul(a,a);
    }
    printf("%lld\n",*max_element(dp.begin(),dp.end()));
    return 0;
}
