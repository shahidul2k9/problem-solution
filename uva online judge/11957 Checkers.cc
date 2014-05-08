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
#define DIMEN 106
int main(){

     //freopen("input.txt", "r", stdin);
     //freopen("output.txt", "w", stdout);

    int ans;
    int MOD = 1000007;
    char g[DIMEN][DIMEN];
    int M[DIMEN][DIMEN];
    int N;
    int test;
    int r, c, cs  = 1;
    bool W;
    char line[DIMEN];
    gets(line);
    sscanf(line,"%d", &test);
    while(test--){
        gets(line);
        sscanf(line, "%d", &N);
        for( int i = N; i >= 1; i-- ){
            gets(g[i] + 1);
           // g[i][0] = '.';
        }
        memset(M, 0, sizeof(M));

        W = false;
        for( r = 1; r <= N; r++ ){
            for( c = 1; c <= N; c++ )
                if(g[r][c] == 'W'){
                    W = true;
                    break;
                }
        if(W)break;
        }
        M[r][c] = 1;

    for( int i = r; i < N; i++ ){
        for( int j = 1; j <= N; j++ ){
            if( M[i][j] ==  0 ) continue;
            if( g[i + 1][j - 1] == '.' )
             M[i + 1][j - 1] = ( M[i + 1][j - 1] + M[i][j] )%MOD;
            else if(j - 2 > 0 && g[i+2][j-2] != 'B')
             M[i + 2][j - 2] = ( M[i + 2][j - 2] + M[i][j] )% MOD;
            if( g[i+1][j+1] == '.' )
                M[i+1][j+1] = ( M[i+1][j+1] + M[i][j] ) % MOD;
            else if( j + 2 <= N && g[i+2][j+2] != 'B')
              M[i+2][j+2] = ( M[i+2][j+2] + M[i][j] ) % MOD;
        }
    }

        ans = 0;
        for( int i = 1; i <= N; i++ )
            ans = ( ans + M[N][i] ) % MOD;
        printf("Case %d: %d\n",cs++,  ans);
    }


    return 0;
}
