#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
using namespace std;
#define ifor( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define dfor( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )

#define SQR(x) ((x)*(x))
#define INF INT_MAX
#define EPS 1e-9
#define PI (2*acos(0.0))
#define SZ size()

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long ll;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<string, char> msc;
typedef vector<vector<ii>  > vvii;
#define WHITE 0
#define GRAY 1
#define BLACK 2

int main()
{
   // READ("input.txt");
    //WRITE("output.txt");
    int D;
    char str[26];
    int no[14],maxSize,ans;
    while(scanf("%d", &D)&&D!=0){
        gets(str);
        ifor(i,0,D-1){
            no[i] = 0;
            gets(str);
            ifor(j,0,24)if(str[j]=='X')no[i]++;
        }
        maxSize = *max_element(no,no+D);
        ans = 0;
        ifor(i,0,D-1)ans = ans + maxSize - no[i];
        printf("%d\n", ans);
    }
    return 0;
}
