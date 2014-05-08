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
typedef long long int Type;
Type A[20][20];
int n, a;

Type f(int i, int j){
    if(A[i][j] != -1)return A[i][j];

    Type ans = 0;
    if( i < j){
        for(int k = i; k < j; k++)
            ans = max(f(i,k) + f(k+1,j), ans);
        return A[i][j] = ans;
    }

     Type ans1, ans2;
    ans1 = ans2 = 0;

   if(i < n)
        for(int k = i+1; k <= n; k++)
            ans1 = max(f(k,1) + f(k,j), ans1);
    if(j > 0)
        for(int k = 1; k < j; k++)
            ans2 = max(f(i,k) + f(n,k), ans2);
    ans = ans1 + ans2;
    return A[i][j] = ans;


}
int main(){
  // freopen("input.txt", "r", stdin);
    while(scanf("%d %d", &n, &a) == 2){
        memset(A, -1, sizeof(A));
        A[n][1] = a;

        printf("%lld\n", f(1, n));
    }

	return 0;
}
