#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>


using namespace std;
#define MAX 30
#define WHITE -1
#define GRAY 1
#define BLACK 2
vector<int> g[MAX];
vector<int> ans;
int B[MAX][10];
vector <int> S;
int color[MAX];
int len[MAX];
int pre[MAX];
int NB, ND;
int sz, st, en;
bool isNested(int x, int y){
    for(int i = 0; i < ND; i++)
        if(B[x][i] >= B[y][i])
            return false;

        return true;
}


void topSort(int from){
    color[from] = GRAY;
    int to;
    for(int i = 0; i < g[from].size(); i++){
        to = g[from][i];
        if(color[to] == WHITE)
            topSort(to);
    }
    color[from] = BLACK;
    S.push_back(from);
}
void dfs(int from){
    for(int i = 0; i < g[from].size(); i++){
        int to = g[from][i];
        if(len[to] < len[from] + 1){
            len[to] = len[from] + 1;
            pre[to] = from;
            dfs(to);
        }
    }

}

void backtrack(int ind){
    ans.push_back(ind);
    if(pre[ind] != -1)
        backtrack(pre[ind]);
}
void printAdj(){

    for(int i = 0; i < NB; i++){
        for(int j = 0; j < g[i].size(); j++)
            printf("%d ", g[i][j]);
        puts("");
    }
}
int main()
{
    freopen("input.txt", "r", stdin);

    while(scanf("%d %d", &NB, &ND) == 2){

        for(int i = 0; i < NB; i++)
            for(int j = 0; j < ND; j++)
                scanf("%d", &B[i][j]);



    for(int i = 0; i < NB; i++){
        sort(B[i], B[i]+ND);
        g[i].clear();
    }

    for(int i = 0; i < NB; i++)
        for(int j = 0 ; j < NB; j++){
            if(isNested(i, j))
                g[i].push_back(j);
        }

   // printAdj();

    memset(color, WHITE, sizeof color);

    S.clear();

    for(int i = 0; i < NB; i++)
        if(color[i] == WHITE)
            topSort(i);
    reverse(S.begin(), S.end());

   // for(int i = 0; i < S.size(); i++)cout << S[i]<<" "; cout << endl;



    memset(len, WHITE, sizeof len);
    memset(pre, WHITE, sizeof pre);
    for(int i = 0; i < NB; i++){
        if(len[S[i]] == -1){
            len[S[i]] = 1;
            dfs(S[i]);

        }
    }

    int ansInd;
    int sz = 0;
    for(int i = 0; i< NB; i++){
        if(len[i] > sz ){
            ansInd = i;
            sz = len[i];
        }
    }
    ans.clear();
    backtrack(ansInd);
    printf("%d\n", sz);
    for(int i = ans.size()-1; i >= 0; i--)
        printf("%d%c", ans[i] + 1, (i == 0)?'\n':' ');

    }

    return 0;

}
