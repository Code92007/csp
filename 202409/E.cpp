#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node;
extern node e[N];
mt19937 rng(94127);
struct node{
    int l,r,sz,c,first,last,cnt;
    unsigned pri;
    int size(){
        return sz;
    }
    void read(){
        scanf("%d",&c);
        first=last=c;
        sz=cnt=1;
        pri=rng();
    }
    void pushup(){
        sz=1+e[l].size()+e[r].size();
        first=l?e[l].first:c;
        last=r?e[r].last:c;
        cnt=1;
        if(l)cnt+=e[l].cnt-(e[l].last==c);
        if(r)cnt+=e[r].cnt-(e[r].first==c);
    }
}e[N];
int n,m,k,x,l,r,root[N];
unordered_map<int,int> mp[N];
void split(int u,int key,int &a,int &b){
    if(!u){
        a=b=0;
        return;
    }
    if(u<=key){
        a=u;
        split(e[u].r,key,e[u].r,b);
        e[u].pushup();
    }
    else{
        b=u;
        split(e[u].l,key,a,e[u].l);
        e[u].pushup();
    }
}
int merge(int a,int b){
    if(!a || !b)return a|b;
    if(e[a].pri<e[b].pri){
        e[a].r=merge(e[a].r,b);
        e[a].pushup();
        return a;
    }
    e[b].l=merge(a,e[b].l);
    e[b].pushup();
    return b;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i){
        e[i].read();
        root[1]=merge(root[1],i);
        ++mp[1][e[i].c];
    }
    for(int id=2;id<=k+1;++id){
        scanf("%d%d%d",&x,&l,&r);
        int a,b,c;
        split(root[x],r,b,c);
        split(b,l-1,a,b);
        root[x]=merge(a,c);
        root[id]=b;
        int u=id,v=x;
        if(e[root[x]].size()<e[root[id]].size()){
            mp[x].swap(mp[id]);
            u=x;
            v=id;
        }
        vector<int> st;
        if(root[u])st.push_back(root[u]);
        while(!st.empty()){
            int p=st.back();
            st.pop_back();
            int col=e[p].c;
            ++mp[u][col];
            auto it=mp[v].find(col);
            if(--it->second==0)mp[v].erase(it);
            if(e[p].l)st.push_back(e[p].l);
            if(e[p].r)st.push_back(e[p].r);
        }
        int cnt=root[id]?e[root[id]].cnt:0;
        printf("%zu %d\n",mp[id].size(),cnt);
    }
    return 0;
}
