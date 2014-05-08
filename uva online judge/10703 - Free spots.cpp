

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

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))

#define INF INT_MAX


#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long ll;
typedef unsigned int u32;
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

typedef pair <int, int > pii;
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define SQR(x) ((x)*(x))
#define PI 2*acos(0)
#define EPS 1e-7
#define MAX 500

#define R 500
#define C 500
int main(){
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    bool A[R+1][C+1];
    int w, h, n, x1, x2, y1, y2, a, b, c, d, ans;

    while(scanf("%d %d %d", &w, &h, &n) == 3 && w){

        memset(A, false, sizeof(A));

        for(int k = 1; k <= n; k++){
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            a = min(x1, x2);
            c = max(x1, x2);

            b = min(y1, y2);
            d = max(y1,y2);

            for(int i = a; i <= c; i++)
                for(int j = b; j <= d; j++)
                    A[i][j] = true;
        }

        ans = 0;
        for(int i = 1; i <= w; i++)
            for(int j = 1; j <=h; j++)
                if(!A[i][j])
                ans += 1;

        if(ans == 0)puts("There is no empty spots.");
        else if(ans == 1)puts("There is one empty spot.");
        else printf("There are %d empty spots.\n", ans);
    }
	return 0;
}
