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
#define INF 10000000
int N, M;
int cp[1000];
int memo[1000][101];
vector < ii > g[1000];
struct State{
    int node, cost, fuel;
    State(){}
    State(int v, int c, int f){node = v; cost= c; fuel = f;}
    bool operator < (  const State& that) const{
        if(this->cost != that.cost ) return this->cost < that.cost;
        return this->fuel > that.fuel;
    }
};
int dijkstra( int src, int dest, int capacity ){
    priority_queue < State  > pq;
    for( int i = 0; i < N; i++ )
        for( int j = 0; j <= capacity; j++ )
            memo[i][j] = INF;


    memo[src][0] = 0;
    pq.push(State(src, 0, 0));
    State top, now;
    int to, from, wt;
    while( !pq.empty( ) ){
        top = pq.top();
        from = top.node;
        pq.pop();

        if( memo[from][top.fuel] < top.cost) continue;
        if( from == dest && top.fuel == 0 ) return top.cost;

         if( memo[from][ top.fuel + 1] > top.cost + cp[from] && top.fuel < capacity) {
            now = State(from, top.cost + cp[from], top.fuel + 1);
            pq.push(now);
         }
            now = top;
            if( now.fuel > 0)
            for( int i = 0; i <(int)g[from].size(); i++ ){
            to = g[from][i].first;
            wt = g[from][i].second;
            if( wt <= now.fuel && memo[to][ now.fuel-wt ] > now.cost ){
                memo[to][ now.fuel-wt ] = now.cost;
                pq.push(State(to, now.cost, now.fuel-wt));

            }
        }


    }
    return -1;
}
int main(){
   // freopen("input.txt", "r", stdin);
     //freopen("output.txt", "w", stdout);
    int from,to, wt, q, capacity;
    while(scanf("%d %d", &N, &M) == 2){
        for( int i = 0; i < N; i++ )
            scanf("%d", &cp[i]);
        for( int i = 0; i < M; i++ ){
            scanf("%d %d %d", &from, &to, &wt);
            g[from].push_back(ii(to, wt));
            g[to].push_back(ii(from, wt));
            }
        scanf("%d", &q);
        for( int i = 0; i < q; i++ ){
            scanf("%d %d %d", &capacity, &from, &to);
            int ans = dijkstra(from, to, capacity);

            if( ans != -1)
                printf("%d\n", ans);
            else printf("impossible\n");
        }
        for( int i = 0; i < N; i++ ) g[i].clear();
    }
	return 0;
}
