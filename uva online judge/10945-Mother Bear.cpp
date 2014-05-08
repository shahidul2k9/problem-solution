#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    char a1[500],a2[500];
    int x,i,j;
    while(1)
    {
        gets(a1);
        x=strcmp("DONE",a1);
        if(x==0)break;
        i=0;j=0;
        for(i=0;a1[i]!=NULL;i++)
        {
            if((a1[i]>='a'&&a1[i]<='z'))
            {
                a1[j]=a1[i];
                j++;
            }
            else if(a1[i]>='A'&&a1[i]<='Z')
            {
                a1[j]=a1[i]+32;
                j++;

            }

        }
        a1[j]=NULL;
        j=j-1;
        for(i=0;a1[i]!=NULL;i++)
        {
            a2[i]=a1[j];
            j--;
        }
        a2[i]=NULL;
        x=strcmp(a1,a2);
        if(x==0)cout<<"You won't be eaten!"<<endl;
        else cout<<"Uh oh.."<<endl;
    }

    return 0;
}
