#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    int n,i,x,noswap,k;
    while(scanf("%d",&n)==1)
    {
        noswap=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            v.push_back(x);
        }
        for(i=0;i<n-1;i++)
        for(k=0;k<n-1;k++)
        {
            if(v[k]>v[k+1])
            {
                swap(v[k],v[k+1]);
                noswap=noswap+1;
            }
        }
        cout<<"Minimum exchange operations : "<<noswap<<endl;
        v.clear();
        }
}
