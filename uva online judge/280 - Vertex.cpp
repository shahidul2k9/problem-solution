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

VVI g;
VI color;
int nodes, edges;
int reachableNodes;
void DFS_Visit(int u)
{

    FOR(i, 0, g[u].size()-1) {
        int v = g[u][i];
        if(color[v] == WHITE) {
            color[v] = GRAY;
            reachableNodes++;
            DFS_Visit(v);
        }
    }
}

void DFS(int src)
{
    color = VI(nodes+1,WHITE);
    reachableNodes = 0;
    DFS_Visit(src);
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int u, v, query,src;

   while(cin >> nodes&& nodes!=0){
    g = VVI(nodes+1);
    while(cin>>u&&u!=0){
        while(cin>> v&& v!=0)
            g[u].push_back(v);
    }
    cin >> query;
        FOR(i,1,query){
            cin >> src;
            DFS(src);
            printf("%d", nodes-reachableNodes);
            FOR(i,1,nodes){if(color[i]==WHITE)printf(" %d",i);}
            printf("\n");
            }
   }
       return 0;
}
