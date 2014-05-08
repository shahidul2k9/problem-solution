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
#define N 606

string sa[N];
int lcplen[N];
int lx,ly,lsa;
int lcp(const int& p1,const int& p2){
    int i;
    int lp1 = sa[p1].length();
    int lp2 = sa[p2].length();
    if(sa[p1][lp1-1]==sa[p2][lp2-1])return 0;
    int l = min(lp1,lp2);
    for(i=0;i<l&&(sa[p1][i]==sa[p2][i]);i++);
    return i;
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    string x,y;
    bool blank=false;
    int pos,ans;
    map<string,bool> m;
    while(getline(cin,x)){
        getline(cin,y);
        x.append("$");
        y.append("#");
        lx = x.length();
        ly = y.length();
        lsa = lx+ly;

        FOR(i,0,lx-1)sa[i]=x.substr(i);

        FOR(i,0,ly-1)sa[lx+i]=y.substr(i);
        sort(sa,sa+lsa);
        pos= ans = 0;
        FOR(i,0,lsa-2){

            lcplen[i] = lcp(i,i+1);
            if(ans<lcplen[i]){
                ans = lcplen[i];
                pos = i;
            }
        }
        if(blank)puts("");
        blank=true;
        if(ans ==0)printf("No common sequence.\n");
        else{
            m.clear();
            FOR(i,0,lsa-2){
                if(ans==lcplen[i])m[sa[i].substr(0,ans)]=true;
            }

            for(map<string,bool>::iterator it=m.begin();it!=m.end();it++)cout<<it->first<<endl;
        }
        getline(cin,x);
        if(feof(stdin))break;
    }
	return 0;
}
