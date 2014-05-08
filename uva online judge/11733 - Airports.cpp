#include <set>
#include <map>
#include <list>
#include <climits>
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
typedef map<int, char> MIC;
typedef map<string, int> MSI;
typedef map<int, string> MIS;
typedef vector<vector<vector<int> > > VVVI;
#define MAX_NODE 10010
#define MAX_EDGE 100010
int nodes,edges;
int pre[MAX_NODE];
struct Edge{
    int st;
    int en;
    int w;
}edge[MAX_EDGE];

int findPre(int u){
    if(pre[u]==u)return u;
    else return pre[u]= findPre(pre[u]);
}
bool comp(Edge e1, Edge e2){
    return e1.w < e2.w;
}
int main()
{
   READ("input.txt");
   // WRITE("output.txt");
    int test,airCost,cs=1,conCom, prest,preen;
    int ans;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d %d", &nodes,&edges,&airCost);
        FOR(i,0,edges-1)
            scanf("%d %d %d", &edge[i].st,&edge[i].en, &edge[i].w);

        FOR(i,1,nodes)pre[i] = i;
        ans = 0;
        conCom = nodes;
        sort(edge,edge+edges,comp);
        for(int i=0;i<edges;i++){
            if(edge[i].w>=airCost)break;
            prest = findPre(edge[i].st);
            preen = findPre(edge[i].en);
            if(prest!=preen){
                ans += edge[i].w;
                pre[prest] = pre[preen];
                if(--conCom==1)break;
            }
        }
        printf("Case #%d: %d %d\n", cs++, ans+conCom*airCost, conCom);
    }
  return 0;
}
