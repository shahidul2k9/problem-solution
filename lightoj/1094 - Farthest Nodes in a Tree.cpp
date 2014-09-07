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
typedef pair<int, int> ii;
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_NODES 30009
 
vector<ii> g[MAX_NODES];
int color[MAX_NODES];
int dist[MAX_NODES];
void bfs(int src){
    int u,v,i;
    queue<int> q;
    dist[src]=0;
    q.push(src);
    color[src]=GRAY;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(i=0;i<g[u].size();i++){
            v = g[u][i].first;
            if(color[v]==WHITE){
                dist[v] = dist[u] + g[u][i].second;
                color[v] = GRAY;
                q.push(v);
            }
        }
    }
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int test, st, en, nodes, w, i,cs=0;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &nodes);
        for(i=0;i<nodes;i++){g[i].clear();color[i]=WHITE;}
        for(i=0;i<nodes-1;i++){
            scanf("%d %d %d", &st, &en, &w);
            g[st].push_back(ii(en,w));
            g[en].push_back(ii(st,w));
        }
 
        int  src=0;
        bfs(src);
        for(i=0;i<nodes;i++){
            if(dist[src]<dist[i])src=i;
            color[i]  = WHITE;
        }
        bfs(src);
        printf("Case %d: %d\n", ++cs, *max_element(dist, dist+nodes));
        }
return 0;
}