#include<bits/stdc++.h>
using namespace std;
const int N=15;
struct node{
    int l,b,r,t,id;
}a[N];
int n,m,x,y;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        node &v=a[i];
        scanf("%d%d%d%d",&v.l,&v.b,&v.r,&v.t);
        v.id=i+1;
    }
    while(m--){
        scanf("%d%d",&x,&y);
        int p=-1;
        for(int i=n-1;i>=0;--i){
            node &v=a[i];
            if(v.l<=x && x<=v.r && v.b<=y && y<=v.t){
                p=i;
                break;
            }
        }
        if(p<0)puts("IGNORED");
        else{
            node v=a[p];
            printf("%d\n",v.id);
            for(int i=p;i<n-1;++i){
                a[i]=a[i+1];
            }
            a[n-1]=v;
        }
    }
    return 0;
}
