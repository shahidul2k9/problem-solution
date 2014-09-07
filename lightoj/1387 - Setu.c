#include <stdio.h>
#include <stdlib.h>

int main() {
    //freopen("input.txt","r",stdin);
    int i, test, n, ctc=1, k, account;
    char input[50], type[20];
    scanf("%d",&test);
    while(test--) {
        scanf("%d",&n);
        gets(input);
        account = 0;
        printf("Case %d:\n",ctc++);
        for(i=0; i<n; i++) {
            gets(input);
            if(strlen(input)>6) {
                sscanf(input,"%s %d",type,&k);
                account += k;
            } else {
                printf("%d\n",account);
            }

        }
    }
    return 0;
}
