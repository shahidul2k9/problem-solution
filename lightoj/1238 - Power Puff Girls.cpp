#include <iostream>
#include <cstdio>
#include <climits>
#include <queue>
using namespace std;
#define M 21
#define N 21
#define INF INT_MAX
char g[M][N];
int dist[M][N];
bool color[M][N];
int row,col;
int dr[]= {0,-1, 0,1};
int dc[]= {1, 0,-1,0};
void bfs(int x,int y) {
    int i,j;
    for(i=0; i<row; i++)
        for(j=0; j<col; j++) {
            dist[i][j]=INF;
            color[i][j]=false;
        }
    dist[x][y]=0;
    color[x][y]=true;
    queue< pair<int,int> > q;
    int prex,prey;
    q.push(make_pair(x,y));
    while(!q.empty()) {
        prex=q.front().first;
        prey=q.front().second;
        q.pop();
        for(i=0; i<4; i++) {
            x = prex + dr[i];
            y = prey + dc[i];
            if(x>-1&&x<row&&y>-1&&y<col&&g[x][y]!='#'&&g[x][y]!='m'&&color[x][y]==false) {
                dist[x][y] = min(dist[prex][prey]+1,dist[x][y]);
                color[x][y]=true;
                q.push(make_pair(x,y));
            }
        }
    }

}
int main() {
    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int test,cs=0,i,j,ax,ay,bx,by,cx,cy,hx,hy;
    scanf("%d",&test);
    while(test--) {
        scanf("%d %d",&row,&col);
        gets(g[0]);
        for(i=0; i<row; i++)gets(g[i]);

        for(i=0; i<row; i++)
            for(j=0; j<col; j++) {
                if(g[i][j]=='a') {
                    ax=i;
                    ay=j;
                } else if(g[i][j]=='b') {
                    bx=i;
                    by=j;
                } else if(g[i][j]=='c') {
                    cx=i;
                    cy=j;
                } else if(g[i][j]=='h') {
                    hx=i;
                    hy=j;
                }
            }



        bfs(hx,hy);
        printf("Case %d: %d\n",++cs,max(max(dist[ax][ay],dist[bx][by]),dist[cx][cy]));
    }
    return 0;
}
