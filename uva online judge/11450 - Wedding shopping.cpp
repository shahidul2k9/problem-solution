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
int M,C;
int memo[201][25];
int price[25][25];
int shop(int money_left, int garment_id){
    int i;
    if(money_left<0)return INT_MIN;
    if(garment_id==C)return M - money_left;
    if(memo[money_left][garment_id]!=-1)return memo[money_left][garment_id];
    int max_value = INT_MIN;
    for(i=1;i<=price[garment_id][0];i++){
        max_value = max(max_value,shop(money_left-price[garment_id][i], garment_id+1));
    }
    return memo[money_left][garment_id] = max_value;
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int test,score,i,j;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &M, &C);
        for(i=0;i<C;i++){
            scanf("%d", &price[i][0]);
            for(j=1;j<=price[i][0];j++)scanf("%d", &price[i][j]);
        }
        memset(memo,-1,sizeof(memo));
        score = shop(M,0);
        if(score>0)printf("%d\n",score);
        else printf("no solution\n");
    }
    return 0;
}
