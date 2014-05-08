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



#define MAX_NODE 1005
#define NIL -1
int dy[]={1,-1,0,0};
int dx[]={0, 0,1,-1};
VVB g;
int DX,DY;
queue<pair<int,int> > q;
bool color[MAX_NODE][MAX_NODE];
int dist[MAX_NODE][MAX_NODE];

int nodes, edges;
int destx,desty;

bool isOngrid(pair<int,int> p){
    if(p.first<0||p.first>=DY||p.second<0||p.second>=DX||g[p.first][p.second]==false)
        return false;
    else return true;
}
int BFS(int srcy, int srcx)
{
    pair<int,int> u,v;

   FOR(i,0,DY-1)
      FOR(j,0,DX-1){
          dist[i][j] = INF;
          color[i][j] = false;
      }

    color[srcy][srcx] = true;
    dist[srcy][srcx] = 0;
    q.push(make_pair(srcy,srcx));

    while(!q.empty()) {
        u = q.front();
         q.pop();

        FOR(i,0,3) {
            v.first = u.first + dy[i];
            v.second = u.second + dx[i];

            if(color[v.first][v.second] == false&&isOngrid(v)) {
                color[v.first][v.second] = true;
                dist[v.first][v.second] = dist[u.first][u.second] + 1;

                q.push(v);
            }

        }
    }
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int st,en,adj,srcx,srcy,sz;

   while(scanf("%d %d", &DY, &DX)==2 &&DX!=0&&DY!=0){

    g = VVB(DY,VB(DX,true));

    cin >> sz;
    FOR(i, 0, sz-1) {
        cin >> st>> adj;
        FOR(j,0,adj-1){
        cin >> en;
        g[st][en] = false;
        }
    }
    cin >> srcy >> srcx>> desty >> destx;
    BFS(srcy,srcx);
    cout << dist[desty][destx] << endl;
   }
	return 0;
}
