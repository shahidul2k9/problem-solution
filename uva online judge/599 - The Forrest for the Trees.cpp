#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
using namespace std;
#define ifor( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define dfor( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )

#define SQR(x) ((x)*(x))
#define INF INT_MAX
#define EPS 1e-9
#define PI (2*acos(0.0))
#define SZ size()

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long ll;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<string, char> msc;
typedef map<char,int> mci;
typedef vector<vector<ii>  > vvii;
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_NODE 27
vi g[MAX_NODE];
int dist[MAX_NODE];
int number,nodes;
void bfs(int src){
    int u,v;
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()){
        number++;
        u = q.front();
        q.pop();
        ifor(i,0,g[u].size()-1){
            v = g[u][i];
            if(dist[v]==INF){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    mci hash;
    int test, st, en,acons,trees;
    string str;
    scanf("%d", &test);
    while(test--){
    ifor(i,1,MAX_NODE-1){
        g[i].clear();
        dist[i] = INF;
        }
    hash.clear();
    nodes  = 0;
    while(cin >> str && str[0]!='*'){
        if(!hash[str[1]]) {
            hash[str[1]] = ++nodes;
            st = nodes;
            }
        else st = hash[str[1]];
        if(!hash[str[3]]){
            hash[str[3]] = ++nodes;
            en = nodes;
            }
        else en = hash[str[3]];
        g[st].push_back(en);
        g[en].push_back(st);

    }
    cin >> str;
    for(int i=0; i<=str.length()-1; i +=2){
        if(!hash[str[i]])
            hash[str[i]] = ++nodes;
    }
    acons = trees = 0;
    ifor(i,1,nodes){
        if(dist[i]==INF){
            number = 0;
            bfs(i);
            if(number==1)acons++;
            else trees++;
            }
    }
    printf("There are %d tree(s) and %d acorn(s).\n", trees,acons);
    }
    return 0;
}
