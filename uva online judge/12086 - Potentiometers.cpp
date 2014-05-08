#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <climits>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;
#define MAX 200000+1
const int MAX_SEG = 524288;
int ts[MAX_SEG];
int A[MAX];
int N;

int queryts( int node, int b, int e, int i, int j ){
    if(b >= i && e <= j) return ts[node];

    if ( b > j || e < i ) return 0;

    int mid = (b + e)/2;
    return queryts( node << 1, b, mid, i, j ) + queryts ( (node << 1) + 1, mid + 1, e, i, j );
}





int buildts( int node, int b, int e ){
    if ( b == e )
        return    ts[node] =  A[b];


    int mid = (b + e)/2;
    int x = buildts( (node << 1), b, mid);
    int y = buildts( (node << 1) + 1, mid + 1, e);
    return ts[node] = x + y;
}

void update(int node, int b, int e, int ind, int nval){
    if( ind < b || ind > e) return;

    if(b == e) ts[node] = nval;
    else{
        update(node << 1, b, (b + e)/2,  ind,  nval);
        update((node << 1) + 1, (b + e)/2 + 1, e,  ind, nval);
        ts[node] = ts[node << 1] + ts[(node << 1) + 1];

    }

}

int main(){
    string cmd;
    int ts = 0;
    freopen("input.txt", "r", stdin);

    while(scanf("%d", &N) == 1 && N){

        for ( int i = 1; i <= N; i++ )
            scanf("%d", &A[i]);

       buildts(1, 1, N);

        int i, j;
        if(ts)puts("");
        printf("Case %d:\n", ++ts);
        while(cin >> cmd && cmd !="END"){
            scanf("%d %d", &i, &j);
            if(cmd == "M"){
            if(i > j) swap(i, j);
            printf("%d\n", queryts(1, 1, N, i , j ));
            }
            else update(1, 1, N, i, j);
        }

    }
}
