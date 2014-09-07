#include <stdio.h>
#include <math.h>
int main() {
    int T,n,lie,i,a[12],t=0;
    a[0]=2;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(i=1; i<=n; i++) {
            scanf("%d",&a[i]);
        }
        for(i=0,lie=0; i<n; i++) {
            if(a[i+1]>a[i])lie+=ceil(((double)a[i+1]-a[i])/5);
        }
        printf("Case %d: %d\n",++t,lie);
    }

    return 0;
}
