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
#define MX 35
char A[MX], B[MX];
int m, n;
int lcss[MX][MX];
i64 num[MX][MX];

void computeLCSS(){
    for(int i = 0; i <= m; i++)
        lcss[i][0] = i;
    for(int i = 0; i <= n; i++)
        lcss[0][i] = i;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            if(A[i-1] == B[j-1]) lcss[i][j] = lcss[i-1][j-1];
            else lcss[i][j] = min(lcss[i][j-1], lcss[i-1][j]);
            lcss[i][j]++;
        }
}
void computeWays(){
    for(int i = 0; i <= m; i++)
        num[i][0] = 1;
    for(int j = 0; j <= n; j++)
        num[0][j] = 1;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            if( A[i-1] == B[j-1]) num[i][j] = num[i-1][j-1];
            else if(lcss[i][j-1] < lcss[i-1][j])
                num[i][j] = num[i][j-1];
            else if(lcss[i][j-1] > lcss[i-1][j])
                    num[i][j] = num[i-1][j];
            else num[i][j] = num[i][j-1] + num[i-1][j];
        }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int test, cs  = 1;
    scanf("%d", &test);
    while( test-- ){
        scanf("%s", A);
        scanf("%s", B);
        m  = strlen(A);
        n = strlen(B);
        computeLCSS();
        computeWays();
        printf("Case %d: %d %lld\n", cs++, lcss[m][n], num[m][n]);

    }

	return 0;
}
