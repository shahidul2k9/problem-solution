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
#define OM 1000000
bitset< OM + 1 > sieve;

long long int M  = (long long int) 1000000000000;

int main(){

   // freopen("input.txt", "r", stdin);
    vector<long long int > p;
    sieve.flip();
    sieve.reset(0);
    sieve.reset(1);
    for( int i = 2; i <= OM; i++ ){
        if(sieve.test(i)){
            for(long long  int k = (long long int)i*i; k <= M; k *= i ) p.push_back(k);
            for(int k = i+i; k <= OM; k += i )
                sieve.reset(k);
        }
    }
    sort(p.begin(), p.end());
    int test, lo, hi;
    long long int a, b;
    scanf("%d",&test);
    while( test-- ){
        scanf("%lld %lld", &a, &b);
        lo = lower_bound(p.begin(), p.end(), a) - p.begin();
        hi = lower_bound(p.begin(), p.end(), b) - p.begin();
        if(hi == p.size() || p[hi] != b ) hi--;
        printf("%d\n", hi - lo + 1);

    }
    return 0;
}

