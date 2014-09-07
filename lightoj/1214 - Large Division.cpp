#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
    long int t;
    cin >> t;
    long int i, j,len, b, d,k;
    string a;

    for (i=1; i<=t; i++) {
        cin>>a;
        cin >> b;
        d = 0;
        if (a[0]=='-') j=1;
        else j=0;
        len = a.length();
        for (; j<len; j++) {


            d = d*10 + (a[j]-'0');
            d = d%b;
        }

        cout << "Case " << i << ": ";
        if (d) cout << "not divisible" << endl;
        else cout << "divisible" << endl;

    }
    return 0;
}
