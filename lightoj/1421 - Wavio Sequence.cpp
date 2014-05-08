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
#define inf INT_MAX
#define MX 100005
int main(){
   freopen("input.txt", "r", stdin);
     //freopen("output.txt", "w", stdout);
    int T, ans,  tc = 1;
    int lis[MX], lds[MX], sit[MX], val[MX];
    int N;
    scanf("%d", &T);
    while( T-- ){
        scanf("%d", &N);
        for(int k = 1; k<= N; k++)
            scanf("%d", &val[k]);
        for(int k = 1; k<= N; k++)
            sit[k] = inf;
        sit[0] = -inf;
        for(int k = 1; k<= N; k++){
            lis[k] = lower_bound(sit, sit+N+1, val[k]) - sit;
            sit[lis[k]] = val[k];
        }
        for(int k = 1; k<= N; k++)
            sit[k] = inf;
        sit[0] = -inf;
        for(int k = N; k>= 1; k--){
            lds[k] = lower_bound(sit, sit+N+1, val[k]) - sit;
            sit[lds[k]] = val[k];
        }
        ans = 1;
        for(int k = 1; k <= N; k++){
            ans = max(2*min(lis[k], lds[k])-1, ans);
        }
        printf("Case %d: %d\n", tc++, ans);
    }
    return 0;
}
