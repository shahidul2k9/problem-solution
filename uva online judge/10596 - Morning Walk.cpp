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

int main(){
    //freopen("input.txt", "r", stdin);
    int V, E, st, en;
    int deg[200];
    while( scanf("%d %d", &V, &E) == 2 ){
        memset(deg, 0, sizeof(int)*V);
        for( int k = 1; k <= E; k++ ){
            scanf("%d %d", &st, &en);
            deg[st]++;
            deg[en]++;
        }
        int k = 0;
        for( k = 0; k < V; k++ ){
            if(deg[k] == 0 || deg[k] % 2 == 1)
                break;
        }
        if(k == V)puts("Possible");
        else puts("Not Possible");
    }

	return 0;
}
