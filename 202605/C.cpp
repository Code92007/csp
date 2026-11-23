#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=15,M=45;
int n,m,own[M],low[M],high[M],held[N];
bool ok[N],drop[N];
struct node{
    char tp;
    int st,w,num,a[M],t[M];
    int pos=1,fail,rem,state,dur=-1;
    bool rel;
    ll sum;
}p[N];
int main(){
    scanf("%d%d",&n,&m);
    int lim=1;
    for(int i=1;i<=n;++i){
        auto &x=p[i];
        scanf(" %c%d",&x.tp,&x.st);
        if(x.tp!='X'){
            scanf("%d",&x.w);
        }
        scanf("%d",&x.num);
        lim=max({lim,x.st,x.w+1});
        for(int j=1;j<=x.num;++j){
            scanf("%d%d",&x.a[j],&x.t[j]);
            lim=max(lim,x.t[j]);
        }
    }
    int cnt=0,quiet=0;
    for(int now=1;cnt<n;++now){
        bool event=0;
        memset(ok,0,sizeof ok);
        memset(drop,0,sizeof drop);
        memset(low,0,sizeof low);
        memset(high,0,sizeof high);
        memset(held,0,sizeof held);
        for(int i=1;i<=n;++i){
            auto &x=p[i];
            if(!x.state && x.st==now){
                x.state=1;
                event=1;
            }
            if(x.state!=1)continue;
            int r=x.a[x.pos];
            if(x.tp=='C' && x.fail>=x.w){
                high[r]=i;
                ok[i]=1;
            }
            else if(!low[r]){
                low[r]=i;
            }
        }
        for(int r=1;r<=m;++r){
            if(high[r]){
                own[r]=high[r];
            }
            else if(!own[r] && low[r]){
                own[r]=low[r];
                ok[low[r]]=1;
            }
        }
        for(int i=1;i<=n;++i){
            auto &x=p[i];
            if(x.state!=1)continue;
            bool run=ok[i];
            if(!run){
                ++x.fail;
                if(x.tp=='A' && !x.rel && x.fail==x.w){
                    drop[i]=1;
                    x.rel=1;
                    event=1;
                }
                if(x.tp=='B' && x.fail==x.w){
                    run=1;
                }
            }
            if(run){
                x.state=2;
                x.rem=x.t[x.pos];
                event=1;
            }
        }
        for(int r=1;r<=m;++r){
            if(own[r]){
                ++held[own[r]];
            }
        }
        for(int i=1;i<=n;++i){
            auto &x=p[i];
            if(x.state!=2)continue;
            x.sum+=held[i];
            if(--x.rem==0){
                event=1;
                if(++x.pos>x.num){
                    x.state=3;
                    x.dur=now-x.st+1;
                    drop[i]=1;
                    ++cnt;
                }
                else{
                    x.state=1;
                    x.fail=0;
                    x.rel=0;
                }
            }
        }
        for(int r=1;r<=m;++r){
            if(own[r] && drop[own[r]]){
                own[r]=0;
            }
        }
        quiet=event?0:quiet+1;
        if(quiet>lim)break;
    }
    for(int i=1;i<=n;++i){
        printf("%lld %d\n",p[i].sum,p[i].dur);
    }
    return 0;
}
