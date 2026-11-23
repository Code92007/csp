#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int N=2500,M=2010;
typedef bitset<N> bits;
struct record{
    ull key;
    int u;
};
int n,m;
char s[M];
vector<P> dn;
vector<record> rec;
vector<string> expr;
vector<ull> keys;
vector<int> attr,id;
vector<bits> eq,has;
ull code(int a,int b){
    return (ull(a)<<32)|unsigned(b);
}
int num(const string &str,size_t &p){
    int x=0;
    while(p<str.size() && str[p]>='0' && str[p]<='9'){
        x=x*10+str[p++]-'0';
    }
    return x;
}
bits parse(const string &str,size_t &p){
    if(str[p]=='&' || str[p]=='|'){
        char op=str[p++];
        ++p;
        bits a=parse(str,p);
        p+=2;
        bits b=parse(str,p);
        ++p;
        return op=='&'?a&b:a|b;
    }
    int a=num(str,p);
    char op=str[p++];
    int b=num(str,p);
    int x=lower_bound(keys.begin(),keys.end(),code(a,b))-keys.begin();
    if(op==':')return eq[x];
    return has[id[x]]&~eq[x];
}
int main(){
    scanf("%d",&n);
    rec.reserve(n*500);
    for(int i=0;i<n;++i){
        int u,k;
        scanf("%d%d",&u,&k);
        dn.push_back({u,i});
        while(k--){
            int a,b;
            scanf("%d%d",&a,&b);
            rec.push_back({code(a,b),i});
        }
    }
    scanf("%d",&m);
    expr.resize(m);
    for(string &str:expr){
        scanf("%2000s",s);
        str=s;
        for(size_t p=0;p<str.size();){
            if(str[p]>='0' && str[p]<='9'){
                int a=num(str,p);
                ++p;
                int b=num(str,p);
                keys.push_back(code(a,b));
            }
            else ++p;
        }
    }
    sort(keys.begin(),keys.end());
    keys.erase(unique(keys.begin(),keys.end()),keys.end());
    for(ull &key:keys){
        int a=key>>32;
        if(attr.empty() || attr.back()!=a)attr.push_back(a);
        id.push_back(attr.size()-1);
    }
    eq.resize(keys.size());
    has.resize(attr.size());
    sort(rec.begin(),rec.end(),[](const record &a,const record &b){
        return a.key<b.key;
    });
    size_t x=0,y=0;
    for(record &v:rec){
        int a=v.key>>32;
        while(y<attr.size() && attr[y]<a){
            ++y;
        }
        if(y<attr.size() && attr[y]==a)has[y].set(v.u);
        while(x<keys.size() && keys[x]<v.key){
            ++x;
        }
        if(x<keys.size() && keys[x]==v.key)eq[x].set(v.u);
    }
    vector<record>().swap(rec);
    sort(dn.begin(),dn.end());
    for(string &str:expr){
        size_t p=0;
        bits ans=parse(str,p);
        bool first=true;
        for(auto &[u,i]:dn){
            if(!ans[i])continue;
            if(!first)putchar(' ');
            printf("%d",u);
            first=false;
        }
        putchar('\n');
    }
    return 0;
}
