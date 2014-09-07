#include <iostream>
#include <cstdio>
#define M 501
#define N 501
#include <queue>
using namespace std;
char g[M][N];
bool vis[M][N];
int crystall,r,c;
inline bool isOnGrid(int i, int j) {
    return (i>=0&&j>=0&&i<r&&j<c);
}
void bfs(int x,int y) {
    int i,j;
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            vis[i][j]=false;
    queue< pair<int,int> >q;
    pair <int,int> p;
    if(g[x][y]=='C')crystall++;
    q.push(make_pair(x,y));
    vis[x][y]=true;
    while(!q.empty()) {
        p =q.front();
        q.pop();
        int x;
        int y;
        x=p.first;
        y=p.second+1;
        if(isOnGrid(x,y)) {
            if(g[x][y]!='#'&&vis[x][y]==false) {
                if(g[x][y]=='C')crystall++;
                vis[x][y]=true;
                q.push(make_pair(x,y));
            }
        }
        x=p.first;
        y=p.second-1;
        if(isOnGrid(x,y)) {
            if(g[x][y]!='#'&&vis[x][y]==false) {
                if(g[x][y]=='C')crystall++;
                vis[x][y]=true;
                q.push(make_pair(x,y));
            }
        }
        x=p.first-1;
        y=p.second;
        if(isOnGrid(x,y)) {
            if(g[x][y]!='#'&&vis[x][y]==false) {
                if(g[x][y]=='C')crystall++;
                vis[x][y]=true;
                q.push(make_pair(x,y));
            }
        }
        x=p.first+1;
        y=p.second;
        if(isOnGrid(x,y)) {
            if(g[x][y]!='#'&&vis[x][y]==false) {
                if(g[x][y]=='C')crystall++;
                vis[x][y]=true;
                q.push(make_pair(x,y));
            }
        }
    }
}
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test,cs=0,q,i,j,x,y;
    int store[M][N];
    char buf[M];
    scanf("%d",&test);
    while(test--) {
        scanf("%d %d %d",&r,&c,&q);
        getchar();
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                store[i][j]=-1;
        for(i=0; i<r; i++) {
            gets(buf);
            for(j=0; j<c; j++)g[i][j]=buf[j];
        }
        printf("Case %d:\n",++cs);
        for(i=0; i<q; i++) {
            scanf("%d %d",&x,&y);
            x--;
            y--;
            if(store[x][y]!=-1)printf("%d\n",store[x][y]);
            else {
                crystall=0;
                bfs(x,y);
                printf("%d\n",crystall);
                for(int k=0; k<r; k++)
                    for(j=0; j<c; j++)
                        if(vis[k][j]==true)store[k][j]=crystall;
            }

        }

    }
    return 0;
}
