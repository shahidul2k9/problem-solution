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
#define SIZE 10000001
#define EPS 1e-9
int digits[SIZE];
int main(){

   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   #endif

   digits[0] = 0;
   double d = 0;
   for( int k = 1; k < SIZE; k++ ){
        d += log10(k);
        digits[k] = (int)d;
   }
    int test, n;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &n);
        printf("%d\n", digits[n]+1);
    }
	return 0;
}
