#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <map>
#include <climits>
using namespace std;
#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )

typedef map<string,int> MSI;
typedef map<int,string> MIS;
typedef vector<vector<int> > VVI;
VVI dist;
#define V 201
#define INF INT_MIN
//int dist[V][V] ;

void floyd(int n){
            FOR(k,1,n)
                FOR(i,1,n)
                    FOR(j,1,n)
                        dist[i][j] = max(dist[i][j],min(dist[i][k],dist[k][j]));
}
int main()
{
    freopen("input.txt","r",stdin);
    int nodes, w, edges, cs=1, ind;
    string st,en;
    while(scanf("%d %d", &nodes, &edges)==2 && nodes!=0){
         ind = 0;
         MSI cit;
         dist = VVI(nodes+1,vector<int> (nodes+1,0));


        FOR(i,1,edges){
            cin >> st >> en >> w;
            if(cit[st]<=0)
                cit[st] = ++ind;
            if(cit[en]<=0)
                cit[en] = ++ind;
            dist[cit[st]][cit[en]] = w;
            dist[cit[en]][cit[st]] = w;
        }
        cin >> st >> en;
        floyd(nodes);
        printf("Scenario #%d\n", cs++);
        printf("%d tons\n\n", dist[cit[st]][cit[en]]);
    }

    return 0;
}
