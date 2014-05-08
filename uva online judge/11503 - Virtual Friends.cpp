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


#define ALL_BITS 0xFFFFFFFF
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= (~(1 << i)))
#define FLIP_BIT(mask, i) (mask ^= (1 << i))

#define OFF_SETED_LSB(x) ( x &= (x-1) )
#define GET_RIGHT_PART_OF_SETED_LSB(x) ( x &= (-x) )//right side of seted lsb including lsb
#define SET_UNION(A,B) (A|B)
#define SET_INTERSECTION(A,B) (A&B)
#define SET_DIFFERENCE(A,B) (A& (~B))
#define CTZ(x) __builtin_ctz(x)
#define CLZ(x) __builtin_clz(x)
#define COUNT_SET_BITS(x) __builtin_popcount(x)
#define IS_POWER_OF_TWO(x) (x&(x-1))
#define MAX_PRESONS 2*100000
int pre[MAX_PRESONS];
int findPre(int p){
    if(pre[p] == p) return p;
    else return pre[p] = findPre(pre[p]);
}
int main(){

    freopen("input.txt", "r", stdin);
    int weight[MAX_PRESONS];
    int test, pairs;
    string x, y;
    int rx,ry;


    map<string, int > hash;
    int top;
    scanf("%d", &test);
    while(test--){
        hash.clear();
        scanf("%d", &pairs);
        top = 0;
        for(int i = 0; i < pairs; i++){
            cin >> x >> y;
            if(hash.find(x) == hash.end()){
                pre[top] = top;
                weight[top] = 1;
                hash[x] = top++;
            }
            if(hash.find(y) == hash.end()){
                pre[top] = top;
                weight[top] = 1;
                hash[y] = top++;
            }
            rx = findPre(hash[x]);
            ry = findPre(hash[y]);
            if(rx != ry){

                weight[rx] = weight[rx] + weight[ry];
                weight[ry] = weight[rx];
                pre[rx] = pre[ry];

            }
            printf("%d\n", weight[rx]);
        }
    }
	return 0;
}
