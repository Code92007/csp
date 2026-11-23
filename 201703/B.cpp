#include<bits/stdc++.h>
using namespace std;
int n,m,p,q;
vector<int> a;
int main(){
    scanf("%d%d",&n,&m);
    a.resize(n);
    iota(a.begin(),a.end(),1);
    while(m--){
        scanf("%d%d",&p,&q);
        int x=find(a.begin(),a.end(),p)-a.begin();
        a.erase(a.begin()+x);
        a.insert(a.begin()+x+q,p);
    }
    for(int i=0;i<n;++i){
        if(i)putchar(' ');
        printf("%d",a[i]);
    }
    puts("");
    return 0;
}
