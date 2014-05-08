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

#define ROW 11
#define COL 101
#define inf 1 << 20
int squre[102];
int ans[10001];

void f(int x){
    for(int i = 0; squre[i] <= x; i++)
        if(ans[x] > 1 + ans[x-squre[i]])
            ans[x] = 1 + ans[x-squre[i]];


}

int main(){
    //freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);


    int n, test;
    for(int i = 0; i <= 101; i++)
        squre[i] = i * i;

    ans[1] = 1;
    for(int i = 2; i<= 10000; i++){
        ans[i] = inf;
        f(i);

    }

    scanf("%d", &test);
    while(test--){
        scanf("%d", &n);
        printf("%d\n", ans[n]);

    }
	return 0;
}
