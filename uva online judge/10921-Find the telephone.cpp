#include <iostream>
#include<stdio.h>
using namespace std;
int main()
{
    char ar[30];
    int i;
        i=0;
        while(gets(ar)!=NULL){

         for(i=0;ar[i]!=NULL;i++){
            if(ar[i]>='A'&&ar[i]<='C')cout<<2;
            else if(ar[i]>='D'&&ar[i]<='F')cout<<3;
            else if(ar[i]>='G'&&ar[i]<='I')cout<<4;
            else if(ar[i]>='J'&&ar[i]<='L')cout<<5;
            else if(ar[i]>='M'&&ar[i]<='O')cout<<6;
            else if(ar[i]>='P'&&ar[i]<='S')cout<<7;
            else if(ar[i]>='T'&&ar[i]<='V')cout<<8;
            else if(ar[i]>='W'&&ar[i]<='Z')cout<<9;
            else if(ar[i]=='1'||ar[i]=='0'||ar[i]=='-')cout<<ar[i];
         }
         cout<<endl;
        }

    return 0;
}
