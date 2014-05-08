#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test,cs=0,a,b,c;
    scanf("%d",&test);
    while(test--){
        scanf("%d %d %d",&a,&b,&c);
        if(a<21&&b<21&&c<21)printf("Case %d: good\n",++cs);
        else
            printf("Case %d: bad\n",++cs);
    }
    return 0;
}
