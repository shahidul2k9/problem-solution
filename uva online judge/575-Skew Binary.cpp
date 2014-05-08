#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

int main()
{
    char ar[500];
    int l,num,k;
    //freopen("input.txt","r",stdin);
    while(gets(ar))
        {
            l=strlen(ar);
            if(ar[0]=='0'&&ar[1]==NULL)break;
            num=0;
            k=1;
            for(l=l-1;l>=0;l--)
                {
                    num=num+(ar[l]-48)*(pow(2,k)-1);
                    k++;
                }
            cout<<num<<endl;
        }
    return 0;
}
