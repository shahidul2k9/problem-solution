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

char hash[93];
void hashAll(){
    hash['A'] = hash['B'] = hash['C'] = '2';
    hash['D'] = hash['E'] = hash['F'] = '3';
    hash['G'] = hash['H'] = hash['I'] = '4';
    hash['J'] = hash['K'] = hash['L'] = '5';
    hash['M'] = hash['N'] = hash['O'] = '6';
    hash['P'] = hash['R'] = hash['S'] = '7';
    hash['T'] = hash['U'] = hash['V'] = '8';
    hash['W'] = hash['X'] = hash['Y'] = '9';
}
string charToString(char ch){
    stringstream ss ;
    ss << ch;
    string str ;
    ss >> str;
    return str;
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    msi store;
    int test, no;
    char str[1000000];
    char tele[9];
    tele[8] = '\0';
    int ind,printed;
    hashAll();
    scanf("%d", &test);
    while(test--){
        scanf("%d", &no);
        store.clear();
        FOR(i,1,no){
            scanf("%s", str);
            ind = 0;
            FOR(j,0,strlen(str)-1){
                    if(ind == 8)break;
                    if(ind==3){
                        tele[ind++] = '-';
                    }
                    if(isalpha(str[j])){
                        tele[ind++] = hash[str[j]];
                    }

                    else if(isdigit(str[j])) tele[ind++] = str[j];
            }
        store[string(tele)] += 1;
        }
        printed = 0;
        for(msi ::iterator it = store.begin(); it != store.end(); it++)
            if((*it).second >1){
                printed++;
             cout << (*it).first << " " <<  (*it).second << endl;
            }
        if(printed == 0) puts("No duplicates.");
        if(test)puts("");
    }
	return 0;
}
