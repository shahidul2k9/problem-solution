#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MX 1 << 22
#define left(n) n << 1
#define right(n) (n<<1)+1
typedef long long int i64;
int X[30000+10];
int M[MX], A[MX], N;
 
void builtMin(int node, int b, int e){
    if(b == e) {
        M[node] = b;
        return;
    }
    builtMin(left(node), b, (b+e)/2);
    builtMin(right(node), (b+e)/2+1, e);
 
    if(X [M[left(node)] ] < X[ M[right(node)]])
        M[node] = M[left(node)];
        else M[node] = M[right(node)];
}
int queryMin(int node, int b, int e, int i, int j){
    if(b >= i && e <= j) return M[node];
    if(b > j || e < i)return -1;
    int mid = (b+e)/2;
    int l = queryMin(left(node), b, mid, i, j);
    int r = queryMin(right(node), mid+1, e, i, j);
    if(l == -1) return r;
    if(r == -1) return l;
    if(X[l] < X[r])return l;
    return r;
}
 
i64 area(int b, int e){
    if( b > e) return 0;
    if(b == e) return X[b];
    int minIndex = queryMin(1, 1,N, b,e);
    i64 ans = max(area(b, minIndex-1), area(minIndex+1, e));
    return max(ans, (i64)(e-b+1)*X[ minIndex]);
 
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
 
    int test, cs=1;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &N);
        for(int i = 1; i <= N; i++)
            scanf("%d", &X[i]);
        builtMin(1,1,N);
        printf("Case %d: %lld\n", cs++, area(1,N));
    }
    return 0;
}