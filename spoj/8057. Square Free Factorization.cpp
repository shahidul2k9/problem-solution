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
int minimalFactors(int n){
    int ans = 0;
    int num;
    for(int k = 0; k < (int) pl.size() && pl[k]<= n; k++ ){
        num = 0;
        while(n % pl[k] == 0){num++; n /= pl[k];}
        ans = max(ans, num);
    }

  return ans;
}
int main(){
    //spoj does not support macro ONLINE
    #ifndef ONLINE
   // freopen("input.txt", "r", stdin);
    #endif
    sieveGen();
    int test, n;
    scanf("%d",&test);
    while(test--){
        scanf("%d", &n);
        printf("%d\n", minimalFactors(n));
    }
	return 0;
}
