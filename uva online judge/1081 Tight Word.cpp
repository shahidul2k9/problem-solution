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
double m[101][10];
bool c[101][10];
int k, n;
double nums(int i, int j ){
    if( i < 0 || j < 0 || j > k ) return 0.0;
    if( i == 1) return 1.0;
    if( c[i][j]) return m[i][j];

    m[i][j] = nums(i-1, j) + nums(i-1, j-1) + nums( i-1, j+1);
    c[i][j] = true;
    return m[i][j];
}
int main(){
    //freopen("input.txt", "r", stdin);
    double sum;
    while(scanf("%d %d", &k, &n) == 2){
        sum = 0;
        memset(c, false, sizeof(c));
        for(int i = 0; i <=k; i++ ) sum += nums(n, i);
        printf("%0.5lf\n",100.0* sum/pow( (double)(k+1),n ));
    }


	return 0;
}
