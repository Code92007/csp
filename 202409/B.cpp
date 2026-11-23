#include<bits/stdc++.h>
using namespace std;
const int N=31,M=128;
int n,q,k,f[N][M];
string s,t;
void read(string &str){
    str.clear();
    int c;
    while((c=getchar())!=EOF && c!='\n'){
        str+=char(c);
    }
}
int main(){
    read(s);
    s=s.substr(1,s.size()-2);
    for(int i=0;i<M;++i){
        f[0][i]=i;
    }
    scanf("%d",&n);
    read(t);
    while(n--){
        read(t);
        f[0][int(t[1])]=t[2];
    }
    for(int i=1;i<N;++i){
        for(int j=0;j<M;++j){
            f[i][j]=f[i-1][f[i-1][j]];
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&k);
        putchar('#');
        for(char &ch:s){
            int c=ch;
            for(int i=0;i<N;++i){
                if(k>>i&1)c=f[i][c];
            }
            putchar(c);
        }
        puts("#");
    }
    return 0;
}
