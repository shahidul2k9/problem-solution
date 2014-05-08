#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX_NODE 25
int maxPath;
bool g[MAX_NODE][MAX_NODE];
bool taken[MAX_NODE][MAX_NODE];
int m,n;
void goin(int index,int depth){
    int i;
    for(i=0;i<n;i++){
        if(g[index][i]&&!taken[index][i]){
            taken[index][i]=taken[i][index]=true;
            goin(i, depth+1);
            taken[index][i]=taken[i][index]=false;
            }
        else maxPath = max(maxPath,depth);
    }
}
int main()
{
    int st,en,i;
    freopen("input.txt", "r", stdin);
    while(scanf("%d%d", &n, &m)==2&&n&&m){
         memset(g,0,sizeof(g));
        for(i=1;i<=m;i++){
            scanf("%d %d", &st, &en);
            g[st][en]=g[en][st] =true;
            }
        for(i=0;i<n;i++)g[i][i]=false;
            memset(taken,0,sizeof(taken));
            maxPath = 0;
           for(i=0;i<n;i++) goin(i,0);
           /*
           here you must run this loop because because you have to run look up path starting from
           0,1,2,.............,n-1 since you there is no edge from x---x(g[x][x]=false) so first
           time the function deosn't generate all the child of the state space tree.
           */
            printf("%d\n", maxPath);
        }

    return 0;
}
