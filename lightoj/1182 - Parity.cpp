#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int TC,tc,n;
    tc = 1;
    cin >> TC;
    while(tc<=TC) {
        cin >> n;
        if(__builtin_popcount(n)%2==0)
            printf("Case %d: even\n",tc);
        else printf("Case %d: odd\n",tc);
        tc = tc + 1;
    }
    return 0;
}
