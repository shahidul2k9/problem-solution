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
typedef vector<vector<ii>  > vvii;
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_NODE 1001
vvi g;
int color[MAX_NODE];
int dfsLow[MAX_NODE];
int dfsNum[MAX_NODE];
int nodes,edges,t;
bool inStack[MAX_NODE];
stack<int> stc;
int u,v,trustGrup;
void stcComponent(int u){

    dfsNum[u] = dfsLow[u] = t++;
    color[u] = GRAY;
    stc.push(u);  inStack[u] = true;

    ifor(i, 0, g[u].SZ-1) {
        int v = g[u][i];
        if(color[v] == WHITE) {
            stcComponent(v);
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
        }
        else if(inStack[v] == true)
            dfsLow[u] = min(dfsLow[u], dfsNum[v]);
    }

    if(dfsNum[u] == dfsLow[u]) {
        int w = -1;
        trustGrup++;
        while(w != u) {
            w = stc.top();    stc.pop();    inStack[w] = false;
        }
    }
}
void Tarjan(){
    t = trustGrup = 0;
    ifor(i,1,nodes){
        color[i] = WHITE;
        inStack[i]=false;
        dfsLow[i] = dfsNum[i] = INF;
    }
    ifor(i,1,nodes){
        if(color[i]==WHITE){
            stcComponent(i);
        }
    }
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    string st, en, str;
    msi people;
    while(scanf("%d %d", &nodes, &edges)&&nodes!=0){
        g = vvi(nodes+1);
        getline(cin,str);
        people.clear();
        ifor(i,1,nodes){
            getline(cin,str);
            people[str] = i;
        }
        ifor(i,1,edges){
            getline(cin,st);
            getline(cin,en);
            g[people[st]].push_back(people[en]);
        }
        Tarjan();
        printf("%d\n", trustGrup);
    }
    return 0;
}
