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

#define MAX_OUTPOS 600
#define MAX_EDGES 179700
struct Point{
    int x;
    int y;
};
struct Edge{
    int st;
    int en;
    double w;
};
Point outpost[MAX_OUTPOS];
int pre[MAX_OUTPOS];
Edge e[MAX_EDGES];
double dist(Point a, Point b){
    double x1x2 = a.x-b.x;
    double y1y2 = b.y - a.y;
    return sqrt(abs(x1x2*x1x2) + abs(y1y2*y1y2));
}
bool comp(Edge e1, Edge e2){
    return e1.w - e2.w < 1e-9;
}
int nodes,edges;
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
    int i,j,k,test,sat;

    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &sat, &nodes);
        for(i=0;i<nodes;i++){
            scanf("%d %d", &outpost[i].x, &outpost[i].y);
        }
        k = 0;
        for(i=0;i<nodes;i++)
            for(j=i+1;j<nodes;j++){
                e[k].st = i;
                e[k].en = j;
                e[k].w = dist(outpost[i],outpost[j]);
                k++;
            }
        resetPre(nodes);
        int cc = nodes;

        sort(e,e+k,comp);
        double d=0;
        for(i=0;i<k&&cc!=sat;i++){
            int stp = findPre(e[i].st);
            int enp = findPre(e[i].en);
            if(stp!=enp){
                d=e[i].w;
                pre[stp] = enp;
                cc--;
            }
        }

        printf("%.2lf\n", d);
    }

	return 0;
}

