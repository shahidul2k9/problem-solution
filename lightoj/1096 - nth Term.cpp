#include <string.h>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
typedef  int T;
#define MAX 4
#define  MOD 10007
struct Matrix{
    T mat[MAX][MAX];
    int N;
    Matrix():N(4){}
    Matrix(int n):N(n){}
    Matrix multiply(Matrix B){
        Matrix C;
        for(int r = 0; r < N; r++)
            for(int c = 0; c < N; c++){
                C.mat[r][c] = 0;
                for(int k = 0 ; k < N; k++)
                    C.mat[r][c] =  (C.mat[r][c] + (mat[r][k]*B.mat[k][c])%MOD) %MOD;
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
    void init(int a, int b, int c){
       mat[0][0] = a;
       mat[0][1] = 0;
       mat[0][2] = b;
       mat[0][3] = 1;
 
       mat[1][0] = 1;
       mat[1][1] = 0;
       mat[1][2] = 0;
       mat[1][3] = 0;
 
       mat[2][0] = 0;
       mat[2][1] = 1;
       mat[2][2] = 0;
       mat[2][3] = 0;
 
       mat[3][0] = 0;
       mat[3][1] = 0;
       mat[3][2] = 0;
       mat[3][3] = 1;
    }
};
int main(){
   //freopen("input.txt", "r", stdin);
   int a, b, c, n,out;
   Matrix ans, base;
    int T, tc = 1;
    scanf("%d", &T);
    while( T-- > 0){
        scanf("%d %d %d %d", &n, &a, &b, &c);
        a %= MOD;
        b %= MOD;
        c %= MOD;
        base.init(a,b,c);
        if(n <= 2)
            out = 0;
 
        else{
            ans = base.power(n-2);
            out = ans.mat[0][3]*c;
            out %= MOD;
        }
        printf("Case %d: %d\n", tc++, out);
    }
    return 0;
}