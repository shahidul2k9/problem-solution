#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    double r1,r2,h,p,r,k,pi,juice;
    pi=2*acos(0.0);
    int T,t=1;
    cin>>T;
    while(t<=T) {
        cin>>r1>>r2>>h>>p;
        k=h/(r1/r2-1);
        r=((k+p)/k)*r2;
        juice=(pi*(r*r*(p+k)-r2*r2*k))/3;
        printf("Case %d: %.9lf\n",t,juice);
        t++;
    }
    return 0;
}
