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
long long N;

bool move(long long p){
    if(p*2 >= N || p*9 >= N)
        return true;

    bool op1 = move(p*2) ;
    bool op2 = move(p*9) ;
    if(op1 != op2 )
        return true;
    if(op1 == true) return false;
    return true;


}
int main(){
  // freopen("input.txt", "r", stdin);

    while(scanf("%lld", &N) == 1){
        if(move(1))
            puts("Stan wins.");
        else puts("Ollie wins.");
    }

    return 0;
}
