#include <iostream>
#include <cmath>
#define pi acos(-1.0)
#include <stdio.h>
using namespace std;

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    double ra,rb,rc,a,b,c,A,B,C,area,s;
    int TC,tc;
    tc = 1;
    cin >> TC;
    while(tc<= TC) {
        cin >> ra >> rb >> rc;
        a = rb + rc;
        b = ra + rc;
        c = rb + ra;
        A = acos((b*b+c*c-a*a)/(2*b*c));
        B = acos((c*c+a*a-b*b)/(2*a*c));
        C = acos((a*a+b*b-c*c)/(2*a*b));
        s = (a+b+c)/2;
        area = sqrt(s*(s-a)*(s-b)*(s-c));

        printf("Case %d: ",tc);
        area = area - (0.5)*(ra*ra*A+rb*rb*B+rc*rc*C);
        printf("%.10lf\n",area);
        tc++;
    }
    return 0;
}
