#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXQUEEN 9
int column[MAXQUEEN];
int score[MAXQUEEN][MAXQUEEN];
int i,row,total,maxScore;
bool promising(int r, int c){
    for(i=1;i<r;i++)
        if(r==i||c==column[i]||abs(r-i)==abs(c-column[i]))return false;

    return true;
}
void nQueens(int row){
    for(int col=1;col<=8;col++){
        if(promising(row,col)){
            column[row] = col;
            if(row==8){
               total = 0;
                for(i = 1;i<=8;i++) total += score[i][column[i]];
                maxScore = max(total,maxScore);
                }
            else nQueens(row+1);
        }
    }
}
int main(){
    int test;
    freopen("input.txt", "r", stdin);
    scanf("%d", &test);
    while(test--){
        for(int i=1;i<9;i++)
            for(int j=1;j<9;j++)scanf("%d", &score[i][j]);
        maxScore = 0;
        nQueens(1);
        printf("%5d\n",maxScore);
    }
    return 0;
}
