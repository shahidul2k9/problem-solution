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
#include <deque>
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;

int M[11][11];
int nodes, hops;
int A[8];
bool in[11];
bool found;
void down(int n, int h ){
    if( h > hops){
        found = true;
        printf("(");
        for( int i = 0; i < hops; i++ )
            printf("%d,", A[i]);
        printf("%d)\n", A[hops]);
        return;
    }
    for( int i = 1; i <= nodes; i++ ){
        if(M[n][i] && in[i] == false) {
            A[h] = i;
            in[i] = true;
            down(i, h+1);
            in[i] = false;
            }
    }
}

int main(){

    //freopen("input.txt", "r", stdin);
    int garbage;
    bool blank = false;
    while(scanf("%d %d", &nodes, &hops) == 2){
        if(blank)puts("");
        blank = true;
        for( int i = 1; i <= nodes; i++ )
            for( int j = 1; j <= nodes; j++ )
                scanf("%d", &M[i][j]);

    memset(in, false, sizeof(in));
    found = false;
        A[0] = 1;
        in[1] = true;
        down(1, 1);
        in[1] = false;
    if( !found ) printf("no walk of length %d\n", hops);
    scanf("%d", &garbage);
    }
    return 0;
}

