#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

#define M 10001
struct Ehephant{
    int W;
    int IQ;
    int id;
}S[M];
bool comp(const Ehephant& a, const Ehephant& b){
    if(a.W != b.W)
        return a.W < b.W;
    return a.IQ > b.IQ;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int N(0), L[M],  ans[M], LIS;

    while(scanf("%d %d", &S[N].W, &S[N].IQ) == 2) {
        S[N].id = N+1;
        N++;
        }
    if(N == 0)return 0;

    sort(S, S + N, comp);
    for(int i = 0; i < N; i++)L[i] = 1;

    for(int i = 1; i < N; i++)
        for(int j = 0; j < i; j++)
            if(S[j].W < S[i].W && S[j].IQ > S[i].IQ) L[i] = max(L[j] + 1, L[i]);
    int pos = 0;
    for(int i = 0; i < N; i++) if(L[i] > L[pos]) pos = i;
    LIS = L[pos];
    printf("%d\n", LIS);
    int top = L[pos] - 1;
    ans[top] = S[pos].id;

    for(int j = pos - 1; j >=0; j--){
        if(L[j] == L[pos] - 1 && S[j].W < S[pos].W && S[j].IQ > S[pos].IQ) {
            ans[--top] = S[j].id;
            pos = j;
        }
    }
    for( int i = 0; i < LIS; i++)printf("%d\n", ans[i]);
    return 0;
}
