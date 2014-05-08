#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
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

#define N 100
int g[N][N];
int M[N][N];

int n,k;

int move(int r, int c){
    if(M[r][c] != -1) return M[r][c];
    int ans = 0;
    int Rlo, Rhi;
    int Clo, Chi;

    Rlo = max(0, r - k);
    Rhi = min(n-1, r +k);
    Clo = max(0, c - k);
    Chi = min(n-1, c + k);

    for(int i = Rlo; i <= Rhi; i++){
        if(g[r][c] < g[i][c])
            ans = max(ans, move(i, c));
    }

    for(int i = Clo; i <= Chi; i++){
        if(g[r][c] < g[r][i])
        ans = max(ans, move(r, i));
    }
    return M[r][c] = ans + g[r][c];
}

int main(){
    //freopen("input.txt", "r", stdin);
    int test;
    scanf("%d",&test);
    while(test--){
        scanf("%d %d",&n,&k);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d",&g[i][j]);
        memset(M, -1, sizeof(M));

        printf("%d\n",move(0, 0));
        if(test)puts("");
    }
	return 0;
}
