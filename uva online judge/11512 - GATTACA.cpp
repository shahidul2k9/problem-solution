
/*
Using Trie You have got TLE
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
typedef map<char, int> mci;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 1000000
#define NOLINK -2

#define R 4
int at,root,ans;
mci m;
mis hash;
int ansdepth,ansfre;
string longsub;
struct Trie{
    int words;
    int prefixes;
    int link[R];
};
vector<Trie>t;
//Trie t [N];
void clear_trie_node(int n){
    t[n].words = t[n].prefixes = 0;
    FOR(i,0,R-1)t[n].link[i] = NOLINK;
}
int getNode(){
    at++;
    t.resize(at);
    clear_trie_node(at-1);
    return at-1;
}
string asciToString(char ch){
    stringstream ss;
    string s;
    ss<<ch;
    ss>>s;
    return s;
}
void addWord(const string& key){
    int cur = root;
    int lb;
    FOR(i,0,key.length()-1){
        lb = m[key[i]];
        if(t[cur].link[lb]==NOLINK){
            t[cur].link[lb] = getNode();
        }
        cur = t[cur].link[lb];
        t[cur].prefixes++;
    }
    t[cur].words++;
}
void traverse(int u, int depth,string k){
    if(depth>ansdepth&&t[u].prefixes>1){
        ansfre = t[u].prefixes;
        ansdepth = depth;
        longsub = k;
        //cout<<"*"<<ansdepth<<k<<ansfre<<"*"<<endl;
    }
    FOR(i,0,R-1){

        if(t[u].link[i]!=NOLINK)traverse(t[u].link[i],depth+1,k+hash[i]);
    }
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int test;
    string key;

    hash[0] = "A";
    hash[1] = "C";
    hash[2] = "G";
    hash[3] = "T";
    m['A'] = 0;
    m['C'] = 1;
    m['G'] = 2;
    m['T'] = 3;
    scanf("%d", &test);
    t.reserve(N);
    while(test--){
        at=0;
        root = getNode();
        cin>>key;
        FOR(i,0,key.length()-1){
            addWord(key.substr(i));
        }
        ansdepth = ansfre = 0;
        traverse(root,0,"");
        if(ansfre==0)printf("No repetitions found!\n");
        else cout<<longsub<<" " << ansfre<<endl;
        t.clear();
    }
	return 0;
}
*/
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
#define N 1005
int lcpLength(const string& s1, const string& s2){
    int len = min(s1.length(),s2.length());
    int i;
    for(i=0;i<len&&(s1[i]==s2[i]);i++);
    return i;
}
bool comp(const string& s1, const string& s2){
    return s1<s2;
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");

    int test;
    string sa[N];
    int lcp[N];
    string key;
    int pos,lcplen;
    cin>>test;
    while(test--){
        cin>>key;
        int len = key.length();
        FOR(i,0,len-1){
        sa[i] = key.substr(i);
        }
        /*
        FOR(i,0,len-1){
            cout<<i<< " "<< sa[i]<<endl;
        }
        */
        sort(sa,sa+len);
        /*
        FOR(i,0,len-1){
            cout<<i<< " "<< sa[i]<<endl;
        }
        cout<<endl;
*/
        lcplen = pos = 0;
        FOR(i,0,key.length()-2){
            lcp[i] = lcpLength(sa[i],sa[i+1]);
            if(lcplen<lcp[i]){
                pos = i;
                lcplen = lcp[i];
            }
        }
        if(lcplen==0)printf("No repetitions found!\n");

        else {
            int i;
            for(i=pos;i<len-2&&(lcp[i]==lcp[i+1]);i++);

            for(int j=0;j<lcplen;j++)printf("%c",sa[pos][j]);
            printf(" %d\n",i-pos+2);
           //cout<<pos<<" " << lcplen<<endl;
        }

    }
	return 0;
}

