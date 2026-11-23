#include<bits/stdc++.h>
using namespace std;
struct node{
    int id;
    bool dirty;
};
int n,m,q;
vector<list<node>> g;
unordered_map<int,list<node>::iterator> mp;
int main(){
    scanf("%d%d%d",&n,&m,&q);
    g.resize(m);
    mp.reserve(min(q,n*m)*2+1);
    while(q--){
        int op,x;
        scanf("%d%d",&op,&x);
        auto &cur=g[x/n%m];
        auto it=mp.find(x);
        if(it!=mp.end()){
            it->second->dirty|=(op==1);
            cur.splice(cur.begin(),cur,it->second);
            continue;
        }
        if((int)cur.size()==n){
            node v=cur.back();
            if(v.dirty)printf("1 %d\n",v.id);
            mp.erase(v.id);
            cur.pop_back();
        }
        printf("0 %d\n",x);
        cur.push_front({x,op==1});
        mp[x]=cur.begin();
    }
    return 0;
}
