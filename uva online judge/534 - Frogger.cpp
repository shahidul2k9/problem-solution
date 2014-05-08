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


#define EPS 1e-9
#define MAX_NODES 205
#define MAX_EDGES 20000
struct Point{
    int x;
    int y;
};
struct Edge{
    int st;
    int en;
    double w;
};
Point node[MAX_NODES];
int pre[MAX_NODES];
Edge e[MAX_EDGES];
int nodes,edges;

double dist2d(Point a, Point b){

    return sqrt(SQR(a.x-b.x) + SQR(a.y-b.y));
}
bool comp(Edge e1, Edge e2){
    return e1.w - e2.w < EPS;
}

void resetPre(int n){
    for(int i=0;i<n;i++)pre[i]=i;
}
int findPre(int u){
    if(pre[u]==u)return u;
    else return pre[u]=findPre(pre[u]);
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int i,j,cs=0;
    while(scanf("%d", &nodes)==1&&nodes){
        for(i=0;i<nodes;i++){
            scanf("%d %d", &node[i].x, &node[i].y);
        }
        edges = 0;
        for(i=0;i<nodes;i++)
            for(j=i+1;j<nodes;j++){
                e[edges].st = i;
                e[edges].en = j;
                e[edges].w = dist2d(node[i],node[j]);
                edges++;
            }
        resetPre(nodes);

        double minMax = 0;
        sort(e,e+edges,comp);

        for(i=0;i<edges;i++){
            int stp = findPre(e[i].st);
            int enp = findPre(e[i].en);
             if(findPre(0)==findPre(1))break;
            if(stp!=enp){
                minMax = e[i].w;
                pre[stp] = enp;
            }

        }
        printf("Scenario #%d\n", ++cs);
        printf("Frog Distance = %.3lf\n\n", minMax);

    }

	return 0;
}


