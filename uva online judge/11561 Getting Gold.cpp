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
#include <deque>
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;
char g[50][51];
bool movable[50][50];
int R, C;
int dr[] = {1, 0, -1,0};
int dc[] = {0, 1, 0, -1};
int ans = 0;
inline bool isInside(int r, int c){
    return r < R && r >= 0 && c < C && c >= 0;
}
void dfs(int r, int c){
    if( g[r][c] == '#')return;
    if(g[r][c] == 'G'){
        ans += 1;
    }
     g[r][c] = '#';
    if(movable[r][c])
    for(int k = 0; k < 4; k++ )
            if(isInside(r + dr[k],  c + dc[k]))
                dfs(r + dr[k], c+dc[k]);

}
int main(){
    int nr, nc;
    //freopen("input.txt", "r", stdin);
    while(scanf("%d %d", &C, &R) == 2){
        for( int i = 0; i < R; i++ )
            scanf("%s", g[i]);
        memset(movable, true, sizeof(movable));
        for(int i = 0; i < R; i++ )
            for( int j = 0; j < C; j++ )
                for(int k = 0; k < 4; k++ ){
                    nr = i + dr[k];
                    nc = j + dc[k];
                    if(isInside(nr, nc) && g[nr][nc] == 'T' )
                        movable[i][j] = false;
                }
        for(int r = 0; r < R; r++ )
            for( int c = 0; c < C; c++ )
                if( g[r][c] == 'T')
                        g[r][c] = '#';
                else if(g[r][c] == 'P'){
                    nr = r;
                    nc = c;
                }
        ans = 0;
        dfs(nr, nc);
        printf("%d\n", ans);
    }
	return 0;
}
