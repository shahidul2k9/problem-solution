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

typedef vector < int > vi;
int main()
{
    freopen("input.txt", "r", stdin);
    stringstream ss;
    string str;
    vi S, L, I, Seq;
    int lo, hi, mid, LIS, test, N, inf, item;
    inf = INT_MAX;

    scanf("%d", &test);getline(cin, str);
    getline(cin, str);
    while(test--){
        L.clear();
        S.clear();
        I.clear();
        Seq.clear();
        while(getline(cin, str) && str.size()> 0){
            ss.clear();
            ss << str;
            ss >> item;
            S.push_back(item);
        }
        N = S.size();
        I = vi( N + 1, inf);
        I[0] = -inf;

        LIS = 0;
        for( int i = 0; i < N; i++){
            lo = 0;
            hi = LIS;
            while(lo <= hi){
                mid = (hi - lo)/2 + lo;
                if(S[i] > I[mid]) lo = mid + 1;
                else hi = mid - 1;
            }
            I[lo] = S[i];
            L.push_back(lo);
            if(LIS  < lo) LIS = lo;

        }

        Seq = vi(LIS);
        int i, top;
        for( i = N - 1; i >= 0; i--)
            if(L[i] == LIS)break;
        top = LIS - 1;
        Seq[top] = S[i];

        for( int j = i -1; j >= 0; j--){
            if(L[j] == L[i] -1 && S[j] < S[i]) {
                Seq[--top] = S[j];
                i = j;
            }
        }
        printf("Max hits: %d\n", LIS);
        for( i = 0; i < LIS; i++)printf("%d\n", Seq[i]);
        if(test) puts("");

    }
    return 0;
}
