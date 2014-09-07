#include <cstdio>
#include <string.h>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define N 503
int bp[N][N];
int gp[N][N];
int b_s[N];
int g_s[N];
bool engaged[N];
int n;
int getRank(int boy, int girl){
    for(int i=0;i<n;i++)if(gp[girl][i]==boy)return i;
}
inline void engage(int boy, int girl){
    engaged[boy] = true;
    g_s[girl] = getRank(boy,girl);
}

int main(){

   //freopen("input.txt","r",stdin);
    int test,cs=1;
    int x;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);

        for(int i=0;i<n;i++){
            scanf("%d",&x);
            x--;
            for(int j=0;j<n;j++)
                {scanf("%d",&gp[x][j]);gp[x][j]--;}
        }

        for(int i=0;i<n;i++){
            scanf("%d",&x);
            x--;
            for(int j=0;j<n;j++)
                {scanf("%d",&bp[x][j]);bp[x][j]--;}
        }



        memset(engaged,0,sizeof(engaged));
        memset(b_s,-1,sizeof(b_s));
        memset(g_s,-1,sizeof(g_s));

        for(int boy = 0;boy<n;boy++){
            if(engaged[boy])continue;
            int girl = bp[boy][++b_s[boy]];
            if(g_s[girl]==-1)
                engage(boy,girl);
            else{
                int curr_boy_rank = getRank(boy,girl);
                int prev_boy_rank = getRank(gp[girl][g_s[girl]],girl);
                if(curr_boy_rank<prev_boy_rank){
                    int dumped_boy = gp[girl][g_s[girl]];
                    engaged[dumped_boy] = false;
                    engage(boy,girl);
                    boy = dumped_boy;
                    boy--;
                    continue;

                }
                else {boy--;continue;}
            }

        }
        //printf("Case %d: ",cs++);
        for(int i=0;i<n;i++)printf("%d %d\n",i+1,bp[i][b_s[i]]+1);
    }
}
