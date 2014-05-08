#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
#define V 200
vector <int> g[V];
bool taken[V];
bool color[V];
bool flag;
int x, y;
int bfs(int n, int src){
    int i;
    flag = false;
    queue <int> q;
    q.push(src);
    taken[src] = true;
    color[src] = true;
    y = 0;
    x = 1;
    while(!q.empty()){
        int u = q.front();q.pop();
        int sz = g[u].size();
        for(i = 0;i<sz;i++){
            int v = g[u][i];
            if(!taken[v]){
                if(color[u] == true) y++;
                else x++;
                color[v] = !color[u];
                q.push(v);
                taken[v] = true;
            }
            if(color[u] == color[v]) {
                flag = true;
                return 0;
            }
        }
    }
    return 0;
}
int main()
{
   // freopen("input.txt","r",stdin);
    int test,i,nodes, edges, f, s, guards;
    scanf("%d",&test);
    while(test--){
        scanf("%d %d", &nodes, &edges);
        guards =0;
        for(i=0;i<nodes;i++){
            g[i].clear();
            taken[i]=false;
            color[i]= false;
            }
        for(i=0;i<edges;i++){
            scanf("%d %d", &s, &f);
            g[s].push_back(f);
            g[f].push_back(s);
            }
        for(i=0;i<nodes;i++){
            if(taken[i] == false){
                bfs(nodes,i);
                if(x==0||y==0)guards +=1;
                else guards += min(x,y);
                if(flag == true)break;
            }
        }
        if(flag == true) printf("-1\n");

            else printf("%d\n", guards);

    }
    return 0;
}
