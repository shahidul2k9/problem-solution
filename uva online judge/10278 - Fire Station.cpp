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
vector < ii > g[501];
int N, F;
int dist[501];
priority_queue< Node > pq;
void dijkstra(){
    int from, to, wt, cost;
    while(!pq.empty()){
        from = pq.top().node;
        cost = pq.top().cost;
        pq.pop();
        if(dist[from] == cost)
            for( int i = 0; i < (int)g[from].size(); i++ ){
                to = g[from][i].first;
                wt = g[from][i].second;
                if( dist[to] == -1 || dist[to] > dist[from] + wt){
                    dist[to] = dist[from] + wt;
                    pq.push(Node(to, dist[to]));
                }
            }
    }
}
int main(){
  // freopen("input.txt", "r", stdin);
    int predist[501];
    int test, cur, prev, ans, n;
    string line;
    stringstream ss;
    int st, en, wt;
    scanf("%d", &test);
    while( test-- ){
        scanf("%d %d", &F, &N);
        memset(dist, -1, sizeof(int)*(N+1));
        for( int i = 0; i < F; i++ ){
            scanf("%d", &n);
            pq.push(Node(n, 0));
            dist[n] = 0;
        }
        getline(cin, line);
        while(getline(cin, line) && line.size() != 0){
            ss.clear();
            ss << line;
            ss >> st >> en >> wt;
            g[st].push_back(ii(en, wt));
            g[en].push_back(ii(st, wt));
        }

        dijkstra();
        memcpy(predist, dist, sizeof(int)*(N+1));
        prev = INT_MAX;
        ans = 1;
        for( int i = 1; i<= N; i++ ){
            dist[i] = 0;
            pq.push(Node(i, 0));
            dijkstra();
            cur = 0;
            for( int k = 1; k <= N; k++ )
                cur = max(dist[k], cur);
            if( cur < prev ) {
                prev = cur;
                ans = i;
            }
            memcpy(dist, predist, sizeof(int)*(N+1));
        }
        printf("%d\n", ans);
        for( int i = 1; i <= N; i++ ) g[i].clear();
        if(test)puts("");
    }
    return 0;
}
