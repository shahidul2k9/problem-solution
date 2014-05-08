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
#define MAX_NODE 210
VVI g;
string name;
int nodes;
int dist[MAX_NODE];
bool color[MAX_NODE];
bool isAdjacent(string str){
    int len = str.length();
    if(len!=name.length())return false;
    int co = 0;
    FOR(i,0,len-1) if(str[i]!=name[i]) co++;
    return (co==1);
}
void bfs(int src){
    queue<int> q;
    int u,v;
    FOR(i,1,nodes){
        dist[i] = INF;
        color[i] = false;
        }
    dist[src] = 0;
    color[src] = true;
    q.push(src);

    while(!q.empty()){
        u = q.front();
        q.pop();
        FOR(i,0,g[u].size()-1){
            v = g[u][i];
            if(color[v]==false){
                color[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
int main()
{
   READ("input.txt");
    //WRITE("output.txt");
    map<string,int> ::iterator it;
    map<string,int> ::iterator ptr;
    int test;
    scanf("%d", &test);
    string str;
    string st,en;
    bool letBlank = false;

    while(test--){
    if(letBlank)printf("\n");
    letBlank = true;
    MSI dic;
    nodes = 0;
        while(cin>> name&&name[0]!='*'){
                if(!dic[name])
                    dic[name] = ++nodes;
        }
        g = VVI(nodes+1);
            for(it = dic.begin();it!=dic.end();it++){
                name = it->first;
                ptr = it;
                ptr++;
                for(; ptr!=dic.end();ptr++){
                    str = ptr->first;
                if(isAdjacent(str)){
                    g[dic[str]].push_back(dic[name]);
                    g[dic[name]].push_back(dic[str]);
                }
                }

            }


        getline(cin,name);
        while(getline(cin,name)&&name!=""){
            stringstream ss;
            ss << name;
            ss >> st;
            ss >> en;
            bfs(dic[st]);
            cout << st << " " << en << " " << dist[dic[en]] << endl;
        }

    }
  return 0;
}
