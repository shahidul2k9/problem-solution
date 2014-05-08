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
#define UL 1000000
bitset< UL + 1 > sieve;
vector < int > pl;
int f[UL+1], cf[UL+1];
void makePrime(){
    sieve.flip();
    sieve.reset(0);
    sieve.reset(1);
    for(int i = 4; i <= UL; i += 2)
        sieve.reset(i);

    pl.push_back(2);

    for(int i = 3; i <= UL;i += 2)
        if(sieve.test(i)){
            pl.push_back(i);
        for(int j =  i + i + i;  j <= UL; j += i + i)
            sieve.reset(j);
        }

}
int factors(int N){
    if(sieve[N])
        return 1;


    for(int i = 0; i < pl.size(); i ++)
        if(N % pl[i] == 0) return f[N/pl[i]] + f[ pl[i] ];
    return 0;
}
int main(){
    int n;
    makePrime();
    f[0] = f[1] = cf[0] = cf[1] = 0;

    for(int i = 2; i <= UL; i++){
        f[i] = factors(i);
        cf[i] = cf[i-1] + f[i];
    }

    while(scanf("%d", &n) == 1){
        printf("%d\n", cf[n]);
    }
    return 0;
}
