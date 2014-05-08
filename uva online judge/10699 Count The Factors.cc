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
    int N;
    markPrime(pl);
    int ufacts, i;
    while(scanf("%d", &N) == 1 && N){
      ufacts = 0;
      i = 0;
      printf("%d : ", N);
      while(N != 1){
          if(N % pl[i] == 0){
              ufacts++;
              while(N%pl[i] == 0)
                 N = N / pl[i];
          }
          i++;
      }
      printf("%d\n", ufacts);
    }
}
