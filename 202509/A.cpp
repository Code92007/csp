#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=25;
int n,a,cnt;
char s[M];
int read(){
    scanf("%s",s);
    int i=0,x=0,k=-1,sgn=1;
    if(s[i]=='-' || s[i]=='+'){
        if(s[i]=='-')sgn=-1;
        ++i;
    }
    for(;s[i];++i){
        if(s[i]=='.')k=0;
        else{
            x=x*10+s[i]-'0';
            if(k>=0)++k;
        }
    }
    if(k<0)k=0;
    while(k<2){
        x*=10;
        ++k;
    }
    return x*sgn;
}
int main(){
    scanf("%d%d",&n,&a);
    ll r=a*100;
    for(int i=0;i<n;++i){
        ll x=read(),y=read();
        cnt+=(x*x+y*y<=r*r);
    }
    printf("%.8f\n",4.0*cnt/n);
    return 0;
}
