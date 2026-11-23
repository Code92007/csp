#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int N=1e5+10,M=4;
const int dx[M]={1,0,-1,0},dy[M]={0,1,0,-1};
int m;
struct mirror{
    ll x1,y1,x2,y2;
    double a;
    int k;
}s[N];
map<P,int>h,v;
void update(int id,bool add){
    mirror &p=s[id];
    for(ll x=p.x1+1;x<p.x2;++x){
        ll y=p.y1+p.k*(x-p.x1);
        if(add){
            h[P(y,x)]=id;
            v[P(x,y)]=id;
        }
        else{
            h.erase(P(y,x));
            v.erase(P(x,y));
        }
    }
}
int main(){
    scanf("%d",&m);
    for(int i=1;i<=m;++i){
        int op;
        scanf("%d",&op);
        if(op==1){
            mirror &p=s[i];
            scanf("%lld%lld%lld%lld%lf",&p.x1,&p.y1,&p.x2,&p.y2,&p.a);
            if(p.x1>p.x2){
                swap(p.x1,p.x2);
                swap(p.y1,p.y2);
            }
            p.k=p.y2>p.y1?1:-1;
            update(i,1);
        }
        else if(op==2){
            int id;
            scanf("%d",&id);
            update(id,0);
        }
        else{
            ll x,y,t;
            int d;
            double w;
            scanf("%lld%lld%d%lf%lld",&x,&y,&d,&w,&t);
            while(t>0 && w>=1){
                bool hor=d%2==0,pos=d<2;
                auto &g=hor?h:v;
                ll line=hor?y:x,cur=hor?x:y;
                auto it=g.end();
                if(pos)it=g.upper_bound(P(line,cur));
                else{
                    auto p=g.lower_bound(P(line,cur));
                    if(p!=g.begin())it=prev(p);
                }
                bool ok=(it!=g.end() && it->first.first==line);
                ll dis=ok?abs(it->first.second-cur):t+1;
                if(dis>t){
                    x+=dx[d]*t;
                    y+=dy[d]*t;
                    break;
                }
                x+=dx[d]*dis;
                y+=dy[d]*dis;
                t-=dis;
                mirror &p=s[it->second];
                w*=p.a;
                d^=p.k==1?1:3;
            }
            if(w<1)puts("0 0 0");
            else printf("%lld %lld %lld\n",x,y,(ll)floor(w));
        }
    }
    return 0;
}
