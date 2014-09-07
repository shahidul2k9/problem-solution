#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

int main() {
    //freopen("input.txt","r",stdin);
    double h,area,a,b,c,d,s,x, triangleArea;
    int test,cs=1;
    cin >> test;
    while(test--) {
        cin >> a >> b >> c >> d;
        x = fabs(a - c);
        s = 0.5*(x+b+d);
        triangleArea = sqrt(s*(s-x)*(s-b)*(s-d));
        h = (triangleArea*2)/x;
        printf("Case %d: %.10lf\n",cs++,(0.5*(a+c)*h));
    }

    return 0;
}
