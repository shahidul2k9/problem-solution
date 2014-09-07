#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define EPSILON 1e-8
#define SQR(x) ((x)*(x))
 
double PI;
 
typedef struct {
  double x, y;
} Point;
 
typedef struct {
  Point o;
  double r;
} Circle;
 
double CIArea (Circle A,  Circle B) {
  double d, dA, dB, tx, ty;
 
  d = sqrt(SQR(B.o.x - A.o.x) + SQR(B.o.y - A.o.y));
 
  if ((d < EPSILON) || (d + A.r <= B.r) || (d + B.r <= A.r))
    return SQR((B.r < A.r) ? B.r : A.r) * PI;
  if (d >= A.r + B.r)
    return 0;
 
  dA = tx = (SQR(d) + SQR(A.r) - SQR(B.r))/d/2;
  ty = sqrt(SQR(A.r) - SQR(tx));
  dB = d - dA;
 
  return SQR(A.r)*acos(dA/A.r) - dA*sqrt(SQR(A.r)-SQR(dA))
    + SQR(B.r)*acos(dB/B.r) - dB*sqrt(SQR(B.r)-SQR(dB));
}
 
int main () {
    //freopen("input.txt","r",stdin);
  int test,cs=1;
  Circle A, B;
 
  PI = acos(-1);
    scanf("%d",&test);
  while (test--){
      scanf("%lf %lf %lf %lf %lf %lf",&A.o.x, &A.o.y, &A.r, &B.o.x, &B.o.y, &B.r);
    printf("Case %d: %.8lf\n", cs++, CIArea(A, B));
  }
  return 0;
}