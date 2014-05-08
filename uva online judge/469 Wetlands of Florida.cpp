#include <iostream>
#include <cstdio>
#define M 100
#define N 100
#include <queue>
#include <string.h>
using namespace std;
char g[M][N];
int crystall,r,c;
int dr[]={0,-1,-1,-1, 0, 1, 1,1};
int dc[]={1, 1, 0,-1,-1,-1, 0,1};
inline bool isOnGrid(int i, int j){
    return (i>=0&&j>=0&&i<r&&j<c);
}
int floodFill(int x,int y,char ch,char fil){

    int i;
    if(!isOnGrid(x,y))return 0;
    if(g[x][y]!=ch)return 0;

    int ans=1;
    g[x][y]=fil;
    for(i=0;i<8;i++){
    ans +=floodFill(x+dr[i],y+dc[i],ch,fil);
    }
    return ans;
}
int main()
{
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test,i,x,y;
    char buf[M+1];
    scanf("%d",&test);getchar();
    gets(buf);
    while(test--){
        for(i=0;1;i++){
        gets(buf);
        if(buf[0]!='W'&&buf[0]!='L')break;
        sscanf(buf,"%s",g[i]);
        }
        r = i;
        c = strlen(g[0]);
        sscanf(buf,"%d %d",&x,&y);
        while(1){
            printf("%d\n",floodFill(x-1,y-1,'W','.'));
            floodFill(x-1,y-1,'.','W');
            gets(buf);
            if(strcmp(buf,"")==0||feof(stdin))break;
            sscanf(buf,"%d %d",&x,&y);
        }
        if(test)printf("\n");
    }
    return 0;
}
