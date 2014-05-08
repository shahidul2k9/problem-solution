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

#define MAX_ROW 35
#define MAX_COLUMN 85
string g[MAX_ROW];

bool marked[MAX_ROW][MAX_COLUMN];
int row;

int dy[]= {1, -1, 0, 0};
int dx[]= {0, 0, 1, -1};
bool isLastLine(){
    for(int i=0;i<g[row].size();i++)if(g[row][i]!='_')return false;
    return true;
}

char findContourChar(){
    int i,j;
    for(i=0;i<row;i++)
        for(j=0;j<g[i].size();j++)
            if(g[i][j]!=' ')return g[i][j];
    return ' ';
}

bool isSafe(int r, int c){
    if(r>=row||r<0||c>=g[r].size()||c<0)return false;
    return true;
}
void floodFill(int r, int c, char ch){
    int i;
    if(!marked[r][c]&&g[r][c]!='X'){
    g[r][c] = ch;
    marked[r][c] = true;
    for(i=0;i<4;i++)
        if(isSafe(r+ dy[i], c+dx[i]))floodFill(r+ dy[i], c + dx[i], ch);
    }


}
int main()
{
    READ("input.txt");
    WRITE("output.txt");
    char chcon;
    row =0;
    int i,j;
    while(getline(cin,g[row])){

        if(!isLastLine()){row++;continue;}

        chcon = findContourChar();
        memset(marked,0, sizeof(marked));
        for(i=0;i<row;i++)
            for(j=0;j<g[i].size();j++){
                if(g[i][j]!=' '&&g[i][j]!=chcon)
                    floodFill(i,j, g[i][j]);
            }

        for(i=0;i<=row;i++) cout << g[i] << endl;
        row =0;

    }
	return 0;
}
