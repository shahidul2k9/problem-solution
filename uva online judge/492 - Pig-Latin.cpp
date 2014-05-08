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


int main()
{
    freopen("input.txt","r",stdin);
    char ch;


    while(ch = getchar()){
        if(ch == EOF)return 0;
        if(ch == 'a' || ch == 'A' || ch=='e' || ch=='E' || ch == 'i' || ch == 'I' \
           || ch == 'o' || ch == 'O' || ch == 'u'|| ch == 'U') {
               cout << ch;
               while(ch = getchar()){
                   if(!isalpha(ch))break;
                   cout << ch;
                   }
               cout << "ay";
           }
        else if(isalpha(ch)){
            char save = ch;
            while(ch = getchar() ) {
                if(!isalpha(ch))break;
                cout << ch;

                }
            cout << save << "ay";
        }
        cout << ch;
    }
	return 0;
}
