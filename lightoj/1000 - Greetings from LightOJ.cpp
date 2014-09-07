#include <stdio.h>
#include <stdlib.h>

int main() {
    int TC,tc,a,b;
    scanf("%d",&TC);
    tc = 1;
    while(tc<=TC) {
        scanf("%d%d",&a,&b);
        printf("Case %d: %d\n",tc,(a+b));
        tc++;
    }
    return 0;
}
