#include <algorithm>
#include <bitset>

#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main(){

    int test;
    int N, ans;
    int A[101];
    string line;
    stringstream ss;
    scanf("%d", &test);
    getline(cin, line);

    while(test--){
        getline(cin, line);
        ss.clear();
        ss << line;
        N = 0;

        while(ss >> A[N])N++;

        ans = 0;

        for(int i = 0; i <N; i++)
            for(int j = i+1; j < N; j++)
                ans = max(ans, gcd(A[i], A[j]));
        printf("%d\n", ans);
    }
    return 0;
}
