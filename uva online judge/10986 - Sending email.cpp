#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>
#include <string.h>		// For memset function
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <map>

using namespace std;

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )

#define SQR(x) ((x)*(x))

#define INF INT_MAX
#define EPS 1e-9
#define PI (2*acos(0.0))
#define TO_RAD (PI/180)
#define TO_DEG (180/PI)

#define SZ size()
#define PB push_back
#define PF push_front

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long LL;
typedef vector<char> VC;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<vector<int> > VVI;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2


typedef vector<vector<pair<int, int> > > VVP;

int nodes, edges;
VI dist;
priority_queue<II, vector<II>, greater<II> > pq;
VVP g;

void dijkstra(int src)
{
    dist = VI(nodes, INF);
    int u,v,w,d;
    dist[src] = 0;

    pq.push(II(0,src));

    while( !pq.empty() ) {
        u = pq.top().second;
        d = pq.top().first;
        pq.pop();
        if(d==dist[u])/* if true then update u now and other occurences of u in pq
                        at this moment never will be updated*/
            FOR(i, 0, g[u].size()-1) {

                v = g[u][i].first;
                w = g[u][i].second;
                if( dist[u] + w < dist[v] ) {
                    dist[v] = dist[u] + w;
                    pq.push(II(dist[v],v));
                }
            }
    }
}
int main()
{
    //READ("input.txt");
   // WRITE("output.txt");

    int st, en, w,test, cs=1;
    int source, target;
    scanf("%d", &test);
    while(test--){
         cin >> nodes >> edges >> source >> target;
        g = VVP(nodes);
        FOR(i, 1, edges) {
            cin >> st >> en >> w;
            g[st].PB(II(en,w));
            g[en].PB(II(st,w));
        }
        dijkstra(source);
        printf("Case #%d: ", cs++);
        if(dist[target]==INF)printf("unreachable\n");
        else printf("%d\n", dist[target]);
    }
	return 0;
}
