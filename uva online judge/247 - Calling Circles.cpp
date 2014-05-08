#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>		// For memset function
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <map>

using namespace std;

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))

#define INF 99999999
#define SZ size()
#define PB push_back
#define PF push_front

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef map<int, string> MIS;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int NODE, EDGE;
VVI G;
VI color, dfsNum, dfsLow;
int nodeNum;
stack<int> S;
VI inStack;
MSI names;
MIS rnames;
void strongConnect(int u);
void Tarjan()
{
    nodeNum = 0;
    FOR(u, 1, NODE) {
        if(color[u] == WHITE)
            strongConnect(u);
    }
}

void strongConnect(int u)
{
    dfsNum[u] = dfsLow[u] = nodeNum++;
    color[u] = GRAY;
    S.push(u);  inStack[u] = true;

    FOR(i, 0, G[u].SZ-1) {
        int v = G[u][i];
        if(color[v] == WHITE) {
            strongConnect(v);
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
        }
        else if(inStack[v] == true)
            dfsLow[u] = min(dfsLow[u], dfsNum[v]);
    }

    if(dfsNum[u] == dfsLow[u]) {
        int comma = 0;
        int w = -1;
        while(w != u) {
            w = S.top();    S.pop();    inStack[w] = false;
            if(comma++>0)printf(", ");
            cout << rnames[w];
        }
        cout << "\n";
    }
}

int main()
{
    READ("input.txt");
   // WRITE("output.txt");
    bool blank = false;
    int i, j, k;
    int cs=1;
    int u, v;
    string st,en;
    while(cin >> NODE >> EDGE && NODE!=0 && EDGE!=0) {
        if(blank)printf("\n");
        blank = true;
        names.clear();
        rnames.clear();
        G = VVI(NODE+1);
        color = VI(NODE+1, WHITE);
        dfsNum = VI(NODE+1);
        dfsLow = VI(NODE+1);
        inStack = VI(NODE+1,  false);
        int in =1;
        FOR(i, 1, EDGE) {
            cin >> st >> en;
            if(names[st]==0){
                names[st] = in;
                rnames[in] = st;
                in++;
                }
            if(names[en]==0){
                names[en]= in;
                rnames[in] = en;
                in++;
                }
            G[names[st]].PB(names[en]);
        }
        printf("Calling circles for data set %d:\n", cs++);
        Tarjan();

    }

	return 0;
}
