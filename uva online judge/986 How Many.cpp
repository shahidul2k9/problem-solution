#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int W[39][20][20][20];
int N, R, K;
int ways(int row, int col, int r, int k){
    if(row < 0 || col < 0 || r < 0 ) return 0;

    if( row == col && r == 0 ) return 1;
    if(W[row][col][r][k] != - 1) return W[row][col][r][k];

    int ans = ways(row-1, col-1, r, k);

    if(col + 1 == k ){
        ans += ways(row-2, col, r-1, k);
        ans += ways(row-2, col+2, r, k);
    }
    else
        ans += ways(row-1, col + 1, r, k);
   // cout << row << " " <<col <<  " " << r << " " << k << " " << ans << endl;
    return W[row][col][r][k] = ans;

}
int main(){


    while(scanf("%d %d %d", &N, &R, &K) == 3){
        memset(W, -1, sizeof(W));
        printf("%d\n", ways(2*N, 0, R, K));

    }
    return 0;
}
