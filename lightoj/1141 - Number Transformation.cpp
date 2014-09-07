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
int S, T;
vector < int > pf[1001];
void primefactor( int n){
    int ind = n;
    int div = 2;
    int add = 0 ;
    while(n > 1){
        add = 0;
        while( n % div == 0 ){
            add = div;
            n /= div;
        }
        div += 1;
        if( add ) pf[ind].push_back(add);
    }
    if( add == ind ) pf[ind].clear();
}
int bfs( ){
    int dist[1001];
    memset(dist, -1, sizeof(dist));
    dist[S] = 0;
    queue < int > q;
    q.push(S);
    int from, to;
    while( !q.empty() ){
        from = q.front();
        q.pop();
        for( int i = 0; i < (int) pf[from].size(); i++ ){
            to = from + pf[from][i];
            if( to <= T && dist[to] == -1 ) {
                q.push(to);
                dist[to] = dist[from] + 1;
                if( to  == T) return dist[T];
            }
        }
    }
    return dist[T];
}
int main(){
 
    int test;
    int cs = 1;
   //freopen("input.txt", "r", stdin);
   for( int i = 2; i <= 1000; i++ ) primefactor(i);
   scanf("%d", &test);
    while( test-- ){
        scanf("%d %d", &S, &T);
        printf("Case %d: %d\n", cs++, bfs());
    }
 
 
 
 
    return 0;
}