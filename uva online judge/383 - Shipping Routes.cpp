#include <cstdio>
#include <cmath>
#include <map>
#include <climits>
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

#define INF INT_MAX


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

#define WHITE 1
#define GRAY 2
#define BLACK 3
#define MAX_NODE 100

VVI g;
queue<int> q;
VI dist,color;

int nodes, edges;

// s means startNode
void BFS(int s)
{
    int u, v;

   dist = VI(nodes+1,INF);
   color = VI(nodes+1,WHITE);

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
                q.push(v);
            }
        }
        color[u] = BLACK;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int  test,query, capacity,cs =1;
    string st,en,item;
    scanf("%d", &test);
    printf("SHIPPING ROUTES OUTPUT\n\n");
   while(test--){
    scanf("%d %d %d", &nodes, &edges, &query);
    g = VVI(nodes+1);
    MSI hash;
    FOR(i,1,nodes){
        cin >> item;
        hash[item] = i;
    }
    FOR(i, 1, edges) {
        cin >> st >> en;
        g[hash[st]].push_back(hash[en]);
        g[hash[en]].push_back(hash[st]);
    }
    printf("DATA SET  %d\n\n", cs++);
    FOR(i,1,query){
        cin >> capacity>> st >> en;
            BFS(hash[st]);
            if(dist[hash[en]]>capacity)printf("NO SHIPMENT POSSIBLE\n");
            else printf("$%d\n", dist[hash[en]]*100*capacity);

    }
    printf("\n");
   }
   printf("END OF OUTPUT\n");
	return 0;
}
