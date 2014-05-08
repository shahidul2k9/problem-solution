#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
#define MAX 51
#define INF 1 << 30

int C[MAX], M[MAX][MAX];
int L, N;
int minCost(int left, int right){
    if(left + 1 ==right)return 0;
    if(M[left][right] != -1 )return M[left][right];
    int ans = INF;

    for(int i = left + 1; i < right; i++)
         ans = min(ans, minCost(left, i) + minCost(i, right) + C[right]-C[left]);
    return M[left][right] = ans;
}
int main()
{
    freopen("input.txt", "r", stdin);
    while(scanf("%d", &L) == 1 && L){
        scanf("%d", &N);

        for(int i = 1; i <= N; i++)scanf("%d", &C[i]);
        C[0] = 0;
        C[N+1] = L;
        memset(M, -1, sizeof M);
        printf("The minimum cutting is %d.\n", minCost(0, N+1));
    }
    return 0;
}
