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
typedef map<char, int> mci;
typedef map<int, string> mis;
typedef map<string, string> mss;
typedef map<string, char> msc;

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct {
    char ch;
    int f;
}AlphaList;

bool comp(AlphaList a, AlphaList b){
    if(a.f!=b.f)return a.f>b.f;
    else return a.ch<b.ch;
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    AlphaList list[27];
    int test,i,j;
    string line;
    mci m;
    char ch;

    scanf("%d", &test);
    getline(cin,line);
    while(test--){
        getline(cin,line);
        for(i=0;i<line.length();i++){
            ch = line[i];
            if(isalpha(ch)){
                ch = toupper(ch);
                m[ch] += 1;
            }
        }

    }

     map<char,int> :: iterator it;
        for(i=0,it=m.begin();it!=m.end();it++){
            list[i].ch =  (*it).first;
            list[i].f = (*it).second;
            i++;
        }

    sort(list,list+i,comp);
    for(j=0;j<i;j++)printf("%c %d\n",list[j].ch, list[j].f);
	return 0;
}
