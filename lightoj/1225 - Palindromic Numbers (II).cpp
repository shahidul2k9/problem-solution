#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int TC,tc=1;
    string str,rev;
    cin >> TC;

    while(tc<=TC) {
        cin >>str;

        rev = str;
        reverse(rev.begin(),rev.end());
        if(str==rev) {
            cout << "Case "<<tc<<": Yes"<<endl;
        } else    cout << "Case "<<tc<<": No"<<endl;
        tc++;
    }
    return 0;
}
