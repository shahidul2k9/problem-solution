#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <map>
using namespace std;
#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define V 100
#define INF 999999999
typedef vector < vector <int> > VII;
VII g;
int low[V];
int d[V];
bool art[V];
int color[V];
int pre[V];
int t;
int rootChild;
int root;
void articulationPoint(int u){

    color[u] = GRAY;
    d[u] = low[u] = t++;
    int sz = g[u].size();
    FOR(i,0,sz-1){
        int v = g[u][i];
        if(color[v]==WHITE){
            pre[v] = u;
            if(root == u && ++rootChild>1)
                art[u] = true;

            articulationPoint(v);

            if(low[v]>=d[u] && u != root )art[u] = true;

            low[u] = min(low[u],low[v]);
        }
        else if(v !=pre[u])
            low[u] = min(d[v],low[u]);

    }
    color[u] = BLACK;
    t++;
}
void dfs(int n){
    t = 0;
    FOR(i,0,n-1){
        color[i] = WHITE;
        //d[i] = low[i] = INF;
        pre[i] = i;
        art[i] = false;
        }
    FOR(i,0,n-1){
        if(color[i]==WHITE){
            rootChild = 0;
            root = i;
            articulationPoint(i);
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    int nodes, st, en;
    stringstream buf;
    string temp;
    while(scanf("%d", &nodes)&& nodes!=0){
        getline(cin,temp);
        g = VII(nodes);
        while(true){
            getline(cin,temp);
            buf.clear();
            buf << temp;
            buf >> st;
            if(st==0)break;
            st -= 1;
            while(buf >> en){
                en -= 1;
                g[st].push_back(en);
                g[en].push_back(st);
            }
        }
    dfs(nodes);


    int artNum = 0;
    FOR(i,0,nodes-1)if(art[i])artNum++;
    printf("%d\n", artNum);
    }
    return 0;
}
