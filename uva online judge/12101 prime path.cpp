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
#include <algorithm>
#include <numeric>
#include <sstream>


using namespace std;

#define MA 9999
#define NODES 1061
vector < int > g[NODES];
bitset < MA + 1 > sieve;
vector < int > ls;
map < int, int > hash;
int dist[NODES+1];
int bfs(int src , int dest){
    queue < int > q;
    memset(dist, -1, sizeof(dist));
    dist[src] = 0;
    q.push(src);
    int from, to;
    while(!q.empty()){
        from = q.front();q.pop();
        if( from == dest ) return dist[dest];
        for( int i = 0; i < (int) g[from].size(); i++ ){
            to = g[from][i];
            if( dist[to] == -1 ) {
                dist[to] = dist[from] + 1;
                q.push(to);
            }
        }
    }
    return INT_MAX;
}
bool isonedif(int a, int b ){
    int d = 0;
    for( int  i = 0; i < 4; i++ ){
        if(a%10 != b%10) d++;
        a /= 10;
        b /= 10;
    }
    return d == 1;
}
int main(){
    sieve.flip();sieve.reset(0);sieve.reset(1);
    for( int i = 2; i <= MA; i++ ){
        if( sieve.test(i)){
            if( i > 999 ) ls.push_back(i);
        for( int k = i + i; k <= MA; k += i )
            sieve.reset(k);
        }
    }
    for( int i = 0; i < (int)ls.size(); i++ ) hash[ls[i]] = i;

    for( int from = 0; from < (int)ls.size(); from++ )
        for( int to = from + 1; to < (int) ls.size(); to++ )
            if( isonedif(ls[from], ls[to])){
            g[from].push_back(to);
            g[to].push_back(from);
            }
    int test, a, b, ans;
    scanf("%d", &test);
    while( test-- ){
        scanf("%d %d", &a, &b);
        ans = bfs(hash[a], hash[b]);
        if( ans == INT_MAX)
            printf("Impossible\n");
        else
            printf("%d\n", ans);

    }
	return 0;
}
