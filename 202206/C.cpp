#include<bits/stdc++.h>
using namespace std;
const int N=510,M=15;
int n,m,q;
char s[M];
struct role{
    unordered_set<string>op,type,name;
}a[N];
unordered_map<string,int>id;
unordered_map<string,bitset<N>>user,group;
string read(){
    scanf("%s",s);
    return s;
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;++i){
        id[read()]=i;
        for(auto *st:{&a[i].op,&a[i].type,&a[i].name}){
            int k;
            scanf("%d",&k);
            while(k--){
                st->insert(read());
            }
        }
    }
    while(m--){
        string r=read();
        int k;
        scanf("%d",&k);
        while(k--){
            string t=read(),s=read();
            (t=="u"?user:group)[s].set(id[r]);
        }
    }
    while(q--){
        string s=read();
        int k;
        scanf("%d",&k);
        bitset<N>can;
        auto it=user.find(s);
        if(it!=user.end())can=it->second;
        while(k--){
            string g=read();
            auto it=group.find(g);
            if(it!=group.end())can|=it->second;
        }
        string op=read(),type=read(),name=read();
        bool ok=0;
        for(int i=0;i<n;++i){
            if(!can[i])continue;
            role &r=a[i];
            bool x=r.op.count("*") || r.op.count(op);
            bool y=r.type.count("*") || r.type.count(type);
            bool z=r.name.empty() || r.name.count(name);
            if(x && y && z){
                ok=1;
                break;
            }
        }
        printf("%d\n",ok);
    }
    return 0;
}
