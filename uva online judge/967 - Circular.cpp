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

#define TM 1000000

bitset < TM + 1 > sieve;
char num[100];
bool iscirprime(int n){
    if( !sieve.test(n) ) return false;
    sprintf(num,"%d",n);
    int len = strlen(num);
    int con = pow(10,len - 1);
    int d;
    for(int i = 0; i < len; i++ ){
        d = num[i] - '0';
        n = (n - con* d)*10 + d;
        if( !sieve.test(n) ) return false;
    }
    return true;

}

int main(){
  // freopen("input.txt", "r", stdin);
   vector < int > cirprime;
   sieve.flip();
   sieve.reset(0);
   sieve.reset(1);
   for( int i = 4; i <= TM; i +=2 ) sieve.reset(i);

   for( int i = 3; i <= 1000; i+=2 ){
            if(sieve.test(i))
            for(int a = i + i; a <= TM; a += i)
                sieve.reset(a);
   }

    for( int i = 100; i <= TM; i++ ){
        if( iscirprime(i))cirprime.push_back(i);
    }
    int a, b, lo, hi;
    while( scanf("%d %d", &a, &b) == 2){
    lo = lower_bound(cirprime.begin(), cirprime.end(), a) - cirprime.begin();
    hi = upper_bound(cirprime.begin(), cirprime.end(), b) - cirprime.begin();
    if(cirprime[hi] != b || hi == (int)cirprime.size()) hi--;
    if( hi < lo )
        puts("No Circular Primes.");

    else if( lo == hi )
        puts("1 Circular Prime.");

    else
        printf("%d Circular Primes.\n", hi - lo + 1);
    }

    return 0;
}

