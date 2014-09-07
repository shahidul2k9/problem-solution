#include <math.h>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int TC,tc,k,n,x,i;
    char ch[27];
    cin >> TC;
    tc = 1;
    while(TC>=tc) {
        cout << "Case "<< tc << ":"<< endl;
        cin >> n >> k;
        for(i=0; i<n; i++)ch[i] ='A'+i;
        ch[i]=NULL;
        x = 0;
        do {
            for(i=0; i<n; i++)printf("%c",ch[i]);
            cout << endl;
            x++;
        } while(next_permutation(ch,ch+n)&&x<k);
        tc++;
    }
    return 0;
}
