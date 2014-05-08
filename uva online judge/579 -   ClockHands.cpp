#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    float h,m,dh,dm,deg;
    while(1){
        scanf("%f:%f",&h,&m);
        if(h==0&&m==0)break;
        dm = 6*m;
        dh = 30*(h+(dm/360));
        if(dm>dh) deg = dm-dh;
        else deg = dh-dm;
        if(deg>180)printf("%.3f\n",360-deg);
        else printf("%.3f\n",deg);
    }
    return 0;
}
