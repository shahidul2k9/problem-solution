

#include <string.h>
#include <cstdio>
#include <climits>
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
typedef unsigned int u32;
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

typedef pair <int, int > pii;
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define SQR(x) ((x)*(x))
#define PI 2*acos(0)
#define EPS 1e-7
#define MAX 10009
vector<pii> g[MAX];

int dist[MAX];
int start, maxDistID;
void dfs(int from){
    int to;
    for(int i = 0; i < g[from].size(); i++){
        to = g[from][i].first;
        if(dist[to] == -1){
            dist[to] = dist[from] + g[from][i].second;
            if(dist[maxDistID] < dist[to])
                maxDistID = to;
            dfs(to);
        }
    }

}
void process(){
    memset(dist, -1, (start+1)*sizeof(int));
    dist[start] = 0;
    maxDistID = start;
    dfs(start);

    memset(dist,-1, (start+1)*sizeof(int));
    dist[maxDistID] = 0;
    maxDistID = maxDistID;
    dfs(maxDistID);

    printf("%d\n", dist[maxDistID]);

    for(int i = 1; i <= start; i++)
        g[i].clear();

    start = 0;

}
int main(){

    //freopen("input.txt", "r", stdin);
    stringstream ss;
    string line;
    int st, en, wt;
    start = 0;
    bool processed = false;

    while(getline(cin, line)){
        if(line.size() == 0){
            process();
            processed = true;
            }
        else {
            ss.clear();
            ss << line;
            ss >> st >> en >> wt;
            start = max(st, max(en, start));
            g[st].push_back(pii(en, wt));
            g[en].push_back(pii(st, wt));
            processed = false;
        }
    }
    if(processed == false) process();



	return 0;
}
