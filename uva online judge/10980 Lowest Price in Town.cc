#include <algorithm>
#include <bitset>

#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;
long long int cost[22][101];
struct Price{
    long long int d;
    int numbers;
};
long long int inf;
Price lis[21];
long long toLongDollar(char* d){
    int ind = 0;
    for(int i = 0; d[i]; i++)
        if(d[i] != '.')
            d[ind++] = d[i];
    d[ind] = NULL;
    return atoll(d);
}
long long int compute(int n, int num){
    if( num <= 0) return 0;
    if(n < 0) return inf;
    if(cost[n][num] != -1) return cost[n][num];

    long long int ans = inf;
    int sz;
    for(int i = 0; true; i++){
        sz = i*lis[n].numbers;
        ans = min(ans, i*lis[n].d + compute(n-1, num - sz));
        if(sz >= num)
            break;
    }
    return cost[n][num] = ans;
}
int main(){
   // freopen("input.txt", "r", stdin);
    char dollar[100];
    int cs = 1;
    int N, x;
    string chs;
    int A[10000];
    inf = 1000000000000000;
    while(scanf("%s %d", dollar, &N) == 2){
        lis[0].d = toLongDollar(dollar);
        lis[0].numbers = 1;
        for(int i = 1; i <= N; i++){
            scanf("%d %s",&lis[i].numbers, dollar);
            lis[i].d = toLongDollar(dollar);
        }
        getchar();
        getline(cin, chs);
        stringstream ss;
        ss << chs;
        x = 0;
        while(ss >> A[x]){x++;};


        memset(cost, -1, sizeof(cost));

        printf("Case %d:\n", cs++);

        for(int i = 0; i < x; i++){
            if(cost[N][A[i]] == -1) compute(N, A[i]);
            printf("Buy %d for $%.2lf\n",A[i], (double)cost[N][A[i]]/100);
        }


    }

    return 0;
}
