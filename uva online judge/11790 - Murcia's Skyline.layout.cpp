#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;
typedef vector < int > vi;
int main()
{
    freopen("input.txt", "r", stdin);
    vi  H, W, SUM;

    int  test, N, height, width ,  lisSum, ldsSum, cs = 1;
    scanf("%d", &test);
    while(test--){
        H.clear();
        W.clear();
        SUM.clear();
        scanf("%d", &N);

        for(int i = 0; i < N; i++){
            scanf("%d", &height);
            H.push_back(height);
        }
        for(int i = 0; i <N; i++){
            scanf("%d", &width);
            W.push_back(width);
        }

        for (int i = 0; i < N; i++)SUM.push_back(W[i]);

        for ( int i = 1; i < N; i++)
            for( int j = 0; j < i; j++)
                if(H[i]> H[j]  && SUM[i] < SUM[j] + W[i]){
                    SUM[i] = SUM[j] + W[i];
                }



        int pos = 0;
        for( int i = 1; i < N; i++)if(SUM[i]> SUM[pos]) pos = i;
        lisSum = SUM[pos];


        reverse(H.begin(), H.end());
        reverse(W.begin(), W.end());
        for (int i = 0; i < N; i++)SUM[i] = W[i];

        for ( int i = 1; i < N; i++)
            for( int j = 0; j < i; j++)
                if(H[i]> H[j]  && SUM[i] < SUM[j] + W[i]){
                    SUM[i] =  SUM[j] + W[i];
                }
        pos = 0;
        for( int i = 1; i < N; i++)if(SUM[i]> SUM[pos]) pos = i;
        ldsSum = SUM[pos];

        if(lisSum >= ldsSum)printf("Case %d. Increasing (%d). Decreasing (%d).", cs++, lisSum, ldsSum);
        else printf("Case %d. Decreasing (%d). Increasing (%d).", cs++, ldsSum, lisSum);
        puts("");

    }
    return 0;
}
