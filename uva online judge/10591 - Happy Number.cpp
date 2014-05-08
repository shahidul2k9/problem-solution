#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t,n,s,k,mod,ct=1;
    vector <int> v;
    vector <int> ::iterator it;
    cin>>t;
    while(ct<=t){
        cin>>n;
        v.push_back(n);
        k = n;
        while(1){

            s = 0;
            for(;k!=0;k=k/10){mod = k%10;s = s+mod*mod;}
            if(s == 1){cout<<"Case #"<<ct<<": "<<n<<" is a Happy number."<<endl;break;}

            it = find(v.begin(),v.end(),s);
            if(it!=v.end()){cout<<"Case #"<<ct<<": "<<n<<" is an Unhappy number."<<endl;break;}
            v.push_back(s);
            k = s;
        }
        v.clear();
        ct++;
    }
    return 0;
}
