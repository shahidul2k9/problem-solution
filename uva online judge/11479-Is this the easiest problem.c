#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test,cs=0;
    long long  int a,b,c;
    scanf("%d",&test);
    while(test--){

        scanf("%lld %lld %lld",&a,&b,&c);
        printf("Case %d: ",++cs);
        if(a+b<=c||b+c<=a||c+a<=b)printf("Invalid\n");
        else if(a==b&&b==c)printf("Equilateral\n");
        else if(a==b||b==c||c==a)printf("Isosceles\n");
        else printf("Scalene\n");
    }
    return 0;
}
