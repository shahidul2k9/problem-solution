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

#define TM 1000000

int main(){
  // freopen("input.txt", "r", stdin);
    int A[500];
    unsigned long long int ans, cur;

    int test,  N;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &N);
        for( int i = 0; i < N; i++ )
            scanf("%d", &A[i]);

        ans = LONG_LONG_MAX;
        for(int i = 0; i < N; i++ ){
            cur = 0;
            for( int j = 0; j < N; j++ ){
                cur += abs(A[i] - A[j]);
            }
            if( cur < ans )ans = cur;
        }
    printf("%llu\n", ans);
    }
    return 0;
}

