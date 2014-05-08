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
#define MAX_NODE 1000
#define NIL -1
VI g[MAX_NODE];
queue<int> q;

VI dist,pre,color;

int nodes, edges;

// s means startNode
void BFS(int s)
{
    int u, v;

   dist = VI(nodes+1,INF);
   pre = VI(nodes+1, NIL);
   color = VI(nodes+1,WHITE);

    color[s] = GRAY;
    dist[s] = 0;
    pre[s] = NIL;
    q.push(s);

    while(!q.empty()) {
        u = q.front();  q.pop();

        FOR(i, 0, g[u].size()-1) {
            v = g[u][i];
            if(color[v] == WHITE) {
                color[v] = GRAY;
                dist[v] = dist[u] + 1;
                pre[v] = u;
                q.push(v);
            }
        }
        color[u] = BLACK;
    }
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string u, v;
    bool blank = false;
   while(scanf("%d", &edges)==1){
    MSI city;
    MIS rev;
    nodes= 0;
    if(blank)cout << endl;
    blank = true;
    FOR(i, 1, edges) {
        cin >> u >> v;
        if(city[u]==0){
            city[u] = ++nodes;
            rev[nodes] = u;
            g[nodes].clear();
        }
        if(city[v]==0){
            city[v] = ++nodes;
            rev[nodes] = v;
            g[nodes].clear();
        }
        g[city[u]].push_back(city[v]);
        g[city[v]].push_back(city[u]);
    }

     cin >> u >> v;
     if(city[u]==0){
            city[u] = ++nodes;
            rev[nodes] = u;
            g[nodes].clear();
        }
        if(city[v]==0){
            city[v] = ++nodes;
            rev[nodes] = v;
            g[nodes].clear();
        }

    BFS(city[u]);
    if(dist[city[v]]==INF) {printf("No route\n");continue;}
    int st = city[u];
    int en = city[v];
    VI path;
    for(int i = en;i!=st;i = pre[i]){
        path.push_back(i);
    }

    path.push_back(st);
    if(st==en)cout << u << " " << v << endl;
    else {
        FORD(i,path.size()-1,1){
            cout << rev[path[i]] << " " << rev[path[i-1]] << endl;
        }
    }
   }
	return 0;
}
