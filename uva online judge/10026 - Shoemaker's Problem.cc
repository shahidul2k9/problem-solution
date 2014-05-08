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

#define EPS 1E-9

struct Job{
    long long int s, t;
    int sn;
};
bool callback(const Job & a, const Job & b){
    long long int  x = a.s* b.t;
    long long int y = a.t*b.s;
    if(x != y) return x > y;
    return  a.sn < b.sn;
}
int main(){
    //freopen("input.txt", "r", stdin);
     // freopen("output.txt", "w", stdout);

    int N, test;
    Job A[1009];
    scanf("%d",  &test);
    while(test--){
        scanf("%d", &N);
        for(int i = 1; i <= N; i++){
            scanf("%lld %lld", &A[i].t, &A[i].s);
            A[i].sn = i;
        }
            sort(A + 1,A + N + 1, callback);
     for(int i = 1; i <N; i++)
        printf("%d ", A[i].sn);

    printf("%d\n", A[N].sn);
    if(test)puts("");
    }

	return 0;
}
