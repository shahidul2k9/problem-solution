#include <iostream>
#include <stdio.h>
#include<math.h>
using namespace std;

int main()
{
    float c,e,f,n;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%f%f%f",&e,&f,&c);
        n = ((e+f)/(c-1))-1;
        if(n<=0)cout<<0<<endl;
        else cout<<ceil(n)<<endl;
    }
    return 0;
}
