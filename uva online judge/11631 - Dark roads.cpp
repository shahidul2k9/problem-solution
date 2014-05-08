#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define pb(x) push_back(x)
#define MAXN 200005
typedef  pair<int,int> pii;
// ( w (u, v) ) format
vector< pair< int, pii > > g;
int parent[MAXN];

int findset(int x)
{
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

int kruskal(int e)
{
    int i, pu, pv,total;
    sort(g.begin(), g.end()); // increasing weight
    for(i=total=0; i<e; i++)
    {
        pu = findset(g[i].second.first);
        pv = findset(g[i].second.second);
        if(pu != pv)
        {
            total += g[i].first; // add edge cost
            parent[pu] = parent[pv]; // link
        }
    }
    return total;
}

void reset(int n)
{
    g.clear();
    for(int i=0; i<=n; i++) parent[i] = i;
}


int main()
{
    //freopen("input.txt","r",stdin);
    int i, u, v, w ,n, e,sum;
    while(scanf("%d %d", &n, &e)&&(n!=0||e!=0))
    {
    sum=0;
    reset(n);
    for(i=0; i<e; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        sum+=w;
        g.push_back(pair< int, pii >(w, pii(u, v)));
    }
    printf("%d\n",sum-kruskal(e)); // runs kruskal and construct mst vector
    }
    return 0;
}
