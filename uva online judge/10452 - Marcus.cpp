#include <iostream>
#include <cstdio>
#define M 8
#define N 8
#include <queue>
using namespace std;
int r,c;
inline bool isOnGrid(int i, int j){
    return (i>=0&&j>=0&&i<r&&j<c);
}
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    char g[M][N];
    int test,i,j,x,y,px,py;;
    char buf[M+1];
    char com[M]="IEHOVA#";
    scanf("%d",&test);
    while(test--){
        scanf("%d %d",&r,&c);
        getchar();
        for(i=0;i<r;i++){
                 gets(buf);
            for(j=0;j<c;j++)g[i][j]=buf[j];
        }
       for(i=0;i<c;i++)
            if(g[r-1][i]=='@'){px=r-1;py=i;}

        for(i=0;i<7;i++){
        x=px;
        y=py+1;//right
        if(isOnGrid(x,y)&&g[x][y]==com[i]){
           printf("right");
           if(i!=6)printf(" ");
           px=x;
           py=y;
           continue;
           }
        x=px;
        y=py-1;;//left
        if(isOnGrid(x,y)&&g[x][y]==com[i]){
           printf("left");
           if(i!=6)printf(" ");
           px=x;
           py=y;
           continue;
           }

        x=px-1;//forth
        y=py;
        if(isOnGrid(x,y)&&g[x][y]==com[i]){
           printf("forth");
           if(i!=6)printf(" ");
           px=x;
           py=y;
           continue;
           }
        }
    printf("\n");
    }
    return 0;
}
