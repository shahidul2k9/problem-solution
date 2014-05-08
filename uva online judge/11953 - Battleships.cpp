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

#define N 101
char g[N][N];

int n;
int dy[]= {1,-1,0,0,1,1,-1,-1};
int dx[]= {0,0,1,-1,1,-1,-1,1};

bool isSafe(int y, int x){
    if(y>=n||y<0||x>=n||x<0)return false;
    return true;
}
void dfs(int y, int x){
    if(isSafe(y,x)&&g[y][x]!='.')
       {
        g[y][x] = '.';
       for(int i=0;i<8;i++)dfs(y+dy[i],x+dx[i]);
       }
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int test,unsinked, i,j,cs=0;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &n);
        for(i=0;i<n;i++)
            scanf("%s", g[i]);
        unsinked = 0;

        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                if(g[i][j]=='X'||g[i][j]=='x'){
                    unsinked++;
                    dfs(i,j);
                    }
            }

    printf("Case %d: %d\n", ++cs, unsinked);
    }
	return 0;
}
