#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
#define W 20
#define H 20
char g[W][H];
bool vis[W][H];
int lands,r,c;
bool isOnGrid(int i, int j) {
    return (i>=0&&j>=0&&i<r&&j<c);
}
void bfs(int x,int y) {
    lands=1;
    int i,j;
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            vis[i][j]=false;
    queue< pair<int,int> >q;
    pair <int,int> p;
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
            if(g[x][y]=='.'&&vis[x][y]==false) {
                lands++;
                vis[x][y]=true;
                q.push(make_pair(x,y));
            }
        }
        x=p.first;
        y=p.second-1;
        if(isOnGrid(x,y)) {
            if(g[x][y]=='.'&&vis[x][y]==false) {
                lands++;
                vis[x][y]=true;
                q.push(make_pair(x,y));
            }
        }
        x=p.first-1;
        y=p.second;
        if(isOnGrid(x,y)) {
            if(g[x][y]=='.'&&vis[x][y]==false) {
                lands++;
                vis[x][y]=true;
                q.push(make_pair(x,y));
            }
        }
        x=p.first+1;
        y=p.second;
        if(isOnGrid(x,y)) {
            if(g[x][y]=='.'&& vis[x][y]==false) {
                lands++;
                vis[x][y]=true;
                q.push(make_pair(x,y));
            }
        }
    }
}
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test,cs=0,i,j,x,y;
    char buf[W+1];
    scanf("%d",&test);
    while(test--) {
        scanf("%d %d",&c,&r);
        getchar();

        for(i=0; i<r; i++) {
            gets(buf);
            for(j=0; j<c; j++) {
                g[i][j]=buf[j];
                if(g[i][j]=='@') {
                    x=i;
                    y=j;
                }
            }
        }

        bfs(x,y);
        printf("Case %d: %d\n",++cs,lands);
    }
    return 0;
}
