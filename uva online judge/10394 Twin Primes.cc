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
typedef pair<int, int >ii;
#define UL 20000000

bitset<UL> p;

void setPrimes(){
    p.flip();
    p.reset(0);
    p.reset(1);

    for(long long i = 2; i <= sqrt(UL); i++)
        if(p.test(i)){
            for(long long j = i + i; j < UL; j += i)
                p.reset(j);
        }
}
int main(){
  // freopen("input.txt", "r", stdin);
    int N;
    setPrimes();
    vector< int> twins;



    for(int i = 2; i < UL - 2 ; i++)
        if(p.test(i)){
            if(p.test(i + 2))
            twins.push_back(i);
        }

    while(scanf("%d", &N) == 1){
        N--;
        printf("(%d, %d)\n", twins[N], twins[N]+2);
    }


}
