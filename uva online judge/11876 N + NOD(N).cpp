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
#define ML 1000000
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test, a, b;
    int cs = 1;
    vector <int>  S = vector<int>(ML+1, 1);
    vector < int > ans;
    ans.push_back(0);
    ans.push_back(1);
    int c;
    for( int i = 2; i <= ML; i++ ){
            for( int j = i; j <= ML; j += i )
                S[j] += 1;
    }

    for( int i = 2; true ;i++ ){
        c = ans[i-1] + S[ ans[i-1]];
        if( c <= ML ) ans.push_back(c);
        else break;
    }
    scanf("%d", &test);
    while ( test--){
        scanf("%d %d", &a, &b);
        int lo = lower_bound(ans.begin(), ans.end(), a) - ans.begin();
        int hi = upper_bound(ans.begin(), ans.end(), b) - ans.begin();
        printf("Case %d: ", cs++);
        if( hi == (int)ans.size() || ans[hi] != b) printf("%d\n", hi - lo);
        else printf("%d\n", hi - lo + 1);
    }
    return 0;
}

