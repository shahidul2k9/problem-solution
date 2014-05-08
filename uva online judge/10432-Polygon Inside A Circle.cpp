#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{

    double PI,r,n,a,b,w;
    PI=2*acos(0.0);
    while(scanf("%lf%lf",&r,&n)==2)
    {
        w=PI/n;
        a=r*cos(w);
        b=r*sin(w);
        printf("%.3lf\n",n*a*b);
    }
    return 0;
}
