/*
This proble has a bug value of M can be 0
*/


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

#define MAX_NODE 25
MIS revName;
int d[MAX_NODE][MAX_NODE];
int dist[MAX_NODE];
int nodes,edges;
void floyd(){
    FOR(k,1,nodes)
        FOR(i,1,nodes)
            FOR(j,1,nodes){
                if(d[i][k]!=INF&&d[k][j]!=INF){
                    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
                }
            }
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int st,en, sum, w, minDist,cs = 1;
    string num;
    while(scanf("%d %d", &nodes, &edges)&& nodes!=0){
        revName.clear();
        FOR(i,1,nodes)
            FOR(j,1,nodes) d[i][j] = INF;
        FOR(i,1,nodes) {
            cin >> num;
            revName[i]= num;
            }
        FOR(i,1,edges){
            scanf("%d %d %d", &st, &en, &w);
            d[st][en] = d[en][st] = w;
        }
        FOR(i,1,nodes)d[i][i] = 0;
        floyd();
        minDist=INF;
        FOR(i,1,nodes){
            sum = 0;
            FOR(j,1,nodes){
                if(d[i][j]==INF){
                    sum = INF;
                    break;
                }
                else{
                    sum +=d[i][j];
                }
            }
            minDist = min(minDist,sum);
            dist[i] = sum;
        }

        FOR(i,1,nodes){
            if(dist[i]==minDist){
                printf("Case #%d : %s\n",cs++, revName[i].c_str());
                break;
                }
        }
    }
  return 0;
}
