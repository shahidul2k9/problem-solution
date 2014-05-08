#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
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

#define N 12

int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int n, sum,dm,top,dow,cs=0;
    int a[N][N];
    while(scanf("%d", &n)&&n){
        dm = ceil((float)n/2);
        top = 0;
        dow = n-1;
        FOR(i,0,n-1)
            FOR(j,0,n-1)scanf("%d", &a[i][j]);
        printf("Case %d: ",++cs);
        FOR(d,0,dm-1){
            sum = 0;
            FOR(i,top,dow) if(a[top][i]!=INF){sum +=a[top][i];a[top][i]=INF;}
            FORD(i,dow,top) if(a[dow][i]!=INF){sum +=a[dow][i];a[dow][i]=INF;}

            FOR(i,top+1,dow-1)if(a[i][top]!=INF){sum +=a[i][top];a[i][top]=INF;}

            FORD(i,dow-1,top+1) if(a[i][dow]!=INF){sum +=a[i][dow];a[i][dow]=INF;}
            //for(int i=dow-1;i>=top;i--) sum +=a[i][dow];
            top++;
            dow--;
            printf("%d%c",sum,(d==dm-1)?'\n':' ');
        }

    }
	return 0;
}
