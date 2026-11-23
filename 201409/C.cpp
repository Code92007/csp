#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int op,n;
char pat[N],s[N];
string lower(string str){
    for(char &c:str){
        c=tolower((unsigned char)c);
    }
    return str;
}
int main(){
    scanf("%s%d%d",pat,&op,&n);
    string p=op?pat:lower(pat);
    while(n--){
        scanf("%s",s);
        string key=op?s:lower(s);
        if(key.find(p)!=string::npos)puts(s);
    }
    return 0;
}
