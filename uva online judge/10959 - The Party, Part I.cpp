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
#define INF 99999999

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef vector<char> VC;
typedef vector<vector<char> > VVC;
typedef vector<int> vi;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef map<int, string> MIS;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_NODE 1009
int nodes,edges;
int dist[MAX_NODE];
vi g[MAX_NODE];

void bfs(int src){
    queue<int> q;
    int u,v;
    FOR(i,0,nodes-1)dist[i] = INF;
    q.push(src);
    dist[src]=0;
    while(!q.empty()){
        u = q.front();
        q.pop();
        FOR(i,0,g[u].size()-1){
            v = g[u][i];
            if(dist[v]==INF){
                dist[v] = dist[u] +1;
                q.push(v);
            }
        }
    }
}
int main()
{
   //READ("input.txt");
    //WRITE("output.txt");
   int test,st,en;
   bool isBlank = false;
   scanf("%d", &test);
   while(test--){
       cin>> nodes >> edges;
       FOR(i,1,edges){
           scanf("%d %d", &st, &en);
           g[st].push_back(en);
           g[en].push_back(st);
       }

       bfs(0);
       if(isBlank)printf("\n");
       FOR(i,1,nodes-1)printf("%d\n",dist[i]);
       isBlank = true;
       FOR(i,0,nodes-1)g[i].clear();
   }
  return 0;
}
