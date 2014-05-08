#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

int main()
{
    char array[10000000];
    long int tn,l,i,count,sum;
    float q;
    int m,n,t;
    tn=0;
    t=0;
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    gets(array);

    while(tn<t)
        {
            gets(array);
            l=strlen(array);
            q=sqrt(l);
            m=ceil(q);
            n=floor(q);
            count=0;
            if(m==n)
            {
            for(count=0;count<m;count++)
                {
                    sum=count;
                    cout<<array[count];
                    for(i=m;i<2*m-1;i++)
                        {
                        sum=sum+m;
                        cout<<array[sum];
                        }
                }
             cout<<endl;
            }
        else
        {
        cout<<"INVALID"<<endl;}
        tn=tn+1;
        }

    return 0;
}
