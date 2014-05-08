#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 105
int dx[] = {0, 0, 1, -1, 1,-1,1,-1};
int dy[] = {1, -1, 0, 0, 1,-1,-1,1};
int m,n;
bool isSafe(int x, int y){
    if(x<0||y<0||x>=m||y>=n)return false;
    return true;
}
int main()
{
   // freopen("input.txt", "r" , stdin);
    char buf[MAX][MAX];
    int out[MAX][MAX];
    int x,y,i,j,k,cs=0;
    bool BLANK = false;

    while(scanf("%d %d",&m, &n)==2&& m){
        gets(buf[0]);

        for(i=0;i<m;i++)gets(buf[i]);
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)out[i][j]=0;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++){
                if(buf[i][j]=='*'){
                    for(k=0;k<8;k++){
                        x= i+dx[k];
                        y = j+dy[k];
                        if(isSafe(x,y))out[x][y] +=1;
                    }
                }
            }

    if(BLANK)printf("\n");
     printf("Field #%d:\n",++cs);
    BLANK=true;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(buf[i][j]=='*')printf("*");
            else
            printf("%d",out[i][j]);
            }
        printf("\n");
        }
    }
    return 0;
}
