#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;


int main()
{
    freopen("input.txt", "r", stdin);
vector < int > S;
vector < int > I;
    int item, lo, hi, LIS, N, mid , cs = 1;
    int inf = 1 << 25;
    bool blank = false;
    while(scanf("%d", &item) == 1 && item != -1){
        S.clear();
        I.clear();
        S.push_back(item);
        while(scanf("%d", &item)==1 & item != -1)
            S.push_back(item);

        N = S.size();
        reverse(S.begin(), S.end());
        I = vector < int > (N + 1, inf);
        I[0] = -inf;

        LIS = 0;
        for(int i = 0; i < N; i++){
            lo = 0;
            hi = LIS;
            while(lo <= hi){
                mid = (hi - lo)/2 + lo;
                if( S[i] >= I[mid] ) lo = mid + 1;
                else hi = mid - 1;

            }
            I[lo] = S[i];
            if(lo > LIS) LIS = lo;

        }
        if(blank)puts("");
        blank = true;
        printf("Test #%d:\n", cs++);
        printf("  maximum possible interceptions: %d\n", LIS);
    }
    return 0;
}
