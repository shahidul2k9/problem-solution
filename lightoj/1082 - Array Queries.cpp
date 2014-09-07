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

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PI;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b) {
    while(b)b^=a^=b^=a%=b;
    return a;
}

#define WHITE 0
#define GRAY 1
#define BLACK 2


int N;
VI A;
VVI M;

void ProcessRMQ() {
//  int k = (int)floor(log2(N)) + 1;
    M = VVI(N, VI((int)floor(log2(N)) + 1));

    FOR(i, 0, N-1) M[i][0] = i;

    for(int j = 1; 1 << j <= N; j++)
        for(int i = 0; i + (1 << j) - 1 < N; i++)
            if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
}

int rmq(int i, int j) {
    int k = (int)floor(log2(j - i + 1));

    if(A[M[i][k]] <= A[M[j - (1 << k) + 1][k]]) return M[i][k];

//int temp = j - (1 << k) + 1;
    return M[j - (1 << k) + 1][k];
}
void clearAll() {
    int sz = M.size();
    A.clear();
    FOR(i,0,sz-1)M[i].clear();
}
int main() {
    // READ("input.txt");
//    WRITE("output.txt");
    int i, j, k,Q,m,n;
    int TC, tc=1;
    clearAll();
    cin>>TC;
    while(TC--) {

        cin >> N >> Q;
        A = VI(N);

        FOR(i, 0, N-1) cin >> A[i];

        ProcessRMQ();
        cout<<"Case "<<tc++<<":"<<endl;
        FOR(i,1,Q) {
            cin>>m>>n;
            cout <<A[rmq(m-1, n-1)] << "\n";
        }


    }
    return 0;
}
