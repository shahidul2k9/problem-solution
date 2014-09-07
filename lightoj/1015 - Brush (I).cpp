#include <iostream>

using namespace std;

int main() {
    int T,t,x,n,i;
    unsigned long long int s;
    cin>>T;
    t=1;
    while(t<=T) {
        s=0;
        cin>>n;
        for(i=0; i<n; i++) {
            cin>>x;
            if(x>=0)s+=x;
        }
        cout<<"Case "<<t<<": "<<s<<endl;
        t++;
    }
    return 0;
}
