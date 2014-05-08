
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<sstream>


using namespace std;
#define D 250*250
#define inf 1 << 30
int N;
int s[D+1];

int I[D+1];
int L[D+1];
int lis(){

    for(int i = 1; i<= N; i++)
        I[i] = inf;
    I[0] = -inf;

    int lo, hi, mid, ans;
    ans = 0;
    for(int i = 1; i <= N; i++){
        lo = 0;
        hi = ans;

        while(lo <= hi){
            mid = (lo + hi)/2;
            if( s[i] > I[mid])
                lo = mid + 1;
            else hi = mid - 1;
        }

        I[lo] = s[i];
        ans = max(lo, ans);

    }

    return ans;
}
int main(){
    //freopen("input.txt", "r", stdin);
    int n, p, q, x;
    int test;
    int index[D+1];
    int cs = 0;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d %d", &n, &p, &q);

        memset(index, -1, sizeof(int)*((n*n)+1));
        for(int i = 0; i<= p; i++){
            scanf("%d", &x);
            index[x] = i;
        }

        N = 0;
        for(int i = 0; i <= q; i++){
            scanf("%d", &x);
            if(index[x] != -1){
                s[++N] =index[x];
            }
        }
    /*
    for(int i = 1; i <= N; i++)
        printf("%d ", s[i]);
    puts("");
    */
    printf("Case %d: %d\n",++cs, lis());
    }
}

