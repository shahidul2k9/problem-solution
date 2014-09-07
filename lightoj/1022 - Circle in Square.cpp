#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main() {
    double a,r,pi;
    pi = 2*acos(0);
    int TC,tc;
    tc = 1;
    cin >> TC;
    while(tc<=TC) {
        cin >> r;
        a = r+r;
        printf("Case %d: %.2lf\n",tc,((a*a)-(pi*r*r)));
        tc ++;
    }
    return 0;
}
