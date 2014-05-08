#include <algorithm>
#include <bitset>

#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

vector < vector < int > > g;

int C, L, S, E, M, D;
int memo[101][201];
int solve(int n, int k){
    if(memo[n][k] != -1) return memo[n][k];
    if(k == 0){
        if( n == E) return 1;

        return 0;
    }
    for(int i = 0; i < (int)g[n].size(); i++)
        if( solve(g[n][i], k - 1) == 1 ) return memo[n][k] = 1;

    return memo[n][k] = 0;
}
int main(){


     //freopen("input.txt", "r", stdin);
     //freopen("output.txt", "w", stdout);
     int from, to;
     while(scanf("%d %d", &C, &L) == 2 && (C || L)){
         g = vector < vector< int > > (C + 1, vector<int>(0));

         for(int i = 0; i < L ; i++ ){
             scanf("%d %d", &from , &to);
             g[from].push_back(to);
             g[to].push_back(from);
         }
         memset(memo, -1, sizeof(memo));
         scanf("%d %d %d", &S, &E, &D);
         if(solve(S, D)) puts("Yes, Teobaldo can travel.");
         else puts("No, Teobaldo can not travel.");
     }

    return 0;
}
