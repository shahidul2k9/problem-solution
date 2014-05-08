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
typedef map<char, int> mci;
typedef map<int, string> mis;
typedef map<string, string> mss;
typedef map<string, char> msc;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 500
char g[N][N];
int o[N][N];
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
int cm[N];
int r,c,id;
char ch;
bool isSafe(int y,int x){
    if(y<0||x<0||y>=r ||x>=c)return false;
    return true;
}

void floodFill(int y,int x){
    o[y][x]=id;
    FOR(i,0,7){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(isSafe(ny,nx)&&g[ny][nx]==ch&&o[ny][nx]==0)

        floodFill(ny,nx);
    }

}
int main()
{
    string line;
    string p="%";
    string d ="d";
    //READ("input.txt");
    //WRITE("output.txt");
    char fs[100];
    while(true){
        getline(cin,line);
        if(feof(stdin)||line[0]=='%'){
            id=0;
            FOR(i,0,r-1)
                FOR(j,0,c-1)
                    o[i][j]= 0;

            FOR(i,0,r-1){
                FOR(j,0,c-1){
                    if(o[i][j]==0){
                        id++;
                        ch = g[i][j];
                        floodFill(i,j);
                        }
                }
                }

            memset(cm,0,sizeof(cm));
            FOR(i,0,c-1)
                FOR(j,0,r-1) cm[i] =max(cm[i],o[j][i]);

            FOR(i,0,c-1){
                sprintf(fs,"%d",cm[i]);
                cm[i] = strlen(fs);
            }

            FOR(i,0,r-1){
                FOR(j,0,c-1){
                    sprintf(fs,"%s%d%s",p.c_str(),cm[j],d.c_str());
                    printf(fs,o[i][j]);
                    printf("%c",(j==c-1)?'\n':' ');
                }
                }

        printf("%c%c", '%','\n');
        if(feof(stdin))break;
        r=0;
        }
        else {
            c=0;
            FOR(i,0,line.size()-1){
                if(line[i]!=' ')
                    g[r][c++] = line[i];
            }
        r++;
        }
    }
	return 0;
}
