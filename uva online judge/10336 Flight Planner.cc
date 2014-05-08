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
int memo[10][1001];
int wind[10][1001];
#define inf 99999999
int X;
int minFuel(int alt, int dist){
    if(alt > 9 || alt < 0 || dist > X)
        return inf;

    if(memo[alt][dist] != -1)
        return memo[alt][dist];
    int ans = min(minFuel(alt + 1, dist+1) + 60 - wind[alt][dist], minFuel(alt - 1, dist+1) + 20 - wind[alt][dist]);
    return
       memo[alt][dist] = min(ans, minFuel(alt, dist+1) + 30 - wind[alt][dist]);

}
int main(){
    //freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &X);
        X /= 100;

        for(int i = 9; i >= 0; i--)
            for(int j = 0; j < X; j++)
                scanf("%d", &wind[i][j]);
        /*
        for(int i = 0; i <= 9; i++){
            for(int j = 0; j < X; j++)
                printf("%d ", wind[i][j]);
            puts("");
        }
        */

        memset(memo, -1, sizeof(memo));
        memo[0][X] = 0;
        printf("%d\n\n", minFuel(0, 0));

    }

    return 0;
}
