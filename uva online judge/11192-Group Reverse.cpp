#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    int g,con,m,i,k,l,glen;
    char a[101];
    freopen("input.txt","r",stdin);
    while(1)
        {
            cin>>g;
            if(g==0)break;
            gets(a);
            l=strlen(a);
            glen=(l-1)/g;
            con=1;
            k=glen;
            m=2;
            for(i=0;i<g;i++)
                {
                    for(k=k;k>=con;k--)
                    cout<<a[k];
                    k=m*glen;
                    m++;
                    con=con+glen;
                }
            cout<<endl;
        }
    return 0;
}
