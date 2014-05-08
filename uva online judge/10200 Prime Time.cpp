#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>


using namespace std;

#define TH 10000

bitset < TH+1> isp;
vector < int > p;
bool isPrime( int n ){
    if( n <= TH ) return isp.test(n);
    int sq = sqrt(n);
    for( int i = 0; i < (int)p.size() && p[i] <= sq; i++)
        if( n % p[i] == 0) return false;
    return true;

}
int main(){

    //freopen("input.txt", "r", stdin);
    int  a, b, actual, x, lo, hi, denominator;
    vector < int > ep;
    isp.flip();
    isp.reset(0);
    isp.reset(1);
    for(int i = 2;  i <= TH; i++ ){
        if( isp.test(i) ){
            p.push_back(i);
            for( int j = i + i; j <= TH; j += i )
                isp.reset(j);
        }
    }

    for( int n = 0; n <= 10000 ; n++ ){
         x = n*n + n + 41;
        if(isPrime(x)) ep.push_back(x);
    }

    while(scanf("%d %d", &a, &b) == 2){

    denominator = b - a + 1;
    a = a * a + a + 41;
    b = b * b + b + 41;
    lo = lower_bound(ep.begin(), ep.end(), a) - ep.begin();
    hi = lower_bound(ep.begin(), ep.end(), b) - ep.begin();

    actual = hi - lo + 1;
    if(hi == (int) ep.size() || ep[hi] != b) actual--;

    // if you don't use 1e-9 you will get WA why?

    printf("%.2lf\n", 100.0 * actual/ (double)denominator + 1e-9);

    }
	return 0;
}
