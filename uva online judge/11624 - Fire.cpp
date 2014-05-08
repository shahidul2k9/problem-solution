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


#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_NODE 1010
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int DY,DX;
char g[MAX_NODE][MAX_NODE];
int jd[MAX_NODE][MAX_NODE];
int fd[MAX_NODE][MAX_NODE];
bool color[MAX_NODE][MAX_NODE];
struct Point {
    int x;
    int y;
    Point(int b,int a){
        y = b;
        x = a;
    }
    Point(){}

};
bool isSitting(Point v){
    if(v.y<0||v.x<0||v.y>=DY||v.x>=DX||g[v.y][v.x]=='#'||g[v.y][v.x]=='F')
        return false;
        else return true;

}
void bfsForJoe(Point src){
    queue<Point> q;
    Point u,v;
    FOR(i,0,DY-1)
        FOR(j,0,DX-1){
            jd[i][j] = INF;
            color[i][j] = false;
        }
    jd[src.y][src.x] = 0;
    color[src.y][src.x]= true;
    q.push(src);
    while(!q.empty()){
        u = q.front();
        q.pop();
        FOR(i,0,3){
            v.y = u.y  + dy[i];
            v.x = u.x  + dx[i];
            if(color[v.y][v.x]==false&&isSitting(v)){
                color[v.y][v.x] = true;
                jd[v.y][v.x] = jd[u.y][u.x] + 1;
                q.push(v);
            }
        }
    }

}
void bfsForFire(){

    queue<Point> q;
    Point u,v;
    FOR(i,0,DY-1)
        FOR(j,0,DX-1){
            if(g[i][j]=='F'){
                color[i][j] = true;
                fd[i][j] = 0;
                q.push(Point(i,j));
            }
            else {
            fd[i][j] = INF;
            color[i][j] = false;
            }
        }
    while(!q.empty()){
        u = q.front();
        q.pop();
        FOR(i,0,3){
            v.y = u.y  + dy[i];
            v.x = u.x  + dx[i];
            if(color[v.y][v.x]==false&&isSitting(v)){
                color[v.y][v.x] = true;
                fd[v.y][v.x] = fd[u.y][u.x] + 1;
                q.push(v);
            }
        }
    }

}
int main()
{
   //READ("input.txt");
    //WRITE("output.txt");
    int test;
    Point jpt,fpt;
    scanf("%d",&test);

    while(test--){
        scanf("%d%d",&DY,&DX);
        gets(g[0]);
        FOR(i,0,DY-1)
            gets(g[i]);
        FOR(i,0,DY-1)
            FOR(j,0,DX-1){
                if(g[i][j]=='J'){jpt.y = i;jpt.x = j;}
            }
        bfsForJoe(jpt);
        bfsForFire();
        int dist = INF;
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
        if(dist!=INF)printf("%d\n",dist+1);
        else printf("IMPOSSIBLE\n");
    }
  return 0;
}
