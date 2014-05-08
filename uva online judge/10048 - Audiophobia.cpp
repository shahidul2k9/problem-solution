/*
Floyd Warshall
complexcity O(n^3)
*/
#include <climits>
#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 100
#define INF INT_MAX
int d[MAXN][MAXN]; // d[i][j] = distance from i node to j node
int floyd(int n){
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
    return 0;
}
int main(){
    freopen("input.txt","r",stdin);
    int n,e,i,j,u,v,w,q,cs=1; // n=number of nodes,e=number of edges
    while(scanf("%d %d %d",&n,&e,&q)){
    if(n==0&&e==0&&q==0)break;
    for(i=0;i<n;i++) //node number begins from 0 to n-1
        for(j=0;j<n;j++)
            d[i][j]=INF;
for(i=0;i<e;i++){
	scanf("%d %d %d",&u,&v,&w);
	u--;v--;
	d[u][v]=d[v][u]=w; //if graph is bidirectional
}
floyd(n);
int a,b;
if(cs!=1)printf("\n");
printf("Case #%d\n",cs++);
for(i=0;i<q;i++){
    scanf("%d %d",&a,&b);
    a--;b--;
if(d[a][b]==INF)
    printf("no path\n");
    else
    printf("%d\n",d[a][b]);
    }
}
return 0;
}
