#include <string.h>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
typedef  int T;
#define MAX 2
int MOD;
struct Matrix{
    T mat[MAX][MAX];
    int N;
    Matrix():N(2){}
    Matrix(int n):N(n){}
    Matrix multiply(Matrix B){
        Matrix C;
        for(int r = 0; r < N; r++)
            for(int c = 0; c < N; c++){
                C.mat[r][c] = 0;
                for(int k = 0 ; k < N; k++)
                    C.mat[r][c] =  (C.mat[r][c] + (mat[r][k]*B.mat[k][c])%MOD)%MOD;
            }
        return C;
    }
    Matrix power(int n){
        if(n == 1) return (*this);
        Matrix P;
        P = power(n/2);
        P = P.multiply(P);
        if(n & 1) P = multiply(P);
        return P;
 
    }
    void init(){
       mat[0][0] = 0;
       mat[0][1] = 1;
       mat[1][0] = 1;
       mat[1][1] = 1;
    }
};
int main(){
    //freopen("input.txt","r",stdin);
    int a, b, n,out, m;
    Matrix ans, base;
    int T, tc = 1;
    scanf("%d", &T);
    while( T-- > 0){
        scanf("%d %d %d %d", &a, &b, &n, &m);
        MOD = pow(10,m);
        a %= MOD;
        b %= MOD;
        if(n < 2){
            if(n == 0) out = a;
            else out = b;
 
        }
        else{
            base.init();
            ans = base.power(n-1);
            out = ( (ans.mat[1][0]*a)%MOD + (ans.mat[1][1]*b)%MOD ) % MOD;
        }
        printf("Case %d: %d\n", tc++, out);
    }
    return 0;
}