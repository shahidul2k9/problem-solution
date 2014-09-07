#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T,t,me,li;
    cin>>T;
    t=1;
    while(T>=t) {
        cin>>me>>li;
        cout << "Case "<<t<<": "<<(int)abs((double)me-li)*4+me*4+19<<endl;
        t++;
    }
    return 0;
}
