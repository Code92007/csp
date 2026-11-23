#include<bits/stdc++.h>
using namespace std;
int n,k,cnt=1;
queue<int> q;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        q.push(i);
    }
    while(q.size()>1){
        int x=q.front();
        q.pop();
        if(cnt%k && cnt%10!=k)q.push(x);
        ++cnt;
    }
    printf("%d\n",q.front());
    return 0;
}
