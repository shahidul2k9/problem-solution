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
typedef pair< int , int > ii;
#define INF 999999
vector < int > g[2001];
int dist[2001];
map<int, bool>  has;
int N, M, K;
int dijkstra(int src, int dest){
        priority_queue < ii, vector<ii> , greater<ii> > pq;
        for( int i = 1; i <= N; i++ )
            dist[i] = INF;
        if(has.find(src) == has.end())dist[src] = 1;
        else dist[src] = 0;
        pq.push(ii(src, dist[src]));
        int from, to, cost, wt;
        while( !pq.empty()){
            from = pq.top().first;
            cost = pq.top().second;
            pq.pop();
            //if( dest == from ) return dist[dest];
            if(dist[from] == cost)
                for( int i = 0; i < (int)g[from].size(); i++ ){
                    to = g[from][i];
                    if(has.find(to) == has.end()) wt = 1;
                    else wt = 0;
                    if(dist[to] > dist[from] + wt){
                        dist[to] = dist[from] + wt;
                        pq.push(ii(to, dist[to]));
                    }
                }
        }
    return dist[dest];
}
int main(){
    //freopen("input.txt", "r", stdin);
    int  ans, st, en, x;
    int Q, test, cs = 1;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d %d", &N, &M, &K);
        has.clear();
        for( int i = 1; i <= K; i++ ){
            scanf("%d", &x);
            has[x] = true;
        }
        for( int i = 1; i <= M; i++ ){
            scanf("%d %d", &st, &en);
            g[st].push_back(en);
            g[en].push_back(st);
        }
        printf("Case %d:\n", cs++);
        scanf("%d", &Q);
        while(Q--){
            scanf("%d %d", &st, &en);
            if( st == en ) ans = 0;
            else
            ans = dijkstra(st, en);
           if( ans == INF) ans = -1;
           printf("%d\n", ans);
        }
        puts("");
        for( int i = 1; i <= N; i++ ) g[i].clear();
    }


	return 0;
}
