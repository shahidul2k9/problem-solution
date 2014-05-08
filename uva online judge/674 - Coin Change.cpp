#include <cstdio>
#include <iostream>

using namespace std;

typedef unsigned long long u64;
int coin[] = {0000, 1, 5, 10, 25 , 50};
u64 C[7489+10];
int W;
u64 countWays(){
    for(int i = 1; i <= W; i++)C[i] = 0;
    C[0] = 1;
    for(int i = 1; i <= 5; i++)
        for(int j = coin[i]; j <= W; j++)
            C[j] = C[j] + C[j - coin[i]];
    return C[W];
}
int main()
{
    while(scanf("%d", &W)==1)printf("%llu\n", countWays());
    return 0;
}
