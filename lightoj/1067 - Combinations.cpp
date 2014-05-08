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
typedef long long int i64;
typedef unsigned int u32;
typedef unsigned long long int u64;
typedef vector < int > IV;
typedef vector < IV > IVV;
#define GetFS(b) ( (b) & (-b) )
#define ClrFS(b) (b & ~GetFS(b))
#define Neg(v) memset((v), -1, sizeof(v))
#define Zero(v) memset((v), 0, sizeof(v))
#define SInf(v) memset((v), 0x7f, sizeof(v))
#define For(t,i,c) for(t::iterator i =(c).begin(); i != (c).end(); ++i)
#define RFor(t,v,c) for(t::reverse_iterator i = (c).rbegin(); i != (c).rend(); ++i)

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))

#define INF INT_MAX

#define SQR(x) ((x)*(x))
#define PI 2*acos(0)
#define EPS 1e-7

#define MOD 1000003
#define OM 1000000

i64 x,y;
void extenedEuclid(i64 a, i64 b){
    if( b == 0){
        x = a;
        y = 0;
        return;
    }
    extenedEuclid(b, a % b);
    i64 tx, ty;
    tx = y;
    ty = x - a/b*y;
    x = tx;
    y = ty;
}
i64 fact[OM+1];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int test, cs = 1, n, k;
    i64 deno;
    fact[0] = 1;
    for(i64 i = 1; i <= OM; i++ )
        fact[i] = (fact[i-1]*i) %MOD;
    scanf("%d", &test);
    while( test-- ){
    printf("Case %d: ", cs++);
    scanf("%d%d", &n, &k);
    if(n < k ) puts("0");
    else{
        deno = (fact[k]*fact[n-k])%MOD;
        extenedEuclid(deno, MOD);
        deno = x;
        while(deno < 0) deno += MOD;
        deno %= MOD;
        printf("%lld\n", fact[n]* deno %MOD);
    }

    }
	return 0;
}
