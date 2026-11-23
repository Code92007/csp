#include<bits/stdc++.h>
using namespace std;
const int N=1<<16,M=85,K=20;
int n,k,cnt[N];
double p[K],dp[N][M];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%lf",&p[i]);
    }
    int len=1<<n;
    for(int s=1;s<len;++s){
        cnt[s]=cnt[s>>1]+(s&1);
    }
    for(int s=len-2;s>=0;--s){
        int need=(n-cnt[s])*k;
        double sum=0;
        for(int i=0;i<n;++i){
            if(s>>i&1)sum+=p[i];
        }
        for(int c=need-1;c>=0;--c){
            double val=1+sum*dp[s][c+1];
            for(int i=0;i<n;++i){
                if(!(s>>i&1))val+=p[i]*dp[s|(1<<i)][c];
            }
            dp[s][c]=val;
        }
    }
    printf("%.12lf\n",dp[0][0]);
    return 0;
}
