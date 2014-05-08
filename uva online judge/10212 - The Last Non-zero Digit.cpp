#include <stdio.h>
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
#include <string.h>
#include <sstream>
using namespace std;
inline bool ismul(int n ){
    return n % 9 == 0;
}
int main(){
    //freopen("input.txt", "r", stdin);
    long long N, M, ans;
    while(scanf("%lld %lld", &N, &M) == 2){
        ans = 1;
        for( long long int a = N - M + 1; a <= N; a++ ){
            ans *= a;
            while(ans %10 == 0) ans /= 10;
            ans %= 10000000000;
        }
        printf("%lld\n", ans%10);
    }
    return 0;
}
