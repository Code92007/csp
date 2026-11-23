#include<bits/stdc++.h>
using namespace std;
const int N=13;
int y,d,m=1,len[N]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    scanf("%d%d",&y,&d);
    if(y%400==0 || (y%4==0 && y%100!=0))len[2]=29;
    while(d>len[m]){
        d-=len[m];
        ++m;
    }
    printf("%d\n%d\n",m,d);
    return 0;
}
