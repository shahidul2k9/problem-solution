#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;
typedef vector < int > vi;

#define MAX 100
#define WHITE -1
#define GRAY 1
#define BLACK 2

vi g[10000];
int dx[] = {1,  0, -1, 0};
int dy[] = {0,  1, 0, -1};
int M[MAX][MAX];
int P[MAX][MAX];
int S[MAX*MAX];
int len[MAX*MAX];
int color[MAX*MAX];
int R, C, N, top;
bool isAdjacent(int w, int x, int y, int z){
    if(y >= R || y < 0 || z >= C || z < 0)return false;
    if(M[w][x] <= M[y][z]) return false;
    return true;
}
void setPoints(){
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            P[i][j] = i * C + j;
}

void topsort(int from){
    int to;
    color[from] = GRAY;
    for(int i = 0; i < g[from].size(); i++){
        to = g[from][i];
        if(color[to] == WHITE)
            topsort(to);
    }
    S[--top] = from;
}

void longestPath(int from){
    int to;
    for(int i = 0; i < g[from].size(); i++){
        to = g[from][i];
        if(len[to] < len[from] + 1){
            len[to] = len[from] + 1;
            longestPath(to);
        }
    }
}
void printAdj(){
    for(int i = 0; i < N; i++){
        printf("%d->", i);
        for(int j = 0; j < g[i].size(); j++)
            printf("%d ", g[i][j]);
        puts("");
    }

}
int main()
{
    freopen("input.txt", "r", stdin);
    int test;
    string name;
    scanf("%d", &test);
    while(test--){
        cin >> name >> R >> C;
        setPoints();
        N = R * C;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                scanf("%d", &M[i][j]);

        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                for(int k = 0; k < 4; k++)
                    if(isAdjacent(i, j, i + dy[k], j + dx[k]))
                        g[P[i][j]].push_back(P[i + dy[k]][j + dx[k]]);
    //printAdj();

    memset(color , WHITE, sizeof color);
    top = N;

    for(int i = 0; i < N; i++)
        if(color[i] == WHITE) topsort(i);

    memset(len, WHITE, sizeof len);
    for(int i = 0; i < N; i++)
        if(len[S[i]] == -1){
            len[S[i]] = 1;
            longestPath(S[i]);
        }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans = max(ans, len[i]);
        g[i].clear();
        }
    printf("%s: %d\n", name.c_str(), ans);
    }

    return 0;
}
