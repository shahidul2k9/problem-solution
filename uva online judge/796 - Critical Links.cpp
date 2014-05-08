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
#define V 200
#define WHITE 0
#define GRAY 1
#define BLACK 2
typedef vector< vector<int> > VII;
typedef vector< vector<bool> > VVB;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector < pair<int, int> > VPI;
VII g;
VI f, d, low, color, pre;
VB art;
VVB bridge;
int rootChild, root, t;
void articulationPointAndBridge(int u){

    color[u] = GRAY;
    d[u] = low[u] = t++;
    int sz = g[u].size();
    FOR(i,0,sz-1){
        int v = g[u][i];


        if(color[v]==WHITE){
            pre[v] = u;
            if(root == u && ++rootChild>1)
                art[u] = true;

            articulationPointAndBridge(v);

            if(low[v]>=d[u] && u!=root)art[u] = true;
            if(low[v]>d[u])bridge[u][v] = bridge[v][u]=true;

            low[u] = min(low[u],low[v]);
        }
        else if(pre[u]!=v)
            low[u] = min(d[v],low[u]);

    }
    color[u] = BLACK;
    t++;
}
void dfs(int n){
    t = 0;
    color = VI(n,WHITE);
    pre = VI(n,-1);
    d = VI(n);
    low = VI(n);
    art = VB(n,false);
    bridge = VVB(n);
    FOR(i,0,n-1)
        FOR(j,0,n-1)
            bridge[i][j] = false;
    FOR(i,0,n-1){
        if(color[i]==WHITE){
            rootChild = 0;
            root = i;
            articulationPointAndBridge(i);
        }
    }
}
int main()
{
   freopen("input.txt","r",stdin);
    int  nodes, st, outg, en;
    string buf;
    stringstream ss;
    bool blank = false;
    while(scanf("%d", &nodes)==1){
        g = VII(nodes);
        FOR(i,0,nodes-1){
            scanf("%d (%d)", &st, &outg);
 //           scanf("%d", &st);
//            buf.clear();
//            cin >> buf;
//            FOR(j,0,buf.length()-1)if(buf[j]=='('||buf[j]==')')buf[j] = ' ';
//            ss << buf;
//            ss >> outg;
            FOR(j,0,outg-1){
                scanf("%d", &en);
                g[st].push_back(en);
               // g[en].push_back(st);
            }
        }
    dfs(nodes);
    int cou = 0;
    FOR(i,0,nodes-1)
        FOR(j,0,nodes-1)
            if(bridge[i][j]==true)cou++;
    //sort(bridge.begin(),bridge.end());
    printf("%d critical links\n", cou/2);
    FOR(i,0,nodes-1)
        FOR(j,i+1,nodes-1){
            if(bridge[i][j]==true)
                printf("%d - %d\n", i, j);
    }
    printf("\n");
    }
    return 0;
}
