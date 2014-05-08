#include <iostream>
using namespace std;

int main()
{
    int t,n,i;
    cin>>t;
    i=0;
    while(i<t)
        {
            cin>>n;
            n=(n*63+7492)*5-498;
            n=(n/10)%10;
            if(n<0)n=n*(-1);
            cout<<n<<endl;
            i++;
        }

    return 0;
}
