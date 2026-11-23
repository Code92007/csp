#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef map<string,ll> counts;
const int N=1010;
int n,p;
char s[N];
ll num(){
    if(!isdigit(s[p]))return 1;
    ll x=0;
    while(isdigit(s[p])){
        x=x*10+s[p++]-'0';
    }
    return x;
}
void add(counts &a,const counts &b,ll k){
    for(const auto &[x,v]:b){
        a[x]+=v*k;
    }
}
counts formula(){
    counts ans;
    while(s[p] && s[p]!=')' && s[p]!='+' && s[p]!='='){
        counts cur;
        if(s[p]=='('){
            ++p;
            cur=formula();
            ++p;
        }
        else{
            string x(1,s[p++]);
            if(islower(s[p]))x+=s[p++];
            cur[x]=1;
        }
        ll k=num();
        add(ans,cur,k);
    }
    return ans;
}
counts expr(){
    counts ans;
    while(s[p] && s[p]!='='){
        ll k=num();
        counts cur=formula();
        add(ans,cur,k);
        if(s[p]=='+')++p;
        else break;
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%1000s",s);
        p=0;
        counts a=expr();
        ++p;
        counts b=expr();
        puts(a==b?"Y":"N");
    }
    return 0;
}
