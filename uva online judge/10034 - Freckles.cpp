#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PQ priority_queue
#define PB push_back
#define SZ size()
#define ff first
#define ss second

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef vector<char> VC;
typedef vector<vector<char> > VVC;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef map<int, string> MIS;
#define MAX_NODE 101
#define MAX_EDGE 50000
#define SQ(x) (x)*(x)
#define EPS 1e-9
int pre[MAX_NODE];
struct Edge{
    int u;
    int v;
    float w;
}edges[MAX_EDGE];
struct Point{
    float x;
    float y;
    Point(float a,float b){
    x = a;
    y = b;
    }
    Point(){}
};
bool comp(Edge a,Edge b){
    return (a.w - b.w)<EPS;
}
int findPre(int u){
    if(pre[u]==u)return u;
    else return pre[u] = findPre(pre[u]);
}

float dist2d(Point a, Point b){
    return sqrt(SQ(a.x-b.x)+SQ(a.y-b.y));
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int test;
    int nodes,numOfEdge;
    float x,y,ans;
    bool blank = false;
    vector<Point> v;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&nodes);
        numOfEdge = nodes*(nodes-1)/2;
        v.clear();
        FOR(i,0,nodes-1){
            scanf("%f %f",&x,&y);
            v.push_back(Point(x,y));
            pre[i] = i;
        }
        int ind = 0;
        FOR(i,0,nodes-2)
            FOR(j,i+1,nodes-1){
                edges[ind].u = i;
                edges[ind].v = j;
                edges[ind].w = dist2d(v[i],v[j]);
                ind++;
            }

       sort(edges,edges+numOfEdge,comp);
       ans = 0;
       FOR(i,0,numOfEdge-1){
           int preu = findPre(edges[i].u);
           int prev = findPre(edges[i].v);
           if(preu!=prev){
               ans += edges[i].w;
               pre[preu] = prev;
           }
       }
       if(blank)printf("\n");
       blank = true;
       printf("%.2f\n",ans);
    }
  return 0;
}
