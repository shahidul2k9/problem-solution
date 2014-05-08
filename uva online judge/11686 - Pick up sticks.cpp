#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PQ priority_queue
#define PB push_back
#define SZ size()
#define ff first
#define ss second

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef vector<char> VC;
typedef vector<vector<char> > VVC;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

VVI g;
VI ft;
VI color;
VI top;
bool cycle;
int nodes, edges, t, in;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

inline int src() { int ret; scanf("%d", &ret); return ret; }
void dfs(int u){
    color[u] = GRAY;
      FOR(i,0,g[u].size()-1){
        int v = g[u][i];
    if(color[v]==WHITE){
        dfs(v);
    }
    else if(color[v] == GRAY) {cycle = true; return ;}
    }
    color[u] = BLACK;
    ft[u] = t++;
    top[in--] = u;
}
void topSort(){
        cycle = false;
        FOR(i,1,nodes){
            if(color[i]==WHITE){
                if(cycle == true)return;
                dfs(i);
            }
        }
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int st,en;
    while(scanf("%d %d", &nodes, &edges)==2 && nodes!=0 && edges!=0){
        g = VVI(nodes+1);
        color = VI(nodes+1,WHITE);
        ft = VI(nodes+1,0);
        top = VI(nodes+1);
        t = 0;
        in = nodes;
        FOR(i,1,edges){
            scanf("%d %d", &st ,&en);
            g[st].push_back(en);
        }
        topSort();
        if(cycle == true)printf("IMPOSSIBLE\n");
        else
            FOR(i,1,nodes)printf("%d\n", top[i]);
    }
  return 0;
}
