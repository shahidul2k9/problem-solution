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
#include <deque>
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;

#define TT 10000
#define TM 1000000

vector < int > primes;
bitset < TM + 1 > sieve;

bool isPrime( int n ){
    if( n <= TM ) return sieve.test(n);
    for( int i = 0; i <(int) primes.size() && primes[i] <= sqrt(n); i++ ){
        if( n % i) return false;
    }
    return true;
}
int main(){
  // freopen("input.txt", "r", stdin);
   int M[10005];
   int A[10005];
   int from, len, N;
   int test;
   sieve.flip();
   sieve.reset(0);
   sieve.reset(1);
   primes.push_back(2);
   for( int i = 4; i <= TM; i +=2 ) sieve.reset(i);

   for( int i = 3; i <= TT; i+=2 ){
        if( sieve.test(i) ){
            primes.push_back(i);
            for(int a = i + i; a <= TM; a += i)
                sieve.reset(a);
        }
   }
    scanf("%d", &test);
    while(test--){
        scanf("%d", &N);
        for( int i = 1; i <= N; i++){
            scanf("%d", &A[i]);
            M[i] = A[i];
        }

        from = -1;
        for( int i = 1; i < N; i++ ){
            len = i;
            from = -1;
            for( int j = 1; i + j<= N; j++ ){

                    M[j] = M[j] + A[j + i];
                    if(isPrime(M[j]))
                        from = j;

                if( from != -1 ) break;
                }
            if( from != -1)break;
            }
        if( from != -1 ) {
            printf("Shortest primed subsequence is length %d:",len+1);
            for( int i = from; i <= from + len; i++ ) printf(" %d", A[i]);
            puts("");
            }
        else printf("This sequence is anti-primed.\n");
    }
    return 0;
}

