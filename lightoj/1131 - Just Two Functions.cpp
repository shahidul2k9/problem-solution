#include <string.h>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
typedef  int T;
#define MAX 6
int MOD;
struct Matrix{
    T mat[MAX][MAX];
    int N;
    Matrix():N(MAX){}
    Matrix(int n):N(n){}
    Matrix multiply(Matrix &B){
        Matrix C;
        for(int r = 0; r < N; r++)
            for(int c = 0; c < N; c++){
                C.mat[r][c] = 0;
                for(int k = 0 ; k < N; k++)
                    C.mat[r][c] = (C.mat[r][c] + mat[r][k]*B.mat[k][c])%MOD;
            }
        return C;
    }
    Matrix power(int n){
        Matrix P;
        if(n == 1)
            return(*this);
        P = power(n/2);
        P = P.multiply(P);
        if(n & 1) P = multiply(P);
        return P;
 
    }
    void init(int a1, int b1, int c1, int a2, int b2, int c2){
       memset(mat, 0, sizeof(mat));
       mat[0][0] = a1;
       mat[0][1] = b1;
       mat[0][5] = c1;
 
       mat[1][0] = 1;
 
       mat[2][1] = 1;
 
       mat[3][2] = c2;
       mat[3][3] = a2;
       mat[3][4] = b2;
 
       mat[4][3] = 1;
 
       mat[5][4] = 1;
    }
    void printMat(){
        for(int r = 0; r < N; r++){
            for(int c = 0; c < N; c++)
                printf("%6d", mat[r][c]);
            puts("");
        }
    }
};
int main(){
   //freopen("input.txt", "r", stdin);
   int fn, gn, q, n;
   int abc[6], fg[6], rcur[6];
   Matrix ans, base;
    int T, tc = 1;
    scanf("%d", &T);
    while( T-- > 0){
        for(int idx = 0; idx < 6; idx++)
            scanf("%d", &abc[idx]);
        for(int idx = 0; idx < 6; idx++)
            scanf("%d", &fg[idx]);
        scanf("%d", &MOD);
        scanf("%d", &q);
 
        for(int idx = 0; idx < 6; idx++){
            abc[idx] = abc[idx]%MOD;
            fg[idx] = fg[idx]%MOD;
        }
 
        rcur[0] = fg[2];rcur[1] = fg[1];rcur[2]=fg[0];
        rcur[3] = fg[5];rcur[4] = fg[4];rcur[5] = fg[3];
 
        printf("Case %d:\n", tc++);
        for(int cur = 1; cur <= q; cur++){
            scanf("%d", &n);
            if(n <= 2){
               fn = fg[n];
               gn = fg[3+n];
            }
            else{
                base.init(abc[0], abc[1], abc[2], abc[3], abc[4], abc[5]);
                ans = base.power(n-2);
                //ans.printMat();
                fn = gn = 0;
 
                for(int idx = 0; idx < 6; idx++){
                fn = (fn + ans.mat[0][idx]*rcur[idx])%MOD;
                gn = (gn + ans.mat[3][idx]*rcur[idx])%MOD;
                }
 
            }
            printf("%d %d\n", fn, gn);
        }
    }
    return 0;
}