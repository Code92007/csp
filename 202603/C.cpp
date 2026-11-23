#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int N=105,M=10;
int n,q,p;
char op[M];
struct node{
    ll l,len,pos;
};
vector<node>g[N];
map<ll,ll>mp;
set<P>st;
void erase(map<ll,ll>::iterator it){
    st.erase(P(it->second,it->first));
    mp.erase(it);
}
void add(ll l,ll len){
    if(!len)return;
    mp[l]=len;
    st.insert(P(len,l));
}
int main(){
    scanf("%d%d",&n,&q);
    ll tail=0;
    while(q--){
        scanf("%s%d",op,&p);
        if(op[0]=='n'){
            ll len,l;
            scanf("%lld",&len);
            auto it=st.lower_bound(P(len,-1));
            if(it==st.end()){
                l=tail;
                tail+=len;
            }
            else{
                ll rem=it->first;
                l=it->second;
                erase(mp.find(l));
                add(l+len,rem-len);
            }
            g[p].push_back({l,len,0});
            printf("%lld\n",l);
        }
        else if(op[0]=='s'){
            ll ans=0;
            for(auto &x:g[p]){
                ans+=x.l+x.pos;
                x.pos=(x.pos+1)%x.len;
            }
            printf("%lld\n",ans);
        }
        else{
            int id;
            scanf("%d",&id);
            --id;
            node x=g[p][id];
            g[p].erase(g[p].begin()+id);
            ll l=x.l,r=l+x.len;
            auto it=mp.lower_bound(l);
            if(it!=mp.begin()){
                auto pre=prev(it);
                if(pre->first+pre->second==l){
                    l=pre->first;
                    erase(pre);
                }
            }
            it=mp.lower_bound(r);
            if(it!=mp.end() && it->first==r){
                r+=it->second;
                erase(it);
            }
            if(r==tail)tail=l;
            else add(l,r-l);
        }
    }
    return 0;
}
