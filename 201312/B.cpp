#include<bits/stdc++.h>
using namespace std;
const int N=20;
char s[N],c;
int n,w=1,sum;
int main(){
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n-1;++i){
        if(s[i]!='-')sum+=(s[i]-'0')*w++;
    }
    int r=sum%11;
    c=r==10?'X':char('0'+r);
    if(s[n-1]==c)puts("Right");
    else{
        s[n-1]=c;
        puts(s);
    }
    return 0;
}
