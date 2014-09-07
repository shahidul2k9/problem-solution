#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <climits>
#include <utility>
#include <cmath>
using namespace std;


#define MAX  100000
const int  MAX_SEG  = 262144+1;
int A[MAX + 1], S[MAX + 2], lo[MAX + 1 ], hi[MAX + 1];
int  M[MAX_SEG];

int N, Q;

int built(int node, int b, int e){
    if(b == e) return M[node] = A[b];
    int mid = (b+e)/2;
    int left = node << 1;
    int right = left + 1;

    M[left] = built( left,  b,  mid );
    M[right] = built( right , mid + 1, e );

    return M[node] = max(M[left], M[right]);


}
int query(int node, int b, int e, int i, int j){
    if(b >= i && e <= j) return M[node];
    if(b > j || e < i) return -1;

    int left = query(2*node, b, (b + e)/2, i, j);
    int right = query(2*node+1, (b + e)/2 + 1, e, i, j);
    if(left == -1) return right;
    if(right == -1 )return left;
    return max(left, right);

}
int main(){
    //freopen("input.txt", "r", stdin);
    int st, en;
    while(scanf("%d", &N) == 1&& N){
        scanf("%d", &Q);
        for(int i = 1; i <= N; i++)
            scanf("%d", &S[i]);

        {
            st = 1;
            S[N+1] = INT_MIN;
        }
        for(int i = 1; i <= N + 1; i++){

            if(S[i] != S[i+1]){
                int width = i - st + 1;
                for(int j = st; j <= i; j++){
                    A[j] = width;
                    lo[j] = st;
                    hi[j] = i;
                }
                st = i + 1;
            }
        }


        int i, j, ans;
        built(1, 1, N);
        while(Q--){
            scanf("%d %d", &st, &en);
            ans = 0;
            i = hi[st] + 1;
            j = lo[en] - 1;

            if(hi[st] <= en) ans = max(hi[st] - st +1, ans);
            else ans = max(ans, en - st + 1);

            if(lo[en] >= st) ans = max(en - lo[en] + 1, ans);
            else ans = max(ans, en - st + 1);

            if(i < j) ans = max(query(1, 1, N, i, j), ans);
            printf("%d\n", ans);
        }
    }
    return 0;
}
