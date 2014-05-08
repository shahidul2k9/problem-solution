#include <string.h>
#include <cstdio>
#include <climits>
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
vector < int > g[6];
char E[11];
bool adj[6][6];
void bkt( int node , int pos ){
    if(pos == 9){
        puts(E);
        return;
    }
    for(int k = 0; k < (int)g[node].size(); k++ ){
        int to = g[node][k];
        if( !adj[node][to] ){
            adj[node][to] = adj[to][node] = true;
            E[pos] = to + '0';
            bkt(to, pos + 1);
            adj[node][to] = adj[to][node] = false;
        }
    }
}
int main(){
   // freopen("input.txt", "r", stdin);
   g[1].push_back(2);
   g[1].push_back(5);
   g[1].push_back(3);

   g[2].push_back(1);
   g[2].push_back(3);
   g[2].push_back(5);

   g[3].push_back(2);
   g[3].push_back(1);
   g[3].push_back(4);
   g[3].push_back(5);

   g[4].push_back(3);
   g[4].push_back(5);

   g[5].push_back(1);
   g[5].push_back(2);
   g[5].push_back(3);
   g[5].push_back(4);
   for( int k = 1; k <= 5; k++ )sort(g[k].begin(), g[k].end());
   memset(adj, false, sizeof(adj));
   E[9] = NULL;

       E[0] = '1';
       bkt(1, 1);


	return 0;
}
