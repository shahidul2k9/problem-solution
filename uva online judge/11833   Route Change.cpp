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
vector < ii > g[250];
int dist[250];
int N, M, C, K;
int dijkstra(){
        priority_queue < ii, vector<ii> , greater<ii> > pq;
        for( int i = 0; i < N; i++ )
            dist[i] = INF;
        dist[K] = 0;
        pq.push(ii(K, 0));
        int from, to, wt, cost;

        while( !pq.empty()){
            from = pq.top().first;
            cost = pq.top().second;
            pq.pop();
            //if( from == C-1) return dist[from];
            if( dist[from] == cost)
            for( int i = 0; i <(int)g[from].size(); i++ ){
                to = g[from][i].first;
                wt = g[from][i].second;
                if( from < C){
                    if( to == from + 1 && dist[to] > dist[from] + wt) {
                        dist[to] = dist[from] + wt;
                        pq.push(ii(to, dist[to]));
                    }

                }
                else if( dist[to] >  dist[from] + wt){
                    dist[to] = dist[from] + wt;
                    pq.push(ii(to, dist[to]));
                }

            }
        }
    return dist[C-1];
}
int main(){
    //freopen("input.txt", "r", stdin);
    int st, en, wt, ans;
    while(scanf("%d %d %d %d", &N, &M, &C, &K) == 4 && N){
        for( int i = 0; i < M; i++ ){
            scanf("%d %d %d", &st, &en, &wt);
            g[st].push_back(ii(en, wt));
            g[en].push_back(ii(st, wt));
        }
        ans = dijkstra();
        printf("%d\n", ans);
        for( int i = 0; i < N; i++ )
            g[i].clear();
    }

	return 0;
}
