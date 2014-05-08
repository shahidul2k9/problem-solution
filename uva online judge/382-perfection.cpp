#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    long int k,sum,n;

    printf("PERFECTION OUTPUT\n");
    while(1)
       {
        scanf("%ld",&n);
        if(n == 1){  printf("%5ld  DEFICIENT\n",n);continue;}
        if(n ==0)break;
       sum=1;
       for(k=2;k<n;k++)
            {
             if(n%k==0){sum=sum+k;}
            }
        if(sum<n)
          {
           printf("%5ld  DEFICIENT\n",n);
          }
        else if(sum>n)printf("%5ld  ABUNDANT\n",n);
        else printf("%5ld  PERFECT\n",n);
       }
    printf("END OF OUTPUT\n");
    return 0;
}
