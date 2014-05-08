#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int n,x[1000],testcase,count,i;
    testcase=1;
    scanf("%d",&n);
    while(n>0)
    {
        count=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
            if(x[i]==0)count=count+1;
        }
    cout<<"Case "<<testcase<<": "<<n-2*count<<endl;
    testcase=testcase+1;
    scanf("%d",&n);
    }
    return 0;
}
