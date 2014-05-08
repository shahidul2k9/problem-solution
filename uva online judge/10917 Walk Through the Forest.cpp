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
#define INF 200000000
typedef pair < int , int > ii;
int N, M;

vector < ii > g[1001];
int dist[1001];
int paths[1001];
void dijkstra(int src){
    priority_queue < ii , vector < ii > ,  greater<ii> > pq;
    for( int i = 1; i <= N; i++ ) dist[i] = INF;
    dist[src] = 0;
    pq.push(ii(src, 0));

    int from, to, d, wt;
    while(!pq.empty()){
        from = pq.top().first;
        d = pq.top().second;
        pq.pop();

        if( dist[from] >= d){
            for( int i = 0; i < (int) g[from].size(); i++ ){
                to = g[from][i].second;
                wt = g[from][i].first;
                if( dist[to] > dist[from] + wt){
                    dist[to] = dist[from] + wt;
                    pq.push(ii(to, dist[to]));
                }
            }
        }

    }
}
int countPaths(int to){
    if( paths[to] != -1) return paths[to];
    int ways = 0;
    int from;
    for( int i = 0; i < (int) g[to].size(); i++ ){
        from = g[to][i].second;
        if( dist[from] > dist[to] ) ways += countPaths(from);
    }
    return paths[to] = ways;
}
int main(){

    //freopen("input.txt", "r", stdin);
    int from, to, wt;
    while(scanf("%d %d", &N, &M) == 2){
        for( int i = 1; i <= M; i++ ){
            scanf("%d %d %d", &from, &to, &wt);
            g[from].push_back(ii(wt, to));
            g[to].push_back(ii(wt, from));
        }

        dijkstra(2);
        memset(paths, -1, sizeof(paths));
        paths[1] = 1;
        printf("%d\n", countPaths(2));
        for( int i = 1; i <= N; i++ ) g[i].clear();

    }

	return 0;
}
