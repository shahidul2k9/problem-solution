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

int dc[] = {1, 0, -1, 0};
int dr[] = {0, 1, 0, -1};
typedef pair < int , int > ii;
vector < ii > pts;
int loc, nodes;
char g[50][51];
int dist[50][50];
int M[11][11];
int memo[1 << 11][11];
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
        for( int i = 0; i < 4; i++ ){
            ty = dr[i] + fy;
            tx = dc[i] + fx;
            if( dist[ty][tx] == -1 && g[ty][tx] != '~' && g[ty][tx] != '#' && isvalid(ty, tx))
            {
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

   //freopen("input.txt", "r", stdin);

    bool possible;
    while( scanf("%d %d", &row, &col) == 2 &&(row || col) ){
        getchar();
        for( int i = 0; i < row; i++ ) gets(g[i]);
        possible = true;
        for( int i = 0; i < row; i++ )
            for( int j = 0; j < col; j++ )
                if( g[i][j] == '*'){
                    g[i][j] = '~';
                    for( int k = 0; k < 8; k++)
                        if( isvalid(i + dy[ k ], j + dx[k]) ){
                            if( g[ i + dy[k] ] [ j + dx[k] ]== '!') possible = false;

                            if( g[ i + dy[k] ] [ j + dx[k] ] != '*' )
                                g[ i+dy[k] ] [ j+dx[k] ] = '~';
                        }
                }

        //for( int i = 0; i < row; i++ ) puts(g[i]);
        if( !possible ) {
            puts("-1");
            continue;
        }
        pts.clear();
        loc = - 1;
        for( int i = 0; i < row; i++ )
            for( int j = 0; j < col; j++ ){
                if( g[i][j] == '!')
                    pts.push_back(ii(i, j));

                else if( g[i][j] == '@' ){
                    pts.push_back( ii(i, j) );
                    loc = pts.size() - 1;

                }
            }

    if( loc == -1 ) {
            puts("-1");
            continue;
        }
    nodes = pts.size();

    for( int i = 0; i < (int) pts.size() && possible ; i++ ){

        bfs( pts[i].first, pts[i].second );

        for( int j = 0; j < (int) pts.size(); j++ ){
            if( dist[pts[j].first][ pts[j].second ] == -1 )
                possible = false;

            M[i][j]  = dist[pts[j].first][ pts[j].second ];
        }
    }
    if( !possible ) {
            puts("-1");
            continue;
        }
    /*
    for( int i = 0; i < nodes; i++ ){
        for( int j = 0; j < nodes; j++ )
            printf("%5d", M[i][j]);
        puts("");
        }
    */
    memset(memo, -1, sizeof(memo));
    printf("%d\n", tsp(0, loc));
    }


	return 0;
}
