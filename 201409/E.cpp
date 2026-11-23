#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> mat;
const int mod=1e9+7;
ll n;
int m,len,full,st;
mat a;
mat mul(const mat &x,const mat &y){
    int size=x.size();
    mat z(size,vector<int>(size));
    for(int i=0;i<size;++i){
        for(int k=0;k<size;++k){
            if(!x[i][k])continue;
            for(int j=0;j<size;++j){
                if(y[k][j]){
                    z[i][j]=(z[i][j]+1ll*x[i][k]*y[k][j])%mod;
                }
            }
        }
    }
    return z;
}
void dfs(int S,int next){
    if(S==full){
        ++a[st][next];
        return;
    }
    int c=0;
    while(S>>c&1){
        ++c;
    }
    for(int l=c-1;l<=c;++l){
        if(l<0 || l+1>=m)continue;
        for(int miss=0;miss<4;++miss){
            int up=0,down=0;
            for(int i=0;i<4;++i){
                if(i==miss)continue;
                if(i<2)up|=1<<(l+i);
                else down|=1<<(l+i-2);
            }
            if(!(up>>c&1) || (up&S) || (down&next))continue;
            dfs(S|up,next|down);
        }
    }
}
int main(){
    scanf("%lld%d",&n,&m);
    if((n%3)*(m%3)%3){
        puts("0");
        return 0;
    }
    len=1<<m;
    full=len-1;
    a.assign(len,vector<int>(len));
    for(st=0;st<len;++st){
        dfs(st,0);
    }
    vector<int> dp(len);
    dp[0]=1;
    while(n){
        if(n&1){
            vector<int> v(len);
            for(int i=0;i<len;++i){
                if(!dp[i])continue;
                for(int j=0;j<len;++j){
                    v[j]=(v[j]+1ll*dp[i]*a[i][j])%mod;
                }
            }
            dp.swap(v);
        }
        n>>=1;
        if(n)a=mul(a,a);
    }
    printf("%d\n",dp[0]);
    return 0;
}
