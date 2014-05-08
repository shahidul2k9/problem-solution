#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;
#define SET(N, pos) N |=  (1 << pos)
#define RESET(N, pos) N &=  ~(1 << pos)
#define IS_SET(N, pos) (N & (1 << pos))
#define M 12
int memo[1 << 12 ];
int countBits(int bitmask){
    int bits = __builtin_popcount(bitmask);
    if(bits == M)return bits;
    for(int i = 0; i < M -1; i++) if((bitmask & 1 << i)!=0 && (bitmask & 1 << (i+1))!=0)
        return -1;

    return bits;
}
int drop(int bitmask){
    int bits , ans;
    if(memo[bitmask] != -1)return memo[bitmask];

    bits = countBits(bitmask);
    if(bits != -1) return memo[bitmask] = bits;



    ans = 1 << 12;
    for(int i = 0; i < M - 1; i++){
        if(IS_SET(bitmask, i) && IS_SET(bitmask, i+1)){
            if(i+2 < M && IS_SET(bitmask, i+2) == 0) {
                bits = bitmask | 1 << (i+2);
                bits &= ~(1 << i+1);
                bits &= ~(1 << i);
                ans = min(drop(bits), ans);
            }

            if(i-1 >= 0 && IS_SET(bitmask, i-1) == 0){
                bits = bitmask | 1 << (i-1);
                bits &= ~(1 << i);
                bits &= ~(1 << i+1);
                ans = min(drop(bits), ans);

            }

        }
    }
    return memo[bitmask] = ans;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int test;
    char str[13];
    int bitmask;
    scanf("%d", &test);gets(str);

    while(test--){
        gets(str);
        bitmask ^=  bitmask;
        for(int i = 0; i < M; i++) {
            if(str[i] == 'o')
                SET(bitmask, i);
        }
        memset(memo, -1, sizeof memo);
        printf("%d\n", drop(bitmask));


    }
    return 0;
}
