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
#include <vector>

using namespace std;
const long long int SZ = 31630;
bitset<SZ + 1> sieve;
bitset<100000+10> ans;
vector < int > pl;
void sieveGen(){
    pl.push_back(2);
    for(int  i = 3; i <= SZ; i +=2 ){
        if( !sieve.test(i) ){
            pl.push_back(i);
            for(int  k = i + i; k <= SZ; k += i )
                sieve.set(k);
        }
    //printf("%lld\n", i);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    #endif
    sieveGen();
    int test, up;
    long long int m, n, x;
    scanf("%d", &test);
    while( test-- ){
        scanf("%lld %lld", &m, &n);
        up = upper_bound(pl.begin(), pl.end(), sqrt(n)) - pl.begin();
        if(up == pl.size() ) up--;
        ans.set();
        for(int k = 0; k <= up; k++ ){
            x = (m / pl[k])*pl[k];
            if(x <= pl[k]) x = pl[k] + pl[k];
            for(x; x <=n ; x += pl[k] ){
                if(x - m < 0)continue;
                ans.reset(x - m);
            }
        }
        if( m == 1)ans.reset(0);
        for(int k = 0; k <= n - m; k++ ){
            if(ans.test(k))printf("%lld\n", k+m);
        }
        if(test)puts("");
    }
	return 0;
}
