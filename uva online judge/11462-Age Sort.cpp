#include <iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int age[200],p,i;
    freopen("input.txt","r",stdin);
    scanf("%d",&p);
    while(p!=0)
        {
            for(i=0;i<p;i++)scanf("%d",&age[i]);
            sort(age,age+p);
            for(i=0;i<p-1;i++)printf("%d ",age[i]);
            printf("%d\n",age[p-1]);
            scanf("%d",&p);
        }

    return 0;
}
