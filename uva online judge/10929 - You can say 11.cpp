#include <iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main()
{
    int len,i,c,s;
    string str;
    while(true){
        cin>>str;
        len = str.length();
        if(str.at(0)=='0'&&len==1)break;
        c = 0;
        for(i = 0;i<len;i= i+1){
            s =c*10+str.at(i)-48;
            c = s%11;
        }
        if(c == 0)cout<<str<<" is a multiple of 11."<<endl;
        else cout<<str<<" is not a multiple of 11."<<endl;
    }
    return 0;
}
