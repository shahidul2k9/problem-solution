#include <iostream>
#include <cstdio>
#define ST 1002
#define TI 1002
using namespace std;

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int i,j,n;
    int a1[ST];
    int a2[ST];
    int t1[TI];
    int t2[TI];
    int f1[ST],f2[ST];
    int T,t=1;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(i=1; i<=n; i++)
            scanf("%d",&a1[i]);
        for(i=1; i<=n; i++)
            scanf("%d",&a2[i]);
        for(i=1; i<n; i++)
            scanf("%d",&t1[i]);
        for(i=1; i<n; i++)
            scanf("%d",&t2[i]);
        f1[1]=a1[1];
        f2[1]=a2[1];
        for(j=2; j<=n; j++) {
            f1[j]=min(f1[j-1]+a1[j],f2[j-1]+a1[j]+t2[j-1]);
            f2[j]=min(f2[j-1]+a2[j],f1[j-1]+t1[j-1]+a2[j]);
        }

        printf("Case %d: %d\n",t,min(f1[n],f2[n]));
        t++;
    }
    return 0;
}
