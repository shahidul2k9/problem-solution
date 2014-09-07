#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int TC,tc,lena,lenb,i;
    string a,b;
    bool truth;
    tc = 1;
    cin >> TC;
    getline(cin,a);
    while(tc<=TC) {
        truth = false;
        getline(cin,a);
        getline(cin,b);

        lena = a.size();
        lenb = b.size();
        cout << "Case " << tc << ": ";
        for(i = 0; i<lena ; i++)if(a[i]==' ')a.erase(i,1);
        lena = a.size();
        for(i = 0; i<lena; i++)a[i] = tolower(a[i]);

        for(i = 0; i<lenb; i++)if(b[i]==' ')b.erase(i,1);
        lena = b.size();
        for(i = 0; i<lenb; i++)b[i] = tolower(b[i]);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(lena<lenb && b.find(a) != string::npos) {
            cout << "Yes"<<endl;
            truth = true;
        }

        if(truth == false && a.find(b)!= string::npos) {
            cout << "Yes" << endl;
            truth = true;
        }
        if(truth == false) cout << "No" << endl;
        tc = tc +1;
    }
    return 0;
}
