#include <cstdio>
#include <iostream>

using namespace std;
typedef unsigned long long int u64;
int coins[] = {0000, 1, 5, 10, 25, 50};
u64 C[30001];
int N = 5;
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
int main()
{
    u64 ans;
   while(scanf("%d", &W) == 1){
       ans = countWays();
       if(ans == 1)
        printf("There is only %llu way to produce %d cents change.\n", ans , W);
       else
       printf("There are %llu ways to produce %d cents change.\n", ans , W);
   }

    return 0;
}
