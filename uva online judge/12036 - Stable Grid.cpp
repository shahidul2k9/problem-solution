#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    map <int,int> m;
    vector <int> v;
    int t,n,item,element,i,size,choice,ct=1;
    cin>>t;
    while(t--){
        choice =1;
        cin>>n;
        element =1;
        size=n*n;
        while(element<=size){
            cin>>item;
            if(m.find(item)!=m.end())m[item] = m[item]+1;
            else {
                m[item]=1;
                v.push_back(item);
                }
           element++;
        }
        size = m.size();
    for(i=0;i<size;i++)if(m[v[i]]>n)choice = 0;
    if(choice==0)cout<<"Case "<<ct<<": no"<<endl;
    else cout<<"Case "<<ct<<": yes"<<endl;
    ct++;
    v.clear();
    m.clear();
    }

    return 0;
}
