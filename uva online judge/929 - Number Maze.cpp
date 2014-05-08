#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>
#include <string.h>		// For memset function
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <map>

using namespace std;

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )

#define SQR(x) ((x)*(x))

#define INF INT_MAX
#define EPS 1e-9
#define PI (2*acos(0.0))
#define TO_RAD (PI/180)
#define TO_DEG (180/PI)

#define SZ size()
#define PB push_back
#define PF push_front

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long LL;
typedef vector<char> VC;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<vector<int> > VVI;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_DY 1000
#define MAX_DX 1000

int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
typedef vector<vector<pair<int, int> > > VVP;
typedef pair<int,pair<int,int> >PIP;
int DY,DX;
priority_queue<PIP, vector<PIP >, greater<PIP > > pq;
int g[MAX_DY][MAX_DX];
int dist[MAX_DY][MAX_DX];
bool outsideOfgrid(II p){
    if(p.first<0||p.second<0||p.first>=DY||p.second>=DX)return true;
    else return false;
}
void dijkstra(int srcy,int srcx)
{

    II u,v;
    int w,d;
    dist[srcy][srcx] = g[srcy][srcx];

    pq.push(PIP(g[srcy][srcx],II(srcy,srcx)));

    while( !pq.empty() ) {
        u = pq.top().second;
        d = pq.top().first;
        pq.pop();
        if(d==dist[u.first][u.second])/* if true then update u now and other occurences of u in pq
                        at this moment never will be updated*/
            FOR(i, 0, 3) {

                v.first = u.first + dy[i];
                v.second = u.second + dx[i];
                if(outsideOfgrid(v))continue;
                w = g[v.first][v.second];

                if( dist[u.first][u.second] + w < dist[v.first][v.second] ) {
                    dist[v.first][v.second] = dist[u.first][u.second] + w;
                    pq.push(PIP(dist[v.first][v.second],II(v.first,v.second)));
                }
            }
    }
}
int main()
{
    //READ("input.txt");
   // WRITE("output.txt");

    int test;
    scanf("%d",&test);
    while( test--) {
        cin >> DY >> DX;
        FOR(i, 0, DY-1) {
            FOR(j, 0, DX-1){
                cin>> g[i][j];
                dist[i][j] = INF;
            }
        }
        dijkstra(0,0);
        cout << dist[DY-1][DX-1] << endl;
    }
	return 0;
}
