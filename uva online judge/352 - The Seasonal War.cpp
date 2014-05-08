#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>		// For memset function
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <map>

using namespace std;

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))

#define INF 99999999
#define SZ size()
#define PB push_back
#define PF push_front

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<vector<char> > VVC;
typedef vector<double> VD;
typedef vector<char> VC;
typedef vector<string> VS;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2
int N;
VVC g;
int dr[] = {0, -1, -1, -1,  0,  1, 1, 1};
int dc[] = {1,  1,  0, -1, -1, -1, 0, 1};
int fill(int r, int c, char check, char rep){
    if(r<0||c<0||r>=N||c>=N||g[r][c]!=check)return 0;
    g[r][c] = rep;
    int ans = 1;
    FOR(i,0,7){
        ans += fill(r+dr[i], c+dc[i], check, rep);
    }
    return ans;
}
int main()
{
     READ("input.txt");
    //WRITE("output.txt");
    int tc=1;
    string buf;
    int ans;
    while(scanf("%d", &N)==1){
        g = VVC(N);
        getline(cin,buf);
        FOR(i,0,N-1){
            getline(cin,buf);
            g[i].assign(buf.begin(),buf.end());
        }
    ans = 0;
    FOR(i,0,N-1)
        FOR(j,0,N-1)
            {
                if(fill(i,j,'1','0')>0) ans++;
            }
            printf("Image number %d contains %d war eagles.\n", tc++, ans);
    }
	return 0;
}
