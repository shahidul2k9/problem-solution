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
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;
int main(){
    //freopen("input.txt", "r", stdin);
    int mask, a, b, n;
    bool turn;
    while( scanf("%d", &n) == 1 && n ){
        a = b = 0;
        mask = 1;
        turn = true;
        for( int i = 0; i < 31; i++ ){
            if( mask & n ){
                if( turn )
                    a |= mask;

            else
                b |= mask;
            turn = !turn;
            }
        mask <<= 1;
        }
        printf("%d %d\n", a, b);
    }
	return 0;
}
