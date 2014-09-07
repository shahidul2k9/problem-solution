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
int num[51], val[51];
int w[51][1001];
 
int ways(int n, int k){
    if(w[n][k] != -1) return w[n][k];
    int ans = 0;
    for(int i = 0; i <= num[n] && i*val[n] <= k; i++ ){
        ans = ans + ways(n-1, k - i * val[n]) ;
        ans %= 100000007;
    }
 return w[n][k] = ans;
}
 
int main(){
 
    //freopen("input.txt", "r", stdin);
     //freopen("output.txt", "w", stdout);
    int N, K, test, cs = 1;
 
    scanf("%d", &test);
    while(test-- > 0 ){
        scanf("%d %d", &N, &K);
 
        for(int i = 1; i <= N; i++)
            scanf("%d", &val[i]);
        for( int i = 1; i <= N; i++ )
            scanf("%d", &num[i]);
 
    memset(w[0], 0, sizeof(int)* (K+1) );
    w[0][0] = 1;
    for( int i = 1; i <= N; i++ )
        memset(w[i], -1, sizeof(int)* (K+1) );
 
    printf("Case %d: %d\n", cs++, ways(N, K));
 
    }
    return 0;
}