#include <cstdio>
#include <string.h>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define N 102
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
 
   // freopen("input.txt","r",stdin);
    int test,cs=1;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
 
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                {scanf("%d",&bp[i][j]);bp[i][j] -=(n+1);}
 
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                {scanf("%d",&gp[i][j]);gp[i][j] -=1;}
 
        memset(engaged,0,sizeof(engaged));
        memset(b_s,-1,sizeof(b_s));
        memset(g_s,-1,sizeof(g_s));
 
        for(int boy = 0;boy<n;boy++){
             if(engaged[boy])continue;
            int girl = bp[boy][++b_s[boy]];
            if(g_s[girl]==-1)
                engage(boy,girl);
            else{
                int dumped_boy = gp[girl][g_s[girl]];
                int curr_boy_rank = getRank(boy,girl);
                int prev_boy_rank = getRank(dumped_boy,girl);
                if(curr_boy_rank<prev_boy_rank){
                    engaged[dumped_boy] = false;
                    engage(boy,girl);
                    boy = dumped_boy;
                    boy--;
                    continue;
 
                }
                else {boy--;continue;}
            }
 
        }
        printf("Case %d: ",cs++);
        for(int i=0;i<n;i++)printf("(%d %d)%c",i+1,bp[i][b_s[i]]+n+1,(i==n-1)?'\n':' ');
    }
}