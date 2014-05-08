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
#define SZ size()
#define PB push_back
#define PF push_front

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<vector<char> > > VVVC;
typedef vector<vector<int> > VVI;
typedef vector<vector<char> > VVC;
typedef vector<double> VD;
typedef vector<char> VC;
typedef vector<string> VS;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define L 31
#define R 31
#define C 31
typedef struct {
    int x,y,z;
}Point;

int DX,DY,DZ;
char g[R][C][L];
int d[R][C][L];
bool taken[R][C][L];
int dx[] = {1, -1,  0,  0, 0,  0};
int dy[] = {0,  0,  1, -1, 0,  0};
int dz[] = {0,  0,  0,  0, 1, -1};


Point st,en;
void bfs(Point s){
    FOR(z,0,DZ-1){
            FOR(y,0,DY-1){
                FOR(x,0,DX-1){
                    d[z][y][x] = INF;
                    taken[z][y][x] = false;
                }
            }
        }

    queue<Point> q;
    Point u,v;
    d[s.z][s.y][s.x] = 0;
    taken[s.z][s.y][s.x] = true;
    q.push(s);
    while(!q.empty()){
        u = q.front();
        q.pop();
        FOR(i,0,5){
            v.x = u.x + dx[i];
            v.y = u.y + dy[i];
            v.z = u.z + dz[i];
    if(v.z>=0&&v.y>=0&&v.x>=0&&v.z<DZ&&v.y<DY&&v.x<DX&&g[v.z][v.y][v.x]!='#'&&taken[v.z][v.y][v.x]==false){
                taken[v.z][v.y][v.x]=true;
                d[v.z][v.y][v.x] = d[u.z][u.y][u.x] + 1;
                q.push(v);
            }
        }
    }

}
int main()
{
     //READ("input.txt");
    //WRITE("output.txt");
    string buf;
    while(scanf("%d %d %d", &DZ, &DY, &DX)==3 && DZ!=0 && DY!=0&& DZ!=0){
        getline(cin,buf);
        FOR(z,0,DZ-1){
            FORD(y,DY-1,0){
                getline(cin,buf);
                FOR(x,0,DX-1){
                    g[z][y][x] = buf[x];
                    if(buf[x]=='S'){
                        st.z = z;
                        st.y = y;
                        st.x = x;
                    }
                    if(buf[x]=='E'){
                        en.z = z;
                        en.y = y;
                        en.x = x;
                    }

                }
            }
            getline(cin,buf);
        }

    bfs(st);
    if(d[en.z][en.y][en.x]==INF)
        printf("Trapped!\n");
    else
        printf("Escaped in %d minute(s).\n", d[en.z][en.y][en.x]);
    }
	return 0;
}
