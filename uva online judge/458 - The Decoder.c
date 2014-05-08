#include <stdio.h>
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    char ch;
    int t;
    while(scanf("%c",&ch)==1){
        if(ch!='\n')printf("%c",ch-7);
        else printf("\n");
    }
    return 0;
}
