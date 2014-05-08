#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <sstream>


using namespace std;

#define ML 1000000

bitset < ML+1> isp;
bool isDigitPrime(int n){
    int ans = 0;
    while(n){
        ans += n%10;
        n /= 10;
    }
    return isp.test(ans);
}
int main(){


    int test, a, b;
    vector < int > dp;
    isp.flip();
    isp.reset(0);
    isp.reset(1);
    for(int i = 2;  i <= ML; i++ ){
        if( isp.test(i) ){
            for( int j = i + i; j <= ML; j += i )
                isp.reset(j);
            if(isDigitPrime(i)) dp.push_back(i);
        }
    }
    scanf("%d", &test);
    while(test--){
    scanf("%d %d", &a, &b);
    int lo = lower_bound(dp.begin(), dp.end(), a) - dp.begin();
    int hi = lower_bound(dp.begin(), dp.end(), b) - dp.begin();
    if(hi == dp.size() || dp[hi] != b) printf("%d\n", hi - lo);
    else printf("%d\n", hi - lo + 1);
    }
	return 0;
}
