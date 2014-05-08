#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <cstring>
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

#define NODES 201
vi g[NODES];
int color[NODES];
int N;
int bfs(int src){
    queue < int > q;
    q.push(src);
    color[src] = 1;
    int A, B, from, to;
    A = 1;
    B = 0;
    bool bicolorable = true;
    while(!q.empty()){
        from = q.front();
        q.pop();
        FOR(i,0,g[from].size()-1){
            to = g[from][i];
            if(color[to] == 0){
                color[to] = 3 - color[from];
                q.push(to);
                if(color[to] == 2) B++;
                else A++;
            }
            else if(color[from] == color[to]) bicolorable = false;
        }
    }
    if(bicolorable == false)return 0;
    return max(A,B);
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int test, adjs, ans, en, id;
    mii hash;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &N);
        id = 0;
        FOR(i,1, N){
            scanf("%d", &adjs);
            FOR(j,1,adjs){
                scanf("%d", &en);
                if(en>N)continue;
                g[i].push_back(en);
                g[en].push_back(i);
            }
        }

        memset(color, 0, sizeof color);
        ans = 0;
        FOR(i,1,N){
            if(color[i] == 0)
                ans += bfs(i);
        }
    printf("%d\n", ans);
    FOR(i,1,N)g[i].clear();
    }
	return 0;
}
