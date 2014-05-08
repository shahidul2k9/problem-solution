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

typedef long long Type;
int n, k, m;
Type M[51][51];

Type ways(int n, int k){
    if(M[n][k] != -1)return M[n][k];

    if(n < k ) return M[n][k] = 0;

    Type  ans = 0;

    for(int i = 1; i <=m && i <= n; i++)
        ans += ways(n - i, k-1);
    return M[n][k] = ans;
}

void dumpM(){
    for(int i = 0;i <= n; i++){
        for(int j = 0; j <= k; j++)
            cout << M[i][j] << " ";
        puts("");
    }
}
int main(){
  // freopen("input.txt", "r", stdin);
     //freopen("output.txt", "w", stdout);

    while(scanf("%d %d %d", &n, &k, &m) == 3){
            memset(M,-1,sizeof(M));
            for(int i = 1; i <= m; i++)
                M[i][1] = 1;
            for(int i = m + 1; i <= n; i++)
                M[i][1] = 0;

            M[0][0] = 1;

            printf("%lld\n", ways(n, k));
            //dumpM();
    }
	return 0;
}
