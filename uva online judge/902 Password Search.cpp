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

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))

#define INF INT_MAX
#define WHITE 0
#define GRAY 1
#define BLACK 2

#define R 26
#define MAX 10000
/*
RTE
int N;
char s[MAX];
int ans;
int id[128];
char w[MAX];
char pass[MAX];
struct Trie{
    int p;
    Trie* link[R];
    Trie(){
        p = 0;
       memset(link, NULL,sizeof(Trie*)*R);

    }
}* root;

void insert(char* s, Trie* cur){
    int t;
    cur->p++;
    for(int i = 0; s[i]; i++){
        t = id[s[i]];
        if(cur->link[t] == NULL)
            cur->link[t] = new Trie;

        cur = cur->link[t];

        cur->p++;
    }
}
void traverse(Trie* cur, char* x, int depth){
    if(cur == NULL || ans >= cur->p ) return;

    if(depth == N){
            *x = '\0';
            if(cur->p > ans){
                strcpy(pass, w);
                ans = cur->p;
            }
    return;
    }

    for(int i = 0; i < R; i++)
        if(cur->link[i] != NULL){
        *x = i + 'a';
        traverse(cur->link[i], x + 1, depth+1);
        }
}
void freeMemory(Trie *root){
    if(root == NULL) return;
    for(int i = 0; i < R; i++)
        freeMemory(root->link[i]);
    delete[] root->link;
    delete root;
}
int main(){
        freopen("input.txt", "r", stdin);
        for(int i = 0; i < 26; i++) id[i + 'a'] = i;
        while(scanf("%d %s", &N, s) == 2){
            ans = 0;
            root = new Trie;
            for(int i = 0; s[i]; i++) insert(s+i, root);
            traverse(root,w, 0);
            printf("%s\n", pass);
            freeMemory(root);
        }

	return 0;
}
*/
int main(){
    freopen("input.txt", "r", stdin);
    string s, as;
    int n, ans;
    map < string, int > f;
    while(cin >> n >> s){
        f.clear();
        for(int i = 0; i < s.size()- n +1; i++)
            f[s.substr(i,n)]++;
        ans = 0;
        as = "";
        for(map < string, int > :: iterator it = f.begin(); it != f.end(); it++)
            if((*it).second > ans){
                ans = (*it).second;
                as = (*it).first;
            }
        cout << as << endl;
    }
}
