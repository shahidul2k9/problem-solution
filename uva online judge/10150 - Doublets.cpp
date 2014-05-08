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

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_NODE 25145
string name;
int nodes;
int dist[MAX_NODE];
bool color[MAX_NODE];
int pre[MAX_NODE];
int u,v;
MIS rev;
MSI dic;
void bfs(int src){
    map<int,string> ::iterator revEnd = rev.end();
    string ustr,vstr;
    queue<int> q;
    FOR(i,1,nodes){
        dist[i] = INF;
        color[i] = false;
        pre[i] = i;
        }
    dist[src] = 0;
    color[src] = true;
    q.push(src);

    while(!q.empty()){
        u = q.front();
        ustr = rev[u];
        q.pop();
        FOR(i,0,ustr.length()-1){
            FOR(j,'a','z'){
                if(ustr[i]==j)continue;
                vstr= ustr;
                vstr[i] = j;
                v =  dic[vstr];
                if(color[v]==false&&rev.find(v)!=revEnd){
                    color[v] = true;
                    dist[v] = dist[u] + 1;
                    pre[v] = u;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
   //READ("input.txt");
    //WRITE("output.txt");
    map<string,int> ::iterator it;


    string str;
    string st,en;
    bool letBlank = false;
    while(getline(cin,name)){
        if(name!=""){
            if(!dic[name]){
                dic[name] = ++nodes;
                rev[nodes] = name;
            }
        }
        else while(cin >> st >> en){
            if(letBlank) printf("\n");
            letBlank = true;
            bfs(dic[st]);
            if(dist[dic[en]]==INF)printf("No solution.\n");
            else {
                VI path;
                int u,v;
                v = dic[en];
                u = dic[st];
                while(v!=u){
                    path.push_back(v);
                    v = pre[v];
                }
                path.push_back(u);
                FORD(i,path.size()-1,0) cout << rev[path[i]] << endl;
            }
        }
    }
  return 0;
}
