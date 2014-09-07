#include <stdio.h>
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
#include <cstring>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
vector < int > g[400];
bitset < 400 > explored;
char grid[21][21];
int R, C, N;
int num[20][20], color[20][20];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1,  0, -1};
int match[400];
void bfs(int r,int c){
    queue<int> q;
    color[r][c] = GRAY;
    q.push(r);q.push(c);
    int fromR, fromC, toR, toC;
    while(!q.empty()){
        fromR = q.front();q.pop();
        fromC = q.front(); q.pop();
        for(int k = 0; k < 4; k++ ){
            toR = fromR + dr[k];
            toC = fromC + dc[k];
if(toR >= 0 && toR < R && toC >= 0 && toC < C &&grid[toR][toC] == '*'){
                if(color[toR][toC] == WHITE){
                q.push(toR);
                q.push(toC);
                }
 
                if(color[fromR][fromC] == GRAY){
                    color[toR][toC] = BLACK;
                    g[num[fromR][fromC]].push_back(num[toR][toC]);
                }
                else {
                    color[toR][toC] = GRAY;
                    g[num[toR][toC]].push_back(num[fromR][fromC]);
 
                }
 
            }
        }
    }
}
bool matching(int from){
 
    int to;
    for(int i = 0; i < (int)g[from].size(); i++ ){
        to = g[from][i];
        if( !explored.test(to)){
        explored.set(to);
        if(match[to] == -1 || matching(match[to]) ){
            match[to] = from;
            return true;
        }
        }
    }
    return false;
}
int main(){
    //freopen("input.txt","r", stdin);
    int test, stars, ans, cs= 1;
    scanf("%d", &test);
    while( test-- ){
        N = 0;
        scanf("%d %d", &R, &C);
            getchar();
        for(int i = 0; i < R; i++)gets(grid[i]);
 
        for(int i = 0; i < R; i++ )
            for(int j = 0; j < C; j++ )
                if(grid[i][j] == '*')
                    num[i][j] = N++;
 
        memset(color, 0, sizeof(color));
        for(int i = 0; i < R; i++ )
            for(int j = 0; j < C; j++)
                if(grid[i][j] == '*' && color[i][j] == WHITE)
                    bfs(i,j);
        stars = ans = 0;
        memset(match, -1, sizeof(int)*N);
        for(int i = 0; i < R; i++ )
            for(int j = 0; j < C; j++ )
                if(grid[i][j] == '*'){
                    stars++;
                    if(color[i][j] == GRAY){
                        /*
                        int v = num[i][j];
                        cout << v << " -> ";
                        for(int k = 0; k < g[v].size(); k++ ) cout << g[v][k] << " ";puts("");
                        */
                        explored.reset();
                        ans += matching(num[i][j]);
                    }
                }
    printf("Case %d: %d\n", cs++, stars - ans);
    for(int i = 0; i < N; i++ ) g[i].clear();
    }
    return 0;
}