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
#define MAX 100001
int N, M, L;
int memo[MAX];

int A, B;
struct List{
    char name[17];
    int cost;
};
bool callback(List a, List b){
    if(a.cost != b.cost)
        return a.cost < b.cost;
    return strcmp(a.name, b.name) < 0;
}
int minCost(int n){

    if(memo[n] != -1) return memo[n];
    int cost = INT_MAX;


    int next = n/2;
    if(next >= M && (n - next)*A > B) cost = min(cost, minCost(next) + B);


    if(cost == INT_MAX) cost = A*(n - M);
    return memo[n] = cost;

}
int main(){
   // freopen("input.txt", "r", stdin);
    int test;
    int cs = 1;
    List lis[100];

    scanf("%d", &test);
    while(test--){
        scanf("%d %d %d", &N, &M, &L);
        for(int i = 0; i < L; i++){
            getchar();
            scanf("%[^:]:%d,%d", lis[i].name, &A,&B);

            memset(memo, -1, sizeof(memo));
            memo[M] = 0;
            lis[i].cost = minCost(N);
        }
        sort(lis, lis + L, callback);
        printf("Case %d\n", cs++);
        for(int i = 0; i < L; i++)
            printf("%s %d\n", lis[i].name, lis[i].cost);
    }

    return 0;
}
