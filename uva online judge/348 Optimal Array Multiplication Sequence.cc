#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
#define SIZE 12
int p[SIZE];
int s[SIZE][SIZE];
int m[SIZE][SIZE];
int N;
int minimize(int lo, int hi){

    if(m[lo][hi] != -1) return m[lo][hi];
    int ans = INT_MAX;
    int now;
    for(int i = lo; i < hi; i++){
        now = minimize(lo, i) + minimize(i + 1, hi) + p[lo-1]* p[i] * p[hi];
        if(now < ans){
            ans  = now;
            s[lo][hi] = i;
        }
    }
    return m[lo][hi] = ans;
}
void print(int lo, int hi){
    if(lo > hi)return;

    if(lo == hi) printf("A%d", lo);
    else{
        printf("(");
        print(lo, s[lo][hi]);
        printf(" x ");
        print(s[lo][hi]+1, hi);
        printf(")");
    }
}
int main(){
    //freopen("input.txt", "r", stdin);
    int r, c, cs;
    cs = 0;
    while(scanf("%d", &N) == 1 && N){
        scanf("%d %d",&r, &c);
        p[0] = r;
        p[1] = c;
        for(int i = 1; i <N; i++){
            scanf("%d %d", &r, &c);
            p[i] = r;
        }
        p[N] = c;
        memset(m, -1, sizeof(m));
        for(int i = 0; i<= N; i++)
            m[i][i] = 0;
        minimize(1, N);
        printf("Case %d: ", ++cs);
        print(1, N);
        puts("");
    }


    return 0;
}
