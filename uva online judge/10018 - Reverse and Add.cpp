#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int t,k,curt=0;
    long int a,b,i;
    scanf("%d",&t);
    while(curt<t){
        cin>>a;

          b = 0;
            for(i =a;i!=0;i=i/10){
                b = b*10+i%10;
            }
        for(k=1; ;k++){

            a = a+b;
                b = 0;
                for(i =a;i!=0;i=i/10){
                b = b*10+i%10;
            }
            if(a == b){
                printf("%d %ld\n",k,a);
                break;
            }
        }
        curt++;
    }
    return 0;
}
