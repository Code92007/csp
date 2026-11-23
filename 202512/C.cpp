#include<bits/stdc++.h>
using namespace std;
const int N=405,M=50010,K=6,L=15;
int z,k,t,dir,n,m,op[M][K];
char a[N][N],b[L][L];
char &at(int x,int y){
    for(int i=0;i<dir;++i){
        int v=y;
        y=z-1-x;
        x=v;
    }
    return a[x][y];
}
int main(){
    scanf("%d",&z);
    for(int i=0;i<z;++i){
        scanf("%s",a[i]);
    }
    scanf("%d%d",&k,&t);
    for(int i=0;i<t;++i){
        for(int &x:op[i]){
            scanf("%d",&x);
        }
    }
    for(int id=t-1;id>=0;--id){
        int *p=op[id];
        if(p[0]==1){
            int u=p[1]-1,v=p[2]-1;
            int len=p[3],rot=p[4]/90;
            dir=(dir+4-p[5])%4;
            for(int i=0;i<len;++i){
                for(int j=0;j<len;++j){
                    b[i][j]=at(u+i,v+j);
                }
            }
            for(int i=0;i<len;++i){
                for(int j=0;j<len;++j){
                    int x=i,y=j;
                    for(int h=0;h<rot;++h){
                        int q=y;
                        y=len-1-x;
                        x=q;
                    }
                    at(u+i,v+j)=b[x][y];
                }
            }
        }
        else{
            int u=p[1]-1,d=p[2]-1;
            int l=p[3]-1,r=p[4]-1;
            for(int i=u;i<=d;++i){
                for(int j=l;j<=r;++j){
                    b[i-u][j-l]=at(i,j);
                }
            }
            for(int i=u;i<=d;++i){
                for(int j=l;j<=r;++j){
                    at(i,j)=p[5]==1?b[d-i][j-l]:b[i-u][r-j];
                }
            }
        }
    }
    while(n<z && at(n,0)!='?'){
        ++n;
    }
    while(m<z && at(0,m)!='?'){
        ++m;
    }
    printf("%d %d\n",n,m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            printf("%c",at(i,j));
        }
        puts("");
    }
    return 0;
}
