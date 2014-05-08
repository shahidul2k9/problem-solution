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
#define N 1001

vector<string> s,t;
int m,n;
vvi l;
int lcs(){
    int m = s.size();
    int n = t.size();
    if(m==0||n==0)return 0;
    l = vvi(m+1,vi(n+1));
    int len = max(m,n);

    FOR(i,0,m)l[i][0] = 0;
    FOR(j,0,n)l[0][j] = 0;
    FOR(i,1,m)
        FOR(j,1,n){
            if(s[i-1]==t[j-1])l[i][j] = l[i-1][j-1]+1;
            else l[i][j] = max(l[i-1][j],l[i][j-1]);
        }
        return l[m][n];
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    map<string,bool> h;
    string x,y;
    int mach=0;
    int cs=1;
    bool empty = false;
    stringstream ss;
    while(getline(cin,x)){

        if(x.size()==0)
            empty = true;
        s.clear();
        t.clear();
        FOR(i,0,x.length()-1)if(!(isalpha(x.at(i))||isdigit(x.at(i))))x[i] = ' ';
        ss.clear();
        ss<<x;

        while(ss>>x)
            s.push_back(x);
        getline(cin,x);

        if(x.size()==0||empty){
            printf("%2d. Blank!\n",cs++);
            empty = false;
            continue;
            }
        FOR(i,0,x.length()-1)if(!(isalpha(x.at(i))||isdigit(x.at(i))))x[i] = ' ';
        ss.clear();
        ss<<x;
        while(ss>>x)
            t.push_back(x);
        mach = lcs();
        printf("%2d. Length of longest match: %d\n",cs++,mach);
        empty = false;
    }
	return 0;
}
