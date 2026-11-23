#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=45;
int t,n,m;
ll a[N][N],b[N][N];
vector<ll> p;
string read(){
    string s;
    int c=getchar();
    while(isspace(c)){
        c=getchar();
    }
    while(c!=EOF && !isspace(c)){
        s+=char(c);
        c=getchar();
    }
    return s;
}
ll power(ll x,ll y,ll mod){
    ll ans=1;
    while(y){
        if(y&1)ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
int gauss(ll mod){
    memcpy(b,a,sizeof a);
    int r=0;
    for(int c=0;c<m && r<n;++c){
        int u=r;
        while(u<n && !b[u][c]){
            ++u;
        }
        if(u==n)continue;
        for(int j=0;j<m;++j){
            swap(b[u][j],b[r][j]);
        }
        ll inv=power(b[r][c],mod-2,mod);
        for(int j=c;j<m;++j){
            b[r][j]=b[r][j]*inv%mod;
        }
        for(int i=r+1;i<n;++i){
            ll v=b[i][c];
            if(!v)continue;
            for(int j=c;j<m;++j){
                b[i][j]=(b[i][j]-v*b[r][j]%mod+mod)%mod;
            }
        }
        ++r;
    }
    return r;
}
int main(){
    for(ll x=1e9+7;p.size()<12;x+=2){
        bool ok=true;
        for(ll d=3;d*d<=x;d+=2){
            if(x%d==0){
                ok=false;
                break;
            }
        }
        if(ok)p.push_back(x);
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&m);
        memset(a,0,sizeof a);
        map<string,int> id;
        n=0;
        for(int c=0;c<m;++c){
            string s=read();
            int i=0,len=s.size();
            while(i<len){
                string key;
                while(i<len && islower(s[i])){
                    key+=s[i++];
                }
                int v=0;
                while(i<len && isdigit(s[i])){
                    v=v*10+s[i++]-'0';
                }
                if(!id.count(key))id[key]=n++;
                a[id[key]][c]=v;
            }
        }
        bool ok=true;
        if(n>=m){
            for(ll &mod:p){
                if(gauss(mod)==m){
                    ok=false;
                    break;
                }
            }
        }
        puts(ok?"Y":"N");
    }
    return 0;
}
