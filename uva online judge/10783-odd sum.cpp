#include <iostream>

using namespace std;

int main()
{
    int t,a,p,s,i;
    cin>>t;

    i=1;
    while(t>0){
        cin>>a>>p;
        if(a%2==0)a=a+1;
        if(p%2==0)p=p-1;
        s=(2*a+2*p+p*p-a*a)/4;
        cout<<"Case "<<i<<": "<<s<<endl;
        i++;t--;
    }
    return 0;
}
