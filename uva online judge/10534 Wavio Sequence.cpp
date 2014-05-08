#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <sstream>


using namespace std;

#define M 10001
typedef vector < int > vi;
int main()
{
    freopen("input.txt", "r", stdin);
    stringstream ss;
    string str;
    int S[M], LIS[M], I[M], LDS[M], maxLISLen, maxLDSLen;
    int lo, hi, mid, N, inf, ans;
    inf = INT_MAX;


    while(scanf("%d", &N) == 1){
        for(int i = 0; i < N; i++)
            scanf("%d", &S[i]);


        for(int i = 1; i < N; i++)I[i] = inf;
        I[0] = -inf;

        maxLISLen = 0;
        for( int i = 0; i < N; i++){
            lo = 0;
            hi = maxLISLen;
            while(lo <= hi){
                mid = (hi - lo)/2 + lo;
                if(S[i] > I[mid]) lo = mid + 1;
                else hi = mid - 1;
            }
            I[lo] = S[i];
            LIS[i] = lo;
            if(maxLISLen  < lo) maxLISLen = lo;
        }


        reverse(S, S + N);
        for(int i = 1; i < N; i++)I[i] = inf;
        I[0] = -inf;

        maxLDSLen = 0;
        for( int i = 0; i < N; i++){
            lo = 0;
            hi = maxLDSLen;
            while(lo <= hi){
                mid = (hi - lo)/2 + lo;
                if(S[i] > I[mid]) lo = mid + 1;
                else hi = mid - 1;
            }
            I[lo] = S[i];
            LDS[i] = lo;
            if(maxLDSLen  < lo) maxLDSLen = lo;
        }
        reverse(LDS, LDS + N);
        ans = 1;
        lo = 0; hi = N - 1;
        while(lo <= hi){
           if(LIS[lo] == LDS[hi]){
               ans = max(ans, LIS[lo]);
               lo++;hi--;
           }
           else if(LIS[lo] < LDS[hi]) lo++;
           else hi--;
        }
        printf("%d\n", 2*ans-1);
    }
    return 0;
}
