#include <iostream>
using namespace std;

int main()
{
    long int a,b,n,moda,modb,summod;
    while(1){
        cin>>a>>b;
        if(a==0&&b==0){
            break;
            }
        summod=0;n=0;
        while(1){
            if(a==0&&b==0)break;
            moda=a%10;
            modb=b%10;
            a=a/10;
            b=b/10;
            summod=summod+moda+modb;

            if(summod>9){
                n++;
                summod=1;
                }
            else summod=0;
        }
        if(n>1)cout<<n<<" carry operations."<<endl;
        else if(n==1)cout<<n<<" carry operation."<<endl;
        else cout<<"No carry operation."<<endl;
    }
    return 0;
}
