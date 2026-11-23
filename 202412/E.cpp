#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int n,q,a[N],b[N],x[N],y[N],l[N],r[N],st[N],top;
ll pre[N],ans[N],mx[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&b[i]);
    }
    scanf("%d",&q);
    while(q--){
        memcpy(x,a,(n+2)*sizeof *a);
        memcpy(y,b,(n+2)*sizeof *b);
        int k;
        scanf("%d",&k);
        while(k--){
            int i;
            scanf("%d",&i);
            scanf("%d%d",&x[i],&y[i]);
        }
        for(int i=1;i<=n;++i){
            pre[i]=pre[i-1]+y[i];
        }
        top=0;
        for(int i=1;i<=n;++i){
            while(top && x[st[top]]<x[i]){
                --top;
            }
            l[i]=top?st[top]:0;
            st[++top]=i;
        }
        top=0;
        for(int i=n;i>=1;--i){
            while(top && x[st[top]]<x[i]){
                --top;
            }
            r[i]=top?st[top]:n+1;
            st[++top]=i;
        }
        top=0;
        for(int i=1;i<n;++i){
            while(top && st[top]<i){
                --top;
            }
            ll val=x[i]-(pre[r[i]-1]-pre[i]);
            st[++top]=r[i]-1;
            mx[top]=max(val,mx[top-1]);
            ans[i]=mx[top];
        }
        top=0;
        ll res=0;
        for(int i=n-1;i>=1;--i){
            while(top && st[top]>i){
                --top;
            }
            int j=i+1;
            ll val=x[j]-(pre[j-1]-pre[l[j]]);
            st[++top]=l[j];
            mx[top]=max(val,mx[top-1]);
            res^=max(ans[i],mx[top]);
        }
        printf("%lld\n",res);
    }
    return 0;
}
