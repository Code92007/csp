#include<bits/stdc++.h>
using namespace std;
typedef pair<string,string> P;
struct node{
    int l,r;
    char c;
};
int n,m,q,p;
string s;
vector<node> tr(1);
vector<P> a;
deque<P> d;
string read(){
    string t;
    int c=getchar();
    while(isspace(c)){
        c=getchar();
    }
    while(c!=EOF && !isspace(c)){
        t+=char(c);
        c=getchar();
    }
    return t;
}
int build(){
    int u=tr.size();
    tr.push_back({0,0,0});
    if(s[p++]=='1')tr[u].c=s[p++];
    else{
        tr[u].l=build();
        tr[u].r=build();
    }
    return u;
}
int hex(char c){
    return c<='9'?c-'0':c-'a'+10;
}
string decode(string t){
    if(t[0]!='H')return t;
    if(t.size()>1 && t[1]=='H')return t.substr(1);
    int len=t.size();
    int w=hex(t[len-2])*16+hex(t[len-1]);
    int b=((len-1)/2-1)*8-w,u=1;
    string ans;
    for(int i=0;i<b;++i){
        int v=(hex(t[1+i/4])>>(3-i%4))&1;
        u=v?tr[u].r:tr[u].l;
        if(tr[u].c){
            ans+=tr[u].c;
            u=1;
        }
    }
    return ans;
}
P f(int x){
    return x<=n?a[x-1]:d[x-n-1];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        string k=read(),v=read();
        a.push_back({k,v});
    }
    s=read();
    build();
    scanf("%d",&q);
    while(q--){
        int op,x;
        scanf("%d%d",&op,&x);
        P cur;
        if(op==1)cur=f(x);
        else{
            cur.first=x?f(x).first:decode(read());
            cur.second=decode(read());
        }
        printf("%s: %s\n",cur.first.c_str(),cur.second.c_str());
        if(op==2){
            d.push_front(cur);
            if((int)d.size()>m)d.pop_back();
        }
    }
    return 0;
}
