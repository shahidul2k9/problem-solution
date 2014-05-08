#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
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
#define INF INT_MAX

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
typedef map<int, string> MIS;
#define MAX_NODE 105
int d[MAX_NODE][MAX_NODE];
int nodes,edges;
VI maybe;
void floyd(){
    FOR(k,1,nodes)
        FOR(i,1,nodes)
            FOR(j,1,nodes){
                if(d[i][k]!=INF&&d[k][j]!=INF)d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
}
int main()
{
  //  READ("input.txt");
    //WRITE("output.txt");
    int test,st, en,  dist, w,cs=1;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &nodes, &edges);
        FOR(i,1,nodes)
            FOR(j,1,nodes)d[i][j] = INF;
        FOR(i,1,edges){
            scanf("%d %d %d", &st, &en, &w);
            if(d[st][en]>w)d[st][en] = w;
            if(d[en][st]>w)d[en][st] = w;
        }
        FOR(i,1,nodes)d[i][i]=0;
        floyd();

        dist = INF;
        int x;
        for(int i = 1; i <= nodes; i++ ){
            x = d[i][1];
            if(d[i][1] == x && d[i][2] == x && d[i][3] == x && d[i][4] == x && d[i][5]){

                int curdist = 0;
                for(int k = 1; k <= nodes; k++ )
                    curdist = max(curdist, d[i][k]);
                if(curdist < dist){
                    dist = curdist;
                }

            }
        }

        if(dist == INF) dist = -1;
        printf("Map %d: %d\n", cs++, dist);
    }
  return 0;
}
