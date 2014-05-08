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
#define INF 9999999



int main(){
   //freopen("input.txt", "r", stdin);
   long long int  d[101][101], t[101][101];
    int V, E, test, Q, st, en;
   long long  int dist,  ti;
   scanf("%d", &test);
   while( test-- ){
       scanf("%d %d", &V, &E);
       memset(d, -1, sizeof(d));
       memset(t, -1, sizeof(t));
       for(int i = 1; i <= V; i++ )
            d[i][i] = t[i][i] = 0;
       for(int i = 1; i <= E; i++ ){
           scanf("%d %d %lld %lld", &st, &en, &ti, &dist);
           if(d[st][en] == -1 || t[st][en] > ti || (t[st][en] == ti && d[st][en] > dist)){
                d[st][en] = d[en][st] = dist;
                t[st][en] = t[en][st] = ti;
           }

       }

       for( int k = 1; k < V; k++ )
            for(int i = 1; i <= V; i++ )
                for(int j = 1; j <= V; j++){
                    if(t[i][k] != -1 && t[k][j] != -1){
                        if(t[i][j] == -1 || t[i][k] + t[k][j] <= t[i][j]){
                           if(t[i][k] + t[k][j] == t[i][j] && d[i][k] + d[k][j] < d[i][j]){
                               t[i][j] = t[i][k] + t[k][j];
                               d[i][j] = d[i][k] + d[k][j];
                           }
                           else if(t[i][k] + t[k][j] != t[i][j]) {
                               t[i][j] = t[i][k] + t[k][j];
                               d[i][j] = d[i][k] + d[k][j];
                           }

                        }
                    }
                }
    scanf("%d", &Q);
    while( Q-- ){
        scanf("%d %d", &st, &en);
        if(d[st][en] != -1)
        printf("Distance and time to reach destination is %lld & %lld.\n", d[st][en], t[st][en]);
        else printf("No Path.\n");
    }
    if(test) puts("");
   }

    return 0;
}
