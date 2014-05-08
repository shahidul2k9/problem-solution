#include <iostream>
#include <stdio.h>
#include <cstring>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i, L, U) for(int i = (int)L, i<=U, i++ );
int main()
{
    vector < int > v;
    int a,b,mod,len,k;
    char x[20],y[20];
    cin >> a;
    while(a>0){
        cout << "Original number was " << a << endl;
        while(1){
        sprintf(y,"%d",a);
        len = strlen(y);
        sort(y,y+len);
        k = len - 1;
        for(int i = 0;i<len;i++){
            x[i] = y[k];
            k--;
        }
         x[len] = NULL;
        a = atoi(x);
        b = atoi(y);
        cout << a << " - " << b << " = ";
        a = a - b;
        cout << a << endl;
        vector < int > ::iterator it = find(v.begin(),v.end(),a);
        if(it!=v.end()){cout << "Chain length " << v.size()+1 << endl;break;}
        v.push_back(a);
        }
        v.clear();
        cout << endl;
        cin >> a;

    }
    return 0;
}
