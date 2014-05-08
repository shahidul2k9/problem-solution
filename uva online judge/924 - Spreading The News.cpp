#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
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
#define INF INT_MAX

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
typedef map<int, string> MIS;
int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }


#define WHITE 1
#define GRAY 2
#define BLACK 3
#define MAX_NODE 100
#define NIL -1
VVI g;
queue<int> q;
VI path;
VI dist,pre,color;
int maxLevel;
int nodes, edges;

// s means startNode
void BFS(int s)
{
    int u, v;
    maxLevel = 0;
   dist = VI(nodes,INF);
   color = VI(nodes,WHITE);

    color[s] = GRAY;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()) {
        u = q.front();  q.pop();

        FOR(i, 0, g[u].size()-1) {
            v = g[u][i];
            if(color[v] == WHITE) {
                color[v] = GRAY;
                dist[v] = dist[u] + 1;
                maxLevel = max(maxLevel,dist[v]);
                q.push(v);
            }
        }
        color[u] = BLACK;
    }
}



int main()
{
    freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    int src, adj, query, v;
    int maxBoom,dayOfBoom;
   while(scanf("%d", &nodes)==1){

    g = VVI(nodes);

    FOR(i, 0, nodes-1) {
        cin >> adj;
        FOR(j,1,adj){
            cin >> v;
            g[i].push_back(v);
        }
    }
    scanf("%d", &query);
    FOR(i,1,query){
         scanf("%d", &src);
         BFS(src);
         maxBoom = 0;
         dayOfBoom = 0;
         FOR(j,1,maxLevel){
             int co = count(dist.begin(),dist.end(),j);
             if(co>maxBoom){
                 dayOfBoom = j;
                 maxBoom = co;
                 }
         }
   if(maxBoom==0)printf("0\n");
   else printf("%d %d\n", maxBoom, dayOfBoom);
    }


   }
	return 0;
}
