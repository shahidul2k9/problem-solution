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

int nodes;
VI dist;
VI parent;
VI path;
priority_queue<II, vector<II>, greater<II> > pq;
VVP g;

void dijkstra(int src)
{
    dist = VI(nodes+1, INF);
    parent = VI(nodes+1);
    FOR(i,1,nodes)parent[i] = i;

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
                    parent[v] = u;
                    pq.push(II(dist[v],v));
                }
            }
    }
}
int main()
{
   // READ("input.txt");
   // WRITE("output.txt");

    int st, en, w, cs=1;
    int outDeg;

    while( cin >> nodes && nodes!=0) {
        g = VVP( nodes +1 );
        FOR(i, 1, nodes) {
            cin >> outDeg;
            FOR(j,1,outDeg){
                cin >> en >> w;
                g[i].PB(II(en,w));
        }
           // g[en].PB(II(st,w));
        }
        cin >> st >> en;
        dijkstra(st);
        VI path;
        int u,v;
        u = st;
        v = en;
        while(v!=st){
            path.push_back(v);
            v = parent[v];

        }
        path.push_back(st);
        printf("Case %d: Path = ", cs++);

        FORD(i,path.size()-1,1)printf("%d ", path[i]);

        printf("%d; %d second delay\n", path[0], dist[en]);

    }
	return 0;
}
