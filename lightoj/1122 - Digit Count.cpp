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
typedef long long int i64;
typedef unsigned int u32;
typedef unsigned long long int u64;
bool digit[11];
i64 nums[11][11];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int test,d, n, m, cs  = 1;
    i64 ans;
    scanf("%d", &test);
    while( test-- ){
        scanf("%d %d", &m, &n);
        memset(digit, false, sizeof(digit));
        for(int i = 1; i <= m; i++){
            scanf("%d", &d);
            digit[d] = true;
        }
        memset(nums, 0, sizeof(nums));

        for(int i = 1; i < 10; i++){
            if( digit[i]) nums[i][1] = 1;
        }
        for(int c = 2; c <= n; c++){
            for(int d = 1; d <= 9; d++){
                if( digit[d])
                for(int os = -2; os <= 2; os++)
                    if(os + d > 0 && os + d < 10 ) nums[d][c] += nums[os + d][c-1];
            }
        }

        ans = 0;
        for(int d = 1; d <= 9; d++)
            if(digit[d]) ans += nums[d][n];

        printf("Case %d: %lld\n", cs++, ans);

    }

	return 0;
}
