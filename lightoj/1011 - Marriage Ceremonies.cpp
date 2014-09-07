using namespace std;
#include "cstring"
#include "cstdio"
#include "iostream"
#include "algorithm"
#include "vector"
#include "string"
#include "cctype"
#include "set"
 
typedef long long Long;
#define MAXN 16
int dp[MAXN][1 << MAXN];
int n;
int solve(int i, int mask){
    if(dp[i][mask] != -1)return dp[i][mask];
    int ans = 0;
    for(int k = 0; k < n; k++ )
        if( (1 << k) & mask )
            ans = max(ans, solve(i-1, mask & (~(1 << k))) + dp[i][1 << k] );
    return dp[i][mask] = ans;
}
int main() {
    //freopen("input.txt", "r", stdin);
    int test, cs = 1;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            memset(dp[i], -1, sizeof(dp[i]));
            for(int j = 0; j < n; j++){
                scanf("%d", &dp[i][1 << j]);
            }
        }
        printf("Case %d: %d\n", cs++, solve(n-1, (1 << n ) -1 ));
    }
 
    return 0;
}