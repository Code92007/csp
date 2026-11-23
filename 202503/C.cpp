#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=1005,mod=1e9+7;
int n,tot,now,ed[N];
ll dp[N];
struct node{
    bool op;
    ll val;
    vector<P>g;
}a[N];
unordered_map<string,int>mp;
string read(){
    string s;
    int c;
    while((c=getchar())!='\n' && c!=EOF){
        s+=(char)c;
    }
    return s;
}
int id(const string &s){
    auto it=mp.find(s);
    if(it!=mp.end())return it->second;
    return mp[s]=++tot;
}
ll eval(int u){
    if(ed[u]==now)return dp[u];
    ll val=a[u].val;
    if(a[u].op){
        val=0;
        for(P &x:a[u].g){
            ll v=x.first?eval(x.second):x.second;
            val=(val+v)%mod;
        }
    }
    ed[u]=now;
    return dp[u]=val;
}
int main(){
    scanf("%d",&n);
    read();
    while(n--){
        ++now;
        istringstream in(read());
        int op;
        string s;
        in>>op>>s;
        int u=id(s);
        if(op==3){
            printf("%lld\n",eval(u));
            continue;
        }
        vector<P>g;
        while(in>>s){
            if(s[0]=='$')g.push_back(P(1,id(s.substr(1))));
            else g.push_back(P(0,s.size()));
        }
        if(op==1){
            ll val=0;
            for(P &x:g){
                ll v=x.first?eval(x.second):x.second;
                val=(val+v)%mod;
            }
            a[u].op=0;
            a[u].val=val;
            a[u].g.clear();
        }
        else{
            a[u].op=1;
            a[u].g.swap(g);
        }
    }
    return 0;
}
