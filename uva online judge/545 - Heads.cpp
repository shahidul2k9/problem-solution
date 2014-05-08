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
#define SIZE 90001
#define EPS 1e-9

int main(){

   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   #endif
    int exp[SIZE];
    double base[SIZE];
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
    int test, n;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &n);
        printf("2^-%d = %.3lfE-%d\n", n, base[n]+EPS, exp[n]);
    }
	return 0;
}
