#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <climits>
#include <utility>
#include <cmath>
using namespace std;
int main(){
    int x;
    bool ok = true;
    while(scanf("%d", &x) == 1){
        if(ok){
            if(x == 42) ok = false;
            else printf("%d\n", x);
        }
    }
return 0;
}
