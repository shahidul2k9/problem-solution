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
#define MX 51
char A[MX], B[MX], C[MX];
int mc[MX][MX][MX];

int lcs(int i, int j, int k){
    if( i < 0 || j < 0 || k < 0)return 0;
    if( mc[i][j][k] != -1) return mc[i][j][k];
    if(A[i] == B[j] && B[j] == C[k]) return mc[i][j][k] =  1 + lcs(i-1, j-1, k-1);
    return mc[i][j][k] = max( max(lcs(i-1, j, k), lcs(i, j-1, k)), lcs(i,j,k-1));
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int test, n,o,m,  cs  = 1;
    scanf("%d", &test);
    while( test-- ){
        scanf("%s", A);
        scanf("%s", B);
        scanf("%s", C);
        m = strlen(A);
        n = strlen(B);
        o = strlen(C);
        memset(mc, -1, sizeof(mc));
        printf("Case %d: %d\n", cs++, lcs(m-1, n-1, o-1));
    }


	return 0;
}
