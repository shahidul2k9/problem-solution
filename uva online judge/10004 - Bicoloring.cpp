#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
#include <climits>
using namespace std;
#define pb(x) push_back(x)
#define MAXNODE 210
#define INF INT_MAX
#define ff first
#define ss second
#define sz size()
typedef pair< int, int > pii;
typedef queue <int> qi;
vector< int > g[MAXNODE];
int d[MAXNODE];
int bfs(int n, int src){
    bool color[210];
    bool taken[210];
    for(int i=0;i<n;i++)color[i] = false,taken[i]=false;
    int i,u,v;
    qi q;
    q.push(src);
    d[src]=0;
    while(!q.empty()){
        u = q.front();q.pop();
        for(i=0;i<g[u].sz;i++)
            {
                v = g[u][i];

                if(taken[v]==false) {
                    color[v] = !color[u];
                    taken[v] = true;
                    q.push(v);
                }
                else if(color[u]==color[v]){printf("NOT ");return 0;}
            }
    }
return 0;
}
int main () {
   // freopen("input.txt","r",stdin);
	int n, e, i, u, v;
        while(scanf("%d",&n)&&n!=0){
            scanf("%d",&e);
		for(i = 0; i < n; i++) g[i].clear(); // forget previous info
		for(i = 0; i < e; i++) {
			scanf("%d %d",&u,&v);
			g[u].pb(v);
            g[v].pb(u);//if graph is undirected
		}
        bfs(n,0);
        printf("BICOLORABLE.\n");

        }
	return 0;
}
