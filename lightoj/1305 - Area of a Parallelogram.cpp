#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int ax,ay,bx,by,cx,cy,dx,dy,area;
    int T,t=1;
    cin>>T;
    while(T>=t) {
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        area = (ax*(by-cy)+bx*(cy-ay)+cx*(ay-by));
        dx=ax+cx-bx;
        dy=ay+cy-by;
        cout<<"Case "<<t<<": "<<dx<<" "<<dy<<" "<<(int)abs((double)area)<<endl;
        t++;
    }
    return 0;
}
