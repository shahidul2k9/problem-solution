#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int t,n,k,p,i,out;
    cin>>t;
    i=1;
    while(i<=t)
    {
        cin>>n>>k>>p;
        out=(k+p)%n;
        if(out!=0)cout<<"Case "<<i<<": "<<out<<endl;
        else cout<<"Case "<<i<<": "<<n<<endl;
        i++;
    }

    return 0;
}
