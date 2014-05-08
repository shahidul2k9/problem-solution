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
    READ("input.txt");
    //WRITE("output.txt");
    mss list;
    msi accepted;
    int test, candidates, voters, maxvotes, co;
    string voter, candidate, name, party;
    scanf("%d", &test);
    getline(cin,voter); //for empty line
    while(test--){
        list.clear();
        accepted.clear();
        getline(cin,voter);//for empty line
        maxvotes = co = 0;
        scanf("%d", &candidates);getline(cin, voter);//for empty line
        FOR(i,1,candidates){
            getline(cin, candidate);
            getline(cin, party);
            list[candidate] = party;
            }
        scanf("%d", &voters);getline(cin, voter);//for empty line
        FOR(i,1, voters){
            getline(cin, candidate);
            if(list.find(candidate) != list.end()) {
                accepted[candidate] += 1;
                maxvotes = max(maxvotes, accepted[candidate]);
                }
        }

        for(msi :: iterator it = accepted.begin(); it != accepted.end(); it++){
            if((*it).second == maxvotes){
                co++;
                name = list[(*it).first];
            }
        }
    if(co == 1) cout << name << endl;
    else puts("tie");
    if(test)puts("");
    }
	return 0;
}
