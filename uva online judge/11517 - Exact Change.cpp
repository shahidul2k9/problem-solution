#include <string.h>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;

#define inf 10000

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test;
    scanf("%d", &test);
    int payable, N;
    int M[10001], A[101];
    while(test--){
        scanf("%d %d", &payable, &N);
        for(int i = 1; i <= N; i++)
            scanf("%d", &A[i]);
        //memset(M, 0, sizeof(M));
        for(int i = 1; i <= 10000; i++)
            M[i] = inf;
        M[0] = 0;

        for(int i = 1; i <= N; i++)
            for(int j = 10000; j > 0; j--)
                if(j - A[i] >= 0 && M[j - A[i]] + 1 < M[j])
                    M[j] = M[j - A[i]] + 1 ;

        int i;
        for(i = payable; M[i] == inf; i++);

        printf("%d %d\n", i, M[i]);

    }

	return 0;
}
