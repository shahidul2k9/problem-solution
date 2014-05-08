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
#define N 21
int tc[N];
bool t[N],cp[N];
int n;
ull TC,ans;

void BackTrack(int label){
    if(label==n){
        ull tmp=0;
        for(int i=0;i<n;i++)if(t[i]) tmp +=tc[i];
        if(tmp<=TC) {
            if(ans<tmp){
            ans = max(ans,tmp);
            for(int i=0;i<n;i++)cp[i]=t[i];
            }
        }
        return;
    }
    t[label] = true;
    BackTrack(label+1);
    t[label] = false;
    BackTrack(label+1);
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    while(cin>>TC){
        scanf("%d",&n);
        FOR(i,0,n-1)scanf("%d",&tc[i]);
        ans=0;
        FOR(i,0,n-1)cp[i]=false;
        BackTrack(0);

        FOR(i,0,n-1)if(cp[i])printf("%d ",tc[i]);
        cout <<"sum:" <<  ans << endl;
    }
	return 0;
}
