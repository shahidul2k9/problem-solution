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
    //freopen("input.txt", "r", stdin);
    long long int A[1000];
    long long int ans, cur, mid;

    int   N, q, cs=1;
    while(scanf("%d", &N) == 1 && N){
        printf("Case %d:\n", cs++);

        for( int i = 0; i < N; i++ )
            scanf("%lld", &A[i]);

        scanf("%d", &q);

        while(q--){
        scanf("%lld", &mid);
        ans = A[0] + A[1];
        for(int i = 0; i < N; i++ ){
            for( int j = i+1; j < N; j++ ){
                cur = A[i] + A[j];
                if( abs(ans - mid) > abs(cur - mid)) ans = cur;
            }
        }
        printf("Closest sum to %lld is %lld.\n", mid, ans);
        }
    }
    return 0;
}

