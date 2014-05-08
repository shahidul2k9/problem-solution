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
typedef vector <int > v1d;
typedef vector < v1d > v2d;
typedef vector < v2d > v3d;
vector < v2d > memo;
int nums( int len, int ends, int sum ){
    if( len == 1){
        if( ends == sum) return 1;
        return 0;
    }
    if( sum <= 0 ) return 0;

    if( memo[len][ends][sum] != -1 )
        return memo[len][ends][sum];
    int ans = 0;
    for( int e = 1; e < ends; e++ )
        ans += nums(len-1, e, sum - ends);

    return memo[len][ends][sum] = ans;
}
int main(){
    int cs = 1;
    int ans;
    int L, S;
    int m;
    while( scanf("%d %d", &L, &S)  == 2 && L ){

        if( L > 26 || S > 351 || L > S){
            printf("Case %d: %d\n", cs++ ,0);
            continue;
        }
        memo  = v3d(L+1, v2d(27, v1d(S+1,-1)));
        ans = 0;
        for(int i = 1; i <= 26; i++ )
            ans += nums(L, i, S);

        printf("Case %d: %d\n", cs++ , ans);

        for( int i = 0; i < L+1; i++ )
            for(int j = 0; j < 27; j++)
                    memo[i][j].clear();
    }

    return 0;
}

