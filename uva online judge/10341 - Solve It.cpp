#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;
#define EPS 1e-7
int p,q,r,s,t,u;
double lo,hi,x;
double f(double x){
   return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
   }
double bisection(){
    lo=0;
    hi=1;
    while(hi-lo>EPS){

    x=(lo+hi)/2;
    if(f(lo)*f(x)<=0)hi=x;
    else lo = x;
    }
return (lo+hi)/2;
}
int main()
{
    freopen("input.txt", "r", stdin);
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u)==6){
        if(f(0)*f(1)>0)printf("No solution\n");
        else printf("%.4lf\n",bisection());
    }

    return 0;
}
