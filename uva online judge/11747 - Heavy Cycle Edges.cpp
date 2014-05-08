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
typedef map<int, string> MIS;


#define MAX_NODE 1010
struct Edge{
    int st;
    int en;
    int w;
}g[25000+10];
bool comp(Edge e1, Edge e2){
    return (e1.w < e2.w);
}
int pre[MAX_NODE];
int findPre(int u){
    if(pre[u]==u)return u;
    else return pre[u]=findPre(pre[u]);
}

int main()
{
   //READ("input.txt");
   // WRITE("output.txt");
    int  prest, preen, nodes, edges;
    VI ans;
    while(scanf("%d %d", &nodes, &edges)==2 && nodes!=0){
        ans.clear();

        FOR(i,0,nodes-1){
            pre[i] = i;
        }
        FOR(i,0,edges-1){
            cin >> g[i].st >> g[i].en >> g[i].w;
        }
        sort(&g[0],g+edges,comp);

        FOR(i,0,edges-1){
            prest = findPre(g[i].st);
            preen = findPre(g[i].en);
            if(prest!=preen) {
                pre[prest] = preen;
            }
            else ans.push_back(g[i].w);
        }
        if(ans.size()==0)printf("forest\n");
        else  {
            sort(ans.begin(),ans.end());
            FOR(i,0,ans.size()-2)cout << ans[i] << " ";
            cout << ans[ans.size()-1] << endl;
        }
    }

  return 0;
}
