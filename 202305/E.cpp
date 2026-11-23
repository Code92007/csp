#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=26,M=15,INF=0x3f3f3f3f;
struct edge{
    int u,v,s,w;
};
int n,k,m,id[N];
char t[M];
vector<edge> a,g[N];
vector<int> best,dis[N];
priority_queue<P,vector<P>,greater<P>> q;
string read(){
    string s;
    int c=getchar();
    while(isspace(c)){
        c=getchar();
    }
    while(c!=EOF && !isspace(c)){
        s+=char(c);
        c=getchar();
    }
    return s;
}
int main(){
    scanf("%d%s",&n,t);
    k=strlen(t);
    m=1<<k;
    memset(id,-1,sizeof id);
    for(int i=0;i<k;++i){
        id[t[i]-'a']=i;
    }
    best.assign(N*N*m,INF);
    for(int i=0;i<n;++i){
        string s=read();
        edge e={s.front()-'a',s.back()-'a',0,(int)s.size()-1};
        for(char &c:s){
            if(id[c-'a']>=0)e.s|=1<<id[c-'a'];
        }
        int &v=best[(e.u*N+e.v)*m+e.s];
        v=min(v,e.w);
        a.push_back(e);
    }
    for(int u=0;u<N;++u){
        for(int v=0;v<N;++v){
            vector<int> sup(m);
            for(int s=0;s<m;++s){
                sup[s]=best[(u*N+v)*m+s];
            }
            for(int b=0;b<k;++b){
                for(int s=0;s<m;++s){
                    if(!(s>>b&1))sup[s]=min(sup[s],sup[s|(1<<b)]);
                }
            }
            for(int s=0;s<m;++s){
                int w=best[(u*N+v)*m+s];
                if(w==INF)continue;
                bool ok=true;
                for(int b=0;b<k;++b){
                    if(!(s>>b&1) && sup[s|(1<<b)]<=w)ok=false;
                }
                if(ok)g[u].push_back({u,v,s,w});
            }
        }
    }
    for(int start=0;start<N;++start){
        auto &d=dis[start];
        d.assign(N*m,INF);
        d[start*m]=0;
        q.push({0,start*m});
        while(!q.empty()){
            auto [val,x]=q.top();
            q.pop();
            if(val!=d[x])continue;
            int u=x/m,s=x%m;
            for(auto &e:g[u]){
                int v=e.v*m+(s|e.s);
                if(val+e.w<d[v]){
                    d[v]=val+e.w;
                    q.push({d[v],v});
                }
            }
        }
        for(int v=0;v<N;++v){
            for(int b=0;b<k;++b){
                for(int s=0;s<m;++s){
                    if(s>>b&1)continue;
                    int x=v*m+s,y=v*m+(s|(1<<b));
                    d[x]=min(d[x],d[y]);
                }
            }
        }
    }
    for(auto &e:a){
        int d=dis[e.v][e.u*m+((m-1)^e.s)];
        printf("%d\n",d==INF?-1:d+e.w);
    }
    return 0;
}
