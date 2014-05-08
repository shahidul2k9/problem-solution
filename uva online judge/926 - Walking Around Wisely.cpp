#include <algorithm>
#include <bitset>

#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;
    int N, W;
struct Man{
    bool BW, BS;
    Man(){   BW = BS = false;    }

};
long long int w[31][31];
Man m[32][32];

long long int ways(int x, int y){
    if(x < 1 || y < 1)
        return 0;
    if(w[x][y] != -1) return w[x][y];

    long long int fs, fw;

    if(  m[x][y].BW ) fw = 0;
        else fw = ways(x - 1, y);

    if( m[x][y].BS ) fs = 0;
        else fs = ways(x, y - 1);


        w[x][y] =  fs + fw;
    return w[x][y];
}
int main(){
     //freopen("input.txt", "r", stdin);

        //freopen("output.txt", "w", stdout);

        int test;
        char ch;
        int x, y, dx, dy;
        Man empty;
        scanf("%d", &test);
        while(test--){
            scanf("%d", &N);

            for(int i = 1; i <= N; i++)
                for(int j = 1; j <= N; j++){
                    w[i][j] = - 1;
                    m[i][j] = Man();
                }

            scanf("%d %d", &x, &y);
            w[x][y] = 1;
            scanf("%d %d", &dx, &dy);
            scanf("%d", &W);
            for(int i = 0;i < W; i++){
                scanf("%d %d", &x, &y);
                cin >> ch;
                if(ch == 'N'){
                    m[x][y+1].BS = true;
                }

                else if(ch == 'S'){
                     m[x][y].BS = true;
                     }
                else if(ch == 'E'){
                    m[x + 1][y].BW = true;
                }
                else
                    m[x][y].BW = true;

            }
            /*
            for(int i = 1; i <= N; i++){
                for(int j = 1; j <= N; j++){
                    printf("%d %d   ", m[i][j].BW, m[i][j].BS);
                }
            puts("");
            }
            */
            printf("%lld\n", ways(dx, dy));

        }

    return 0;
}
