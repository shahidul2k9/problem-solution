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
    int M[201][101];
    vector < int > A[201];
    int N, test;
 
int solve(int row, int col){
    if(row < 0 || col == (int) A[row].size() || col < 0 ) return 0;
    if( M[row][col] !=-1 ) return M[row][col];
 
    if( row < N )
        return M[row][col] = max(solve(row-1, col-1),  solve(row-1, col) ) + A[row][col];
 
    else
        return M[row][col] = max( solve(row-1, col) , solve(row-1, col+1) ) + A[row][col];
}
void dump(){
    for( int i = 0; i < 2*N - 1; i++ ){
        for(int j = 0; j < A[i].size(); j++ ){
            printf("%10d", M[i][j]);
        }
        puts("");
    }
}
int main(){
 
    //freopen("input.txt", "r", stdin);
 
    int x, L, cs;
    cs = 1;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &N);
        for(  int i = 0; i <N; i++ ){
            A[i].clear();
            for( int j = 0; j <= i; j++ ){
                scanf("%d", &x);
                A[i].push_back(x);
            }
        }
        L = N - 1;
        for(  int i = N; i <2*N - 1; i++ ){
            A[i].clear();
            for( int j = 0; j <L; j++ ){
                scanf("%d", &x);
                A[i].push_back(x);
            }
            L--;
        }
 
        memset(M, -1, sizeof(M));
        printf("Case %d: %d\n", cs++, solve(2*N-2, 0));
 
    }
 
    return 0;
}