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
int C;
int px[80], py[80], pz[80], sc[80];
int memo[1 << 9];

int solve( int bitmask ){

    if( 1 + bitmask ==(1 << 9) ) return 0;
    if( memo[bitmask] != -1 ) return memo[bitmask];

    int score = -5;
    for( int i = 0; i < C; i++ ){
        if( !( (bitmask & (1 << px[i])) | (bitmask & (1 << py[i])) | (bitmask & (1 << pz[i])) )){
            int ans = solve(bitmask | (1 << px[i]) | bitmask | (1 << py[i]) | bitmask | (1 << pz[i]));
            if(ans != -5)
                score = max(score, sc[i] + ans);
        }
    }
    return memo[bitmask] = score;
}
int main(){
    //freopen("input.txt", "r", stdin);
    int cs = 1;
    int ans;
    while(scanf("%d", &C) == 1 && C){
        for( int i = 0; i < C; i++ ) {
            scanf("%d %d %d %d", &px[i], &py[i], &pz[i], &sc[i]);
            px[i]--;
            py[i]--;
            pz[i]--;
            }

        memset(memo, -1, sizeof(memo));
        ans = solve( 0 );
        if(ans == -5)
            printf("Case %d: %d\n", cs++, -1);
        else printf("Case %d: %d\n", cs++, ans);
    }



	return 0;
}
