#include <cstdio>
#include <string.h>
#include <algorithm>
#include <climits>
#include <vector>
#include <iostream>
using namespace std;
struct RGB{
    int rgb[3];
    RGB(int r, int g, int b) {
        rgb[0] = r;
        rgb[1] = g;
        rgb[2] = b;
    }
};
 
vector < RGB >  lis;
int cost[20][3];
int getCost(int n, int c){
    if( n < 0) return 0;
    if(cost[n][c] != -1)return cost[n][c];
    int ans = INT_MAX;
    for(int cur = 0; cur < 3; cur++){
        if(cur != c) ans = min(ans, getCost(n-1, cur));
    }
    return cost[n][c] =  ans + lis[n].rgb[c];
}
int main(){
    //freopen("input.txt", "r", stdin);
    int r, g, b;
    int test, n, tc=1, ans;
    scanf("%d", &test);
 
    while( test-- ){
        scanf("%d", &n);
        lis.clear();
        for(int idx = 0; idx < n; idx++){
            scanf("%d %d %d", &r, &g, &b);
            lis.push_back(RGB(r, g, b));
        }
        memset(cost, -1, sizeof(cost));
        ans = min(getCost(n-1, 0), getCost(n-1, 1));
        ans = min(ans, getCost(n-1, 2));
        printf("Case %d: %d\n", tc++, ans);
    }
    return 0;
}