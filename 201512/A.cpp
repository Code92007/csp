#include<bits/stdc++.h>
using namespace std;
int n,sum;
int main(){
    scanf("%d",&n);
    while(n){
        sum+=n%10;
        n/=10;
    }
    printf("%d\n",sum);
    return 0;
}
