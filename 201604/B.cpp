#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=15,M=10,K=4,L=16;
int a[N][M],col,top,cnt;
P b[L];
bool check(int x){
    for(int i=0;i<cnt;++i){
        int r=x+b[i].first,c=col+b[i].second;
        if(r>=N || a[r][c])return false;
    }
    return true;
}
int main(){
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<K;++i){
        for(int j=0,x;j<K;++j){
            scanf("%d",&x);
            if(x)b[cnt++]=P(i,j);
        }
    }
    scanf("%d",&col);
    --col;
    while(check(top+1)){
        ++top;
    }
    for(int i=0;i<cnt;++i){
        a[top+b[i].first][col+b[i].second]=1;
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            printf("%d%c",a[i][j],j==M-1?'\n':' ');
        }
    }
    return 0;
}
