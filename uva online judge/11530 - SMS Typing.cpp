#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    int t,tn,click,i;
    tn=1;
    char a[100];
    freopen("input.txt","r",stdin);
    cin>>t;
    gets(a);
    while(tn<=t)
        {
            gets(a);
            click=0;
            for(i=0;a[i]!=NULL;i++)
                {
                    if(a[i]=='a'||a[i]=='d'||a[i]=='g'||a[i]=='j'||a[i]=='m'||a[i]=='p'||a[i]=='t'||a[i]=='w'||a[i]==' ')
                    click=click+1;
                    else if(a[i]=='b'||a[i]=='e'||a[i]=='h'||a[i]=='k'||a[i]=='n'||a[i]=='q'||a[i]=='u'||a[i]=='x')
                    click=click+2;
                    else if(a[i]=='c'||a[i]=='f'||a[i]=='i'||a[i]=='l'||a[i]=='o'||a[i]=='r'||a[i]=='v'||a[i]=='y')
                    click=click+3;
                    else click = click +4;
                }
         cout<<"Case #"<<tn<<": "<<click<<endl;
        tn++;
        }
    return 0;
}
