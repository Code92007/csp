#include<bits/stdc++.h>
using namespace std;
const int N=310,M=303;
int n,a[N],b[N];
signed char dp[N][M][M];
bool check(int i,int x,int y){
    if(x<1 || x>=M || y<1 || y>=M)return false;
    signed char &v=dp[i][x][y];
    if(v!=-1)return v;
    if(i==n-1)return v=((x+y)/2==b[i]);
    int l=3*b[i]-x-y;
    for(int z=l;z<=l+2;++z){
        if(check(i+1,y,z))return v=1;
    }
    return v=0;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&b[i]);
    }
    memset(dp,-1,sizeof dp);
    for(int x=1;x<=2*b[0] && !a[0];++x){
        int l=max(1,2*b[0]-x),r=2*b[0]+1-x;
        for(int y=l;y<=r;++y){
            if(check(1,x,y)){
                a[0]=x,a[1]=y;
                break;
            }
        }
    }
    for(int i=1;i<n-1;++i){
        int l=3*b[i]-a[i-1]-a[i];
        for(int z=l;z<=l+2;++z){
            if(check(i+1,a[i],z)){
                a[i+1]=z;
                break;
            }
        }
    }
    for(int i=0;i<n;++i){
        printf("%d%c",a[i],i==n-1?'\n':' ');
    }
    return 0;
}
