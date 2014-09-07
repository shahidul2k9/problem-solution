#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define edge pair< int, int >
#define MAXN 105
// ( w (u, v) ) format
vector< pair< int, edge > > g;
int parent[MAXN], total, n, e;

int findset(int x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

int kruskal(bool check) {
    total =0;
    int i, pu, pv;
    sort(g.begin(), g.end()); // increasing weight
    if(check==1)reverse(g.begin(),g.end());
    for(i=total=0; i<g.size(); i++) {
        pu = findset(g[i].second.first);
        pv = findset(g[i].second.second);
        if(pu != pv) {

            total += g[i].first; // add edge cost
            parent[pu] = parent[pv]; // link
        }
    }
    return total;
}
int main() {
    //freopen("input.txt","r",stdin);
    int i, u, v, w,test,max,min,sum,cs=0;
    scanf("%d",&test);
    while(test--) {

        scanf("%d",&n);
        for(;;) {
            scanf("%d %d %d", &u, &v, &w);
            if(u==0&&v==0&&w==0)break;
            g.push_back(pair< int, edge >(w, edge(u, v)));
        }
        for(i=0; i<=n; i++)
            parent[i]=i;
        min=kruskal(0); // runs kruskal and construct MST vector
        for(i=0; i<=n; i++)
            parent[i]=i;
        max=kruskal(1);
        sum=max+min;
        if(sum%2==0)printf("Case %d: %d\n",++cs,sum/2);
        else
            printf("Case %d: %d/2\n",++cs,sum);
        //printf("%d %d ",max,min);
        g.clear();
    }
    return 0;
}
