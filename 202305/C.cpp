#include<bits/stdc++.h>
using namespace std;
int n,p;
vector<unsigned char> a,b;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        unsigned x;
        scanf("%2x",&x);
        a.push_back(x);
    }
    int len=0,k=0;
    while(true){
        int x=a[p++];
        len|=(x&127)<<k;
        if(!(x&128))break;
        k+=7;
    }
    b.reserve(len);
    while(p<n){
        int x=a[p++],op=x&3,len,off;
        if(!op){
            len=x>>2;
            if(len<60)++len;
            else{
                int cnt=len-59;
                len=0;
                for(int j=0;j<cnt;++j){
                    len|=int(a[p++])<<(8*j);
                }
                ++len;
            }
            for(int j=0;j<len;++j){
                b.push_back(a[p++]);
            }
        }
        else{
            if(op==1){
                len=((x>>2)&7)+4;
                off=((x>>5)<<8)|a[p++];
            }
            else{
                len=(x>>2)+1;
                off=a[p++];
                off|=int(a[p++])<<8;
            }
            for(int j=0;j<len;++j){
                b.push_back(b[b.size()-off]);
            }
        }
    }
    for(int i=0;i<(int)b.size();++i){
        printf("%02x",b[i]);
        if(i%8==7 || i+1==(int)b.size())puts("");
    }
    return 0;
}
