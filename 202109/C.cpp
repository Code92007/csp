#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
struct neuron{
    double v,u,a,b,c,d;
    int cnt=0;
};
struct edge{
    int v,d;
    double w;
};
int n,s,p,t,delay,ring;
double dt;
ull seed=1;
vector<neuron> a;
vector<int> r;
vector<vector<edge>> g;
vector<vector<double>> in;
void emit(int u,int now){
    for(edge &e:g[u]){
        if(now+e.d<=t)in[(now+e.d)%ring][e.v]+=e.w;
    }
}
int main(){
    scanf("%d%d%d%d%lf",&n,&s,&p,&t,&dt);
    while((int)a.size()<n){
        int cnt;
        neuron x;
        scanf("%d%lf%lf%lf%lf%lf%lf",&cnt,&x.v,&x.u,&x.a,&x.b,&x.c,&x.d);
        while(cnt--){
            a.push_back(x);
        }
    }
    r.resize(p);
    for(int &x:r){
        scanf("%d",&x);
    }
    g.resize(n+p);
    while(s--){
        int u,v,d;
        double w;
        scanf("%d%d%lf%d",&u,&v,&w,&d);
        g[u].push_back({v,d,w});
        delay=max(delay,d);
    }
    ring=delay+1;
    in.assign(ring,vector<double>(n));
    for(int now=1;now<=t;++now){
        for(int i=0;i<p;++i){
            seed=seed*1103515245+12345;
            int val=(seed/65536)%32768;
            if(r[i]>val)emit(n+i,now);
        }
        for(int i=0;i<n;++i){
            neuron &x=a[i];
            double v=x.v,u=x.u;
            x.v=v+dt*(0.04*v*v+5*v+140-u)+in[now%ring][i];
            x.u=u+dt*x.a*(x.b*v-u);
            in[now%ring][i]=0;
            if(x.v>=30){
                x.v=x.c;
                x.u+=x.d;
                ++x.cnt;
                emit(i,now);
            }
        }
    }
    double mn=a[0].v,mx=mn;
    int lo=a[0].cnt,hi=lo;
    for(neuron &x:a){
        mn=min(mn,x.v);
        mx=max(mx,x.v);
        lo=min(lo,x.cnt);
        hi=max(hi,x.cnt);
    }
    printf("%.3f %.3f\n%d %d\n",mn,mx,lo,hi);
    return 0;
}
