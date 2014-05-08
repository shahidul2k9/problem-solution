#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

// ---------------------------------------------------------------------
#define MIN(a, b) ( (a) < (b) ? (a) : (b) )
#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )

#define INF 99999999

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<double> VD;
typedef vector<string> VS;
// ---------------------------------------------------------------------

#define WHITE 1
#define GRAY 2
#define BLACK 3
#define MAX_NODE 10005

VVI G;
int t;
int d[MAX_NODE], f[MAX_NODE];           // d[u] and f[u] denotes the descovered time and finish time
                                        // respectively
int parent[MAX_NODE];
int color[MAX_NODE];
int ord[MAX_NODE];
int nodes, edges;
int ind,connComponent;
void DFS_Visit(int u)
{
    color[u] = GRAY;
    t++;
    d[u] = t;

    FOR(i, 0, G[u].size()-1) {
        int v = G[u][i];
        if(color[v] == WHITE) {
            DFS_Visit(v);
        }
    }
    color[u] = BLACK;
    t = t + 1;
    f[u] = t;
    ord[ind--] = u;
}

void DFS()
{
    ind = nodes;
    t = -1;
    FOR(u, 1, nodes) {
        color[u] = WHITE;
    }

    FOR(u, 1, nodes) {
        if(color[u] == WHITE)
            DFS_Visit(u);
    }
}
void DFS_Visit2(int u)
{
    color[u] = GRAY;


    FOR(i, 0, G[u].size()-1) {
        int v = G[u][i];
        if(color[v] == WHITE) {
            DFS_Visit2(v);
        }
    }
}
void DFS2()
{
    connComponent = 0;
    FOR(u, 1, nodes) {
        color[u] = WHITE;
    }

    FOR(u, 1, nodes) {
        if(color[ord[u]] == WHITE)
            {
                connComponent++;
                DFS_Visit2(ord[u]);

            }
    }
}


int main()
{
    freopen("input.txt", "r", stdin);

    int u, v, test, cs = 1;
    cin >> test;
    while(test--){
    cin >> nodes >> edges;

    G = VVI(nodes+1);

    FOR(i, 1, edges) {
        cin >> u >> v;
        G[u].push_back(v);
    }

    DFS();


    DFS2();
    printf("Case %d: %d\n", cs++, connComponent);
    }
}
