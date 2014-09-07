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
 
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define SQR(x) ((x)*(x))
#define PI 2*acos(0)
#define EPS 1e-7
#define R 352
#define C 352
#define N 352
int m,n,s,t,nodes;
int r[R][C];
int cost[N];
int pre[N];
void addEdge(int st, int en){
    for(int i=0;i<m;i = i + 6){
        r[st][i+en+n] = 1;
    }
}
bool bfs(){
    queue<int> q;
    int u;
    FOR(i,0,nodes-1)pre[i] = -1;
    cost[s] = INT_MAX;
    pre[s] = s;
    q.push(s);
    while(!q.empty()){
        u = q.front();
        q.pop();
        if(u==t)return true;
        for(int i = 0;i<nodes;i++){
            if(pre[i]==-1&&r[u][i]>0){
                cost[i] = min(cost[u],r[u][i]);
                pre[i] = u;
                q.push(i);
            }
        }
    }
    return false;
}
int main()
{
   // READ("input.txt");
    //WRITE("output.txt");
    int test,cs=1;
    string cho;
    msi h;
    h["XXL"] = 0;
    h["XL"] = 1;
    h["L"] = 2;
    h["M"] = 3;
    h["S"] = 4;
    h["XS"] = 5;
    scanf("%d",&test);
    while(test--){
        scanf("%d %d",&m,&n);
        m = m*6;
        memset(r,0,sizeof r);
        FOR(i,0,n-1){
            cin>>cho;
            addEdge(i,h[cho]);
            cin>>cho;
            addEdge(i,h[cho]);
        }
 
        s = m + n;
        t = m + n + 1;
        FOR(i,0,n-1)r[s][i] = 1;
        FOR(i,n,m+n-1)r[i][t] = true;
        nodes = m + n + 2;
        int maxflow = 0;
        while(bfs()){
            maxflow +=cost[t];
            int u = t;
 
            while(u!=pre[u]){
                r[pre[u]][u] -=cost[t];
                r[u][pre[u]] +=cost[t];
                u = pre[u];
            }
        }
        printf("Case %d: ",cs++);
        if(maxflow==n)
            puts("YES");
        else puts("NO");
 
    }
    return 0;
}