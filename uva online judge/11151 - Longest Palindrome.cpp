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
#define SQR(x) ((x)*(x))
#define PI 2*acos(0)
#define EPS 1e-7
#define N 1001
int l[N][N];
string s;
int lpl(int lo,int hi){
    if(l[lo][hi]!=-1)return l[lo][hi];

    if(lo==hi) {
        l[lo][hi]=1;
        return 1;
    }

    if(lo+1==hi){
        if(s[lo]==s[hi])return l[lo][hi] = 2;
        return l[lo][hi] = 1;
    }
     if(s[lo]==s[hi])return l[lo][hi]= 2+lpl(lo+1,hi-1);
     return l[lo][hi] = max(lpl(lo+1,hi),lpl(lo,hi-1));
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int test;
    scanf("%d",&test);
    getline(cin,s);
    while(test--){
        getline(cin,s);
        FOR(i,0,s.length()-1)
            FOR(j,0,s.length()-1)l[i][j]=-1;
        printf("%d\n",lpl(0,s.length()-1));
    }
	return 0;
}
