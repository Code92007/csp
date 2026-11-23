#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int N=110,M=1e5+10,mod=1e9+7;
int n,m;
ll a[N];
char s[M];
vector<string>v;
ll norm(ll x){
    return (x%mod+mod)%mod;
}
int main(){
    scanf("%d%d",&n,&m);
    int c;
    while((c=getchar())!='\n' && c!=EOF){
    }
    fgets(s,M,stdin);
    istringstream in(s);
    string t;
    while(in>>t){
        v.push_back(t);
    }
    while(m--){
        int id;
        scanf("%d",&id);
        for(int i=1;i<=n;++i){
            scanf("%lld",&a[i]);
            a[i]=norm(a[i]);
        }
        vector<P>st;
        for(string &s:v){
            if(s=="+" || s=="-" || s=="*"){
                auto [y,dy]=st.back();
                st.pop_back();
                auto [x,dx]=st.back();
                st.pop_back();
                if(s=="+")st.push_back({(x+y)%mod,(dx+dy)%mod});
                else if(s=="-")st.push_back({norm(x-y),norm(dx-dy)});
                else st.push_back({x*y%mod,(dx*y+x*dy)%mod});
            }
            else if(s[0]=='x'){
                int k=stoi(s.substr(1));
                st.push_back({a[k],k==id});
            }
            else st.push_back({norm(stoll(s)),0});
        }
        printf("%lld\n",st.back().second);
    }
    return 0;
}
