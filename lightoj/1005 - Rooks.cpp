#include <cstdio>
#include <string.h>
#include <algorithm>
#include <climits>
#include <vector>
#include <iostream>
using namespace std;
typedef unsigned long long int u64;
int main(){
    //freopen("input.txt", "r", stdin);
    int test, n, k, tc=1;
    u64 ans;
    scanf("%d", &test);

    while( test-- ){
        scanf("%d %d", &n, &k);
        ans = 0;
        if(n*n >= k){
            ans = 1;
            for(int ck = 1; ck <= k; ck++){
                ans = ans * n*n/ck;
                n -= 1;
            }
        }
        printf("Case %d: %llu\n", tc++, ans);
    }
    return 0;
}
