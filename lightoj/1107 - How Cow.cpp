#include <iostream>

using namespace std;

int main() {
    int T,t,m,x,y,x1,x2,y1,y2,i;
    cin>>T;
    t=1;
    while(t<=T) {
        cout<<"Case "<<t<<":"<<endl;
        cin>>x1>>y1>>x2>>y2;
        cin>>m;
        for(i=0; i<m; i++) {
            cin>>x>>y;
            if(x>x1&&x<x2&&y>y1&&y<y2)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        t++;
    }
    return 0;
}
