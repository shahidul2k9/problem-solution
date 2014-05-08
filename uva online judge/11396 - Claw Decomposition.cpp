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
#include <string.h>
#include <sstream>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
vector < int > g[301];
int color[301];
bool dfs(int from ){
    int to;
    for(int i = 0; i < (int)g[from].size(); i++ ){
        to = g[from][i];
        if(color[to] == WHITE){
            color[to] = 3 - color[from];
            if( dfs(to) == false)return false;
        }
        else if(color[from] == color[to]) return false;
    }
    return true;

}
int main(){
    //freopen("input.txt", "r", stdin);
    int V, st, en;
    while(scanf("%d", &V) == 1 && V){
        while(scanf("%d %d", &st, &en) == 2 && st){
            g[st].push_back(en);
            g[en].push_back(st);
        }
        memset(color, WHITE, sizeof(color));
        bool yn = true;
        for(int i = 1; i <= V; i++ ){
            if(color[i] == WHITE){
                color[i] = GRAY;
                if(dfs(i) == false){
                    yn = false;
                    break;
                }
            }
        }
        if(yn)puts("YES");
        else puts("NO");
        for(int i = 1; i <= V; i++ )g[i].clear();
    }

    return 0;
}
