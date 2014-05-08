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
   freopen("input.txt", "r", stdin);
   int M[101][101];
   int d[101][101];
    int BH, P, R, OF, YH, MA;
   int st, en, wt;
   bitset < 101 > cant;
    while(scanf("%d %d %d %d %d %d", &P, &R, &BH, &OF, &YH, &MA) == 6){
        for(int i = 1; i <= P; i++)
            for(int j = 1; j <= P; j++){
                M[i][j] =  d[i][j] = INF;
                M[j][j] =  d[j][j] = 0;

            }

        for(int i = 1; i <= R; i++){
            scanf("%d %d %d", &st, &en, &wt);
            d[st][en] = d[en][st] = M[st][en] = M[en][st]= wt;
        }
        for( int k = 1; k <= P; k++ )
            for( int i = 1; i<= P; i++ )
                for( int j = 1; j <= P; j++ )
                    if(M[i][k] + M[k][j] < M[i][j])
                        M[i][j] = M[i][k] + M[k][j];


    cant.reset();
    for(int inter = 1; inter <= P; inter++ )
        if(M[BH][OF] == M[BH][inter] + M[inter][OF]){
            cant.set(inter);
            d[inter][inter] = INF;
           // cout << inter << " ";
        }
        //puts("");


    for(int k = 1; k <= P; k++ ){
        if(cant.test(k))continue;
        for(int i = 1; i <= P; i++ ){
            if(cant.test(i))continue;
            for(int j = 1; j <= P; j++ ){
                if(cant.test(j))continue;
                if(d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    if(d[YH][MA] == INF || cant.test(YH) || cant.test(MA))
    puts("MISSION IMPOSSIBLE.");
    else printf("%d\n", d[YH][MA]);

    }

    return 0;
}
