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
#include <climits>
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
 
#define N   12
struct Point{
    int x;
    int y;
};
Point a,last;
string g[N];
int dist[N][N],n,pre,ld;
int maxValue;
int dx[] = {1,-1, 0, 0 };
int dy[] = {0,0,  1,-1 };
bool isSafe(Point v){
    if(v.y>=n||v.x>=n||v.y<0||v.x<0)return false;
    return true;
}
void bfs(Point src){
    queue<Point> q;
    Point u,v;
    dist[src.y][src.x] = 0;
    g[src.y][src.x] = '.';
    q.push(src);
    ld = 0;
    while(!q.empty()){
        if(pre==maxValue)return;
        u = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            v.y  = u.y + dy[i];
            v.x  = u.x + dx[i];
    bool safe = isSafe(v);
    if(safe){
            if(pre+1==g[v.y][v.x]){
                pre= g[v.y][v.x];
                ld = dist[v.y][v.x]=dist[u.y][u.x]+1;
                g[v.y][v.x]= '.';
 
                while(!q.empty())q.pop();
 
                q.push(v);
                break;
 
            }
            else if(g[v.y][v.x]=='.'&&dist[v.y][v.x]<=ld){
                dist[v.y][v.x]=dist[u.y][u.x]+1;
                q.push(v);
            }
 
            }
        }
 
    }
 
}
 
 
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int test,cs=0;
    int i,j;
    scanf("%d", &test);
 
    while(test--){
        scanf("%d", &n);
        for(i=0;i<n;i++)
            cin>>g[i];
 
        maxValue =0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                dist[i][j] = INT_MIN;
                if(g[i][j]=='A'){a.x=j;a.y=i;}
                if(maxValue<g[i][j]){last.y=i;last.x=j;maxValue=g[i][j];}
            }
 
        pre = 'A';
        bfs(a);
 
        printf("Case %d: ",++cs);
        if(pre==maxValue)printf("%d\n", dist[last.y][last.x]);
        else printf("Impossible\n");
 
    }
 
    return 0;
}