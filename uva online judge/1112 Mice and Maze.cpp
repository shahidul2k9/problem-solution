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
typedef pair < int, int > ii;
#define INF 100000000
vector < ii > g[101];
int N, E, T, M;
int dist[101];
int dijkstra(int src ){
    priority_queue < ii > pq;
    for( int i = 1; i <= N; i++ ) dist[i] = INF;
    pq.push( ii(src, 0));
    dist[src] =0;
    int from, to, t, cost;
    while( !pq.empty() ){
        from = pq.top().first;
        cost = pq.top().second;
        pq.pop();

        if( dist[from] == cost && dist[from] <= T)
        for( int i = 0; i < (int) g[from].size(); i++ ){
            to = g[from][i].first;
            t = g[from][i].second;
            if( dist[from] + t < dist[to]){
                dist[to] = dist[from] + t;
                pq.push(ii(to, dist[to]));
            }
        }
    }

    int mices = 0;
    for( int i = 1; i <= N; i++ )
        if( dist[i] <= T )
            mices += 1;
    return mices;
}
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test, from, to, t;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d %d", &N, &E, &T);
        scanf("%d", &M);
        for( int i = 0; i < M; i++ ){
            scanf("%d %d %d", &from, &to, &t);
            g[to].push_back( ii(from, t) );
        }
    printf("%d\n", dijkstra(E));
    if(test)puts("");
    for( int i = 1; i <= N; i++ ) g[i].clear();
    }

	return 0;
}
