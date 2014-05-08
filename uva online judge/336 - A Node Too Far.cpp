#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PQ priority_queue
#define PB push_back
#define SZ size()
#define ff first
#define ss second

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef vector<char> VC;
typedef vector<vector<char> > VVC;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;


#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_NODE 32
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

VVI g;
VI color;
VI tle;
int t,maxTime,reachableNodes;
MII network;

void bfs(int src){
        color[src] = GRAY;
        queue<int> q;
        q.push(src);
        reachableNodes = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(tle[u]<=0)continue;
            FOR(i,0,g[u].size()-1){
                int v = g[u][i];
                if(color[v] == WHITE) {
                   tle[v] = tle[u] - 1;
                    color[v] = GRAY;
                    q.push(v);
                    reachableNodes++;
                }
            }
        }
        }
int main()
{
   //READ("input.txt");
    //WRITE("output.txt");
    int edges, id, st ,en, src, cs=1;
    while(scanf("%d", &edges)==1 && edges!=0){
        id = 1;

        g = VVI(MAX_NODE);


        network.clear();
        FOR(i,1,edges){
            scanf("%d %d", &st, &en);
            if(network[st]==0){
                network[st] = id;
                id++;

            }
             if(network[en]==0){
                network[en] = id;
                id++;

            }
        g[network[st]].push_back(network[en]);
        g[network[en]].push_back(network[st]);
        }
        int TTL;
        while(scanf("%d %d", &src, &TTL)==2 && src!=0 || TTL!=0){
            reachableNodes = 0;
            tle = VI(MAX_NODE,0);
            color = VI(MAX_NODE,WHITE);
            tle[network[src]]=TTL;
            bfs(network[src]);

printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cs++, network.size()-reachableNodes,src,TTL);
        }
    }

  return 0;
}
