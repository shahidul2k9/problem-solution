#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
    int n,p,q,t,ct,i,w,x;
    vector<int> v;
    scanf("%d",&t);
    ct = 1;
    w = 0;
    while(ct<=t) {
        scanf("%d%d%d",&n,&p,&q);
        for(i = 0; i<n; i++) {
            scanf("%d",&x);
            v.push_back(x);
        }
        for(i = 0; i<n; i++) {
            w = w + v[i];
            if(i>=p||w>q)break;
        }
        printf("Case %d: %d\n",ct,i);
        ct = ct + 1;
        w = 0;
        v.clear();
    }
    return 0;
}
