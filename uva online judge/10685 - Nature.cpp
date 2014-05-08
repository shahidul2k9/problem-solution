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

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define SQR(x) ((x)*(x))
#define PI 2*acos(0)
#define EPS 1e-7
#define MAX 200



#define MAX_CREATERS 5000
int sets[MAX_CREATERS];
int els[MAX_CREATERS];

int findRepresentative(int p){
    if(sets[p] == p) return p;
    else return sets[p] = findRepresentative(sets[p]);
}
int main(){

    //freopen("input.txt", "r", stdin);

    map<string, int > hash;
    int C, R;
    int rx,ry;
    int ans;
    string x, y;
    while(scanf("%d %d", &C, &R) == 2 && (C||R)){

        ans = 1;
        hash.clear();
        for(int i = 0; i < C; i++){
            cin >> x;
            hash[x] =i;
            els[i] = 1;
            sets[i] = i;
        }
        for(int i = 0; i < R; i++){
            cin >> x >> y;
            rx = findRepresentative(hash[x]);
            ry = findRepresentative(hash[y]);
            if(rx != ry){
                els[rx] = els[rx] + els[ry];
                sets[ry] = rx;
                ans = max(ans, els[rx]);
            }

        }
        printf("%d\n", ans);

    }
	return 0;
}
