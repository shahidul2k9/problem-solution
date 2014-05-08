#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

struct Edge {
    int x, y, w;

} lis[6000+5];
bool comp(const Edge &e1, const Edge &e2) {
    return e1.w < e2.w;
}
int N, E, ce ;
int pre[205];
int getParent(int x) {
    if(pre[x] == x) return x;
    return pre[x] = getParent(pre[x]);
}
int mist() {
    sort(lis, lis+ce, comp);
    for(int i = 0; i<= N; i++) pre[i] = i;
    int ans = 0, taken = 0,px, py, del = -1;
    for(int idx = 0; idx < ce; idx++) {
        px = getParent(lis[idx].x);
        py = getParent(lis[idx].y);
        if( px != py ) {
            pre[px] = pre[py];
            ans += lis[idx].w;
            taken += 1;
        } else
            del = idx;

    }
    if( del != -1 ) lis[del] = lis[--ce];
    if( taken == N-1) return ans;
    return -1;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int test, cs = 0;
    scanf("%d", &test);
    while( cs++ < test) {
        ce = 0;
        printf("Case %d:\n", cs);
        scanf("%d %d", &N, &E);
        for(int idx = 0; idx < E; idx++) {
            scanf("%d %d %d", &lis[ce].x, &lis[ce].y, &lis[ce].w);
            ce++;
            printf("%d\n", mist());
        }
    }
    return 0;
}
