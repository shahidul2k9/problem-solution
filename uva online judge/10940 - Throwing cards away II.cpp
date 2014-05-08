#include <iostream>
#include <vector>
using namespace std;
int fun(int n){
    if(n ==1)return 1;
    else if(n%2==0)return (2*fun(n/2)-1);
    else return (2*fun(n/2)+1);
}
int main()
{
    int n,m;
    cin>>n;
    while(n>0){
        if(n==1){cout<<1<<endl;cin>>n;continue;}
        m = fun(n);

        if(m == 1)cout<<n<<endl;
        else
        cout<<m-1<<endl;
        cin>>n;
    }
       return 0;
}
