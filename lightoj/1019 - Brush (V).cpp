#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAXNODE 100
#define infinity 1000000000
#define pb(x) push_back(x)
typedef vector < vector <int> > vvi;

vvi edge, cost;
int d[MAXNODE];

//edge[i][j] = jth node connected with i
//cost[i][j] = cost of that edge

void bfs(int n, int source) {


    for(int i=0; i<100; i++) d[i] = infinity;
    queue<int> q;
    q.push( source );
    d[ source ] = 0;

    while( !q.empty() ) {
        int u = q.front(); q.pop();
        int ucost = d[ u ];

        for(int i=0; i<edge[u].size(); i++) {
            int v = edge[u][i], vcost = cost[ u ][i] + ucost;

            // updating - this part is also called relaxing
            if( d[v] > vcost ) {
                d[v] = vcost;
                q.push( v );
            }
        }
    }
    if(d[n-1]==infinity)printf("Impossible\n");
    else
    printf("%d\n",d[n-1]);
}
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T,t,E,N,i,x,y,w;
    scanf("%d",&T);t=1;
    while(T--){
    scanf("%d %d", &N, &E);
    edge = vvi(N);
    cost = vvi(N);
    for(i=0;i<E;i++){
        scanf("%d %d %d",&x,&y,&w);
        x-=1;y-=1;
        edge[x].pb(y);
        edge[y].pb(x);//if graph is bidirected
        cost[x].pb(w);
        cost[y].pb(w);
    }
    //scanf("%d",&src);
    printf("Case %d: ",t);
    bfs(N,0);
    edge.clear();
    cost.clear();
    t++;
    }
    return 0;
}
