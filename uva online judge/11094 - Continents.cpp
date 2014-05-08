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
#define N 25
string g[N];
bool color[N][N];
char ch;
int m,n,sum;
int dy[] ={1,0,-1,0};
int dx[] ={0,1,0,-1};
inline bool isSafe(int y,int x){
    if(y<0||y>=m||x<0||x>=n)return false;
    return true;
}
void floodFill(int y,int x){
    sum++;
    color[y][x] = true;
    int ny,nx;
    FOR(i,0,3){
        ny = y + dy[i];
        nx = x + dx[i];
        if(isSafe(ny,nx)&&g[ny][nx]==ch&&color[ny][nx]==false)floodFill(ny,nx);
    }
    if(x==n-1&&g[y][0]==ch&&color[y][0]==false)floodFill(y,0);
    else if(x==0&&g[y][n-1]==ch&&color[y][n-1]==false)floodFill(y,n-1);
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    string line;
    int test,ans,cy,cx;

    while(scanf("%d%d", &m,&n)==2){
    getline(cin,line);
    FOR(i,0,m-1)getline(cin,g[i]);
    scanf("%d%d", &cy,&cx);
    getline(cin,line);
    ch = g[cy][cx];
    memset(color,WHITE,sizeof(color));
    ans = sum = 0;
    floodFill(cy,cx);
    FOR(i,0,m-1)
        FOR(j,0,n-1){
            if(g[i][j]==ch&&color[i][j]==false) {
               sum = 0;
               floodFill(i,j);
               ans = max(sum,ans);
            }
        }
    printf("%d\n", ans);
    getline(cin,line);
    }
	return 0;
}
