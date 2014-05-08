/*
Floyd Warshall
complexcity O(n^3)
*/
#include <climits>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define MAXN 100
#define INF INT_MAX
#define NINF INT_MIN
int d[MAXN][MAXN]; // d[i][j] = distance from i node to j node
int floyd(int n){
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                d[i][j]=max(d[i][j],min(d[i][k],d[k][j]));
    return 0;
}
int main(){
    freopen("input.txt","r",stdin);
    int n,e,i,j,u,v,w,cs=0; // n=number of nodes,e=number of edges
   while(scanf("%d %d",&n,&e)){
       if(n==0&&e==0)break;
    for(i=0;i<n;i++) //node number begins from 0 to n-1
        for(j=0;j<n;j++)
            d[i][j]=NINF;
for(i=0;i<e;i++){
	scanf("%d %d %d",&u,&v,&w);
	u--;v--;
	d[u][v]=d[v][u]=w; //if graph is bidirectional
}
floyd(n);
scanf("%d %d %d",&u,&v,&w);
u--;v--;
printf("Scenario #%d\n",++cs);
int trip=ceil((float)w/(d[u][v]-1));
printf("Minimum Number of Trips = %d\n\n",trip);
}
return 0;
}
