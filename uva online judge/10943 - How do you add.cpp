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
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;

#define DIM 101
int W[DIM][DIM];
int ways(int k, int n){
    if(W[k][n] != -1) return W[k][n];

    if(k == 1) return W[k][n] = 1;

    int ans = 0;
    for(int i = 0; i <= n; i++)
        ans = (ans % 1000000 +  ways(k-1, i)%1000000 )%1000000;

    return W[k][n] = ans;

}

/*
void dump(int n, int t){
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= t; j++)
            printf("%d ", M[i][j]);
        puts("");
    }

}
*/
int main(){
    //freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
     int N, K;
     while(scanf("%d %d", &N, &K) == 2 && (N && K)){
         memset(W,-1, sizeof(W));
         printf("%d\n", ways(K, N));
     }

	return 0;
}
