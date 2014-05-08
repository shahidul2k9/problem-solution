#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    int n,con;
    float coca;
    while(scanf("%d",&n)==1){
        coca=((float)n*3-1)/2;
        con=ceil(coca);
        cout<<con<<endl;
        }
    return 0;
}
