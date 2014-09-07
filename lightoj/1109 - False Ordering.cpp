#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int divisors(int n) {
    int d = 0, i =1;
    while(i<=n) {
        if(n%i==0)
            d += 1;
        i++;
    }
    return d;
}

bool com(pair<int,int> a,pair<int,int> b) {
    if(a.first != b.first)return a.first<b.first;
    else return (a.second > b.second );
}

int main() {
    //freopen("input.txt","r",stdin);
    int test, i, n, ctc = 1;
    vector <pair<int, int> > v;
    for(i = 1; i<=1000; i++) {
        v.push_back(make_pair(divisors(i), i));
    }

    sort(v.begin(),v.end(),com);
    scanf("%d",&test);
    while(test--) {
        scanf("%d",&n);
        printf("Case %d: %d\n", ctc++, v[n-1].second);
    }
    return 0;
}
