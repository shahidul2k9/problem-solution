#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
#define MAXQUEEN 9
int storeRow[MAXQUEEN];
int i,row,cs,a,b;
bool promising(int r, int c){
    for(i=1;i<c;i++)
        if(r==storeRow[i]||c==i||abs(r-storeRow[i])==abs(c-i))return false;

    return true;
}
void nQueens(int col){
    for(int row=1;row<=8;row++){
        if(promising(row,col)){
            storeRow[col] = row;
            if(col==8&&storeRow[b]==a){
                printf("%2d      %d",cs++,storeRow[1]);
                for(i = 2;i<=8;i++) printf(" %d",storeRow[i]);
                printf("\n");
                }
            else nQueens(col+1);
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int test;
    scanf("%d", &test);
    while(test--){
        cs = 1;
        scanf("%d %d", &a, &b);
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        nQueens(1);
        if(test)printf("\n");
    }
    return 0;
}
