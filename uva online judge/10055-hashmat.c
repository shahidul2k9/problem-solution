#include<stdio.h>
int main(){
  unsigned long int a,b;
  freopen("1.in","r",stdin);
  while(scanf("%lu %lu",&a,&b)==2){
    if(a>b)
                printf("%lu\n",(a-b));
        else
           printf("%lu\n",b-a);
  }
  return 0;
}
