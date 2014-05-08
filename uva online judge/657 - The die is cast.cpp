#include <string.h>
#include <cstdio>
#include <cstdlib>
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

#define WIDTH 55
#define HEIGHT 55
int DY,DX;
int dx[]={1,-1, 0, 0};
int dy[]={0,0, 1, -1};
char obstacle = '#';
char g[HEIGHT][WIDTH];
int ans;
bool isSafe(int y, int x){
    if(y>=DY||x>=DX||y<0||x<0||g[y][x]=='.')return false;
    return true;
}
void floodFill(int y,int x){
    if(isSafe(y,x)){
        if(g[y][x]=='X') g[y][x] = '#';
        else return;
        for(int i=0;i<4;i++) floodFill(dy[i]+y, dx[i]+x);
    }
}
void dfs(int y,int x){
    if(!isSafe(y,x))return;
    if(g[y][x]=='.'||g[y][x]==obstacle)return;

    if(g[y][x]=='X'){
        floodFill(y,x);
        ans++;
        }
    else if(g[y][x]=='*')g[y][x] = obstacle;
    for(int i=0;i<4;i++)
        dfs(y+dy[i],x+dx[i]);
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    vi score;
    int i,j,cs=0;
    while(scanf("%d %d", &DX, &DY)==2&&(DX||DY)){
        gets(g[0]);
        for(i=0;i<DY;i++)gets(g[i]);

        score.clear();
        for(i=0;i<DY;i++)
            for(j=0;j<DX;j++){
                if(g[i][j]=='X'){
                    ans = 0;
                    dfs(i,j);
                    score.push_back(ans);
                }
            }

        printf("Throw %d\n", ++cs);
        sort(score.begin(),score.end());
        FOR(i,0,score.size()-2)printf("%d ",score[i]);
        printf("%d\n\n",score[score.size()-1]);
    }
	return 0;
}
