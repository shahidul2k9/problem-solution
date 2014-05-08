#include <algorithm>
#include <bitset>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string.h>
#include <ctime>
#include <vector>
using namespace std;
long long int x, y, d;
void extendedEuclid(long long int a, long long int b){
    if(b == 0){
        x = 1;
        y = 0;
        d = a;
        return;
    }
    extendedEuclid(b, a % b);
    long long int x1, y1;
    x1 = y;
    y1 = x - a/b*y;
    x = x1;
    y = y1;
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    long long int a, b;
    while(scanf("%lld %lld", &a, &b) == 2){
        if( a == 0) swap(a, b);
        extendedEuclid(a,b);
        printf("%lld %lld %lld\n", x, y, d);
    }
	return 0;
}
