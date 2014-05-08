#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PQ priority_queue
#define PB push_back
#define SZ size()
#define ff first
#define ss second

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef vector<char> VC;
typedef vector<vector<char> > VVC;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }
#define MAX 26
#define WHITE 0
#define GRAY 1
#define BLACK 2

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

inline int src() { int ret; scanf("%d", &ret); return ret; }

int R, C;
int  A[MAX][MAX], S[MAX][MAX];
int maxSum;

int main()
{
  READ("input.txt");
//    WRITE("output.txt");
  int i, j, k;
  int TC, tc;
  string buf;
    cin >> TC;
    getline(cin,buf);

    tc = 1;
    while(TC--){
        if(tc > 1) cout << "\n";

        getline(cin,buf);
        getline(cin,buf);
        int len = buf.size();
        R = C = len;
        FOR(i,1,len){A[1][i] = ( buf[i-1]=='0')?0:1; }
        FOR(i,2,len){
                getline(cin,buf);
                FOR(j,1,len){
                    A[i][j] = (buf[j-1]=='0') ? 0:1;
            }
        }

        //FOR(i, 1, R) S[i][0]=0;
        //FOR(i, 1, C) S[0][i]=0;
        FOR(i, 1, R) FOR(j, 1, C)
            S[i][j] = S[i-1][j] + S[i][j-1] + A[i][j] - S[i-1][j-1];


     maxSum = 0;
     FOR(i, 1, R) FOR(j, 1, C) FOR(k, i, R) FOR(l, j, C) {
        int sum =   S[k][l] - S[k][j-1] - S[i-1][l] + S[i-1][j-1];
        if(abs(k-i+1)*abs(l-j+1)==sum)
            maxSum = max(maxSum, sum);
     }

    cout << maxSum << "\n";

    tc++;
    }

  return 0;
}
