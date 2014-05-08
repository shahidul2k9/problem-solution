#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
    double a,b,c,s,PI,triangleArea,radiousOfIncircle,radiousOfCircumcircle,areaOfInnercircle;
		while(scanf("%lf%lf%lf",&a,&b,&c)==3){
            PI = acos(-1);
			s = (a+b+c)/2;
			triangleArea = sqrt(s*(s-a)*(s-b)*(s-c));
			radiousOfIncircle = triangleArea/s;
			radiousOfCircumcircle = a*b*c/sqrt(2*s*(b+c-a)*(c+a-b)*(a+b-c));
			areaOfInnercircle = PI*radiousOfIncircle*radiousOfIncircle;
			printf("%.4lf %.4lf %.4lf\n",((PI*radiousOfCircumcircle*radiousOfCircumcircle)-triangleArea),(triangleArea-areaOfInnercircle),areaOfInnercircle);
		}
    return 0;
}
