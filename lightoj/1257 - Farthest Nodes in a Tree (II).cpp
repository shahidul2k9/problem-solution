#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
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
typedef pair<int,int> ii;
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NODE 30009
#define NIL -1
 
vector<ii> g[NODE];
int nodes,edges;
int d[NODE];
int ed[NODE];
 
 
void bfs(int u){
    int v,w;
    d[u] = 0;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        u = q.front();
        q.pop();
    FOR(i,0,g[u].size()-1){
    v = g[u][i].first;
    w = g[u][i].second;
    if(d[v]==NIL){
        d[v] = d[u] + w;
        q.push(v);
        }
    }
    }
}
 
void bfs2(int u){
    queue<int> q;
    int v,w;
    ed[u] = 0;
    q.push(u);
    while(!q.empty()){
        u = q.front();
        q.pop();
    FOR(i,0,g[u].size()-1){
    v = g[u][i].first;
    w = g[u][i].second;
    if(ed[v]==NIL){
        ed[v] = ed[u] + w;
       q.push(v);
        }
    }
    }
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int test,st,en,dist,w,cs=0;
 
    scanf("%d", &test);
    while(test--){
 
    scanf("%d", &nodes);
    FOR(i,0,nodes-1)g[i].clear();
    FOR(i,0,nodes-2){
        scanf("%d %d %d", &st, &en, &w);
        g[st].push_back(ii(en,w));
        g[en].push_back(ii(st,w));
    }
 
    printf("Case %d:\n", ++cs);
    memset(d,-1,sizeof(d));
 
    bfs(0);
    dist = -1;
    FOR(i,0,nodes-1)if(d[i]>dist){st = i;dist=d[i];}
 
 
 
    memset(d,-1,sizeof(d));
    bfs(st);
    dist = -1;
    FOR(i,0,nodes-1)if(d[i]>dist){en = i;dist=d[i];}
 
    memset(ed,-1,sizeof(ed));
    bfs2(en);
 
    FOR(i,0,nodes-1)printf("%d\n", max(d[i],ed[i]));
 
    }
    return 0;
}