#include <iostream>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;

int main()
{
    map < string, int> m;
    map < string, int> :: iterator it;
    string s;
    float n;
    int TC;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> TC;
    getline(cin,s);
    getline(cin,s);
    while(TC--){
       while(getline(cin,s)&& s.length()!=0){
           m[s]= m[s]+1;//cout << "="<< s << "="<<endl;
       }
       n = 0;
       for(it = m.begin();it!=m.end();it++)n = n + (*it).second;
       for(it=m.begin();it!=m.end();it++)
       {
       cout << (*it).first <<" " ;
       printf("%.4f\n",((*it).second*100)/n);
       }
       if(TC!=0)cout << endl;
       m.clear();

    }

    return 0;
}
