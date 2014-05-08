#include <iostream>
#include<stdio.h>
using namespace std;
int function(int n){
    n=n+1;
    if(n<=100){return(function(n));}
    else return n;
}
int main()
{
    int n,x;
    scanf("%d",&n);
    while(1){
        if(n==0)break;
        x=n;
        if(n<=100){n=function(n);}
        n=n-10;
        cout<<"f91("<<x<<") = "<<n<<endl;
        scanf("%d",&n);
    }
    return 0;
}
