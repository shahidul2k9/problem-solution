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
#define MAX 10000+10
const int MAX_SEG = 1 << 15;
int A[MAX];
int N;
#define NEGINF -200000000
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
void query(int node, int b, int e, int i, int j, Node& ans){
    if(i > j){
        ans = t[0];
        return;
    }
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
   // freopen("input.txt", "r", stdin);
    int Q, x1, y1,x2, y2, test, maximal;
    Node left, right, mid;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &N);
        for ( int i = 1; i <= N; i++ ){
            scanf("%d", &A[i]);
        }
       init(1, 1, N);
        scanf("%d", &Q);
        while(Q--){
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            maximal = 0;
            if( y1 < x2 ){
                query(1, 1, N, x1,y1,left);
                query(1, 1, N, y1+1,x2-1,mid);
                query(1, 1, N, x2, y2, right);
                maximal = left.suffix + mid.total + right.prefix;
                printf("%d\n",maximal);
                continue;
            }

                query(1,1,N,x2,y1,mid);
                maximal = mid.maximal;
                query(1, 1, N, x1, x2-1, left);
                query(1, 1, N,x2,y2, right);

                maximal = max(maximal,left.suffix + right.prefix);

            query(1, 1, N, x1, y1, left);
            query(1, 1, N,y1+1,y2, right);

            if(maximal < left.suffix + right.prefix)
                maximal = left.suffix + right.prefix;

            printf("%d\n",maximal);

        }

    }
}
