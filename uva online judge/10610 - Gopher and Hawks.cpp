#include <string.h>
#include <cstdio>
#include <climits>
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
#include <deque>
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;
#define EPS 1e-15
vector < int > g[1000+5];
int vis[1000+5];
double getDist(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
int  bfs(){
    memset(vis, -1, sizeof(vis));
    queue<int> q;
    vis[0] = 0;
    q.push(0);
    int from, to;
    while ( !q.empty() ){
        from = q.front();q.pop();
        if(from == 1) return vis[1];
        for( int k = 0; k < (int)g[from].size(); k++ ){
            to = g[from][k];
            if(vis[to] == -1){
                vis[to] = vis[from] + 1;
                q.push(to);
            }
        }
    }
    return -1;
}
int main(){
   // freopen("input.txt", "r", stdin);
    int  N, ans;
    double dist, u, d;
    double lis[1000+5][2];
    char stream[200];
    while(scanf("%lf %lf", &u, &d) == 2 && (u + d)){
        gets(stream);
        N = 0;
        while(gets(stream) && strlen(stream) > 0 ){
            sscanf(stream,"%lf %lf", &lis[N][0], &lis[N][1]);
            N++;
        }
        d = d*60*u;
        for ( int i = 0; i < N; i++ )
            for( int k = i + 1; k < N; k++ ){
                dist = getDist(lis[i][0], lis[i][1], lis[k][0], lis[k][1]);
                if(dist  <= d){
                    g[i].push_back(k);
                    g[k].push_back(i);
                    }

            }
        ans = bfs();
        if(getDist(lis[0][0], lis[0][1], lis[1][0], lis[1][1]) < EPS)
            printf("Yes, visiting 0 other holes.\n");
        else if( ans != -1 )
            printf("Yes, visiting %d other holes.\n", ans-1);
        else printf("No.\n");
        for( int k = 0; k < N; k++ )
            g[k].clear();
    }
	return 0;
}
