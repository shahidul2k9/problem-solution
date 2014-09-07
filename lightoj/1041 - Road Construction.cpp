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

#define MAX_NODES  110
int pre[MAX_NODES];
msi hash;
struct Edge {
    int st;
    int en;
    int w;
} g[100];
bool comp(Edge a, Edge b) {
    return a.w<b.w;
}
int findPre(int u) {
    if(pre[u]==u)return u;
    else return pre[u]= findPre(pre[u]);
}
int main() {
    //READ("input.txt");
    //WRITE("output.txt");
    int test, cs=0, st, en, index, edges, sum, takenEdges, i, w, stp, enp;
    string sst, sen;
    scanf("%d", &test);
    while(test--) {
        scanf("%d", &edges);
        hash.clear();
        index = 0;
        for(i=0; i<edges; i++) {
            cin >> sst >> sen >> w;
            if(!hash[sst]) {
                hash[sst] = ++index;
            }
            if(!hash[sen]) {
                hash[sen]  = ++index;
            }
            st = hash[sst];
            en = hash[sen];
            g[i].st  = st;
            g[i].en = en;
            g[i].w = w;
        }
        sort(g,g+edges, comp);
        sum = takenEdges=0;
        for(i=1; i<=index; i++)pre[i]=i;
        for(i=0; i<edges; i++) {
            stp = findPre(g[i].st);
            enp = findPre(g[i].en);
            if(stp!=enp) {
                sum += g[i].w;
                pre[stp] = enp;
                takenEdges++;
            }
        }
        printf("Case %d: ", ++cs);
        if(takenEdges==index-1)
            printf("%d\n", sum);
        else printf("Impossible\n");
    }
    return 0;
}
