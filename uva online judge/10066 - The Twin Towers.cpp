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
#define N 105

int  s[N],t[N];
int l[N][N];
int m,n;
int lcs(){

    FOR(i,0,max(m,n))l[0][i]=l[i][0]=0;

    FOR(i,1,m)
        FOR(j,1,n){
            if(s[i-1]==t[j-1])l[i][j] = l[i-1][j-1]+1;
            else l[i][j] = max(l[i-1][j],l[i][j-1]);
        }
    return l[m][n];
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int cs=1;
    while(scanf("%d %d",&m,&n)==2&&(m||n)){

        FOR(i,0,m-1)scanf("%d",&s[i]);
        FOR(i,0,n-1)scanf("%d",&t[i]);
        printf("Twin Towers #%d\n",cs++);
        printf("Number of Tiles : %d\n\n",lcs());
    }

	return 0;
}
