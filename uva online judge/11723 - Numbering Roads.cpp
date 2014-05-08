#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    int N,R,i;
    float dif,min;
    i=1;
    while(1){
        scanf("%d%d",&R,&N);
        if(R==0&&N==0)break;
        if(N>=R){
            cout<<"Case "<<i<<": "<<0<<endl;
            i++;
            continue;
        }
        dif=R-N;
        min=dif/N;
        min=ceill(min);
        if(min<=26)cout<<"Case "<<i<<": "<<min<<endl;
        else cout<<"Case "<<i<<": impossible"<<endl;
        i++;
    }
    return 0;
}
