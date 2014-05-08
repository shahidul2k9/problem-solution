#include <iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int i,k,n;
    int ar[64];

    while(1){
        cin>>i;
        if(i==0)break;
            n=0;
            for(k=0;i>0;k++){
                ar[k]=i%2;
                if(ar[k]==1)n++;
                i=i/2;
            }
            cout<<"The parity of ";
            for(k=k-1;k>=0;k--)printf("%d",ar[k]);
            cout<<" is "<<n<<" (mod 2)."<<endl;
    }

    return 0;
}
