#include <algorithm>
#include <bitset>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string.h>
#include <ctime>
#include <vector>
using namespace std;
#define NODE 15
#define inf INT_MAX
#define getsb(b) ( b &(-b) )
#define clrfb(b) ( b & ~getsb(b) )
#define set(b, pos) ( b | (1 << pos) )
#define off(b, pos) ( b & ~( 1 << pos) )
#define test(b, pos) (b & (1 << pos) )

int V, E;
int d[NODE][NODE];
int deg[NODE];
int memo[1 << NODE];

void floyd(){
    for(int k = 0; k < V; k++ )
        for(int i = 0; i < V; i++ )
            for(int j = 0; j < V; j++ )
                if(d[i][k] != inf && d[k][j] !=inf )
                    d[i][j] = min(d[i][k]+d[k][j], d[i][j]);
}
int cpom(int bits){
    if(memo[bits] >= 0 )return memo[bits];
    int ans = inf;
    int b;
    for(int i = 0; i < V; i++ )
        for(int j = i+1; j < V; j++ )
            if(test(bits, i) && test(bits, j)){
                b = bits;
                b = off(b, i);
                b = off(b, j);
                ans = min(ans, cpom(b) + d[i][j]);
            }
    return memo[bits] = ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int weight, st, en, wt, b;
    while( scanf("%d %d", &V, &E) == 2){
        for(int i = 0; i < V; i++ )
            for(int j = 0; j < V; j++)
                d[i][j] = inf;
        memset(deg, 0, sizeof(deg));
        weight = 0;
        for(int e = 0; e < E; e++){
            scanf("%d %d %d", &st, &en, &wt);
            st--;en--;
            weight += wt;
            d[st][en] = d[en][st] = min(d[st][en], wt);
            deg[st]++;
            deg[en]++;
        }
        floyd();
        b = 0;
        for( int v = 0; v < V; v++ )
            if(deg[v] & 1) b = set(b, v);
        memset(memo, -1, sizeof(memo));
        memo[0] = 0;
        weight += cpom(b);
        printf("%d\n",weight);
    }
	return 0;
}
