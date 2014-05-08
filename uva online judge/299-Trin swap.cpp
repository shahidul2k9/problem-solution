#include <iostream>
#define SIZE 10000
#include<algorithm>
using namespace std;
int s,c;
void fun(int a[])
    {
        int i,k;
        for(i=0;i<s;i++)
                {
                    if(a[i]>i+1&&a[i+1]<a[i])
                        {
                            a[i]=a[i]+a[i+1];
                            a[i+1]=a[i]-a[i+1];
                            a[i]=a[i]-a[i+1];
                            c++;
                        }
                }
        for(k=0;k<s;k++)
            {
                if(a[k]!=k+1)fun(a);
            }

    }
int main()
{
    int a[SIZE],t,tn,i;
    tn=0;
    cin>>t;
    while(tn<t)
        {
            cin>>s;
            c=0;
            for(i=0;i<s;i++)
                {
                    cin>>a[i];
                }
            fun(a);
            cout<<"Optimal train swapping takes "<<c<<" swaps."<<endl;
            tn++;

        }
    return 0;
}
