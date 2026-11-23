#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int c,m,n,cnt;
vector<P> a;
vector<int> l,r;
priority_queue<int,vector<int>,greater<int>> q;
void add(int u){
    if(u>=0 && u<m && ++a[u].second==5)q.push(u);
}
int main(){
    scanf("%d%d%d",&c,&m,&n);
    a.resize(m);
    l.resize(m);
    r.resize(m);
    for(auto &[x,y]:a){
        scanf("%d%d",&x,&y);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<m;++i){
        l[i]=i-1;
        r[i]=i+1;
    }
    cnt=m;
    while(n--){
        int x;
        scanf("%d",&x);
        int u=lower_bound(a.begin(),a.end(),P(x,-1))-a.begin();
        add(u);
        while(!q.empty()){
            int v=q.top();
            q.pop();
            int s=l[v],t=r[v];
            if(s>=0)r[s]=t;
            if(t<m)l[t]=s;
            a[v].second=0;
            --cnt;
            add(s);
            add(t);
        }
        printf("%d\n",cnt);
    }
    return 0;
}
