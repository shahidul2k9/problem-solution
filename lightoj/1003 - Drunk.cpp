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
 
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 10009
vi g[N];
int color[N];
bool cycle;
void dfs_visit(int u){
    int v;
    color[u] = GRAY;
    FOR(i,0,g[u].size()-1){
        v = g[u][i];
        if(color[v]==WHITE)dfs_visit(v);
        else if(color[v]==GRAY){
            cycle = true;
            return;
        }
 
    }
    color[u] = BLACK;
}
void DFS(int n){
    memset(color+1,0,sizeof(int)*n);
    FOR(i,1,n){
        if(cycle)return;
        if(color[i]==WHITE)dfs_visit(i);
    }
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    msi h;
 
    int test,m,id,cs=0;
    string st,en;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&m);
        id  = 0;
        FOR(i,1,m){
        cin>>st >> en;
        if(!h[st])h[st] = ++id;
        if(!h[en])h[en] = ++id;
        g[h[st]].push_back(h[en]);
        }
        cycle = false;
        DFS(id);
        printf("Case %d: ",++cs);
       if(cycle)printf("No\n");
       else printf("Yes\n");
       FOR(i,1,id)g[i].clear();
       h.clear();
    }
    return 0;
}
 