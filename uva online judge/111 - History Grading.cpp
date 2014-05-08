#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
int t[21], s[21], lcs[21][21];
int LCS(int i, int j){
    if(i == 0 || j == 0) return 0;
    if(lcs[i][j] != -1)return lcs[i][j];
    if(s[i] == t[j]) return lcs[i][j] = 1 + LCS(i-1, j-1);
    int x = LCS(i-1, j);
    int y = LCS(i, j-1);
    return lcs[i][j] = max(x, y);

}
int main()
{
    freopen("input.txt", "r", stdin);

    int N, item;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++) {
        scanf("%d", &item);
        s[item] = i;
        }
    while(scanf("%d", &item) == 1){
        t[item] = 1;
        for(int i = 2; i <= N; i++ ) {
            scanf("%d", &item);
            t[item] = i;
        }
        memset(lcs, -1, sizeof lcs);
       printf("%d\n", LCS(N, N));
    }
    return 0;
}
