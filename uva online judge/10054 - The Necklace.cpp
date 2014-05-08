#include <algorithm>
#include <bitset>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string.h>
#include <ctime>
#include <vector>
using namespace std;
#define NODE 56
int g[NODE][NODE];
int N;

struct Edge{
    int from,  to;
    Edge(int st, int en): from(st), to(en){}
};
vector < Edge >  ls;
void dfs(int from){
    for(int v = 1; v <= N; v++)
        if(g[from][v]){
            g[from][v]--;
            g[v][from]--;
            dfs(v);
            ls.push_back(Edge(from, v));
        }

}
int main(){
    freopen("input.txt", "r", stdin);
    int E, st, en, cs = 1, test;
    int d[NODE];
    scanf("%d", &test);
    while(test--){
        scanf("%d", &E);
        N = 0;
        memset(d, 0, sizeof(d));
        memset(g, 0, sizeof(g));
        for(int e = 1; e <= E; e++){
            scanf("%d %d", &st, &en);
            g[st][en]++;
            g[en][st]++;

            d[st]++;
            d[en]++;
            N = max(max(st, en), N);
        }
        bool notour = false;
        for(int v = 1; v <= N; v++){
            if(d[v] & 1) notour = true;
            break;
        }
        printf("Case #%d\n", cs++);
        ls.clear();
        if( !notour ) {
            dfs(N);
           if( ls.size() != E || ls[0].to != ls[(int)ls.size()-1].from)
                printf("some beads may be lost\n");
            else
            for(int l = (int)ls.size()-1; l >= 0; l--){
                printf("%d %d\n", ls[l].from, ls[l].to);
            }
            }
        else printf("some beads may be lost\n");
        if(test) puts("");

    }
    return 0;
}
