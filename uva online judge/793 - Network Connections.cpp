#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 10000

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
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        int n,a,b,test,success,fail;
        char ch,buffer[100];
        scanf("%d",&test);
        while(test--){
        scanf("%d",&n);
        getchar();
        init(n);
        success=fail=0;
        buffer[0]='1';
        while (gets(buffer)) {
                if(buffer[0]==NULL)break;
                sscanf(buffer,"%c %d %d",&ch,&a,&b);
                a--;b--;
                if(ch=='c')  makeUnion(a, b);
                else if (connected(a, b)) success++;
                else fail++;
        }
        printf("%d,%d\n",success,fail);
        if(test!=0)printf("\n");
    }
    return 0;
}
