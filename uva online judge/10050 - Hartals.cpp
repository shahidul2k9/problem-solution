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
#define MAX 3651
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    bool hartal[MAX];
    int test,parties,days,h,hartalNo;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &days, &parties);
        ifor(i,1,days) hartal[i] = false;
        ifor(i,1,parties){
            scanf("%d", &h);
            for(int j=h;j<=days; j +=h)hartal[j] = true;
        }
        for(int i = 6;i<=days; i+=7)hartal[i] = false;
        for(int i = 7;i<=days; i+=7)hartal[i] = false;
        hartalNo=0;
        ifor(i,1,days)if(hartal[i]) hartalNo++;
        printf("%d\n", hartalNo);
    }
    return 0;
}
