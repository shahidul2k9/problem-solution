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
#define MAX 200
double a,b,h,w;

void binarySearch(){
    double lo,hi,assumed_h;
    lo = 0;
    hi =  min(a,b);
    while(true){
        w = (hi-lo)/2+lo;
        assumed_h = sqrt(a*a-w*w)*sqrt(b*b-w*w)/(sqrt(a*a-w*w)+sqrt(b*b-w*w));
        if(fabs(assumed_h-h)<=EPS)
            return;
        if(assumed_h>h)lo=w;
        else hi=w;
    }
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    while(scanf("%lf%lf %lf",&a,&b,&h)==3){


    binarySearch();
    printf("%.3lf\n",w);
    }

	return 0;
}

