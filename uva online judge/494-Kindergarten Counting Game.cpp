#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char a[1000];
    int i,wn,l;
    while(gets(a)!=NULL)
    {
        wn=0;
        l=strlen(a);
        for(i=0;i<l;i++)
        {

            if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
            {
                  if((a[i+1]>='a'&&a[i+1]<='z')||(a[i+1]>='A'&&a[i+1]<='Z')){}

                 else wn++;


            }

        }

        cout<<wn<<endl;
    }
    return 0;
}
