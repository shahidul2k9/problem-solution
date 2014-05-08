#include <stdio.h>
int mod(int b,int p,int m){
    if(p==0)return 1;
    else if (p%2==0)return (mod(b,p/2,m)*mod(b,p/2,m))%m;
    else return ((b%m)*mod(b,p-1,m))%m;
}
int main(){
int b,p,m;
 while(scanf("%d%d%d",&b,&p,&m)==3)
     printf("%d\n",mod(b,p,m));
 return 0;
}
