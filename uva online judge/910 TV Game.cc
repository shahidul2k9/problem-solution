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
#define DIMEN 106
int main(){

     freopen("input.txt", "r", stdin);
     //freopen("output.txt", "w", stdout);

    int q[26][2];
    long long int W[26][31];
    long long int ans;
    bool F[26];
    int N, M;
    int from, to;
    char ch;
    while(scanf("%d", &N) == 1){
        for( int i = 0; i < N; i++ ){
            cin >> ch;
            from = ch - 65;

            cin >> ch;
            to = ch - 65;
            q[from][0] = to;
            cin >> ch;
            to = ch - 65;

            q[ from ][1] = to;
            cin >> ch;
            if(ch == '-') F[from] = false;
            else F[from] = true;

        }
        scanf("%d", &M);
        memset(W, 0, sizeof(W));
        W[0][0] = 1;

        for( int h = 1; h <= M; h++ ){
            for( int p = 0; p < N; p++ ){
                W[ q[p][0] ][h] += W[p][h-1];
                W[ q[p][1] ][h] += W[p][h-1];
            }
        }

        ans = 0;
        for(int i = 0; i < N; i++)
            if(F[i]) ans += W[i][M];
        printf("%lld\n", ans);
    }
    return 0;
}
