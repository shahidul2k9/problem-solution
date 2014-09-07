#include <iostream>
#include <stdio.h>
using namespace std;
#define INF 500000
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T,t,n,src,des,i,j,k,r,u,v,dist,ans;
    int d[100][100];
    t=0;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&r);
        for(i=0; i<n; i++)
            for(j=0; j<n; j++) {
                if(i==j)d[i][j]=0;
                else
                    d[i][j]=INF;
            }
        for(i=0; i<r; i++) {
            scanf("%d %d",&u,&v);
            d[u][v]=d[v][u]=1;
        }
        for(k=0; k<n; k++)
            for(i=0; i<n; i++)
                for(j=0; j<n; j++) {
                    dist=d[i][k]+d[k][j];
                    if(dist<d[i][j])
                        d[i][j]=dist;
                }
        scanf("%d %d",&src, &des);
        ans=0;
        for(i=0; i<n; i++)
            ans=max(ans,d[src][i]+d[i][des]);
        printf("Case %d: %d\n",++t,ans);
    }
    return 0;
}
