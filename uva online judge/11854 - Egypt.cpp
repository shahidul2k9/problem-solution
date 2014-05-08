#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int a,b,c,asqure,bsqure,csqure;
    while(1){
        scanf("%d%d%d",&a,&b,&c);
        if(a==0&&b==0&&c==0)break;
        asqure = a*a;
        bsqure =b*b;
        csqure =c*c;
        if((asqure+bsqure==csqure)||(bsqure+csqure==asqure)||(csqure+asqure==bsqure))
        printf("right\n");
        else printf("wrong\n");
    }
    return 0;
}
