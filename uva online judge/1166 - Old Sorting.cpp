#include <cstdio>
#include <iostream>

using namespace std;
#define N 100

int main()
{
    int test,n,cs = 0, swaps;
    int in[N+1],pos[N+1];
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        for(int i = 1; i<=n; i++){
            scanf("%d",&in[i]);
            pos[in[i]] = i;
        }
        swaps = 0;
        for(int i = 1; i<=n; i++){
            if(in[i] != i){
                in[pos[i]] = in[i];
                pos[in[i]] = pos[i];
                in[i] = i;
                swaps++;
            }
        }
    printf("Case %d: %d\n", ++cs, swaps);
    }

    return 0;
}
