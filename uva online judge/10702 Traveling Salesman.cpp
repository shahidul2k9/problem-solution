#include <algorithm>
#include <bitset>

#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;
#define inf 10000000
int M[101][101];
int C, S, E, T;
long long int memo[101][1001];

long long int profit(int n, int t){

    if( memo[n][t] != -1 ) return memo[n][t];

    long long int ans = 0;
    long long int prev;
    for( int i = 1; i <= C; i++ ){
        if(i == n ) continue;
        prev = profit(i, t-1);
        if( prev != -inf ) prev += M[i][n];
        else prev = 0;
        ans = max(ans, prev);
    }
    return memo[n][t] = ans;

}
int main(){


     //freopen("input.txt", "r", stdin);
     //freopen("output.txt", "w", stdout);

    int end;
   long long int ans;
   while(scanf("%d %d %d %d", &C, &S, &E, &T) == 4&& (C || S || E || T)){
       for( int i = 1; i <= C; i++ )
        for(int j = 1; j <= C; j++ )
            scanf("%d", &M[i][j]);


    for(int i = 1; i <= C; i++ ){
        memset(memo[i], -1, sizeof(long long int)* (T + 1));
        memo[i][0] = -inf;
    }
    memo[S][0] = 0;

    ans = 0;
    for( int i = 1; i <= E; i++ ){
        scanf("%d", &end);
        ans = max(profit(end, T), ans);
    }
    printf("%lld\n", ans);
   }

    return 0;
}
