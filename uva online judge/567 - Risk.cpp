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
#define MAX_NODE 21
int dist[MAX_NODE][MAX_NODE];


void floyd(){
    FOR(k,1,MAX_NODE)
        FOR(i,1,MAX_NODE)
            FOR(j,1,MAX_NODE) dist[i][j]= min(dist[i][j],dist[i][k]+dist[k][j]);
}
int main()
{
    int st,en,nadj,query,cs=1;
    //READ("input.txt");
    //WRITE("output.txt");
    while(scanf("%d", &nadj)==1){
        FOR(i,1,MAX_NODE)
            FOR(j,1,i)dist[i][j] = dist[j][i] = INF;
        FOR(i,1,MAX_NODE)dist[i][i] = 0;

        FOR(k,1,19){
            FOR(i,1,nadj){
                scanf("%d", &en);
                dist[k][en] = dist[en][k] = 1;

            }
        scanf("%d", &nadj);
        }
        query = nadj;
        floyd();
       // scanf("%d", &query);
        printf("Test Set #%d\n", cs++);
        FOR(i,1,query){
            scanf("%d %d", &st,&en);
            printf("%2d to %2d: %d\n", st, en, dist[st][en]);
        }
        printf("\n");
    }
  return 0;
}
