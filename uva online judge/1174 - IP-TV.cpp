#include <stdio.h>
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
#include <cstring>
using namespace std;
struct Edge{
    int st, en, wt;
    Edge(){}
    Edge(int from, int to, int cost){st = from;en = to; wt = cost;}
};
int pre[2001];
int rpt(int x ){
    if(pre[x] == x) return x;
    return pre[x] = rpt(pre[x]);
}
bool callback(const Edge &a , const Edge& b){
    return a.wt < b.wt;
}
int main(){
    //freopen("input.txt", "r", stdin);
    map < string, int > table;
    int N, M, test,  id;
    string from, to;
    Edge lis[50000];
    scanf("%d", &test);

    while( test-- ){
        scanf("%d %d", &N, &M);
        id = 0;
        table.clear();
        for(int i = 0; i < M; i++ ){
            cin >> from >> to >> lis[i].wt;
            if( !table[from] ) table[from] = ++id;
            if( !table[to] ) table[to] = ++id;
            lis[i].st = table[from];
            lis[i].en = table[to];
        }
        for(int i = 1; i <= N; i++ ) pre[i] = i;
        sort(lis, lis+M, callback);

        int ans = 0;
        for(int i = 0; i < M; i++ ){
            int ptx = rpt(lis[i].st);
            int pty = rpt(lis[i].en);
            if(ptx != pty){
                ans += lis[i].wt;
                pre[ptx] = pty;
            }
        }
        printf("%d\n", ans);
        if(test)puts("");
    }
    return 0;
}
