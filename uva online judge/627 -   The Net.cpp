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

#define INF 9999999


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
#define NODE 309


vi g[NODE];
mii m, rm;
int d[NODE],pre[NODE];
int nodes;
void bfs(int src){
    queue<int> q;
    int u,v;
    FOR(i,1,nodes)d[i] = pre[i] = INF;
    d[src] = 0;
    q.push(src);
    while(!q.empty()){
        u = q.front();
        q.pop();
        FOR(i,0,g[u].size()-1){
            v = g[u][i];
            if(d[v]>d[u]+1){
                d[v] = d[u] +1;
                pre[v] = u;
                q.push(v);
            }
            else if(d[v]==d[u]+1 && pre[v] > u){
                pre[v] = u;
                q.push(v);
                }
        }
    }
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    vi path;
    int st,en,q;
    string line;
    while(scanf("%d", &nodes)==1){
        FOR(i,1,nodes)g[i].clear();
        getline(cin,line);
        FOR(i,0,nodes-1){
            getline(cin,line);

            FOR(j,0,line.size()-1)if(!isdigit(line[j])) line[j] = ' ';
            stringstream ss;
            ss << line;
            ss >> st;
            while(ss >> en){
                g[st].push_back(en);
                //g[m[en]].push_back(m[st]);
            }
        }

        scanf("%d", &q);
        cout << "-----" << endl;
        FOR(i,1,q){
            scanf("%d %d", &st, &en);
            bfs(st);
            path.clear();
            if(d[en]==INF)printf("connection impossible\n");
            else {
                for(int j = en; j!=st; j = pre[j]){
                    path.push_back(j);
                }
                path.push_back(st);
                FORD(j,path.size()-1,1)cout << path[j] << " ";
                cout << path[0]<< endl;
            }
        }
    }
	return 0;
}
