#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int TC,n,r;
    cin >> TC;
    while(TC--) {
        cin >> n;
        r = n/2;
        cout << r << " " << n-r << endl;
    }
    return 0;
}
