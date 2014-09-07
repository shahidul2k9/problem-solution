#include <cstdio>
#include <string.h>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAXN 250      /* How many vertices in U+V (in total) */
#define N 125
#define EPS 1e-9
#define SQR(x) ((x)*(x))
int r [MAXN][MAXN];      /* MODIFIED Adj. matrix (see note) */
int parent[MAXN];
int cost[MAXN];
int nodes,edges,s,t,m,n;
 
 
 
void addEdge(int x, int y){
r[x][y+n] = 1;
}
 
bool bfs(){
 
    for(int i=0;i<nodes;i++)parent[i]=-1;
    queue<int> q;
    cost[s] = INT_MAX;
    parent[s] = s;
    q.push(s);
    while (!q.empty()) {
    int u =q.front();q.pop();
    if (u == t)
            return true;
 
    for (int i = 0; i < nodes; i++)
        if (r[u][i] > 0 && parent[i]==-1) {
            parent[i] = u;
            cost[i] = min(cost[u], r[u][i]);
            q.push(i);
        }
    }
return false;
}
 
    int main() {
        int cs=1;
        int test;
        int A[N],B[N];
       // freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        scanf("%d",&test);
        while (test--) {
 
            memset(r, 0, sizeof(r));          /* Clear edges */
            scanf("%d",&n);
            for(int i=0;i<n;i++)scanf("%d",&A[i]);
            scanf("%d",&m);
            for(int i=0;i<m;i++)scanf("%d",&B[i]);
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++){
                    if(B[j]%A[i]==0)addEdge(i,j);
                }
            s = m+n;
            t = m+n+1;
            nodes = n + m + 2;
 
            for(int i=0;i<n;i++)r[s][i]=1;
            for(int i=n;i<m+n;i++)r[i][t]=1;
 
            int maxflow = 0;
            while (bfs()) {
 
                    maxflow += cost[t];
                    int u = t;
                    while (parent[u] != u) {
                        r[parent[u]][u] -= cost[t];
                        r[u][parent[u]] += cost[t];
                        u = parent[u];
                    }
            }
            printf("Case %d: %d\n",cs++,maxflow);
        }
    }
 