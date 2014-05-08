#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>


using namespace std;

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))

#define INF INT_MAX


#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<vector<int> > vvc;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<int, string> mis;
typedef map<string, string> mss;
typedef map<string, char> msc;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NEG -1
#define N 101
string g[N];
int d[N][N];
int R,C;
int dy[] = {2,2, -2,-2,1,-1,1,-1};
int dx[] = {1,-1, 1,-1,2, 2,-2,-2};

int ky[] = {1,0,-1,0, 1,1,-1,-1};
int kx[] = {0,1, 0,-1,1,-1,1,-1};
struct Point{
    int x;
    int y;
    Point(){
    }
    Point(int cy, int cx){
        y = cy;
        x = cx;
    }
};
    Point k,p;

bool isSafe(int y, int x){
    if(y<0||x<0||y>=R||x>=C)return false;
    return true;
}
void bfs(Point src){
    queue<Point> q;
    Point u,v;
    d[src.y][src.x] = 0;
    g[src.y][src.x] = '#';
    q.push(src);
    while(!q.empty()){
        u = q.front();
        q.pop();
        if(u.y==p.y&&u.x==p.x)break;
        FOR(i,0,7){
            v.y = u.y + ky[i];
            v.x = u.x + kx[i];
            if(isSafe(v.y,v.x)&&g[v.y][v.x]!='#'){
                d[v.y][v.x] = d[u.y][u.x] +1;
                g[v.y][v.x] = '#';
                q.push(v);
            }
        }
    }
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int test,y,x;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &R, &C);
        FOR(i,0,R-1)cin >> g[i];

        FOR(i,0,R-1)
            FOR(j,0,C-1){
                d[i][j] = NEG;
                if(g[i][j]=='Z'){
                    g[i][j] = '#';
                    FOR(k,0,7){
                        y = i + dy[k];
                        x = j + dx[k];
                        if(isSafe(y,x)&&g[y][x]=='.')g[y][x] = '#';
                    }
                }
                else if(g[i][j]=='B')
                    p = Point(i,j);
                else if(g[i][j]=='A') k = Point(i,j);
            }

        bfs(k);
        if(d[p.y][p.x]!=NEG)printf("Minimal possible length of a trip is %d\n", d[p.y][p.x]);
        else
            printf("King Peter, you can't go now!\n");
    }
	return 0;
}
