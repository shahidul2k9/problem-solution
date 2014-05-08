#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    vector <int> v;
    int t,intot,age,ct=1;
    scanf("%d",&t);
    while(ct<=t){
        scanf("%d",&intot);
        for(int i =0;i<intot;i++){
            scanf("%d",&age);
            v.push_back(age);
        }
        printf("Case %d: %d\n",ct,v.at(intot/2));
        ct++;
        v.clear();
    }
    return 0;
}
