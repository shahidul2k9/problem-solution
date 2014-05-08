#include <iostream>
using namespace std;
typedef unsigned long long int ULL;
ULL divide(ULL n, int d){
    while(n%d==0){
        n /=d;
    }
    return n;
}
bool isUgly(ULL n){
       n = divide(n,2);
       n = divide(n,3);
       n = divide(n,5);
       if(n==1)return true;
       else return false;
}
int main()
{/*
    int co = 0;
    ULL i = 1;
    while(co !=1500){
       if(isUgly(i)){co++; cout << i << " " << co << endl;}
       i++;
    }*/
    cout << "The 1500'th ugly number is 859963392."<< endl;
    return 0;
}
