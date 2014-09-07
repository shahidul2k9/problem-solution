#include <bits/stdc++.h>
using namespace std;
#define MX 1 << 18
int minVal[MX],maxVal[MX];
#define lson(n) n << 1
#define rson(n) (n << 1)+1
#define INF INT_MAX
 
void pushUP(int p){
    minVal[p] = min(minVal[lson(p)], minVal[rson(p)]);
    maxVal[p] = max(maxVal[ lson(p) ], maxVal[ rson(p) ]);
}
void build(int p, int l, int r){
    if(l == r){
        scanf("%d", &minVal[p]);
        maxVal[p] = minVal[p];
        return;
    }
    int mid = (l+r) >> 1;
    build( lson(p), l,mid);
    build(rson(p), mid+1, r);
    pushUP(p);
}
int minQuary(int p, int curBeg, int curEnd, int beg, int end){
    if(curBeg > end || curEnd < beg) return INF;
    if(curBeg >= beg && curEnd <= end) return minVal[p];
    int curMid = (curBeg + curEnd) >> 1;
    return min(minQuary(lson(p), curBeg, curMid, beg, end), minQuary(rson(p), curMid+1, curEnd, beg, end));
}
int maxQuery(int p, int curBeg, int curEnd, int beg, int end){
    if(curBeg > end || curEnd < beg) return -INF;
    if(curBeg >= beg && curEnd <= end) return maxVal[p];
    int curMid = (curBeg + curEnd) >> 1;
    return max(maxQuery(lson(p), curBeg, curMid, beg, end), maxQuery(rson(p), curMid+1, curEnd, beg, end));
}
int main(){
      #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        #endif
        int n, d, test, ans, cs = 1;
        scanf("%d", &test);
        while(test--){
            scanf("%d %d", &n, &d);
            build(1,1,n);
            ans = 0;
            for(int i = 1; i+d-1 <= n; i++ )
                ans = max(maxQuery(1, 1, n,  i, i+d-1) - minQuary(1, 1, n,  i, i+d-1), ans);
 
            printf("Case %d: %d\n", cs++, ans);
        }
    return 0;
}