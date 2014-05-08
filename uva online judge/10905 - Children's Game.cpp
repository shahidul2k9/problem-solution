#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

string A[51];
bool comp( const int&  a, const int&  b){

    string x = A[a]+A[b];
    string y = A[b] +A[a];
    for(int i = 0; i < x.length(); i++)
        if(x[i] != y[i]) return x[i] > y[i];
    return true;
}
int main(){
    freopen("input.txt", "r", stdin);

    int H[51];
    int N;
     while(scanf("%d", &N) == 1 && N){
        for( int i = 0; i < N; i++) {
            cin >> A[i];
            H[i] = i;
            }

        sort(H , H + N, comp);

        for(int i = 0; i <N; i++)cout << A[H[i]];
        puts("");
    }
    return 0;
}
