#include <algorithm>
#include <bitset>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
#define OM 1000000
bitset < OM + 1 > sieve;
vector < int > pl;
void sieveGen(){
    sieve.flip();
    sieve.reset(0);
    sieve.reset(1);
    for( int k = 2; k <= OM; k++ )
        if(sieve.test(k)){
            pl.push_back(k);
            if(k <= sqrt(OM))
            for(int i = k + k; i <= OM; i += k )
                sieve.reset(i);
            }
}
int divisors(int n){
    int ans = 1;
    int num;
    for(int k = 0; k < (int) pl.size() && pl[k]<= n; k++ ){
        num = 0;
        while(n % pl[k] == 0){num++; n /= pl[k];}
        ans *= (num+1);
    }

  return ans;
}
int gcd(int a, int b ){
    if( b == 0 ) return a;
    return gcd(b, a%b);
}
int main(){
    #ifndef ONLINE
    //freopen("input.txt", "r", stdin);
    #endif
    sieveGen();
    int test, a,b;
    scanf("%d",&test);
    while(test--){
        scanf("%d %d", &a, &b);
        printf("%d\n", divisors(gcd(a,b)));
    }
	return 0;
}
