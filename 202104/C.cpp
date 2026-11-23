#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,int,int> E;
const int N=10010,M=25;
int n,q;
ll def,hi,lo;
char host[M],from[M],to[M],type[M];
struct node{
    int st,ver;
    ll end;
    string name;
}a[N];
set<int>g,h;
unordered_map<string,int>id;
priority_queue<E,vector<E>,greater<E>>ev;
void clear(int x){
    id.erase(a[x].name);
    a[x].name.clear();
    a[x].st=0;
    a[x].end=0;
    ++a[x].ver;
    g.insert(x);
}
int main(){
    scanf("%d%lld%lld%lld%s%d",&n,&def,&hi,&lo,host,&q);
    for(int i=1;i<=n;++i){
        g.insert(i);
    }
    while(q--){
        ll t,end;
        int x;
        scanf("%lld%s%s%s%d%lld",&t,from,to,type,&x,&end);
        while(!ev.empty() && get<0>(ev.top())<=t){
            auto [time,x,ver]=ev.top();
            ev.pop();
            if(ver!=a[x].ver)continue;
            if(a[x].st==1)clear(x);
            else if(a[x].st==2){
                a[x].st=3;
                a[x].end=0;
                h.insert(x);
            }
        }
        string src=from,dst=to,op=type;
        if(dst!=host && dst!="*" && op!="REQ")continue;
        if(op!="DIS" && op!="REQ")continue;
        if(dst=="*" && op!="DIS")continue;
        if(dst==host && op=="DIS")continue;
        if(op=="REQ" && dst!=host){
            auto it=id.find(src);
            if(it!=id.end() && a[it->second].st==1)clear(it->second);
            continue;
        }
        if(op=="DIS"){
            auto it=id.find(src);
            if(it!=id.end())x=it->second;
            else if(!g.empty())x=*g.begin();
            else if(!h.empty())x=*h.begin();
            else continue;
            if(!a[x].name.empty())id.erase(a[x].name);
            a[x].name=src;
            id[src]=x;
            a[x].st=1;
        }
        else{
            if(x<1 || x>n || a[x].name!=src){
                printf("%s %s NAK %d 0\n",host,from,x);
                continue;
            }
            a[x].st=2;
        }
        g.erase(x);h.erase(x);
        if(!end)a[x].end=t+def;
        else a[x].end=t+clamp(end-t,lo,hi);
        ++a[x].ver;
        ev.push({a[x].end,x,a[x].ver});
        printf("%s %s %s %d %lld\n",host,from,op=="DIS"?"OFR":"ACK",x,a[x].end);
    }
    return 0;
}
