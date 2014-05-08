#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
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
#define N 200001
char s[N];
int l;
bool isPalindrome(int lo,int hi){
    while(lo<hi)if(s[lo++]!=s[hi--])return false;
    return true;
}
bool isAlindrome(){
    FOR(i,0,l-2){
        bool logic1 = isPalindrome(0,i);
        bool logic2 = isPalindrome(i+1,l-1);
            if(logic1&&logic2)
                return true;
    }
    return false;
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int test;
    scanf("%d",&test);
    gets(s);
    while(test--){
        l = strlen(gets(s));
        if(isAlindrome())puts("alindrome");
        else if(isPalindrome(0,l-1))puts("palindrome");
        else puts("simple");
    }
	return 0;
}
