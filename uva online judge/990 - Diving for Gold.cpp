#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;
vector< int > ans;
int N, W;
int wt[31];
int val[31];
int C[31][1009];
int BringMe(){
    for(int i = 0; i<= N; i++)C[i][0] = 0;
    for(int i = 0; i<= W; i++)C[0][i] = 0;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <=W; j++){
            if(wt[i] <= j) C[i][j] = max(C[i-1][j], val[i] + C[i-1][j - wt[i]]);
            else C[i][j] = C[i-1][j];
        }
    return C[N][W];
}

void traceBack(int i, int j){
    if(i ==0 || j == 0)return;
    if(wt[i] <= j && C[i][j] == val[i] + C[i-1][j - wt[i]]) {
        ans.push_back(i);
        traceBack(i-1, j - wt[i]);
    }
    else traceBack(i-1, j);
}
int main()
{
    freopen("input.txt", "r", stdin);
    int w;
    bool blank = false;
    while(scanf("%d %d", &W, &w) == 2){
        scanf("%d", &N);
        for(int i = 1; i <= N; i++){
            scanf("%d %d", &wt[i], &val[i]);
            wt[i] *= 3*w;
        }
        if(blank) puts("");
        blank = true;
        printf("%d\n", BringMe());
        ans.clear();
        traceBack(N, W);
        printf("%d\n", ans.size());
        for(int i = ans.size()-1; i >= 0; i--)printf("%d %d\n", wt[ans[i]]/(3*w), val[ans[i]]);

    }
    return 0;
}
