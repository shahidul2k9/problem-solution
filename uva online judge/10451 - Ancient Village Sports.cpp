#include <iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main()
{
    double n,area,rin,rout,pi,rinsqure;
    int t = 1;
    pi =2*acos(0);
    while(1){
        scanf("%lf%lf",&n,&area);
        if(n<3)break;
        rinsqure =area/(n*tan(pi/n));
        rin =sqrt(rinsqure);
        rout = rin /cos(pi/n);
        printf("Case %d: %.5lf %.5lf\n",t,(pi*rout*rout-area),(area-pi*rin*rin));
        t++;
    }
    return 0;
}
