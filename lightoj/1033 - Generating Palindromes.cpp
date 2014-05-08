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
char s[109];
int mc[109][109];

int minins(int b, int e){
    if( mc[b][e] != -1) return mc[b][e];
    if( b == e) return mc[b][e] = 0;
    if( b + 1 == e )
        return mc[b][e] = (s[b] != s[e]);
    if( s[b] == s[e] ) return mc[b][e] = minins(b+1, e-1);
    return mc[b][e] = 1 + min(minins(b, e-1), minins(b+1, e));


}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int test, n,  cs  = 1;
    scanf("%d", &test);
    while( test-- ){
        scanf("%s", s);
        n = strlen(s);
        memset(mc, -1, sizeof(mc));
        printf("Case %d: %d\n", cs++, minins(0, n-1));
    }


	return 0;
}
