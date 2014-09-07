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
 
 
 
 
int main(){
 
    // freopen("input.txt", "r", stdin);
     //freopen("output.txt", "w", stdout);
    int N, test, cs = 1;
 
    int  K;
    int val[101];
    int w[10001];
    scanf("%d", &test);
    while(test-- > 0 ){
        scanf("%d %d", &N, &K);
 
        for(int i = 1; i <= N; i++)
            scanf("%d", &val[i]);
 
 
 
 
    memset(w, 0, sizeof(w));
    w[0]  = 1;
    for( int i = 1; i <= N; i++ ){
        for(int k = 1; k <= K; k++){
            if( val[i] <= k)
                w[k] = w[k] + w[k - val[i]];
            if(w[k] > 100000007)
                w[k] %= 100000007;
        }
    }
 
    printf("Case %d: %d\n", cs++, w[K]);
 
    }
    return 0;
}