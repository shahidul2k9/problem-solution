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
#include <algorithm>
#include <numeric>
#include <sstream>

using namespace std;
#define FMN 5000000
bitset < FMN + 1 > sieve;
int psum[FMN+ 1];
int main(){

    //freopen("input.txt", "r", stdin);
    int a, b;
    vector < int > deprime;
    sieve.flip();
    sieve.reset(0);
    sieve.reset(1);
    for( int   i = 2; i <= FMN; i++ ){
        if(sieve.test(i)){

            psum[i] = i;
            for( int j = i + i; j <= FMN; j += i){
                sieve.reset(j);
                psum[j] = psum[j] + i;

            }
        }
        if(sieve.test(psum[i])) deprime.push_back(i);
    }

    //printf("%d\n", deprime.size());
    while(scanf("%d %d", &a, &b) == 2){
        int lo = lower_bound(deprime.begin(), deprime.end(), a) - deprime.begin();
        int hi = lower_bound(deprime.begin(), deprime.end(), b) - deprime.begin();
        if( hi == (int) deprime.size() || deprime[hi] != b ) printf("%d\n", hi - lo);
        else
        printf("%d\n", hi - lo + 1);
    }
	return 0;
}
