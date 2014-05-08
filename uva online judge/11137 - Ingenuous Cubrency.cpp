#include <cstdio>
#include <iostream>

using namespace std;
typedef unsigned long long int u64;
int coins[22];
u64 C[10000];
#define N 21
int W;
u64 countWays(){
    for(int i = 1; i<=W; i++)C[i] = 0;
    C[0] = 1;
    for(int i = 1; i<=N; i++)
        for(int j = coins[i]; j<=W; j++){
            C[j] = C[j] + C[j - coins[i]];
        }

    return C[W];
}
void makeCoins(){
    for(int i = 1; i <= 21; i++) coins[i] = i*i*i;
}
int main()
{

    makeCoins();
   while(scanf("%d", &W) == 1){
       printf("%llu\n", countWays());
   }

    return 0;
}
