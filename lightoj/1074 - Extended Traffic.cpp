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
const long long INF = 2000000;
struct Edge{
    int from,to;
    long long int  w;
};
vector < Edge > edges;
int bn[205];
long long int dist[205];
int ce, cv;
void bellman(int src){
    dist[src]   = 0;
    long long int now;
    int from, to;
    for( int v = 1; v < cv; v++ ){
        for(int e = 0; e < ce; e++ ){
            from = edges[e].from;
            to = edges[e].to;
            now = dist[from] + edges[e].w;
            if(now < dist[to])
                dist[to] = now;
        }
    }


      while(true){
          int e;
        for(e = 0; e < ce; e++ ){
            from = edges[e].from;
            to = edges[e].to;
            if(dist[to] == -INF)continue;
            now = dist[from] + edges[e].w;
            if(now < dist[to]){
                dist[to] = -INF;
                break;
            }
        }
        if(  e == ce)break;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int test, query, dest, w, cs=1;
    scanf("%d", &test);
    while( test-- ){
        printf("Case %d:\n", cs++);
        scanf("%d", &cv);
        for( int v = 1; v <= cv; v++ )
            scanf("%d", &bn[v]);
        scanf("%d", &ce);
        edges = vector < Edge > (ce);
        for( int k = 0; k < ce; k++ ){
            scanf("%d %d", &edges[k].from, &edges[k].to);
            w = bn[ edges[k].to ]-bn[ edges[k].from ];
            edges[k].w = w*w*w;
        }
        for(int v = 1; v <= cv; v++ )
                dist[v]  = INF;
        bellman(1);
        scanf("%d", &query);
        while( query > 0){
            query--;
            scanf("%d",&dest);
            if(dist[dest] < 3 || dist[dest] >200000)puts("?");
            else printf("%lld\n", dist[dest]);
        }
    }
	return 0;
}
