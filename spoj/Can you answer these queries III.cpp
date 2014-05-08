#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <climits>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;
#define MAX 50000+1
const int MAX_SEG = 131072;
int A[MAX];
int N;
#define INF -15009
struct Node{
    int prefix, suffix, maximal, total;

    void leafSetup(int value){prefix = suffix = maximal = total = value;}
    void merge(const Node& left, const Node& right){
        prefix = max(left.prefix, left.total + right.prefix );
        suffix = max(right.suffix, left.suffix + right.total );
        total = left.total + right.total;
        maximal = max(left.maximal, right.maximal);
        maximal = max(maximal, left.suffix+ right.prefix);
    }

}t[MAX_SEG];

void init(int node, int b, int e){
    if(b == e) {
        t[node].leafSetup(A[b]);
        return;
    }
    int m = (b+e) >> 1;
    int l = node << 1;

    init(l, b, m);
    init(l+1, m+1, e);
    t[node].merge(t[l], t[l+1]);
}
void update(int node, int b, int e, int value, int index){

    if( b == e && b == index ) {
        t[node].leafSetup(value);
        return;
    }
    int l = node << 1;
    int m = (b + e) >> 1;
    if( index <=m )
        update(l, b, m, value, index);
    else
        update(l+1, m+1, e, value, index);
    t[node].merge(t[l], t[l+1]);

}
void query(int node, int b, int e, int i, int j, Node& ans){
    if( b >= i && e <= j ){
        ans = t[node];
        return;
    }
    int m = (b + e) >> 1;
    int l = node << 1;
    if(m >= j ) {query(l, b, m, i, j, ans);return;}
    else if(m < i ){query(l+1, m+1, e, i, j, ans);return;}
    else{
        Node left, right;
        query(l, b, m, i, j, left);
        query(l+1, m+1, e, i, j, right);
        ans.merge(left, right);
    }

}
int main(){
    //freopen("input.txt", "r", stdin);
    int Q, x, y, c;
    Node ans;
    while(scanf("%d", &N) == 1){
        for ( int i = 1; i <= N; i++ ){
            scanf("%d", &A[i]);
        }
       init(1, 1, N);
        scanf("%d", &Q);
        while(Q--){
            scanf("%d %d %d", &c, &x, &y);
            if( c == 1){
            query(1, 1, N, x, y, ans);
            printf("%d\n",ans.maximal);
            }
            else update(1, 1, N, y, x);
        }

    }
}
