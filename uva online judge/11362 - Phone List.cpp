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
#define R 10
#define NIL -1
#define N 200000
struct Trie{
    bool val;
    int next[R];
};
Trie t[N];
int tn;
void refresh_node(int tn){
    t[tn].val = false;
            FOR(j,0,R-1)t[tn].next[j] = NIL;
}
bool find_insert(const string& key){
    int cur = 0;
    int in,len;
    len = key.length();
    FOR(i,0,len-1){
        in = key[i] - 48;
        if(t[cur].next[in]==NIL){
            refresh_node(tn);
            t[cur].next[in] =tn++;
        }
        cur = t[cur].next[in];
        if(t[cur].val)return true;
    }
    FOR(i,0,R-1)if(t[cur].next[i]!=NIL)return true;
    t[cur].val = true;
    return false;
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int test,no,cs=1;
    string key;
    bool has;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &no);
        has = false;
        refresh_node(0);
        tn=1;
        FOR(i,1,no){
            cin >> key;
            if(!has)
                has = find_insert(key);
        }
        //printf("Case %d: ",cs++);
        if(has)printf("NO\n");
        else printf("YES\n");
    }
	return 0;
}
