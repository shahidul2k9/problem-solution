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
#define MAX_NODES 100009
vi g[MAX_NODES];
mii hash;
int lycans, vampires;
int color[MAX_NODES];
void bfs(int src){
    queue<int> q;
    int u,v,i;
    color[src]  = GRAY;
    q.push(src);
    lycans++;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(i=0;i<g[u].size();i++){
            v = g[u][i];
            if(color[v]==WHITE){
                if(color[u]==GRAY){
                    vampires++;
                    color[v] = BLACK;
                }
                else{
                lycans++;
                color[v] = GRAY;
                }
            q.push(v);
            }
        }
    }
}
int main()
{
   // READ("input.txt");
    //WRITE("output.txt");
    int test,e,i,st,en,index,cs=1,sum;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &e);
        index=0;
        hash.clear();
        for(i=1;i<=e;i++){
            scanf("%d %d", &st,&en);
            if(!hash[st]){hash[st]=++index;g[hash[st]].clear();}
            if(!hash[en]){hash[en]=++index;g[hash[en]].clear();}
            g[hash[st]].push_back(hash[en]);
            g[hash[en]].push_back(hash[st]);
        }
        for(i=1;i<=index;i++)color[i]=WHITE;
        sum =0;
        for(i=1;i<=index;i++){
            if(color[i]!=WHITE)continue;
            lycans = vampires = 0;
            bfs(i);
            sum += max(lycans,vampires);
        }
        printf("Case %d: %d\n", cs++, sum);
    }
    return 0;
}
 