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

long long int ways[101][101];
int W, H;
long long int countWays(int x, int y){
    if(x < 0 || y < 0) return 0;
    if(ways[x][y] != -1) return ways[x][y];
    ways[x][y] = countWays(x, y - 1) + countWays(x - 1, y);
    return ways[x][y];
}

int main(){
        //freopen("input.txt", "r", stdin);

        //freopen("output.txt", "w", stdout);
        int x, y, N;
        long long int paths;
        while(scanf("%d %d", &W, &H) == 2 && (W || H)){
            scanf("%d", &N);
            memset(ways, -1, sizeof(ways));
            ways[0][0] = 1;
            for(int i = 0; i < N; i++){
                scanf("%d %d", &x, &y);
                ways[x][y] = 0;
            }
        paths = countWays(W, H);
        if(paths == 0)
            puts("There is no path.");
        else if(paths == 1)
            puts("There is one path from Little Red Riding Hood's house to her grandmother's house.");
        else
            printf("There are %lld paths from Little Red Riding Hood's house to her grandmother's house.\n", paths);
        }


    return 0;
}
