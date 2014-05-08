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

#define DIM 71
int M[DIM][DIM];
int F(int n, int t, int p){

    if(M[n][t] != -1)return M[n][t];

    if(n == 1){
        M[n][t] = (t - p < 0)? 0 : 1;
        return M[n][t];
    }

    int ways = 0;
    for(int i = p; i <= t; i++)
        ways += F(n-1, t - i, p);
    return M[n][t] = ways;


}
void dump(int n, int t){
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= t; j++)
            printf("%d ", M[i][j]);
        puts("");
    }

}
int main(){
    //freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    int test;
    int N, T, P;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d %d", &N, &T, &P);
        memset(M, -1, sizeof(M));
        printf("%d\n", F(N, T, P));
    }

	return 0;
}
