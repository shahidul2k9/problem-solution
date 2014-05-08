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
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
#define N 10
char g[N][N];
bool black,white;
int p;
bool isSafe(int y, int x){
    if(y>8||y<0||x>8||x<0)return false;
    return true;
}
void dfs(int y, int x){
    p++;
    g[y][x] = '#';
     for(int i=0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(isSafe(ny,nx)){
                if(g[ny][nx]=='.')dfs(ny,nx);
                else if(g[ny][nx]=='X')black = true;
                else if(g[ny][nx]=='O')white = true;
            }

     }
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int test,wPoints,bPoints,i,j;
    scanf("%d", &test);
    gets(g[0]);
    while(test--){
        for(i=0;i<9;i++)scanf("%s",g[i]);

        wPoints=bPoints=0;

        for(i=0;i<9;i++)
            for(j=0;j<9;j++){
                if(g[i][j]=='.'){
                    p=0;
                    white = black = false;

                    dfs(i,j);

                    if(white==black)continue;
                    if(white) wPoints +=p;
                    else bPoints +=p;
                }
                else if(g[i][j]=='X')bPoints++;
                else if(g[i][j]=='O')wPoints++;
            }

        printf("Black %d White %d\n", bPoints, wPoints);
    }
	return 0;
}
