#include <algorithm>
#include <bitset>

#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

bool isPrime(int n){
    if(n < 2)
        return false;
    if(n == 2)
        return true;

    for(int i = 2; i <= sqrt(n);i += 2)
        if(n%i == 0)
            return false;
    return true;
}
int main(){
  // freopen("input.txt", "r", stdin);
    vector < int > primes;
    for(int i = 2; i <= 100; i++)
        if(isPrime(i))primes.push_back(i);
    int N, x;
    int ans[100], large, p;

    char space[100];
    while(scanf("%d", &N) == 1 && N){
        memset(ans, 0, sizeof(ans));
        large = 2;
        for(int i = N; i > 1 ; i--){
            x = i;
            while(x != 1){
                for(int j = 0; j < primes.size(); j++)
                    if(x % primes[j] == 0){
                        ans[primes[j]] += 1;
                        x /= primes[j];
                        large = max(large, primes[j]);
                        break;
                    }
            }
        }

        printf("%3d! =", N);
        sprintf(space,"%3d! =", N);
        for(int i = 0; i < strlen(space); i++)
            space[i] = ' ';
        p = 0;
        for(int i = 2; i <= large; i++){
            if(!isPrime(i) || ans[i] == 0)continue;

            if(p == 15){
                puts("");
                printf("%s", space);
                p = 0;
                }
            printf("%3d", ans[i]);
            p += 1;
        }
        puts("");
    }


    return 0;
}
