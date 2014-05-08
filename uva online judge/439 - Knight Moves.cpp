#include <cstdio>
#include <cmath>
#include <map>
#include <climits>
#include <iostream>
#include <vector>
#include <string.h>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

// ---------------------------------------------------------------------
#define MIN(a, b) ( (a) < (b) ? (a) : (b) )
#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )

#define INF INT_MAX


typedef long long LL;
typedef vector<char> VC;
typedef vector<vector<char> > VVC;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef map<int, string> MIS;
// ---------------------------------------------------------------------

#define WHITE 0
#define GRAY 1
#define BLACK 3
#define MAX_NODE 9
int dx[]={2,  2, -2, -2, 1, -1,  1, -1};
int dy[]={1, -1,  1, -1, 2,  2, -2, -2};
queue<II> q;
int color[MAX_NODE][MAX_NODE];
int dist[MAX_NODE][MAX_NODE];

int nodes, edges;

// s means startNode
void BFS(int y,int x)
{
    int ux,uy,vy, vx;
    FOR(i,1,MAX_NODE-1)
        FOR(j,1,MAX_NODE-1)dist[i][j] = INF;

    memset(color,0,sizeof(color));
    color[y][x] = GRAY;
    dist[y][x] = 0;
    q.push(II(y,x));

    while(!q.empty()) {
        uy = q.front().first;
        ux = q.front().second;
        q.pop();

        FOR(i, 0, 7) {
            vx = ux + dx[i];
            vy = uy + dy[i];
            if(color[vy][vx] == WHITE&&vx>0&&vy>0&&vx<9&&vy<9){
                //here color[vy][vx] goes invalid index(negative) but why how I gets accepted I dnon't know

                    color[vy][vx] = GRAY;
                    dist[vy][vx] = dist[uy][ux] + 1;
                    q.push(II(vy,vx));

            }
        }
    }
}

int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int srcx,srcy,destx,desty;
    string st, en;
   while(cin >> st >> en){
    srcy = st[0]-'a'+1;
    srcx = st[1]-'0';
    desty = en[0]-'a'+1;
    destx = en[1]-'0';

    BFS(srcy, srcx );
    cout << "To get from " << st<< " to " << en << " takes " << dist[desty][destx]<< " knight moves." << endl;

   }
	return 0;
}
