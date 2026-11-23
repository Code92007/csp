#include<bits/stdc++.h>
using namespace std;
const int N=13;
int a,b,c,l,r,first=2;
int mon[N]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool leap(int y){
    return y%400==0 || (y%4==0 && y%100!=0);
}
int main(){
    scanf("%d%d%d%d%d",&a,&b,&c,&l,&r);
    for(int y=1850;y<=r;++y){
        if(y>=l){
            int w=first;
            for(int m=1;m<a;++m){
                w=(w+mon[m]+(m==2 && leap(y)))%7;
            }
            int d=1+(c%7-w+7)%7+7*(b-1);
            if(d>mon[a]+(a==2 && leap(y)))puts("none");
            else printf("%d/%02d/%02d\n",y,a,d);
        }
        first=(first+365+leap(y))%7;
    }
    return 0;
}
