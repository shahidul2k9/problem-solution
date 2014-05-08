#include <iostream>

using namespace std;

int main()
{
    int t,a,b,i;
    cin>>t;
    i=0;
    while(i<t)
        {
            cin>>a>>b;
            if(a==b)cout<<"="<<endl;
            else if(a<b)cout<<"<"<<endl;
            else cout<<">"<<endl;
            i++;
        }
    return 0;
}
