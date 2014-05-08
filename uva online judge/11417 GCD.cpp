#include <iostream>
#include<stdio.h>
using namespace std;
int GCD(int x,int y){
    int mod;
    while(1){
        mod=y%x;
        if(mod==0)return x;
        y=x;
        x=mod;
    }
}
int main()
{
    int N,G,i,j;
    scanf("%d",&N);
    while(N){
        G=0;
    for(i=1;i<N;i++)
    for(j=i+1;j<=N;j++)
    {G+=GCD(i,j);}
    cout<<G<<endl;
    scanf("%d",&N);
    }
    return 0;
}
