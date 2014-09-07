#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    //freopen("input.txt","r",stdin);
    vector < int > v;
    int test, i, y, z, element, ctc=1, n, q;
    char command;
    int d;
    scanf("%d",&test);
    while(test--) {
        scanf("%d %d", &n, &q);
        v.clear();
        for(i=0; i < n; i++)scanf("%d",&element),v.push_back(element);
        while(q--) {
            command = getchar();
            command = getchar();
            switch(command) {
            case 'S':
                scanf("%d",&d);
                for(i=0; i<n; i++)v[i] +=d;
                break;
            case 'M':
                scanf("%d",&d);
                for(i=0; i<n; i++)v[i] *=d;
                break;

            case 'D':
                scanf("%d",&d);
                for(i=0; i<n; i++)v[i] /=d;
                break;
            case 'R':
                reverse(v.begin(),v.end());
                break;
            case 'P':
                scanf("%d %d",&y, &z);
                swap(v[y],v[z]);
                break;
            default:
                break;
            }

        }
        printf("Case %d:\n", ctc++);
        for(i=0; i<n; i++)
            printf("%d%c", v[i],i==n-1?'\n':' ');
    }
    return 0;
}
