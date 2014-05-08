#include <iostream>

using namespace std;

int main()
{
    int a,b,carry,mod1,mod2,sumofcarry,sum;
     cin>>a>>b;
    while(a!=0&&b!=0)
        {
            carry=0;
            sum=0;
            sumofcarry=0;
            while(1)
                {

                    mod1=a%10;
                    mod2=b%10;
                    sum=mod1+mod2+carry;
                    carry=sum/10;
                    if(carry==1)
                    sumofcarry++;
                    a=a/10;
                    b=b/10;
                    if(a==0&&b==0)break;
                }

            if(sumofcarry==0)cout<<"No carry operation."<<endl;
            else if(sumofcarry==1)cout<<"1 carry operation."<<endl;
            else cout<<sumofcarry<<" carry operations."<<endl;
            cin>>a>>b;
        }
    return 0;
}
