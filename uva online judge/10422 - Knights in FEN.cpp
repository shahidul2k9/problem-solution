#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>


using namespace std;

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))

#define INF INT_MAX


#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<vector<int> > vvc;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<int, string> mis;
typedef map<string, string> mss;
typedef map<string, char> msc;

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define R 5
#define C 5
#define SZ R*(C+1)
#define MIN_MOVE 11
int dy[] = {2, 2,-2,-2, 1,-1, 1,-1};
int dx[] = {1,-1, 1,-1, 2, 2,-2,-2};
char g[R][C+1];
char goal[R][C+1] = { "11111", "01111", "00 11", "00001", "00000" };
bool possible;
int ans;
int h(){
    int d = 0;
    FOR(i,0,R-1)
        FOR(j,0,C-1) d +=(g[i][j] != goal[i][j]);
    return d/2;
}
void dfs(int depth, int y, int x){
    if(depth==ans){
        if(memcmp(goal, g, SZ)== 0){possible = true;}
        return;
    }
    if(depth + h()>ans)return;
    if(possible)return;
    FOR(i,0,7){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<R && ny>=0 && nx < C && nx >=0){
            swap(g[ny][nx],g[y][x]);
            dfs(depth+1, ny,nx);
            swap(g[ny][nx],g[y][x]);
        }
    }
}

int main()
{
    /*Runtime 0.024s Rank 196*/
    READ("input.txt");
    //WRITE("output.txt");
    int test,oy,ox;
    scanf("%d",&test);
    getchar();
    while(test--){

        FOR(i,0,R-1)gets(g[i]);

        FOR(i,0,R-1)
            FOR(j,0,C-1)
                if(g[i][j]==' '){oy = i; ox = j;}

        possible = false;
        FOR(i,0,10){
            ans = i;
            dfs(0,oy,ox);
            if(possible)break;
        }
         if(!possible)puts("Unsolvable in less than 11 move(s).");
        else printf("Solvable in %d move(s).\n",ans);
    }


	return 0;
}

/*
#include <iostream>
#include <string.h>
#include <map>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define R 5
#define C 5
#define SZ R*(C+1)
#define MIN_MOVE 10
int dy[] = {2, 2,-2,-2, 1,-1, 1,-1};
int dx[] = {1,-1, 1,-1, 2, 2,-2,-2};
char goal[R][C+1] = { "11111", "01111", "00 11", "00001", "00000" };
bool solvable;
void printState(char g[R][C+1]){
    FOR(i,0,R-1){
        puts(g[i]);
    }
    puts("");
}
struct State{
    char g[R][C+1];
    int y;
    int x;
    int dist;
    State(){}
};
bool operator < (const State& st1, const State& st2){
    return memcmp(st1.g,st2.g,SZ) < 0;
}
inline bool onGrid(int y, int x){
    if(y < 0 || y>=R || x < 0 || x>=C)return false;
    return true;
}
int h(char g[R][C+1]){
    int d =0;
    FOR(i,0,R-1)
        FOR(j,0,C-1)
            d += (g[i][j] != goal[i][j]);
    return d/2;
}

int BFS(State src){
    State u, v;
    queue<State> q;
    map<State,bool> color;
    color[src] = true;
    src.dist = 0;
    q.push(src);
    int nx, ny;
    while(!q.empty()){
        u = q.front();

        //printf("%d\n",u.dist);printState(u.g);
        if(memcmp(goal,u.g, sizeof SZ)==0||u.dist >MIN_MOVE) break;
        q.pop();
        if(u.dist + h(u.g)>MIN_MOVE)continue;

        FOR(i,0,7){
            ny = u.y + dy[i];
            nx = u.x + dx[i];
            if(onGrid(ny, nx)){
                    //memcpy(v.g, u.g, sizeof SZ);
                    v = u;
                    v.y = ny;
                    v.x = nx;
                    v.dist = u.dist + 1;
                    swap(v.g[ny][nx], v.g[u.y][u.x]);
                if(color[v]==false ){
                    q.push(v);
                    color[v] = true;
                }
            }
        }
    }
    if(!q.empty() && memcmp(goal,q.front().g, SZ) == 0 && q.front().dist<=MIN_MOVE)solvable = true;
    else solvable = false;
return q.front().dist;
}
int main()
{
    //Runtime 0.052s Rank 280
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test,dist;
    State ini;
    scanf("%d",&test);
    getchar();
    while(test--){
        FOR(i,0,R-1)gets(ini.g[i]);

        FOR(i,0,R-1)
            FOR(j,0,C-1)
                if(ini.g[i][j]==' ') {ini.y = i; ini.x = j;}

        dist = BFS(ini);


        if(!solvable)puts("Unsolvable in less than 11 move(s).");
        else printf("Solvable in %d move(s).\n",dist);
    }
    return 0;
}
*/

