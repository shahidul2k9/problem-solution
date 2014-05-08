#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;
#define MAX 200
int M[MAX][MAX];
bool CO[MAX][MAX];
int R, C;
void dag(int fx, int fy){


    for(int i = 1; i <= R; i++)
        for(int j = 1; j <= C; j++)
            if(CO[i][j] == false){
                if(i == 1 && j == 1)M[i][j] = 1;
                else
                M[i][j] = M[i-1][j] + M[i][j-1];
            }
    /*
    int tx, ty;
    tx = fx + 1;
    ty = fy;
    if(tx <= R && !CO[tx][ty]){
        M[tx][ty] += M[fx][fy];
        dag(tx, ty);
    }
    tx = fx;
    ty = fy + 1;
    if(ty <= C && !CO[tx][ty]){
        M[tx][ty] += M[fx][fy];
        dag(tx, ty);
    }
    */
}
void printMatrix(){
    printf("   ");for(int i = 0; i <= C; i++)printf("%d ", i);puts("");
    for(int i = 0; i <= R; i++){
        printf("%d->", i);
        for(int j = 0; j <= C; j++)
            printf("%d ", M[i][j]);
        puts("");

        }

}
int main()
{
    freopen("input.txt", "r", stdin);
    int test, x,y;
    string s;
    stringstream ss;

    scanf("%d", &test);
    while(test--){

    scanf("%d %d", &R, &C);getline(cin, s);

    memset(CO, false, sizeof CO);

    for(int i = 1; i <= R; i++){
        getline(cin, s);
        ss.clear();
        ss << s;
        ss >> x;
        while(ss >> y)CO[x][y] = true;
    }
    CO[1][1] = CO[R][C] = false;

    memset(M, 0, sizeof M);
    M[1][1] = 1;

    dag(1, 1);
    //printMatrix();
    printf("%d\n", M[R][C]);
    if(test)puts("");
    }


    return 0;
}
