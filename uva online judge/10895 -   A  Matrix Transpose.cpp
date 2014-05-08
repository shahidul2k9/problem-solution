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

#define MAX 10009


int main()
{
   // READ("input.txt");
    //WRITE("output.txt");
    int row, col, sz, noEl, value, colNo[MAX];
    vvii at = vvii(MAX);
    while(scanf("%d %d", &row, &col)==2){
        ifor(i,1,col)at[i].clear();
        ifor(i,1,row){
            scanf("%d", &noEl);
            ifor(j,1,noEl)scanf("%d",&colNo[j]);
            ifor(j,1,noEl){
                scanf("%d", &value);
                at[colNo[j]].push_back(ii(i,value));
                }
        }
    printf("%d %d\n", col, row);
    ifor(i,1,col){
        sz = at[i].size();
        printf("%d", sz);
        ifor(j,0,sz-1)printf(" %d", at[i][j].first);
        printf("\n");

        if(sz==0)printf("\n");
        else{
            ifor(j,0,sz-2)printf("%d ", at[i][j].second);
            printf("%d\n", at[i][sz-1].second);
        }


    }
    }
	return 0;
}
