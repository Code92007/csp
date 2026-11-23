#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
unordered_set<string> a,b;
string read(){
    string s;
    int c=getchar();
    while(isspace(c)){
        c=getchar();
    }
    while(c!=EOF && !isspace(c)){
        s+=char(tolower(c));
        c=getchar();
    }
    return s;
}
int main(){
    scanf("%d%d",&n,&m);
    while(n--){
        a.insert(read());
    }
    while(m--){
        b.insert(read());
    }
    for(auto &s:a){
        cnt+=b.count(s);
    }
    printf("%d\n%zu\n",cnt,a.size()+b.size()-cnt);
    return 0;
}
