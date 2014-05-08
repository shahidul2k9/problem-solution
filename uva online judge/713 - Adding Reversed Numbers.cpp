#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    char a[500],b[500];
    char ch;
    int i,t,len1,len2,c,s,minlen,curt=0,chec,mod;
    cin>>t;
    gets(a);
    while(curt<t){
        chec =0;
    for(i =0;;i++){
        scanf("%c",&ch);
        if(ch == ' ')break;
        a[i]=ch;
        }
        a[i]=NULL;

    gets(b);

    len1 = strlen(a);
    len2 = strlen(b);
    if(len1>len2)minlen = len2;
    else minlen = len1;
    c =0;
    for(i =0;i<minlen;i++){
        s =c+a[i]+b[i]-96;
        mod =s%10;
        if(mod!=0)chec=1;
        if(chec ==1)
        cout<<mod;
        c =s/10;
    }
    if(len1>len2){

        for(i=i;i<len1;i++){
              s = c+a[i]-48;
              mod =s%10;
              if(mod!=0)chec=1;
                if(chec ==1)
                cout<<mod;
              c =s/10;
              }

    }
      else{
        for(i=i;i<len2;i++){
              s = c+b[i]-48;
                mod =s%10;
              if(mod!=0)chec=1;
                if(chec ==1)
                cout<<mod;
              c =s/10;
              }
    }
    if(c>0)cout<<c;
    cout<<endl;

    curt++;
    }
    return 0;
}
