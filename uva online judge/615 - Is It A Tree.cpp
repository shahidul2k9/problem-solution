#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <map>
#include <string.h>

using namespace std;

// ---------------------------------------------------------------------
#define MIN(a, b) ( (a) < (b) ? (a) : (b) )
#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )

#define INF 99999999

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef map<int,int> MII;
// ---------------------------------------------------------------------

#define WHITE 1
#define GRAY 2
#define BLACK 3
#define MAX_NODE 1001

VVI g;
int t;
VI color;

int indeg[MAX_NODE];
int nodes,root;
bool backEdge;
void DFS_Visit(int u)
{
    color[u] = GRAY;

    FOR(i, 0, g[u].size()-1) {
        int v = g[u][i];
        if(color[v] == WHITE) {
            DFS_Visit(v);
        }
    }
}

void DFS(int s)
{
    color = VI(nodes+1,WHITE);
    DFS_Visit(s);
}

int main()
{
   // freopen("input.txt", "r", stdin);

    int u, v, cs=1;

   while(cin >> u >> v && u>=0){
       if(u==0&&v==0){
           printf("Case %d is a tree.\n", cs++);
           continue;
       }
      memset(indeg,0,sizeof(indeg));
      nodes = 0;
      MII hashing;
      g = VVI(MAX_NODE+1);
      if(hashing[u]==0) hashing[u] = ++nodes;
      if(hashing[v]==0) hashing[v] = ++nodes;
      g[hashing[u]].push_back(hashing[v]);
      indeg[hashing[v]] +=1;
        while(cin >> u >> v && u!=0&&v!=0) {
            if(hashing[u]==0) hashing[u] = ++nodes;
            if(hashing[v]==0) hashing[v] = ++nodes;
            g[hashing[u]].push_back(hashing[v]);
             indeg[hashing[v]] +=1;
    }

   root = -1;
   backEdge = false;
   FOR(i,1,nodes){
       if(indeg[i]==0){
           if(root==-1)root = i;
           else {
               backEdge = true;
           break;
           }
       }
       else if(indeg[i]>1){
            backEdge = true;
            break;
            }
   }
   if(backEdge==true||root == -1){
       printf("Case %d is not a tree.\n", cs++);
       continue;
   }
   DFS(root);
   FOR(i,1,nodes)if(color[i]==WHITE){backEdge = true;break;}
    if(backEdge)
       printf("Case %d is not a tree.\n", cs++);

    else printf("Case %d is a tree.\n", cs++);
   }
   return 0;
}
