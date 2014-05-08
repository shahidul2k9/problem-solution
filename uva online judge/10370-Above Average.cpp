#include <iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int c,m,i,n,co,a[1000];
    float s,ave,per;
    cin>>c;
    m=0;
    while(m<c)
    {
        cin>>n;
        s=0;
        co=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            s=s+a[i];
        }
        ave=(float)s/n;
        for(i=0;i<n;i++)
            if(a[i]>ave)co++;
        per=(float)co*100/n;
        printf("%.3f",per);
        cout<<"%"<<endl;
        m++;
    }
    return 0;
}
