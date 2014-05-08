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

bool isPrime(int x){
    for(int i = 2; i <= sqrt(x); i++)
        if(x % i == 0)
            return false;

    return true;
}
int main(){
  // freopen("input.txt", "r", stdin);
    vector< int > pl;
    pl.push_back(1);
    pl.push_back(2);
    pl.push_back(3);
    for(int i = 4; i < 1000; i++)
        if(isPrime(i))
            pl.push_back(i);

   int N, C, hi, els, lo;

   while(scanf("%d %d",&N, &C) == 2){
       hi = lower_bound(pl.begin(), pl.end(), N) - pl.begin();
       if(hi == pl.size() || pl[hi] != N) hi = hi - 1;
       printf("%d %d:", N, C);

       els = 2*C;
       if((hi + 1)%2 == 1)
        els -= 1;

       if(hi + 1 <= els){
           lo = 0;
           hi = hi;
       }
       else {
           lo = (hi+1 - els)/2;
           hi = lo + els - 1;

       }
       for(int i = lo; i <= hi; i++)
        printf(" %d", pl[i]);
        puts("\n");

   }
}
