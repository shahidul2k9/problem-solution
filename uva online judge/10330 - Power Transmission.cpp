#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
#define MAXN 210
#define INF 99999999
int main() {
	    freopen("input.txt","r",stdin);
		int nodes,edges,s,t,st,en,cst,i,j;
		int r[MAXN][MAXN];
		int parent[MAXN];
        int cost[MAXN];
        bool vis[MAXN];
        int act,w,ns,nt;
		while (scanf("%d",&act)==1) {

		    nodes = 2*act+2;
		    s = nodes-1;
		    t = nodes;
            for(i=1;i<=nodes;i++)
                for(j=1;j<=nodes;j++)
                    r[i][j]=0;

            for(i=1;i<=act;i++){
            scanf("%d", &w);
            r[i][i+act] =  w;
            }
            scanf("%d", &edges);


            for(i=0;i<edges;i++){
                scanf("%d %d %d",&st,&en,&cst);
				r[st+act][en] += cst;
			}


			scanf("%d%d", &ns,&nt);
			for(i=1;i<=ns;i++){
			    scanf("%d", &st);
			    r[nodes-1][st] = INF;
			}
			for(i=1;i<=nt;i++){
			    scanf("%d", &en);
			r[en+act][t]=INF;
			}
			cost[s] = INF;
			parent[s] = s;
			int maxflow = 0;
			bool path = true;
			while (path) {
				path = false;
				queue<int> q;
				for(i=1;i<=nodes;i++)vis[i]=false;
				for(i=1;i<=nodes;i++)parent[i]=i;
				q.push(s);
				vis[s] = true;
				while (!q.empty()) {
					int u =q.front();q.pop();
					if (u == t) {
						path = true;
						break;
					}
					for (int i = 1; i <=nodes; i++)
						if (r[u][i] > 0 && !vis[i]) {
							parent[i] = u;
							cost[i] = min(cost[u], r[u][i]);
							vis[i] = true;
							q.push(i);
						}
				}
				if (path) {
					maxflow += cost[t];
					int u = t;
					while (parent[u] != u) {
						r[parent[u]][u] -= cost[t];
						r[u][parent[u]] += cost[t];
						u = parent[u];

					}
				}
			}

			printf("%d\n",maxflow);

		}
		return 0;
	}
