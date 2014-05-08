#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char a[1000];
    int x,y,z,i,l,u,c,mod,j;
    while(gets(a)!=NULL)
    {
        l=strlen(a);
        if(a[0]<='9')
        {
            i=l-1;
            while(i>0)
            {
                x=a[i]-48;
                y=a[i-1]-48;
                z=x*10+y;
                if((z<100&&z>96)||(z>64&&z<91)||z==32||z==33||z==44||z==46||z==58||z==59||z==63)
                {
                    printf("%c",z);
                    i=i-2;
                }
                else
                {
                    x=a[i]-48;
                    y=a[i-1]-48;
                    u=a[i-2]-48;
                    z=x*100+y*10+u;
                    i=i-3;
                    printf("%c",z);
                }


            }
            cout<<endl;
            continue;
        }
        l=l-1;
        while(l>=0)
        {
            c=a[l];

            for(j=0;c/10>0;j++)
            {
                mod=c%10;
                cout<<mod;
                c=c/10;
            }
            mod=c%10;
            cout<<mod;
            l--;
        }
        cout<<endl;

    }
    return 0;
}
