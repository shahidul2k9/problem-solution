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

#define MAX 1000005
int main(){
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int N, Q, x, k, v;
    vector< vector<int> > ls;

    while(scanf("%d %d", &N, &Q) ==2){

            ls = vector< vector<int> >(MAX, vector<int>(0));
           for(int i = 1; i <= N; i++){
            scanf("%d", &x);
            ls[x].push_back(i);
        }

        for(int i = 1; i <= Q; i++){
            scanf("%d %d", &k, &v);
            if(ls[v].size() < k)printf("0\n");
            else printf("%d\n", ls[v][k-1]);
        }
    }
	return 0;
}
