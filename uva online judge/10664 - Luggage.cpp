#include <cstring>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;

int wt[21];
int C[101];
int divide(int n, int W){
    for(int i = 0; i<= W; i++)C[i] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = W; j > 0; j--)
            if(wt[i] <= j) C[j] = max(C[j], wt[i] + C[j - wt[i]]);
    return C[W];
}
int main()
{
    int test, el, i, sum;
    string s;
    stringstream ss;
    scanf("%d", &test);getline(cin,s);
    while(test--){
        getline(cin,s);
        ss.clear();
        ss << s;
        i = 0;
        sum = 0;
        while(ss >> el){
            wt[++i] = el;
            sum += el;
        }
        if((sum & 1 )==0) {
            if(divide(i, sum >> 1) == (sum >> 1))puts("YES");
            else puts("NO");
        }
        else puts("NO");

    }
    return 0;
}
