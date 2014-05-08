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
#define sqr(x) (x)*(x)
#define N 8
int n;
int x[N], y[N], ans[N], track[N];
double mindist;
double dist[N][N];
bool vis[N];
void tsp(int level, double cur){
    if(level == n){
        if(mindist >cur) {
            mindist = cur;
            memcpy(ans, track, sizeof ans);
        }
        return;
    }
    FOR(i,0,n-1){
        if(!vis[i]) {
            track[level] = i;
            vis[i] = true;
            tsp(level+1, cur + dist[i][track[level-1]]);
            vis[i] = false;
        }
    }
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int cs = 1;
    while(scanf("%d", &n)==1 && n){
        FOR(i,0,n-1) {
            scanf("%d %d", &x[i], &y[i]);
            vis[i] = false;
            }
        FOR(i,0,n-1)
            FOR(j,0,n-1) dist[i][j] = sqrt(sqr(x[i]-x[j]) + sqr(y[i] - y[j])) + 16;
        mindist = 488888484;
        FOR(i,0,n-1){
        vis[i] = true;
        track[0] = i;
        tsp(1, 0);
        vis[i] = false;
        }
        puts("**********************************************************");
        printf("Network #%d\n", cs++);
        FOR(i,0,n-2){
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", x[ans[i]], y[ans[i]], x[ans[i+1]], y[ans[i+1]], dist[ans[i]][ans[i+1]]);
        }
        printf("Number of feet of cable required is %.2lf.\n", mindist);
    }
	return 0;
}
