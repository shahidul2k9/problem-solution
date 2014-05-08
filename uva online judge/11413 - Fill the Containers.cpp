

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
#define MAX 1000
int A[MAX];
int N, M;

bool isPossible(int size){
    int curM = 1;
    int amountM = 0;
    int i;
    for(i = 0; i < N; i++){
        if(amountM + A[i] <= size){
            amountM += A[i];
        }
        else if(curM == M || size < A[i])return false;
        else {
            amountM = A[i];
            curM += 1;
        }
    }
    return true;
}
int binarySearch(int lo, int hi){
    int mid;
    while(lo < hi && lo + 1 != hi){
        mid = (hi - lo)/2 + lo;
        if(isPossible(mid))hi = mid;
        else lo = mid;

    }
    if(lo == hi) return lo;
    if(isPossible(lo)) return lo;
    else return hi;
}
int main(){
    //freopen("input.txt", "r", stdin);


    int ans, hi;
    while(scanf("%d %d", &N, &M) == 2){
        hi = 0;
        for(int i = 0; i < N; i++){
            scanf("%d", &A[i]);
            hi += A[i];

        }

        ans = binarySearch(0, hi);
        printf("%d\n", ans);
    }


	return 0;
}
