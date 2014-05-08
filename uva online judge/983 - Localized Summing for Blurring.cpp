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

#define DIM 1005
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int MS[DIM][DIM];
    int N, M, AN, hold;
    long long int ans;
    bool blank = false;
    while(scanf("%d %d", &N, &M)== 2){

        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                scanf("%d", &MS[i][j]);


        for(int i = 0; i <= N; i++)
            MS[i][0] = MS[0][i] = 0;

        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                MS[i][j] = MS[i-1][j] + MS[i][j-1] - MS[i-1][j-1] + MS[i][j];

        AN = N - M + 1;


    if(blank) puts("");
        blank = true;
    ans = 0;
    for(int i = 1; i <= AN; i++)
        for(int j = 1; j <= AN; j++){
            hold = MS[i+M-1][j+M-1] - MS[i-1][j+M-1] - MS[i+M-1][j-1] + MS[i-1][j-1];
            printf("%d\n", hold);
            ans += (long long int )hold;
        }
    printf("%lld\n", ans);
    }
	return 0;
}
