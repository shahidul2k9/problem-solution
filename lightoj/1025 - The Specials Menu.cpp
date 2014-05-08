#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int i64;
i64 memo[60][60];
char s[61];
i64 ways(int l, int r){
    if(l == r)return 1;
    if(l > r)return 0;
    if(memo[l][r] != -1) return memo[l][r];

    memo[l][r] = ways(l+1, r) - ways(l+1, r-1) + ways(l, r-1) ;
    if(s[l] == s[r]) memo[l][r] += ways(l+1, r-1) + 1;
    return memo[l][r];

}
int main(){
    freopen("input.txt", "r", stdin);
    int T, tc = 1, n;
    i64 ans;
    scanf("%d", &T);
    while( T-- ){
        scanf("%s", s);
        memset(memo, -1, sizeof(memo));
        n = strlen(s);
        ans = ways(0, n-1);
        printf("Case %d: %lld\n", tc++, ans);
    }

    return 0;
}
