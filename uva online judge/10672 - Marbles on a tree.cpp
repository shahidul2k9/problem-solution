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
vector < int > g[10001];
 int mr[10001];
 int pre[10001];
 bool processed[10001];
 bool color[10001];
 int moves;
void dfs(int from ){
    int to, now;
    color[from] = true;
    if(processed[from])return;
    for( int i = 0; i < (int)g[from].size(); i++ ){
        to = g[from][i];

        if( !processed[to] && !color[to]) {
            pre[to] = from;
            dfs(to);
            }
    }

    if( mr[from] > 0)
        now = mr[from] - 1;
    else now = mr[from] - 1;
    mr[from] = 1;
    mr[pre[from]] += now;
    moves += abs(now);
    processed[from] = true;

}
int main(){
   // freopen("input.txt", "r", stdin);
    int N;
    int marbles, outdeg, st, en;
    while( scanf("%d", &N) == 1 && N){

        for( int i = 1; i <= N;i++ ){
            scanf("%d %d %d", &st, &marbles, &outdeg);
            mr[st] = marbles;

            for( int k = 0; k < outdeg; k++ ){
                scanf("%d", &en);
                g[st].push_back(en);
                g[en].push_back(st);
            }
        }
        moves = 0;
        memset(processed, false, sizeof(processed));
        memset(color, false, sizeof(color));
        pre[1] = 1;
        dfs(1);
        printf("%d\n", moves);
        for(int i = 1; i <= N; i++ ) g[i].clear();
    }
	return 0;
}
