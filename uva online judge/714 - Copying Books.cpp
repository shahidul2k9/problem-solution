

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
long long int  A[MAX];
int K, M;
vector<pii> group;
bool isPossible(long long int size){
    int curK = 1;
    long long int amountK = 0;
    for(int i = 0; i < M; i++){
        if(amountK + A[i] <= size){
            amountK += A[i];
        }
        else if(curK == K || size < A[i])return false;
        else {
            amountK = A[i];
            curK += 1;
        }
    }
    return true;
}
long long int binarySearch(long long int lo,  long long int hi){
    long long int  mid;
    while(lo < hi && lo + 1 != hi){
        mid = ((hi - lo)/2) + lo;
        if(isPossible(mid))hi = mid;
        else lo = mid;

    }
    if(lo == hi) return lo;
    if(isPossible(lo)) return lo;
    else return hi;
}

void paritition(long long int  ans){

    group.clear();
    long long int  amount = 0;
    int top = M - 1;
    int i;
    for(i = M-1; i >= 0; i-- ){
        if(amount + A[i] <= ans){
            amount += A[i];

        }
        else{
            group.push_back(pii(i+1, top));
            top = i;
            amount = A[i];
        }
    }

    group.push_back(pii(0, top));

    reverse(group.begin(), group.end());
    int curK = group.size();

    for(i = 0; i < group.size(); i++){
        for(int j = group[i].first; j <= group[i].second; j++){
            printf("%lld", A[j]);

            if(curK < K && j < group[i].second){
                curK += 1;
                printf(" / ");
            }
            else if(j != group[i].second) printf(" ");

        }
        if(i+1 < group.size())
            printf(" / ");
    }


    puts("");
}
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int test;
    long long int high, ans;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &M, &K);
        high = 0;
        for(int i = 0; i < M; i++){
            scanf("%lld", &A[i]);
            high += A[i];
        }

    ans = binarySearch(0, high);

    paritition(ans);

    }
	return 0;
}
