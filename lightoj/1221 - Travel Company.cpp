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
const long long INF = 20000000022L;
struct Edge{
    int from,to;
    long long int  w;
};
vector < Edge > edges;
long long int dist[205];
int ce, cv;
bool bellman(){
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


      for(int e = 0; e < ce; e++ ){
            from = edges[e].from;
            to = edges[e].to;
            now = dist[from] + edges[e].w;
            if(now < dist[to])
                return true;
        }
    return false;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int test ,income, expense, p, cs=1;
    scanf("%d", &test);
    while( test-- ){
        scanf("%d %d %d", &cv, &ce, &p);
        printf("Case %d: ", cs++);


        edges = vector < Edge > (ce);
        for( int k = 0; k < ce; k++ ){
            scanf("%d %d %d %d", &edges[k].from, &edges[k].to, &income, &expense);
            edges[k].w = p*expense - income;
        }




        fill(dist, dist+cv, 0);
        if(bellman())puts("YES");
        else puts("NO");
    }
	return 0;
}
