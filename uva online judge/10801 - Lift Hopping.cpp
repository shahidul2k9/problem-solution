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
struct Node{
    int cost;
    int node;
    Node(){}
    Node(int n, int c){node = n;cost = c;}
    bool operator <(const Node & node)const{
        return cost > node.cost;
    }
};

typedef pair < int , int > ii;
vector < ii > g[100];
int  el, k;


int dist[100];

int dijkstra(){
    memset(dist, -1, sizeof(dist));
    dist[0] = 0;

    priority_queue< Node > pq;
    pq.push(Node(0, 0));
    int from, to, wt, cost;
    while( !pq.empty()){
        from = pq.top().node;
        cost = pq.top().cost;
        pq.pop();
        if( k == from) return dist[k];

        if( cost == dist[from])
            for( int i = 0; i < (int)g[from].size(); i++ ){
                to = g[from][i].first;
                wt = g[from][i].second;
                if( dist[to] == -1 || dist[to] > dist[from] + wt + 60){
                    dist[to] = dist[from] + wt + 60;
                    pq.push(Node(to, dist[to]));
                }
            }
    }
    return dist[k];
}
int main(){
  //freopen("input.txt", "r", stdin);
  int  ind, ans;
  int T[5];
  int stops[101];
  string line;
  stringstream ss;

  while(scanf("%d %d", &el, &k) == 2){
      for( int i = 0; i < el; i++ )
        scanf("%d", &T[i]);
        getline(cin, line);//clear
        for( int i = 0; i <el; i++ ){
            getline(cin, line);
            ss.clear();
            ss << line;
            ind = 0;
            while(ss >> stops[ind++]);
            ind--;

            for( int x = 0; x < ind; x++ )
                for( int y = x + 1; y < ind; y++){
                    g[ stops[x] ].push_back(ii(stops[y], (stops[y] - stops[x])*T[i]));
                    g[ stops[y] ].push_back(ii(stops[x], (stops[y] - stops[x])*T[i]));
                }
        }
    ans = dijkstra();
    if( ans == -1)puts("IMPOSSIBLE");
    else{
    if( k != 0)
     ans -= 60;
     printf("%d\n", ans);
    }
    for( int i = 0; i < 100; i++ ) g[i].clear();
  }

    return 0;
}
