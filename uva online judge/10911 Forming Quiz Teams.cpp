#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <climits>
#define IS_ON(pos, bitmask) (1 << pos) & bitmask
#define ON(pos, bitmask)  bitmask |= (1 << pos)
//#define OFF(pos, bitmask)  bitmask ^= (1 << pos)
#define OFF(pos, bitmask)  bitmask &= (~(1 << pos))
using namespace std;
    int N;
    string name;
    int x, y;
    int px[16];
    int py[16];
    double memo[1 << 16];
    bool visit[1 << 16];
double dist2d(int i, int j){
    return sqrt( (double)pow(px[i] - px[j], 2 ) + pow(py[i] - py[j], 2));
}
double solve( int state ){
    if( visit[state] ) return memo[state];
    double ans = double(1 << 30);
    double cur, d;
    for( int i = 0; i < 2*N; i++ ){
        if( IS_ON(i, state) )continue;
        for(int j = i + 1; j < 2*N; j++ ){
                if( IS_ON(j, state) )continue;

                d = dist2d(i, j);
                ON(i, state);
                ON(j, state);

                cur =   solve(state) + d;
                ans = min(ans, cur);
                OFF(i, state);
                OFF(j, state);
        }
    }

    visit[state] = true;
    return memo[state] = ans;
}
int main(){
    //freopen("input.txt", "r", stdin);
    int cs = 1;
    while( scanf("%d", &N) == 1 && N){
        for( int i = 0; i < 2*N; i++ )
            cin >> name >> px[i] >> py[i];

        memset(visit, false, sizeof(visit));
        visit[ (1 << (2*N)) - 1] = true;
        memo[ (1 << (2*N)) - 1] = 0;

        printf("Case %d: %.2lf\n", cs++, solve(0));
    }


    return 0;
}
