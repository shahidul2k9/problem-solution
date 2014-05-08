#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int a,b,i,c,n,k;
    while(scanf("%d%d",&a,&b)==2){
        cout<<a<<" "<<b<<" ";
        if(a>b){
            a=a+b;
            b=a-b;
            a=a-b;
        }
        c=1;
        for(k=a;k<=b;k++){
            n=k;
            for(i=1;n>1;i++)
            {
            if(n%2!=0)n=3*n+1;
            else n=n/2;
            }
            if(c<i)c=i;

        }
        cout<<c<<endl;
    }
    return 0;
}
