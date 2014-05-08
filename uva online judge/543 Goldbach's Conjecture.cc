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
bitset<UL+1> sieve;

void markPrime(vector<int> & pl){

    sieve.flip();
    sieve.reset(0);
    sieve.reset(1);
    for(int i = 2; i <= UL; i++)
        if(sieve.test(i)){
            for( int j = i + i; j <= UL; j +=i )
                sieve.reset(j);
            pl.push_back(i);
        }

}
int main(){
    //freopen("input.txt", "r", stdin);
    vector<int> pl;
    int N, a, b;
    bool found;

    markPrime(pl);
    while(scanf("%d", &N) == 1 && N){
        found = false;

        for(int i = 1; i <= lower_bound(pl.begin(), pl.end(), N/2) - pl.begin(); i++){
            a = pl[i];
            b = N - a;
            if(binary_search(pl.begin(), pl.end(), b)){
                printf("%d = %d + %d\n",N, min(a, b), max(a, b));
                found = true;
                break;
            }
        }
        if(!found)puts("Goldbach's conjecture is wrong.");
    }
}
