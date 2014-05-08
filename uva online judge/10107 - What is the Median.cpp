#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 10001
int main()
{
    //freopen("input.txt","r",stdin);
    long long int a[MAX];
    long long int temp, out, n = 0;
    int i, ind =-1;
    while(cin >> temp){
        for(i=ind; i>=0 && (a[i]>temp); i--) {
                     a[i+1] = a[i];
            }

        a[i+1] = temp;
        n++;
        ind++;
        if(n%2==0)
            out = (a[n/2-1]+a[n/2])/2;
        else out = a[n/2];
        cout << out << endl;
    }
    return 0;
}
