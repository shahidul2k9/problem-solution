

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


typedef long long int T;

bool balanced;
T goDown(){
    T wl, wr, dl, dr;

    scanf("%lld %lld %lld %lld", &wl, &dl, &wr, &dr);

    if(wl == 0){
        wl = goDown();
        }

    if(wr == 0){
        wr = goDown();
        }
    if(wl*dl != wr*dr) balanced = false;

    return wl + wr;


}
int main(){

    //freopen("input.txt", "r", stdin);

    T wl, wr, dl, dr;
    int test;
    scanf("%d", &test);
    while(test--){
        balanced = true;
        goDown();
        if(balanced)puts("YES");
        else puts("NO");
        if(test)puts("");
    }

	return 0;
}
