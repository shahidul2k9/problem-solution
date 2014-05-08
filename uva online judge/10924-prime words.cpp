#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    int s,i;
    float root;
    char ar[20];
    while(gets(ar)!=NULL){

        s=0;
        for(i=0;ar[i]!=NULL;i++)
        {
            if(ar[i]>='a'&&ar[i]<='z'){s=s-('a')+ar[i]+1;}
            else s=s-('A')+ar[i]+27;
        }

        if((s==1)||(s==2))
        {
            cout<<"It is a prime word."<<endl;
            continue;
        }
        root=sqrt(s);
        root=ceil(root);
        for(i=2;i<=root;i++){
            if(s%i==0)
                {
                    cout<<"It is not a prime word."<<endl;
                    break;
                }
        }
        if((i-1)==root)
        {cout<<"It is a prime word."<<endl;}
    }
    return 0;
}
