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

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))

#define INF INT_MAX



int main(){
    freopen("input.txt", "r", stdin);
    int N, M, K, from, to;
    bool adj[50][50];
    bool A[50][20];
    while(scanf("%d %d %d", &N, &M, &K) == 3&& N){

        memset(adj, false, sizeof(adj));
        for( int i = 0; i < M; i++){
            scanf("%d %d", &from, &to);
            adj[from][to] = true;
        }
        A[0][0] = true;
        for(int i = 1; i < N; i++ ) A[i][0] = false;

        for( int h = 1; h < 20; h++ ){
            for( int i = 0; i < N; i++ ){
                A[i][h] = false;
                for( int pre = 0; pre < N; pre++ ){
                    if(pre == i) continue;
                    if(A[pre][h-1] && adj[pre][i]){
                        A[i][h] = true;
                        break;
                    }
                }
            }
        }

        int k;
        for(k = K - 1; k < 20; k++ ){
            if(A[N-1][k])break;
        }
        if(k < 20) printf("%d\n", k+1);
        else printf("LOSER\n");

    }
	return 0;
}
