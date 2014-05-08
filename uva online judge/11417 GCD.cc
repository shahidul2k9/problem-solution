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
typedef long long int Type;
int G[501][501];
int N;
int gcd(int a,int  b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
int fillgcd(int a, int b){
    int ans = gcd(a, b);
    for(int i = 2; i*a <= N && i*b <= N; i++)
        G[i*a][i*b] = ans*i;
    return ans;
}

int main(){
   freopen("input.txt", "r", stdin);
    int ans;
    while(scanf("%d", &N) == 1 && N){
        memset(G,-1,sizeof(G));

        ans = 0;
        for(int i = 1; i <N; i++)
            for(int j = i +1; j<=N; j++){
                    if(G[i][j] == -1)
                        G[i][j] = fillgcd(i,j);
                    ans += G[i][j];
            }
        printf("%d\n", ans);
    }

	return 0;
}
