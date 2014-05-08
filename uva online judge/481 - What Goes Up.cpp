#include <iostream>
#include <climits>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;


int main()
{
    freopen("input.txt", "r", stdin);
    vector < int > S;
    vector < int > I;
    vector < int > L;
    vector < int > Seq;
    int item, lo, hi, LIS, N, mid , cs = 1;
    int inf = INT_MAX;
    while(scanf("%d", &item) ==1){
        S.push_back(item);
    }


        N = S.size();

        I = vector < int > (N + 1, inf);
        I[0] = -inf;

        LIS = 0;
        for(int i = 0; i < N; i++){
            lo = 0;
            hi = LIS;
            while(lo <= hi){
                //mid = (hi - lo)/2 + lo;
                mid = (hi + lo)/2;
                if( S[i] > I[mid] ) lo = mid + 1;
                else hi = mid - 1;

            }
            I[lo] = S[i];
            if(lo > LIS) LIS = lo;
            L.push_back(lo);
        }


    printf("%d\n-\n", LIS);


    Seq = vector < int > (LIS);
    int i;
    for(i = N-1; i >= 0; i--) if(LIS == L[i])break;
    int top = LIS-1;
    Seq[top] = S[i];
    for(int j = i - 1 ; j >= 0 ; j--){
        if(L[j] == L[i] - 1 && S[j] < S[i]){
            Seq[--top] = S[j];
            i = j;
        }
    }

    for(i = 0; i < LIS; i++ )printf("%d\n", Seq[i]);
    return 0;
}
