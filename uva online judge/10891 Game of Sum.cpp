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
    int N;
    int A[101];
    int M[101][101];
    int memo[101][101];

int move( int a, int b ){
    if ( a > b ) return 0;
    if( memo[a][b] != -1 )
        return memo[a][b];

    int ans = INT_MIN;

    int total;
    for( int i = a; i <= b; i++ ){
        if( i+1 <= b  )
            total = M[i+1][b];
        else total = 0;
        ans = max( M[a][i] + total- move(i+1, b), ans);
    }

    for( int j = b; j > a; j-- ){
        if ( a <= j - 1 )
        total = M[a][j-1];
        else total = 0;
        ans = max(M[j][b] + total - move(a, j-1), ans);
    }
    return memo[a][b] = ans;

}
void dump( ) {
    puts("M");
    for ( int i = 0; i < N; i++){
        for( int j = 0; j < N; j++ )
            printf("%5d", M[i][j]);
        puts("");
    }
    puts("memo");
    for ( int i = 0; i < N; i++){
        for( int j = 0; j < N; j++ )
            printf("%5d", memo[i][j]);
        puts("");
    }
}
int main(){

    //freopen("input.txt", "r", stdin);
    while( scanf("%d", &N) == 1 && N ){

        for( int i = 0; i < N; i++ )
            scanf("%d", &A[i]);

        memset(memo, -1, sizeof(memo));
        for( int i = 0; i < N; i++ )
            for( int j = i; j < N; j++ ){
              if( i == j ) {M[i][j] = A[i];}
              else M[i][j] = M[i][j-1] + A[j];
            }

    printf("%d\n", 2* move(0, N-1) - M[0][N-1]);
    }
	return 0;
}
