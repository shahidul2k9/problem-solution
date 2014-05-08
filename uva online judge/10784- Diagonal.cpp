#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    int cerial,con;
    double N,n;
    cerial=1;
    while(1)
    {
        cin>>N;
        if(N==0)break;
        N=(3+sqrt(9+8*N))/2;
        con=ceil(N);
        cout<<"Case "<<cerial<<": ";
        cout<<con<<endl;
        cerial++;
    }
    return 0;
}
