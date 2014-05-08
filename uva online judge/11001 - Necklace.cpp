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

int main(){
    double total, x, ans, cur;
    int N;
    //freopen("input.txt", "r", stdin);
    while(scanf("%lf %lf", &total, &x) == 2 && (total>0.0 || x > 0.0)){
        ans = 0.0;
        N = 0;
        for( int n = 1;  total/n > x; n += 1 ){
            cur = 0.3*sqrt(total/n - x)*n;
            if ( cur >= ans ){
                if(fabs(cur - ans)  <= 1e-12)
                    N = 0;
                else N = n;
                ans = cur;
               // cout << " = " << n << " " << cur  << endl;
            }
        }
        printf("%d\n", N);
    }

	return 0;
}
