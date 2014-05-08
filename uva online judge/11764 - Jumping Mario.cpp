#include <iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
    int t,ct,height,n,i,highjump,lowjump;
    vector<int> v;
    ct=1;
    scanf("%d",&t);
    while(ct<=t)
    {
        highjump = lowjump = 0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {   scanf("%d",&height);
            v.push_back(height);
        }

    for(i=0;i<n-1;i++)
    {
        if(v[i]<v[i+1])highjump = highjump + 1;
        else if(v[i]>v[i+1])lowjump = lowjump +1;
    }
    printf("Case %d: %d %d\n",ct,highjump,lowjump);
    ct++;
    v.clear();
    }
    return 0;
}
