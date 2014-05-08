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
#define EPS 1e-6
#define inf 1/0.0

double lx[100],ly[100];
inline double dist2d(int a, int b){
    return sqrt( (lx[a] - lx[b])*(lx[a] - lx[b]) + (ly[a] - ly[b])*(ly[a] - ly[b]));
}

int main(){
    //freopen("input.txt", "r", stdin);
    double d[100][100];
    int cs = 1, test, V;
    double ans;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &V);
        for( int i = 0; i < V; i++ )
            scanf("%lf %lf", &lx[i], &ly[i]);

        for( int i = 0; i < V; i++ )
            for( int k = 0; k < V; k++ ){

                if( i == k )d[i][k] = 0.0;
                else d[i][k] = dist2d(i, k);
                if(d[i][k] > 10.0) d[i][k] = inf;
            }
        for( int k = 0; k < V - 1; k++ )
            for( int i = 0; i < V; i++ )
                for( int j = 0; j < V; j++ ){
                    //if(!isinf(d[i][k]) && !isinf(d[k][j]) && d[i][k] + d[k][j] < d[i][j])
                        d[i][j] =min(d[i][j], d[i][k] + d[k][j]);
                }
        ans = 0;
        for( int i = 0; i < V; i++ )
            for(int k = 0; k < V; k++ ){
                ans = max(ans, d[i][k]);
            }
        printf("Case #%d:\n", cs++);
        if(isinf(ans))
            puts("Send Kurdy\n");
        else
            printf("%.4lf\n\n",ans);
    }



    return 0;
}
