#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int s,d,t,a,b;
    float ca,cb,cs,cd;
	cin>>t;
    while(t>0){
        cin>>s>>d;


        if(s>=d){
            cs=s;cd=d;
            ca=(cs+cd)/2;
            cb=ca-cd;
            a=ca;b=cb;
            if(ca>a){cout<<"impossible"<<endl;
                    t--;
                     continue;
                    }
            if(a>b)cout<<a<<" "<<b<<endl;
            else cout<<b<<" "<<a<<endl;
        }
        else cout<<"impossible"<<endl;

    t--;
    }

    return 0;
}
