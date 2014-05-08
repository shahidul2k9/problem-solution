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
#define N 26
int d[N];
int weight[N];

vi g[N];
int total;
inline int toNOde(char ch){
    return ch - 'A';
}
void dfs(int u){
    int v;
    FOR(i,0,g[u].size()-1){
        v = g[u][i];
        if(weight[v]+d[u]>d[v]){
        d[v] = d[u] + weight[v];
        total = max(total,d[v]);
        }
        dfs(v);
    }
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int test;
    string str;
    stringstream ss;
    char ch;
    int w,st;
    scanf("%d",&test);
    getline(cin,str);
    getline(cin,str);
    while(test--){
    memset(weight,-1,sizeof weight);
    FOR(i,0,N-1)g[i].clear();
    while(getline(cin,str)&&str.length()!=0){
        ss.clear();
        ss << str;
        ss>>ch;
        ss >> w;
        st = toNOde(ch);
        weight[st] = w;
        while(ss>>ch)
            g[st].push_back(toNOde(ch));
    }
    int ans = 0;
    FOR(i,0,N-1){
        if(weight[i]!=-1){
            memset(d,0,sizeof d);
            d[i] = weight[i];
            total = 0;
            dfs(i);
            ans = max(total,ans);
        }
    }
    printf("%d\n",ans);
    if(test)puts("");
    }
	return 0;
}
