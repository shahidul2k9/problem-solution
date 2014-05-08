#include <iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n,k,div,ciga,mod,i;
    while(scanf("%d%d",&n,&k)==2){
        ciga=n;
        for(i=0;n>=k;i++)
        {
            div=n/k;
            mod=n%k;
            ciga=ciga+div;
            n=div+mod;
        }
        cout<<ciga<<endl;
    }
    return 0;
}
