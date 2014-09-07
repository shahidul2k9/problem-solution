#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(pair< int, string> a, pair<int, string> b) {
    return a.first<b.first;
}
int main() {
    //freopen("input.txt","r",stdin);
    vector < pair<int, string > > v;
    int w,h,l, i, test, n, ctc=1;
    string name;
    scanf("%d",&test);
    while(test--) {
        scanf("%d",&n);
        v.clear();
        for(i=0; i<n; i++) {
            cin >> name;
            scanf("%d %d %d",&l, &w, &h);
            v.push_back(make_pair((l*w*h),name));
        }
        sort(v.begin(),v.end(),comp);
        printf("Case %d: ",ctc++);
        if(v[0].first<v[n-1].first)printf("%s took chocolate from %s\n", (v[n-1].second).c_str(), (v[0].second).c_str());
        else printf("no thief\n");
    }
    return 0;
}
