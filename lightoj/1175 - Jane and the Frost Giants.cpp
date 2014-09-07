#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>
 
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
 
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};
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
 
#define N 202
char g[N][N];
int fd[N][N], jd[N][N];
int DY,DX;
 
 
struct Point{
    int x,y;
    Point(int yy, int xx){
        y = yy;
        x = xx;
    }
    Point(){}
};
 
bool isSafe(Point v){
    if(v.y>=DY||v.y<0||v.x>=DX||v.x<0)return false;
    return true;
}
 
void bfsForJ(Point src){
    queue<Point> q;
    jd[src.y][src.x] = 0;
    q.push(src);
    Point u,v;
    while(!q.empty()){
        u = q.front();
        q.pop();
 
        FOR(i,0,3){
            v.y = u.y + dy[i];
            v.x = u.x + dx[i];
            if(isSafe(v)&&g[v.y][v.x]=='.'&&jd[v.y][v.x]==INF){
                jd[v.y][v.x] = jd[u.y][u.x] + 1;
                q.push(v);
            }
        }
    }
 
}
 
 
void bfsForF(){
    queue<Point> q;
 
    FOR(i,0,DY-1)
        FOR(j,0,DX){
            if(g[i][j]=='F'){
                fd[i][j] = 0;
                q.push(Point(i,j));
            }
        }
    Point u,v;
    while(!q.empty()){
        u = q.front();
        q.pop();
 
        FOR(i,0,3){
            v.y = u.y + dy[i];
            v.x = u.x + dx[i];
            if(isSafe(v)&&g[v.y][v.x]=='.'&&fd[v.y][v.x]==INF){
                fd[v.y][v.x] = fd[u.y][u.x] + 1;
                q.push(v);
            }
        }
    }
 
}
int main()
{
  //  READ("input.txt");
    //WRITE("output.txt");
    int test,cs=0;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &DY, &DX);
        gets(g[0]);
        FOR(i,0,DY-1)gets(g[i]);
        Point  jpt;
        FOR(j,0,DY-1)
            FOR(i,0,DX-1){
                jd[j][i] = fd[j][i] =INF;
                if(g[j][i]=='J'){
                   jpt = Point(j,i);
                }
            }
    bfsForJ(jpt);
    bfsForF();
    int dist =INF;
       FOR(i,0,DY-1)if(jd[i][0]<fd[i][0]){
            dist = min(dist,jd[i][0]);
        }
        FOR(i,0,DX-1)if(jd[0][i]<fd[0][i]){
            dist = min(dist,jd[0][i]);
            }
 
        FOR(i,0,DX-1)if(jd[DY-1][i]<fd[DY-1][i]){
            dist = min(dist,jd[DY-1][i]);
            }
 
        FOR(i,0,DY-1)if(jd[i][DX-1]<fd[i][DX-1]){
            dist = min(dist,jd[i][DX-1]);
        }
        printf("Case %d: ", ++cs);
        if(dist!=INF)printf("%d\n",dist+1);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}