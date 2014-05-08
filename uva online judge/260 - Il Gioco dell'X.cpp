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
typedef pair<int,int> ii;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 205
string g[N];
int dw[N][N];
int db[N][N];
int n;
queue<ii>q;

int dy[] ={-1,0,1,-1,0,1};
int dx[] ={-1,-1,0,0,1,1};
inline bool isSafe(int y, int x){
    if(y<=0||x<0||y>=n||x>=n)return false;
    return true;
}
void bbfs(){
    int uy,ux,vy,vx;
    while(!q.empty()){
        uy =q.front().first;
        ux = q.front().second;
        q.pop();
        FOR(i,0,5){
            vy = uy + dy[i];
            vx = ux + dx[i];
            if(isSafe(vy,vx)&&g[vy][vx]=='b'&&db[vy][vx]==INF){
                db[vy][vx] = db[uy][ux] +1;
                q.push(ii(vy,vx));
            }
        }
    }
}

void wbfs(){
    int uy,ux,vy,vx;
    while(!q.empty()){
        uy =q.front().first;
        ux = q.front().second;
        q.pop();
        FOR(i,0,5){
            vy = uy + dy[i];
            vx = ux + dx[i];
            if(isSafe(vy,vx)&&g[vy][vx]=='w'&&dw[vy][vx]==INF){
                dw[vy][vx] = dw[uy][ux] +1;
                q.push(ii(vy,vx));
            }
        }
    }
}
int main()
{
    int bmin,wmin,cs=0;
    READ("input.txt");
    //WRITE("output.txt");
    while(scanf("%d", &n)&&n){
        getline(cin,g[0]);
        FOR(i,0,n-1)
            getline(cin,g[i]);
        FOR(i,0,n-1)
            FOR(j,0,n-1)dw[i][j] = db[i][j] =INF;
        FOR(i,0,n-1)if(g[0][i]=='b'){q.push(ii(0,i));db[0][i]=0;}
        bbfs();

        FOR(i,0,n-1)
            if(g[i][0]=='w'){
                q.push(ii(i,0));dw[i][0] = 0;
            }
        wbfs();
        bmin = wmin = INF;
        FOR(i,0,n-1){
            bmin = min(bmin,db[n-1][i]);
            wmin = min(wmin,dw[i][n-1]);
        }

        printf("%d %c\n", ++cs, bmin<wmin?'B':'W');
    }
	return 0;
}
