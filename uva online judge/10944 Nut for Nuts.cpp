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
#define isvalid(r, c) r >= 0 && r < row && c >=0 && c < col
#define INF 1 << 20
int dx[] = {1, 0, -1, -1, -1,  0,  1, 1};
int dy[] = {1, 1,  1,  0, -1, -1, -1, 0};
typedef pair < int , int > ii;
vector < ii > pts;
int loc, nodes;
char g[20][21];
int dist[20][20];
int M[20][20];
int memo[1 << 16][16];
int row, col;
void bfs(int sy, int sx ){
    queue < ii > q;
    memset(dist, -1, sizeof(dist));
    dist[sy][sx] = 0;
    q.push(ii(sy, sx));
    int fx, fy, tx, ty;

    while( !q.empty() ){
        fy = q.front().first;
        fx = q.front().second;
        q.pop();
        for( int i = 0; i < 8; i++ ){
            ty = dy[i] + fy;
            tx = dx[i] + fx;
            if( isvalid(ty, tx) && dist[ty][tx] == -1 ){
                dist[ty][tx] = dist[fy][fx] + 1;
                q.push(ii(ty, tx));
            }
        }
    }

}
int tsp( int bitmask, int pos ){
    if( memo[bitmask][pos] != -1 ) return memo[bitmask][pos];
    if( bitmask == (1 << nodes)-1 ) return memo[bitmask][pos] = M[pos][loc];
    int ans = INF;
    for( int i = 0; i < nodes; i++ ){
        if( !(bitmask & (1 << i)) ){
            ans = min( ans , tsp( bitmask | (1 << i), i) + M[pos][i]);
        }
    }
    return memo[bitmask][pos] = ans;
}
int main(){

   // freopen("input.txt", "r", stdin);

    while( scanf("%d %d", &row, &col) == 2 ){
        getchar();
        for( int i = 0; i < row; i++ ) gets(g[i]);

        pts.clear();
        for( int i = 0; i < row; i++ )
            for( int j = 0; j < col; j++ ){
                if( g[i][j] == '#')
                    pts.push_back(ii(i, j));

                else if( g[i][j] == 'L' ){
                    pts.push_back( ii(i, j) );
                    loc = pts.size() - 1;

                }
            }

    nodes = pts.size();

    for( int i = 0; i < (int) pts.size(); i++ ){

        bfs( pts[i].first, pts[i].second );

        for( int j = 0; j < (int) pts.size(); j++ ){
            M[i][j] = M[j][i] = dist[pts[j].first][ pts[j].second ];
        }
    }
    memset(memo, -1, sizeof(memo));
    printf("%d\n", tsp(0, loc));
    }


	return 0;
}
