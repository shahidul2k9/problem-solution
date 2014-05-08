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
    bool with;
    Node(){}
    Node(int n, int c, bool w){node = n;cost = c;with =  w;}
    bool operator <(const Node & node)const{
        return cost > node.cost;
    }
};

typedef pair < int , int > ii;
vector < ii > g[500];
int N, E;
int dist[500][2];

void dijkstra(){
    priority_queue< Node > pq;
    memset(dist, -1, sizeof(dist));
    dist[0][1] = 0;
    pq.push(Node(0, 0, true));

    int from, to, wt, cost;
    bool with;
    while(!pq.empty()){
        from = pq.top().node;
        cost = pq.top().cost;
        with = pq.top().with;
        pq.pop();
        if(dist[from][with] == cost)
            for( int i = 0; i < (int)g[from].size(); i++ ){
                to = g[from][i].first;
                wt = g[from][i].second;
                if( dist[to][!with] == -1 || dist[to][!with] > dist[from][with] + wt){
                    dist[to][!with] = dist[from][with] + wt;
                    pq.push(Node(to, dist[to][!with], !with));
                }
            }
    }
}
int main(){
   //freopen("input.txt", "r", stdin);
  int st, en, wt, cs=1;
    while( scanf("%d %d", &N, &E) == 2 ){
        for( int i = 0; i < E; i++ ){
            scanf("%d %d %d", &st, &en, &wt);
            g[st].push_back(ii(en, wt));
            g[en].push_back(ii(st,wt));
        }
        dijkstra();
        if( dist[N-1][1] != -1 )printf("Set #%d\n%d\n", cs++, dist[N-1][1]);
        else printf("Set #%d\n?\n", cs++);
        for( int i = 0; i < N; i++ )g[i].clear();
    }

    return 0;
}
