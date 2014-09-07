#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <assert.h>
 
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
 
#define NDEBUG
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
#define N 2500000
#define NOEDGE -2
#define R 4
int cn,root,ans;
 
struct Trie{
    int words;
    int prefixes;
    int link[R];
}t[N];
 
void clear_trie_node(int n){
    t[n].words = t[n].prefixes = 0;
    FOR(i,0,R-1)t[n].link[i] = NOEDGE;
}
void addWord(const string& key){
    int cur = 0;
    int label;
    FOR(i,0,key.length()-1){
        if(key[i]=='A')label=0;
        else if(key[i]=='C')label=1;
        else if(key[i]=='G')label=2;
        else label=3;
    //assert(label>=0&&label<=3);
        if(t[cur].link[label]==NOEDGE){
            clear_trie_node(cn);
            t[cur].link[label] = cn++;
        }
        cur = t[cur].link[label];
        t[cur].prefixes++;
    }
    t[cur].words++;
}
void traverse(int u, int depth){
    FOR(i,0,R-1){
        ans = max(ans,t[u].prefixes*depth);
        if(t[u].link[i]!=NOEDGE)
            traverse(t[u].link[i],depth+1);
    }
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int test,cs,nk;
    cs=1;
    string key;
    scanf("%d", &test);
    while(test--){
        scanf("%d",&nk);
        cn =1;
        ans  =0;
        clear_trie_node(root);
        FOR(i,1,nk){
            cin>>key;
            addWord(key);
        }
 
        traverse(0,0);
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}