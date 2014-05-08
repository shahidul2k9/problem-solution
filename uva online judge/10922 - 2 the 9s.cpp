#include <stdio.h>
#include <cstdio>
#include <climits>
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
#include <string.h>
#include <sstream>
using namespace std;
inline bool ismul(int n ){
    return n % 9 == 0;
}
int main(){
    //freopen("input.txt", "r", stdin);
    char seq[1001];
    int degree, ans, sum, len;
    while(true){
        len = strlen(gets(seq));
        if(len == 1 && seq[0] == '0')break;
        ans = degree = 0;
        for(int i = 0; i < len; i++ )
            ans += seq[i] - '0';
    sum = ans;
    while(ismul(ans)){
        degree += 1;
        if(ans == 9)break;
        sum = 0;
        while(ans){
            sum += ans%10;
            ans /= 10;
        }
        ans = sum;
    }
    if(degree)printf("%s is a multiple of 9 and has 9-degree %d.\n", seq, degree);
    else printf("%s is not a multiple of 9.\n", seq);

    }
    return 0;
}
