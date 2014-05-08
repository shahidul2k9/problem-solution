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

#define MAX_ROWS 35
string g[MAX_ROWS];
int r;
int dx[] = {1, -1,0,0};
int dy[] = {0, 0, 1,-1};
bool isSafe(int row, int col){
    if(row>=r||col>=g[row].size()||row<0||col<0||g[row][col]!=' ')return false;
    return true;
}
void floodFill(int rn, int cn){
    if(isSafe(rn,cn)){
        g[rn][cn] = '#';
        for(int i=0;i<4;i++)
            floodFill(rn+dy[i], cn+dx[i]);
        }

}
int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int test,row,col;
    scanf("%d", &test);
    getline(cin,g[0]);
    while(test--){
        r=0;
        bool letsGo = true;
        while(letsGo){
            getline(cin,g[r]);
            letsGo = false;
            for(int i=0;i<g[r].size();i++){
                if(g[r][i]!='_'){
                    letsGo= true;
                    if(g[r][i]=='*'){
                        row = r;
                        col = i;
                    }
                }
            }
            r++;
            }

    g[row][col] = ' ';
    floodFill(row,col);

    for(int i=0;i<r;i++)cout << g[i] << endl;
    }
	return 0;
}
