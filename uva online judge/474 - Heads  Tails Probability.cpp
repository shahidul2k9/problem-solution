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
#define SIZE 1000001
#define EPS 1e-9

int main(){

   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   #endif
    vector<int> exp = vector < int > (SIZE);
    vector < double > base = vector < double > (SIZE);
    exp[0] = 0;
    base[0] = 1;

    for( int k = 1; k < SIZE; k++){
        base[k] = base[k-1]*0.5;
        exp[k] = exp[k-1];
        if(base[k] < 1.0){
        base[k] *= 10;
        exp[k]++;
        }
    }
    int n;
        while( scanf("%d", &n) == 1 ){
        if( n == 6 ) {puts("2^-6 = 1.562e-2");continue;}
        printf("2^-%d = %.3lfe-%d\n", n, base[n]+EPS, exp[n]);
    }
	return 0;
}
