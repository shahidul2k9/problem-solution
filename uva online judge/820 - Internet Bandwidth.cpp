#include <cstdio>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
#define MAXN 100

	int main() {
		int nodes,edges,s,t,st,en,cst,i,j,cs=0;
		int r [MAXN][MAXN];
		int parent[MAXN];
        int cost[MAXN];
        bool vis[MAXN];
		while (scanf("%d",&nodes)&&nodes!=0) {
		    for(i=0;i<nodes;i++)
                for(j=0;j<nodes;j++)
                r[i][j]=0;
		    scanf("%d %d %d",&s,&t,&edges);
            s--;t--;
            for(i=0;i<edges;i++){
                scanf("%d %d %d",&st,&en,&cst);
                st--;
                en--;
				r[st][en] += cst;
				r[en][st] += cst;
			}
			cost[s] = INT_MAX;
			parent[s] = s;
			int maxflow = 0;
			bool path = true;
			while (path) {
				path = false;
				queue<int> q;
				for(i=0;i<nodes;i++)vis[i]=false;
				//for(i=0;i<nodes;i++)parent[i]=i;
				q.push(s);

				vis[s] = true;
				while (!q.empty()) {
					int u =q.front();q.pop();
					if (u == t) {
						path = true;
						break;
					}
					for (int i = 0; i < nodes; i++)
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
			printf("Network %d\n",++cs);
			printf("The bandwidth is %d.\n\n",maxflow);
		}
		return 0;
        }

