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

#define WHITE 2
#define UNKNOWN 0
#define BLACK 1
#define N 101
vi g[N];
int n,k,colored;
int color[N],cp[N];
int maxBlack,black;
inline bool isPromising(const int& u){
    int v;
    FOR(i,0,g[u].size()-1){
        v = g[u][i];
        if(v<u&&color[v]==BLACK)return false;
    }
    return true;
}

void graphColor(int u){
   if(u==n+1){
       if(black>maxBlack) {
       maxBlack = black;
       memcpy(cp,color,sizeof(color));
       }
       return;
   }
   color[u] = WHITE;
   graphColor(u+1);

   if(isPromising(u)){
       black++;
       color[u] = BLACK;
       graphColor(u+1);
       black--;
   }
}
int main()
{
    //READ("input.txt");
  //  WRITE("output.txt");
    int test,i,st,en;
    bool one_more;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &n, &k);
        for(i=1;i<=n;i++){
            g[i].clear();
            color[i] = UNKNOWN;
        }
        FOR(i,0,k-1){
            scanf("%d %d", &st, &en);
            g[st].push_back(en);
            g[en].push_back(st);
        }

        maxBlack = black = 0;
        graphColor(1);

        one_more = false;
        printf("%d\n",maxBlack);
        FOR(i,1,n)if(cp[i]==BLACK){
            if(one_more)
                printf(" %d",i);
            else printf("%d",i);
            one_more = true;
        }
        printf("\n");
    }
	return 0;
}
