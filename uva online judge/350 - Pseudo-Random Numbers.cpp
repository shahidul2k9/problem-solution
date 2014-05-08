#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector <int> v;
    vector <int> ::iterator it;
    int Z,I,M,L,i,ct=1;
    while(1){
        cin>>Z>>I>>M>>L;
        if(Z==0&&I==0&&M==0&&L==0)break;

        while(1){
        v.push_back(L);
        L = (Z*L+I)%M;
        it = find(v.begin(),v.end(),L);
        if(it!=v.end()){
            for(i=0;v[i]!=*it;i++){}
            cout<<"Case "<<ct<<": "<<v.size()-i<<endl;
            break;
            }
        }
        v.clear();
        ct++;

    }
    return 0;
}
