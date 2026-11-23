#include<bits/stdc++.h>
using namespace std;
int n,k,x,y;
int main(){
    scanf("%d%d",&n,&k);
    while(k--){
        scanf("%d%d",&x,&y);
        int c=getchar();
        while(isspace(c)){
            c=getchar();
        }
        while(c!=EOF && !isspace(c)){
            if(c=='f')y=min(n,y+1);
            else if(c=='b')y=max(1,y-1);
            else if(c=='l')x=max(1,x-1);
            else x=min(n,x+1);
            c=getchar();
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}
