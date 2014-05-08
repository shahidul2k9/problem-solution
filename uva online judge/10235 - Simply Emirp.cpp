#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
    int n,root,rn,mod,mul;
    long int i;
    while(scanf("%d",&n)==1){

        root = ceil(sqrt(n));
        mod = 1;

       for(i =2;i<=root;i++)if(n%i==0){mod=0;break;}



        if(mod ==0 )printf("%d is not prime.\n",n);

        else{
            mul = 1;
            rn =0;
            for(i =n;i!=0;i=i/10){
                rn = rn*10+i%10;
            }
        root = ceil(sqrt(rn));
        mod = 1;

        for(i =2;i<=root;i++)if(rn%i==0){mod=0;break;}


        if(mod == 1 && n!=rn) printf("%d is emirp.\n",n);
        else printf("%d is prime.\n",n);
        }
    }
    return 0;
}
