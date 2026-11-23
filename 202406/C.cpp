#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2.5e5+10;
int n,m;
char s[N];
struct node{
    int v,pre,nxt;
    ll w;
    bool ok;
};
struct edge{
    int l,r,ver=0;
    ll sum=0;
    set<int>pos;
};
struct item{
    ll sum;
    int id,ver;
};
vector<string>v;
vector<node>a;
vector<edge>e;
struct cmp{
    bool operator()(const item &a,const item &b)const{
        if(a.sum!=b.sum)return a.sum<b.sum;
        edge &x=e[a.id],&y=e[b.id];
        int al=v[x.l].size(),ar=v[x.r].size();
        int bl=v[y.l].size(),br=v[y.r].size();
        if(al+ar!=bl+br)return al+ar>bl+br;
        if(al!=bl)return al>bl;
        int d=v[x.l].compare(v[y.l]);
        if(d)return d>0;
        d=v[x.r].compare(v[y.r]);
        if(d)return d>0;
        return a.id>b.id;
    }
};
unordered_map<string,int>id;
unordered_map<ull,int>mp;
priority_queue<item,vector<item>,cmp>q;
int index(int l,int r){
    ull key=(ull(l)<<32)|r;
    auto it=mp.find(key);
    if(it!=mp.end())return it->second;
    int u=e.size();
    e.push_back({l,r,0,0,{}});
    return mp[key]=u;
}
void change(int u,int d){
    if(u<0 || a[u].nxt<0)return;
    int i=index(a[u].v,a[a[u].nxt].v);
    edge &x=e[i];
    x.sum+=d*a[u].w;
    ++x.ver;
    if(d==1)x.pos.insert(u);
    else x.pos.erase(u);
    if(x.sum>0)q.push({x.sum,i,x.ver});
}
int main(){
    scanf("%d%d",&n,&m);
    vector<string>word(n);
    vector<ll>freq(n);
    set<char>alpha;
    for(int i=0;i<n;++i){
        scanf("%s%lld",s,&freq[i]);
        word[i]=s;
        for(char &c:word[i]){
            alpha.insert(c);
        }
    }
    for(const char &c:alpha){
        string x(1,c);
        id[x]=v.size();
        v.push_back(x);
        puts(x.c_str());
    }
    for(int i=0;i<n;++i){
        int start=a.size();
        for(char &c:word[i]){
            int u=a.size();
            int pre=u==start?-1:u-1;
            a.push_back({id[string(1,c)],pre,u+1,freq[i],1});
        }
        a.back().nxt=-1;
    }
    for(int i=0;i<(int)a.size();++i){
        change(i,1);
    }
    int cnt=v.size();
    while(cnt<m){
        while(!q.empty()){
            item x=q.top();
            if(x.ver==e[x.id].ver && e[x.id].sum)break;
            q.pop();
        }
        if(q.empty())break;
        int cur=q.top().id;
        q.pop();
        int l=e[cur].l,r=e[cur].r;
        string str=v[l]+v[r];
        puts(str.c_str());
        ++cnt;
        int val;
        auto it=id.find(str);
        if(it==id.end()){
            val=v.size();
            id[str]=val;
            v.push_back(str);
        }
        else val=it->second;
        vector<int>pos(e[cur].pos.begin(),e[cur].pos.end());
        for(int &u:pos){
            if(!a[u].ok || a[u].nxt<0)continue;
            int w=a[u].nxt;
            if(a[u].v!=l || a[w].v!=r)continue;
            int pre=a[u].pre,nxt=a[w].nxt;
            change(pre,-1),change(u,-1),change(w,-1);
            a[u].v=val,a[u].nxt=nxt;
            a[w].ok=0,a[w].nxt=-1;
            if(nxt>=0)a[nxt].pre=u;
            change(pre,1),change(u,1);
        }
    }
    return 0;
}
