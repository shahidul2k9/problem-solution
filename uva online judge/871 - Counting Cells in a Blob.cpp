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
int dx[]={1,-1,0,0,1,-1,1,-1};
int dy[]={0,0,1,-1,1,1, -1,-1};
#define N 26
char g[N][N];
string t[N];
int l[N];
int row,m;
bool isSafe(int y, int x){
    if(y>=row||y<0||x>=l[y]||x<0)return false;
    return true;
}
void dfs(int y, int x){
    m++;
    g[y][x] = '0';
     for(int i=0;i<8;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(isSafe(ny,nx))
                if(g[ny][nx]=='1')dfs(ny,nx);
     }
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int test,i,j,ans,index;
    bool blank = false;
    scanf("%d", &test);
    getline(cin,t[0]);
    getline(cin,t[0]);
    while(test--){
        row=0;
        while(getline(cin,t[row])&&t[row]!=""){
            index=0;
            for(i=0;i<t[row].size();i++){
                if(t[row][i]=='0'||t[row][i]=='1')g[row][index++]=t[row][i];
            }
            l[row] = index;
            row++;
        }

        ans = 0;
        for(i=0;i<row;i++)
            for(j=0;j<l[i];j++){
                if(g[i][j]=='1') {
                    m=0;
                    dfs(i,j);
                    ans = max(m,ans);
                }
            }
        if(blank)printf("\n");
        blank=true;
        printf("%d\n", ans);
    }
	return 0;
}
