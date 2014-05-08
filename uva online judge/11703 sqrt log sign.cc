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
int seq[1000001];
int evilF(int i){
    if(seq[i] != -1)
        return seq[i];
    int r, l, s;
    r = i - sqrt((double)i);
    l = log(i);
    s = i*pow(sin(i),2);
    seq[i]= (evilF(r) + evilF(l) + evilF(s))%1000000;
    return seq[i];

}
int main(){
    //freopen("input.txt", "r", stdin);
    int i;
    memset(seq, -1, sizeof(seq));
    seq[0] = 1;
    while(scanf("%d", &i) && i != -1){
        if(seq[i] == -1) evilF(i);
        printf("%d\n", seq[i]);
    }

    return 0;
}
