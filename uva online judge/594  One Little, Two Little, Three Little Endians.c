#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, ans;
    while(scanf("%d", &i) == 1){
        ans = 0;
        ans |= (i << 24);
        ans |= ((i & 0x0000FF00) << 8);
        ans |= ((i & 0x00FF0000) >> 8);
        ans |= (i >> 24);
        printf("%d converts to %d\n", i, ans);
    }

	return 0;
}
