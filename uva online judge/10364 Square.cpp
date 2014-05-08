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
    int test;
    int M[20], N, L;
    int memo[4][1 << 20];

    int move( int k, int bitmask , int  sum){

        if( k == 4 ) return 1;
        if( sum == L ) return move(k+1, bitmask, 0);
        if( memo[k][bitmask] != -1) return memo[k][bitmask];
        int ans = 0;
        for ( int i = 0; i < N && !ans ; i++ ){
            if( !(bitmask & (1 << i)) && sum + M[i] <= L ){
               ans = ans | move(k, bitmask | (1 << i), sum + M[i]);
            }
        }
        return memo[k][bitmask] = ans;
    }
int main(){
   //freopen("input.txt", "r", stdin);
   scanf("%d", &test);
   int sum;
   while( test-- ){
       sum = 0;
       scanf("%d", &N);
       for( int i = 0; i < N; i++ ) {
           scanf("%d", &M[i]);
           sum += M[i];
           }

           L = sum/4;
           if( 4*L != sum){
               puts("no");
               continue;
           }

        for( int i = 0; i < 4; i++ )
            memset(memo[i], -1, sizeof(int) * (1 << N) );
        if( move(0, 0, 0) ) puts("yes");
        else puts("no");

   }





	return 0;
}
