
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
vvi l;
vi ans;
msi h;
mis r;
vi a,b;
bool printed;
int  lcs(int m, int n){
    l = vvi(m+1,vi(n+1));
    FOR(i,0,m)l[i][0] = 0;
    FOR(j,0,n)l[0] [j] = 0;
    FOR(i,1,m)
        FOR(j,1,n){
            if(a[i-1]==b[j-1])l[i][j] = l[i-1][j-1]+1;

            else if(l[i-1][j]>l[i][j-1]){
                l[i][j] = l[i-1][j];
            }
            else {
                l[i][j] = l[i][j-1];
            }

        }
    return l[m][n];

}
void printLCS(int i, int j){
    if(i==0||j==0)return;
    if(a[i-1]==b[j-1]){

        printLCS(i-1,j-1);
        ans.push_back(a[i-1]);
    }
    else if(l[i-1][j]>l[i][j-1])
        printLCS(i-1,j);
    else printLCS(i,j-1);
}

int main()
{
    READ("input.txt");
   //WRITE("output.txt");
    int id = 0;
    string key;
    while(cin>>key){
        id=0;
        h.clear();
        r.clear();
        a.clear();
        b.clear();
        if(key[0]!='#'){
        h[key] =++id;
        r[id] = key;
        a.push_back(h[key]);
        }
        if(key[0]!='#')
        while(cin>>key&&key.at(0)!='#'){
            if(h[key]==0){
                h[key] = ++id;
                r[id] = key;
                }
            a.push_back(h[key]);
        }
        while(cin>>key&&key.at(0)!='#'){
            if(h[key]==0){
                h[key] = ++id;
                r[id] = key;
                }
            b.push_back(h[key]);
        }

    lcs(a.size(),b.size());
    printed = false;
    ans.clear();
    printLCS(a.size(),b.size());
    if(ans.size()>0)
    for(int i=0;i<ans.size()-1;i++)cout<<r[ans[i]]<<" ";
    if(ans.size()>0);
        cout<<r[ans[ans.size()-1]];
    cout << endl;
    }
	return 0;
}

