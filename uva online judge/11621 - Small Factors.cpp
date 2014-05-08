#include <string.h>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;

#define TM 1000000

int main(){
  // freopen("input.txt", "r", stdin);
    map < unsigned long long int, bool > has;
    vector < unsigned long long int > v;
    int ind;
    unsigned long long m, mx, key;
    mx = 6442450944;
    for(unsigned long long int i = 1; i <= 2147483648; i <<= 1 ){
        for( unsigned long long j = 1; j <= 3486784401; j = j*3 ){
            m = i*j;
            if(m <= 6442450944)
                if( has[m] == false){
                    has[m] = true;
                    v.push_back(m);
                }
        }
    }

    sort(v.begin(), v.end());
    while( cin >> key && key){
        ind = lower_bound(v.begin(), v.end(), key) - v.begin();
            cout << v[ind] << endl;
    }
    return 0;
}

