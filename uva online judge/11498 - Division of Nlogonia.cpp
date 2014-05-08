#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,m,x,y,t,a,b,i;
    scanf("%d",&t);
    while(t){
        scanf("%d%d",&n,&m);
        for(i =0;i<t;i++){
            scanf("%d%d",&x,&y);
            a = x - n;
            b = y - m;
            if(a == 0||b == 0)
                printf("divisa\n");
            else if(a>0&&b>0)
                printf("NE\n");
            else if(a<0&&b>0)
                printf("NO\n");
            else if(a<0&&b<0)
                printf("SO\n");
            else
                printf("SE\n");
        }
        scanf("%d",&t);
    }
    return 0;
}
