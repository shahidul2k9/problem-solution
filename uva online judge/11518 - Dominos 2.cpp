#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>


using namespace std;

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))

#define INF INT_MAX


#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<vector<int> > vvc;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<int, string> mis;
typedef map<string, string> mss;
typedef map<string, char> msc;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_NODES 10005
vi g[MAX_NODES];
int color[MAX_NODES];
int nodes, edges,fallNo;
void clearAll(){
    for(int i=1;i<=nodes;i++){
        g[i].clear();
        color[i] = WHITE;
    }
}
void dfs(int u){
    fallNo++;
    color[u] = GRAY;
    int v,i;
    for(i=0;i<g[u].size();i++){
        v = g[u][i];
        if(color[v]==WHITE)dfs(v);
    }
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int test,forces,i,st,en,src;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d %d", &nodes, &edges, &forces);
        clearAll();
        for(i=0;i<edges;i++){
            scanf("%d %d", &st, &en);
            g[st].push_back(en);
        }

        fallNo = 0;
        for(i=0;i<forces;i++){
            scanf("%d", &src);
            if(color[src]==WHITE)dfs(src);
        }
        printf("%d\n",fallNo);
    }
	return 0;
}
