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

#define UL 32768
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
    int N, a, b, no;
    int high;
    markPrime(pl);
    while(scanf("%d", &N) == 1 && N){
        no = 0;
        for(int i = 2; i <= N/2; i++)
            if(sieve[i] && sieve[N - i])
                no += 1;
        printf("%d\n", no);
    }
}
