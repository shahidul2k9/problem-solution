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

#define NODES 30
int M[NODES][NODES];
int N, E;
/*This gets WA
void floyd(){
    FOR(k, 0, N)
        FOR(i, 0, N)
            FOR(j, 0, N){
                if( (M[i][k]*M[k][j] *M[j][i]) != 0  || (M[i][k] < 0 && M[k][j] < 0))
                    M[i][j]  = -1;

                else if(M[i][k] > 0 && M[k][j] > 0) M[i][j] += M[i][k] * M[k][j];

              else if( (M[i][k] < 0 && M[k][j] >0) ||(M[i][k] > 0  && M[k][j] <0)  )  M[i][j]   = -1;

            }
}
*/
void modifiedFloyd(){
    FOR(k,0,N)
        FOR(i,0,N)
            FOR(j,0,N)
                if(M[i][k]>0 && M[k][j]>0)M[i][j] += M[i][k]*M[k][j];
    FOR(k, 0, N)
        if(M[k][k] != 0)
            FOR(i, 0, N)
                FOR(j, 0, N)
                    if(M[i][k] * M[k][j] != 0) M[i][j] = -1;

}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int st, en, cs=0;
    while(scanf("%d", &E) == 1){
        memset(M, 0, sizeof M);
        N = -1;
        FOR(i, 1, E){
            scanf("%d %d", &st, &en);
            M[st][en] = 1;
            N = max(N, st);
            N = max(N, en);
        }
        modifiedFloyd();
        printf("matrix for city %d\n", cs++);
        FOR(i, 0, N)
            FOR(j,0, N)printf("%d%c", M[i][j], (j == N ) ? '\n' : ' ');


    }
	return 0;
}
