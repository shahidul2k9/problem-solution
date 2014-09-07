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
#define EPS 1e-9
#define MAX 200
 
double L,W;
 int a,b;
void binarySearch(){
    double lo,hi,half_l,half_w,r,angle,this_len,expected_arc;
    lo = 0;
    hi = 400;
    while(fabs(lo-hi)>EPS){
        L = (hi+lo)/2.0;
 
        half_l = L/2.0;
        W = b*L/a;
        half_w = W/2.0;
        expected_arc = (200-L)/2.0;
        r = sqrt(SQR(half_l)+SQR(half_w));
        angle = acos(half_l/r);
        this_len = r*angle;
        if(this_len>expected_arc)hi=L;
        else lo = L;
    }
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int test,cs=0;
 
    char ch;
    scanf("%d",&test);
    while(test--){
        //scanf("%d %d",&a,&b);
        cin>>a >> ch>>b;
        binarySearch();
        printf("Case %d: %.7lf %.7lf\n",++cs,L,W);
    }
    return 0;
}