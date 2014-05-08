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
#define MAX 101
int d[MAX][MAX];
MII m;
void floyd(int n){
    FOR(k,1,n)
        FOR(i,1,n)
            FOR(j,1,n){
                if(d[i][k]!=INT_MAX&&d[k][j]!=INT_MAX){


                    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);


                    }
            }
}

int main()
{
   // READ("input.txt");
    //WRITE("output.txt");
    int u, v, n,cs=1;
    while(cin>>u >> v && u!=0&& v!=0){
        n = 0;
        m.clear();
        FOR(i,1,MAX-1)
            FOR(j,1,MAX-1)d[i][j] = INT_MAX;
        //memset(d,-1,sizeof(d));
        if(m[u]==0)m[u] = ++n;
        if(m[v]==0)m[v] = ++n;

        d[m[u]][m[v]] = 1;
        while(cin>>u >> v && u!=0&& v!=0){
            if(m[u]==0)m[u] = ++n;
            if(m[v]==0)m[v] = ++n;
            d[m[u]][m[v]] = 1;
        }

        FOR(i,1,n)d[i][i] = 0;

        floyd(n);
        double ave = 0;
        FOR(i,1,n){
            FOR(j,1,n){
                ave +=  d[i][j];
            }
        }
        printf("Case %d: average length between pages = %.3f clicks\n",cs++, ave/(n*(n-1)));
    }
  return 0;
}
