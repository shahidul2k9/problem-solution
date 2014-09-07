#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;
typedef struct {
    double x,y;
} Point;
double disttance(Point a , Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",sdout);
    Point a,b,o;
    double AB,r,angle;
    int test,cs=1;
    cin>>test;
    while(test--) {
        cin>>o.x>>o.y>>a.x>>a.y>>b.x>>b.y;
        AB = disttance(a,b);
        r = disttance(o,a);
        angle = acos(1 - 0.5*pow((AB/r),2));
        printf("Case %d: %.8lf\n",cs++,angle*r);
    }

    return 0;
}
