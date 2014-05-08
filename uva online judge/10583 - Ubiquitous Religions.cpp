#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 50000

     int id [MAXN];    // id[i] = parent of i
     int sz [MAXN];    // sz[i] = number of objects in subtree rooted at i
     int conCom;   // number of components

    // Create an empty union find data structure with N isolated sets.
    void init(int N) {
        conCom = N;
        for (int i = 0; i < N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }

    // Return the number of disjoint sets.

    // Return component identifier for component containing p
    int find(int p) {
        while (p != id[p])
            p = id[p];
        return p;
    }

   // Are objects p and q in the same set?
    bool connected(int p, int q) {
        return find(p) == find(q);
    }


   // Replace sets containing p and q with their union.
    void makeUnion(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) return;

        // make smaller root point to larger one
        if   (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
        else                 { id[j] = i; sz[i] += sz[j]; }
        conCom--;
    }

int main()
{
        int n,m,a,b,i,cs=0;
        while(scanf("%d %d",&n,&m)==2){
        if(n==0&&m==0)break;
        init(n);
        // read in a sequence of pairs of integers (each in the range 0 to N-1),
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            a--;b--;
            makeUnion(a, b);

        }
        printf("Case %d: %d\n",++cs,conCom);
        }
    return 0;
}
