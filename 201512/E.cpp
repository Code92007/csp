#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=2048,K=31;
typedef bitset<N> B;
typedef bitset<M> F;
int m,q,d;
char s[N];
B a[N],base[N],f[N];
F rel,pw[K];
vector<B> v;
F rem(F x){
    for(int i=2*d-1;i>=d;--i){
        if(x[i])x^=rel<<(i-d);
    }
    return x;
}
F mul(const F &x,const F &y){
    F z;
    for(int i=0;i<d;++i){
        if(x[i])z^=y<<i;
    }
    return rem(z);
}
int main(){
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%s",s);
        for(int j=0;j<m;++j){
            a[i][j]=(s[j]=='1');
        }
    }
    scanf("%s",s);
    B cur;
    for(int j=0;j<m;++j){
        cur[j]=(s[j]=='1');
    }
    for(int i=0;i<=m;++i){
        B x=cur,e;
        e[i]=1;
        bool ok=false;
        for(int p=m-1;p>=0;--p){
            if(!x[p])continue;
            if(base[p].none()){
                base[p]=x;
                f[p]=e;
                ok=true;
                break;
            }
            x^=base[p];
            e^=f[p];
        }
        if(!ok){
            d=i;
            for(int j=0;j<=d;++j){
                rel[j]=e[j];
            }
            break;
        }
        v.push_back(cur);
        B next;
        for(int j=0;j<m;++j){
            next[j]=(a[j]&cur).count()%2;
        }
        cur=next;
    }
    if(d){
        pw[0][1]=1;
        pw[0]=rem(pw[0]);
        for(int j=1;j<K;++j){
            pw[j]=mul(pw[j-1],pw[j-1]);
        }
    }
    scanf("%d",&q);
    while(q--){
        unsigned k;
        scanf("%u",&k);
        B ans;
        if(d){
            F p;
            p[0]=1;
            for(int j=0;j<K;++j){
                if(k>>j&1)p=mul(p,pw[j]);
            }
            for(int j=0;j<d;++j){
                if(p[j])ans^=v[j];
            }
        }
        for(int j=0;j<m;++j){
            putchar(ans[j]?'1':'0');
        }
        puts("");
    }
    return 0;
}
